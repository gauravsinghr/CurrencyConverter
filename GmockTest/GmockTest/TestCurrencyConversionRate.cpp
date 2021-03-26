#include "TestCurrencyConversionRate.h"
#include "MockFindCurrencyConversionRate.h"
#include "../../CurrencyConverter/Include/CErrorCode.h"
/// <summary>
/// to setUp pre-test-suite 
/// SetUpTestCase() is invoked before any test defined in this class(test suite) is taken.
///  it serve as preparation operation.
/// this can  be omitted if not required
/// </summary>
void TestCurrencyConversionRate::SetUpTestSuite()
{

}
/// <summary>
/// It should clean up all the resources shared by the tests of this class.
/// TearDownTestCase() will be called after all the tests of this class are performed.
/// this function be omitted if not required.
/// </summary>
void TestCurrencyConversionRate::TearDownTestSuite()
{

}

// This function call before each test performed
void TestCurrencyConversionRate::SetUp()
{
	m_DownLoadData = std::make_shared<MockDownloadData>();
	m_curencyconversionFactor = std::make_shared<MockDataParser>();
	m_currencyConversionRate = std::make_shared<CurrencyConversionRateInterface>(m_DownLoadData);
	m_currencyConversionRateToParseData = std::make_shared<CurrencyConversionRateInterface>(CurrencyConversionRateInterface(m_curencyconversionFactor, m_DownLoadData));
	//CFindCurrencyConversionRate::getInstance().setObjectforDownloadData(m_DownLoadData);
}
// this function call after each test performed
void TestCurrencyConversionRate::TearDown()
{

}
double TestCurrencyConversionRate::getCurrencyConversionRate(const std::string from, const std::string to, ErrorCode::CCurrencyConversionResult& err)
{
	return m_currencyConversionRate->getCurrencyConversionRate("EUR", "USD", err);
}
TEST_F(TestCurrencyConversionRate, getConversionRateTest)
{
	//Mock data Data download using CURL
	ErrorCode::CCurrencyConversionResult err = ErrorCode::CCurrencyConversionResult::CONVERSION_FAIL;
	ON_CALL(*m_DownLoadData,dataRequestCommand).WillByDefault([](const std::string from) {
		return std::string("{\
			\"success\":true,\
			\"timestamp\" : 1607599745,\
			\"base\" : \"EUR\",\
			\"date\" : \"2021-03-05\",\
			\"rates\" : {\
			\"USD\":1.196008\
			}\
			}");
		});
	EXPECT_CALL(*m_DownLoadData, dataRequestCommand(_)).Times(1);
	auto conversionRate = m_currencyConversionRate->getCurrencyConversionRate("EUR", "USD", err);
	std::cout<< "conversionRate = " <<conversionRate << std::endl;
	EXPECT_EQ(conversionRate,1.196008);
}
TEST_F(TestCurrencyConversionRate, getConversionRateTestWhenValueisEmpty)
{
	//Mock data Data download using CURL
	ErrorCode::CCurrencyConversionResult err = ErrorCode::CCurrencyConversionResult::CONVERSION_FAIL;
	ON_CALL(*m_DownLoadData, dataRequestCommand).WillByDefault([](const std::string from) {
		return std::string("");
		});
	EXPECT_CALL(*m_DownLoadData, dataRequestCommand(_)).Times(1);
	auto conversionRate = m_currencyConversionRate->getCurrencyConversionRate("EUR", "USD", err);
	std::cout << "conversionRate = " << conversionRate << std::endl;
	EXPECT_EQ(conversionRate, -1);
}


TEST_F(TestCurrencyConversionRate, getConversionRateTestWhenValueisIncorrect)
{
	//Mock data Data download using CURL
	ErrorCode::CCurrencyConversionResult err = ErrorCode::CCurrencyConversionResult::CONVERSION_FAIL;
	ON_CALL(*m_DownLoadData, dataRequestCommand).WillByDefault([](const std::string from) {
		return std::string("{\
			\"success\":true,\
			\"timestamp\" : 1607599745,\
			\"base\" : \"EUR\",\
			\"date\" : \"2021-03-05\",\
			\"rates\" : {\
			\"USD\":KKK1.196008\
			}\
			}");
		});
	EXPECT_CALL(*m_DownLoadData, dataRequestCommand(_)).Times(1);
	auto conversionRate = m_currencyConversionRate->getCurrencyConversionRate("EUR", "USD", err);
	std::cout << "conversionRate = " << conversionRate << std::endl;
	EXPECT_EQ(conversionRate, 0);
}
TEST_F(TestCurrencyConversionRate, getConversionFator)
{
	//Mock data Data download using CURL
	//CFindCurrencyConversionRate::getInstance().setObjectforCurrencyParser(m_curencyconversionFactor);
	ErrorCode::CCurrencyConversionResult err = ErrorCode::CCurrencyConversionResult::CONVERSION_FAIL;
	ON_CALL(*m_DownLoadData, dataRequestCommand).WillByDefault([](const std::string from) {
		return std::string("{\
			\"success\":true,\
			\"timestamp\" : 1607599745,\
			\"base\" : \"EUR\",\
			\"date\" : \"2021-03-05\",\
			\"rates\" : {\
			\"USD\":1.196008\
			}\
			}");
		});
	EXPECT_CALL(*m_DownLoadData, dataRequestCommand(_)).Times(1);
	//Mocking Data parser
	ON_CALL(*m_curencyconversionFactor, getCurrencyConversionFactor).WillByDefault([](const std::string from) {
		return 1.196010;
		});
	EXPECT_CALL(*m_curencyconversionFactor, getCurrencyConversionFactor(_)).Times(1);
	auto conversionRate = m_currencyConversionRateToParseData->getCurrencyConversionRate("EUR", "USD", err);
	EXPECT_EQ(conversionRate, 1.196010);
}
