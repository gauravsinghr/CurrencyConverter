#include "pch.h"
#include <memory>
#include "../../CurrencyConverter/DataParser/CDataParser.h"
#include "../../CurrencyConverter/Interface/ICDataParser.h"

TEST(getStringInJsonFormat, inputNotDefine) {
	std::unique_ptr<ICDataParser>  parser=std::make_unique<CDataParser>("USD");
	EXPECT_EQ(parser->getStringInJsonFormat(), "null\n");
}
TEST(getStringInJsonFormat, inputDefined) {
	const auto input{
		"{\
		\"success\":true,\
		\"timestamp\" : 1614917700,\
		\"base\" : \"EUR\",\
		\"date\" : \"2021-03-05\",\
		\"rates\" : {\
				\"INR\":87.258933\
			}\
		}"
	};
	const auto output{
		"{\n\t\"base\" : \"EUR\",\n\t\"date\" : \"2021-03-05\",\n\t\"rates\" : \n\t{\n\t\t\"INR\" : 87.258932999999999\n\t},\n\t\"success\" : true,\n\t\"timestamp\" : 1614917700\n}\n"
	};
	std::unique_ptr<ICDataParser>  parser = std::make_unique<CDataParser>(input);
	EXPECT_EQ(parser->getStringInJsonFormat(), output);
}

TEST(getStringInJsonFormat, inputDefinedUsingDefaultConstr) {
	const auto input{
		"{\
		\"success\":true,\
		\"timestamp\" : 1614917700,\
		\"base\" : \"EUR\",\
		\"date\" : \"2021-03-05\",\
		\"rates\" : {\
				\"INR\":87.258933\
			}\
		}"
	};
	const auto output{
		"{\n\t\"base\" : \"EUR\",\n\t\"date\" : \"2021-03-05\",\n\t\"rates\" : \n\t{\n\t\t\"INR\" : 87.258932999999999\n\t},\n\t\"success\" : true,\n\t\"timestamp\" : 1614917700\n}\n"
	};
	std::unique_ptr<ICDataParser>  parser = std::make_unique<CDataParser>();
	parser->parseData(input);
	EXPECT_EQ(parser->getStringInJsonFormat(), output);
}