#pragma once
#include<string>
class ICDownLoadData
{
public:
	virtual std::string dataRequestCommand(const std::string& from) = 0;
	ICDownLoadData() = default;
	virtual ~ICDownLoadData() = default;
};
