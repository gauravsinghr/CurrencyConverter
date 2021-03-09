#include "pch.h"
#include <memory>
#include "../../CurrencyConverter/DataParser/CCurrencyConversionData.h"
#include "../../CurrencyConverter/DataParser/CDataParser.h"
#include "../../CurrencyConverter/Interface/ICDataParser.h"

TEST(getCurrencyConversionFactor, inputNotDefine)
{
	std::unique_ptr< ICDataParser> parser{ std::make_unique<CCurrencyConversionData>() };
	EXPECT_EQ(parser->getCurrencyConversionFactor("USD"), 0.0);
	EXPECT_EQ(parser->getCurrencyConversionFactor("INR"), 0.0);
}
TEST(getCurrencyConversionFactor, inputDefined) {
	std::unique_ptr< ICDataParser> parser{ std::make_unique<CCurrencyConversionData>() };
	parser->parseData("{\
		\"success\":true,\
		\"timestamp\" : 1607599745,\
		\"base\" : \"EUR\",\
		\"date\" : \"2021-03-05\",\
		\"rates\" : {\
		\"USD\":1.196008\
	}\
	}");
	EXPECT_EQ(parser->getCurrencyConversionFactor("USD"), 1.196008);
}