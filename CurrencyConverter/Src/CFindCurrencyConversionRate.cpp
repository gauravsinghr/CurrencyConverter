#include "../Include/CFindCurrencyConversionRate.h"

//compile time const fir Ammount
static constexpr auto INVALID_AMT = -1;
#include<iostream>
/// <summary>
/// constructor
/// </summary>
CFindCurrencyConversionRate::CFindCurrencyConversionRate() :
    m_CurrencyConversionData{ std::make_shared<CCurrencyConversionData>() },
    m_datadownloadfromrest{ std::make_shared<CDownLoadData>() }
{

}
CFindCurrencyConversionRate::CFindCurrencyConversionRate(std::shared_ptr<ICDownLoadData> t_downLoadData):
m_CurrencyConversionData{ std::make_shared<CCurrencyConversionData>() },
m_datadownloadfromrest{ t_downLoadData }
{

}
/// <summary>
/// this function return currency cunversion rate
/// </summary>
/// <param name="from">base currecny</param>
/// <param name="to">target currency</param>
/// <param name="err">error code</param>
/// <returns>currency conversion rate</returns>
double CFindCurrencyConversionRate::getCurrencyConversionRate(const std::string from, const std::string to, ErrorCode::CCurrencyConversionResult& err)const
{
    auto readData{ m_datadownloadfromrest->dataRequestCommand(from )};
    if (0 != readData.length())
    {
        bool result = m_CurrencyConversionData->parseData(readData);
        if (true == result)
        {
            return m_CurrencyConversionData->getCurrencyConversionFactor(to);
        }
    }
    err = ErrorCode::CCurrencyConversionResult::SERVER_INFO_ERROR;
    return INVALID_AMT;
}