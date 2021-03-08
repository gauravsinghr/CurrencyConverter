#pragma once
#include<string>
#include<memory>
#include<functional>
#include "curl/curl.h"
#include "../Interface/ICDownLoadData.h"
class CDownLoadData : public ICDownLoadData
{
public:
	virtual std::string dataRequestCommand(const std::string from) override;
	CDownLoadData();
	~CDownLoadData()=default;
private:
	std::unique_ptr<CURL, std::function<void(CURL*)>> m_curlHandle;
	CURLcode m_result;
	std::string generateRestURLForRequest(const std::string from)const noexcept;
	static size_t callbackToWriteData(void* contents, size_t size, size_t nmemb, void* userp) noexcept;
};