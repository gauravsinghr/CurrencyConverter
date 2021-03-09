 #pragma once
namespace ErrorCode
{
	enum class CCurrencyConversionResult
	{
		INVALID_AMT = -1,
		CONVERSION_FAIL = 0,
		CONVERSION_SUCCESS = 1,
		SERVER_NOT_RESPONDING = 2,
		SERVER_INFO_ERROR = 3,
	};
}
