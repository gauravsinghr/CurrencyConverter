#pragma once
#include "../Include/CErrorCode.h"
class ICCurrencyConverion
{
public:
	virtual double convertCurrency(const std::string from, const std::string to, const double Amt, ErrorCode::CCurrencyConversionResult& err) = 0;
	ICCurrencyConverion() = default;
	virtual ~ICCurrencyConverion() = default;
};
