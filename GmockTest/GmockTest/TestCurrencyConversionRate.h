#pragma once
#include <memory>
#include "pch.h"
#include "../../CurrencyConverter/Interface/ICFindCurrencyConversionRate.h"
#include "../../CurrencyConverter/Interface/ICDataParser.h"
#include "../../CurrencyConverter/Include/CFindCurrencyConversionRate.h"
#include "MockDownLoadData.h"
#include "MockDataParser.h"
#include "CurrencyConversionRateInterface.h"

using ::testing::_;
using ::testing::Test;

class TestCurrencyConversionRate : public CFindCurrencyConversionRate,public testing::Test
{
public:
	static void SetUpTestSuite();
	static void TearDownTestSuite();
	virtual void SetUp() override;
	virtual void TearDown();
	TestCurrencyConversionRate() = default;
	~TestCurrencyConversionRate() = default;
	double getCurrencyConversionRate(const std::string from, const std::string to, ErrorCode::CCurrencyConversionResult& err);
protected:
	std::shared_ptr<MockDownloadData> m_DownLoadData;
	std::shared_ptr<MockDataParser> m_curencyconversionFactor;
	std::shared_ptr<CurrencyConversionRateInterface> m_currencyConversionRate;
	std::shared_ptr<CurrencyConversionRateInterface> m_currencyConversionRateToParseData;
};
