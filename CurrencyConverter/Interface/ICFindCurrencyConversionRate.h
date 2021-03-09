#pragma once
#include <string>
#include "../Include/CErrorCode.h"
#include "../Interface/ICDownLoadData.h"
#include "../Interface/ICDataParser.h"
class ICFindCurrencyConversionRate
{
public:
	ICFindCurrencyConversionRate() = default;
	virtual ~ICFindCurrencyConversionRate() = default;
	virtual std::shared_ptr< ICDownLoadData> getInstanceDownLoadData()const = 0;
	virtual void setObjectforDownloadData(std::shared_ptr< ICDownLoadData>) = 0;
	virtual double getCurrencyConversionRate(const std::string from, const std::string to, ErrorCode::CCurrencyConversionResult& err)const  = 0;
	virtual std::shared_ptr<ICDataParser>  getObjectforCurrencyParser()const = 0;
	virtual void setObjectforCurrencyParser(std::shared_ptr<ICDataParser>) = 0;
};