#pragma once
#include "pch.h"
#include "gmock/gmock.h"
#include <string>
#include "../../CurrencyConverter/Interface/ICDataParser.h"

class MockDataParser : public ICDataParser
{
public:
	MOCK_METHOD(double, getCurrencyConversionFactor, (const std::string currencyCode), (const, override));
	MOCK_METHOD(bool, parseData, (const std::string& data), (override));
	MOCK_METHOD(std::string, getStringInJsonFormat, (), (const, override));
};
