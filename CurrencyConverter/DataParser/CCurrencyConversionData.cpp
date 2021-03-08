#include "CcurrencyConversionData.h"
#include<iostream>
/// <summary>
/// this function return currency conversion rate for converting base currency to target currency
/// </summary>
/// <param name="currency">target currency</param>
/// <returns>currency conversion rate</returns>
double CCurrencyConversionData::getCurrencyConversionFactor(const std::string currency) const
{
	const std::string ratesTag{ "rates" };
	return m_data[ratesTag][currency].asDouble();
}