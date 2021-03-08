#pragma once
class ICDataParser {
public:
	ICDataParser() = default;
	virtual ~ICDataParser() = default;
	virtual double getCurrencyConversionFactor(const std::string currencyCode) const = 0;
	virtual void parseData(const std::string data) = 0;
	virtual std::string getStringInJsonFormat()const = 0;
};
