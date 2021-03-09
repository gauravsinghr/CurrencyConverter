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
	CFindCurrencyConversionRate();
	virtual ~CFindCurrencyConversionRate() = default;
	std::shared_ptr<ICDataParser> m_CurrencyConversionData;
	std::shared_ptr<ICDownLoadData> m_datadownloadfromrest;
public:
	static CFindCurrencyConversionRate& getInstance() {
		static CFindCurrencyConversionRate ins;
		return ins;
	}
	CFindCurrencyConversionRate(const CFindCurrencyConversionRate&) = delete;
	CFindCurrencyConversionRate(CFindCurrencyConversionRate&&) = delete;
	CFindCurrencyConversionRate& operator=(const CFindCurrencyConversionRate&) = delete;
	CFindCurrencyConversionRate& operator=(CFindCurrencyConversionRate&&) = delete;
	virtual double getCurrencyConversionRate(const std::string from, const std::string to, ErrorCode::CCurrencyConversionResult& err)const override;
	virtual void setObjectforDownloadData(std::shared_ptr<ICDownLoadData>)override;
	virtual std::shared_ptr<ICDownLoadData> getInstanceDownLoadData() const override;
	virtual std::shared_ptr<ICDataParser>  getObjectforCurrencyParser()const override;
	virtual void setObjectforCurrencyParser(std::shared_ptr<ICDataParser>)override;
};