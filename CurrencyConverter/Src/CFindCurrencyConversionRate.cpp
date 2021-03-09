#include "../Include/CFindCurrencyConversionRate.h"

//compile time const fir Ammount
static constexpr auto INVALID_AMT = -1;
#include<iostream>
/// <summary>
/// constructor
/// </summary>
CFindCurrencyConversionRate::CFindCurrencyConversionRate() :
    m_CurrencyConversionData{ std::make_shared<CCurrencyConversionData>() },
    m_datadownloadfromrest{ std::make_shared<CDownLoadData>() }
{

}
/// <summary>
/// this function return currency cunversion rate
/// </summary>
/// <param name="from">base currecny</param>
/// <param name="to">target currency</param>
/// <param name="err">error code</param>
/// <returns>currency conversion rate</returns>
double CFindCurrencyConversionRate::getCurrencyConversionRate(const std::string from, const std::string to, ErrorCode::CCurrencyConversionResult& err)const
{
    auto readData{ m_datadownloadfromrest->dataRequestCommand(from )};
    if (0 != readData.length())
    {
        m_CurrencyConversionData->parseData(readData);
        return m_CurrencyConversionData->getCurrencyConversionFactor(to);
    }
    err = ErrorCode::CCurrencyConversionResult::SERVER_INFO_ERROR;
    return INVALID_AMT;
}
/// <summary>
/// This the setter function
/// </summary>
/// <param name="doanloadData">param to set member varaible</param>
void CFindCurrencyConversionRate::setObjectforDownloadData(std::shared_ptr<ICDownLoadData> doanloadData)
{
    m_datadownloadfromrest = doanloadData;
}
/// <summary>
/// this the getter function
/// </summary>
/// <returns>return poiner to for downloading data using rest</returns>
std::shared_ptr< ICDownLoadData> CFindCurrencyConversionRate::getInstanceDownLoadData()const
{
   return m_datadownloadfromrest;
}
 /// <summary>
 /// this function will return object of CData parser class
 /// </summary>
 /// <returns>object to CDataParse</returns>
 std::shared_ptr<ICDataParser>  CFindCurrencyConversionRate::getObjectforCurrencyParser()const
{
     return m_CurrencyConversionData;
}
/// <summary>
/// This function will set object of CDataParser if needed
/// </summary>
/// <param name="obj"> return object of CDataParser</param>
void CFindCurrencyConversionRate::setObjectforCurrencyParser(std::shared_ptr<ICDataParser> obj)
{
    m_CurrencyConversionData = obj;
}