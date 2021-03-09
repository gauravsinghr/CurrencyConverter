#pragma once
#include<iostream>
#include "../Include/CErrorCode.h"
#include "../Interface/ICCurrencyConverion.h"
class CCurrencyConversion : public ICCurrencyConverion
{
private:
	double m_lastCalculatedAmt;
	std::string m_lasteFromCurrency;
	std::string m_lastToCurrency;
	double m_lastConversionRate;
	CCurrencyConversion();
public:
	virtual double convertCurrency(const std::string from, const std::string to, const double Amt, ErrorCode::CCurrencyConversionResult& err)override;
	static CCurrencyConversion& getInstance() {
		static CCurrencyConversion ins;
		return ins;
	}
	CCurrencyConversion(const CCurrencyConversion&) = delete;
	CCurrencyConversion(CCurrencyConversion&&) = delete;
	CCurrencyConversion& operator=(const CCurrencyConversion&) = delete;
	CCurrencyConversion& operator=(CCurrencyConversion&&) = delete;

};
