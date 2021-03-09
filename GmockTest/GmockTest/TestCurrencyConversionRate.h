#pragma once
#include <memory>
#include "pch.h"
#include "../../CurrencyConverter/Interface/ICFindCurrencyConversionRate.h"
#include "../../CurrencyConverter/Interface/ICDataParser.h"
#include "../../CurrencyConverter/Include/CFindCurrencyConversionRate.h"
#include "MockDownLoadData.h"
#include "MockDataParser.h"

using ::testing::_;
using ::testing::Test;

class TestCurrencyConversionRate : public testing::Test
{
public:
	static void SetUpTestSuite();
	static void TearDownTestSuite();
	virtual void SetUp() override;
	virtual void TearDown();
	TestCurrencyConversionRate() = default;
	~TestCurrencyConversionRate() = default;
protected:
	std::shared_ptr<MockDownloadData> m_DownLoadData;
	std::shared_ptr<MockDataParser> m_curencyconversionFactor;
};
