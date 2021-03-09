#pragma once

#include <string>
#include "pch.h"
#include "gmock/gmock.h"
#include "../../CurrencyConverter/Interface/ICFindCurrencyConversionRate.h"
class MockFindCurrencyConversionRate :public ICFindCurrencyConversionRate
{
public:
	MOCK_METHOD(std::shared_ptr< ICDownLoadData>, getInstanceDownLoadData,(),(const, override));
	MOCK_METHOD(void, setObjectforDownloadData, (std::shared_ptr< ICDownLoadData>), (override));
	MOCK_METHOD(double, getCurrencyConversionRate, (const std::string from, const std::string to, ErrorCode::CCurrencyConversionResult& err), (const, override));
};