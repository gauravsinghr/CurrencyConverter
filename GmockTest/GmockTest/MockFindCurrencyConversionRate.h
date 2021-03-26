#pragma once

#include <string>
#include "pch.h"
#include "gmock/gmock.h"
#include "../../CurrencyConverter/Interface/ICFindCurrencyConversionRate.h"
class MockFindCurrencyConversionRate :public ICFindCurrencyConversionRate
{
public:
	MOCK_METHOD(double, getCurrencyConversionRate, (const std::string from, const std::string to, ErrorCode::CCurrencyConversionResult& err), (const, override));
};