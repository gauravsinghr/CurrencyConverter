#pragma once
#include "json/json.h"
#include "../Interface/ICDataParser.h"
class CDataParser:public ICDataParser
{
protected:
	Json::Value m_data;
public:
	CDataParser() = default;
	explicit CDataParser(const std::string input);
	virtual ~CDataParser() = default;
	virtual std::string getStringInJsonFormat()const override;
	virtual bool parseData(const std::string& data) override;
	virtual double getCurrencyConversionFactor(const std::string currencyCode) const{ return 0.0; }
};
