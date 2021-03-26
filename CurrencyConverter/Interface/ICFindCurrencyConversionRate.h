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
	virtual double getCurrencyConversionRate(const std::string from, const std::string to, ErrorCode::CCurrencyConversionResult& err)const  = 0;

};