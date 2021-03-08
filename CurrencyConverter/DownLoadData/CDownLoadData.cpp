#include <iostream>
#include "CdownLoadData.h"
using easyhandle = std::unique_ptr<CURL, std::function<void(CURL*)>>;
/// <summary>
/// constructor to initilaze object and set handle for libcurl
/// </summary>
CDownLoadData::CDownLoadData() :
    m_curlHandle{ easyhandle(curl_easy_init(), curl_easy_cleanup) },
    m_result{ CURLE_OK }
{

}
/// <summary>
///  This function generate USRL for rest command
/// </summary>
/// <param name="from">base currency</param>
/// <returns>generated URL</returns>
std::string CDownLoadData::generateRestURLForRequest(const std::string from) const noexcept
{
    const std::string url{ "http://data.fixer.io/api/" };
    const std::string command{ "latest" };
    const std::string accessKey{ "5bb919addeca0837630902f349bac255" };

    std::string restURL = url + command + "?access_key=" + accessKey;

    restURL = restURL + "&format=1" + "&base=" + from;

    return restURL;
}
/// <summary>
/// this is the calback function for CURLOPT_WRITEFUNCTION
/// </summary>
/// <param name="contents">Pointer to the data delivered</param>
/// <param name="size">always one</param>
/// <param name="nmemb">size of each delivered data</param>
/// <param name="userp">pointer to the dynamically set buy user</param>
/// <returns>Number of byte downloaded on each call of this callback</returns>
inline size_t CDownLoadData::callbackToWriteData(void* contents, size_t size, size_t nmemb, void* userp) noexcept
{
    auto retVal{ size * nmemb };
    if (!retVal)
        return 0;
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return static_cast<int>(size * nmemb);
}
/// <summary>
/// this function set easy handler for libcurl ans set api to download data
/// </summary>
/// <param name="from">base currency</param>
/// <returns>data in string format</returns>
std::string CDownLoadData::dataRequestCommand(const std::string from)
{
    if (nullptr != m_curlHandle) {
        auto requestUrl = generateRestURLForRequest(from);
        std::string buffer{""};

        // set url to use in the request
        curl_easy_setopt(m_curlHandle.get(),
            CURLOPT_URL,
            requestUrl.c_str());

        // set callbackToWriteData to received data
        curl_easy_setopt(m_curlHandle.get(),
            CURLOPT_WRITEFUNCTION,
            callbackToWriteData);

        // custom pointer passed to the callbackToWriteData
        curl_easy_setopt(m_curlHandle.get(),
            CURLOPT_WRITEDATA,
            &buffer);

        // perform download data
        m_result = curl_easy_perform(m_curlHandle.get());

        if (CURLE_OK != m_result)
        {
            std::cout << "Error in CURL call. Error Code:" << m_result << std::endl;
        }

        return buffer;
    }
    return "";
}