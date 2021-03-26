#pragma once
#include "../../CurrencyConverter/Include/CFindCurrencyConversionRate.h"
class CurrencyConversionRateInterface:public CFindCurrencyConversionRate
{
public:
	CurrencyConversionRateInterface( std::shared_ptr<ICDownLoadData> t_downLoadData):
		CFindCurrencyConversionRate(t_downLoadData)
	{

	}

};
