#include<memory>
#include "../Include/CCurrencyConversion.h"
#include "../Include/CErrorCode.h"
#include "../Include/CFindCurrencyConversionRate.h"

// compile time constant
static constexpr auto CONVERTED_AMT_ZERO = 0.00;

//compile time contant
static constexpr auto CONVERTED_RATE_ZERO = 0.00;

//compile time constant
static constexpr auto INVALID_AMT = - 1.00;

/// <summary>
/// This is the singltone class which give result of currency conversion.
/// </summary>
CCurrencyConversion::CCurrencyConversion():
	m_lastCalculatedAmt{ INVALID_AMT },
	m_lasteFromCurrency{"INVALID"},
	m_lastToCurrency{"INVALID"},
	m_lastConversionRate{-1}
{

}
/// <summary>
/// This function return total amount after conerting currency from base to target
/// </summary>
/// <param name="from">Base currency code </param>
/// <param name="to">Traget Currency code</param>
/// <param name="amt">Amount to be converted</param>
/// <param name="err">return success full on conerion success</param>
/// <returns>total ammount after currency conversion</returns>
double CCurrencyConversion::convertCurrency(const std::string from, const std::string to, const double amt, ErrorCode::CCurrencyConversionResult& err)
{
	auto conversionRate{ CFindCurrencyConversionRate::getInstance().getCurrencyConversionRate(from, to, err) };
	auto convertedAmt{ CONVERTED_AMT_ZERO };
	if ((ErrorCode::CCurrencyConversionResult::SERVER_INFO_ERROR != err)
		&& (CONVERTED_RATE_ZERO != conversionRate)) {
			if ( ( m_lastCalculatedAmt == amt )
				&& ( m_lasteFromCurrency == from )
				&& ( m_lastToCurrency == to )
				&& (m_lastConversionRate == conversionRate) ) {
				if (INVALID_AMT != m_lastCalculatedAmt) {
					err = ErrorCode::CCurrencyConversionResult::CONVERSION_SUCCESS;
					convertedAmt = m_lastCalculatedAmt ;
				}
			}
			else{
				m_lastCalculatedAmt = amt;
				m_lasteFromCurrency = from;
				m_lastToCurrency = to;
				m_lastConversionRate = convertedAmt;
				err = ErrorCode::CCurrencyConversionResult::CONVERSION_SUCCESS;
				convertedAmt = conversionRate * amt;
			}
	}
	return convertedAmt;
}
