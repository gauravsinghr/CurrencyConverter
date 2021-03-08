#pragma once
#include "CdataParser.h"
class CCurrencyConversionData final :public CDataParser
{
public:
	CCurrencyConversionData() = default;
	~CCurrencyConversionData() = default;
	virtual double getCurrencyConversionFactor(const std::string currencyCode)const override;
};