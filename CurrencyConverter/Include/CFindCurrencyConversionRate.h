#pragma once
#include<string>
#include<memory>
#include "../DownLoadData/CDownLoadData.h"
#include "../DataParser/CCurrencyConversionData.h"
#include "../Include/CErrorCode.h"
#include "../Interface/ICFindCurrencyConversionRate.h"
class CFindCurrencyConversionRate : public ICFindCurrencyConversionRate
{
private:
	std::shared_ptr<ICDataParser> m_CurrencyConversionData;
	std::shared_ptr<ICDownLoadData> m_datadownloadfromrest;
public:
	static CFindCurrencyConversionRate& getInstance() {
		static CFindCurrencyConversionRate ins;
		return ins;
	}
	CFindCurrencyConversionRate();
	virtual ~CFindCurrencyConversionRate() = default;
	//CFindCurrencyConversionRate(const CFindCurrencyConversionRate&);
	//CFindCurrencyConversionRate(CFindCurrencyConversionRate&&) = delete;
	//CFindCurrencyConversionRate& operator=(const CFindCurrencyConversionRate&) = delete;
	//CFindCurrencyConversionRate& operator=(CFindCurrencyConversionRate&&) = delete;
	virtual double getCurrencyConversionRate(const std::string from, const std::string to, ErrorCode::CCurrencyConversionResult& err)const override;
protected:
	CFindCurrencyConversionRate(std::shared_ptr<ICDownLoadData> t_downLoadData);
	CFindCurrencyConversionRate(std::shared_ptr<ICDataParser> t_dataParser, std::shared_ptr<ICDownLoadData> t_downLoadData);
};