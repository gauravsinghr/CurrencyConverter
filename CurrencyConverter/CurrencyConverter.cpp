#include <iostream>
#include<string>
#include "Include/CErrorCode.h"
#include "Include/CCurrencyConversion.h"
static constexpr const auto DEFAULTAMT = 1.00;
static constexpr const auto INVALIDAMT = 0.00;

/// <summary>
/// This is main thread of application
/// </summary>
/// <returns>Return 0 on successfull execution</returns>
int main()
{
    while (true) {
        std::string convertFrom{ "EUR" };
        std::string convertTo{ "USD" };
        auto totalAmountToConvert = DEFAULTAMT;
       // std::cout << "Enter Currency to be convert " << std::endl;
        //std::cin >> convertFrom;
        std::cout << "Base currency is : " << convertFrom << std::endl;
        std::cout << "Enter Amount to be convert " << std::endl;
        std::cout << "Amount : ";
        std::cin >> totalAmountToConvert;
        std::cout << "Total Amount to be converted " << totalAmountToConvert << std::endl;
        if (totalAmountToConvert <= INVALIDAMT) {
            std::cout << "You entered inavlid Amount " << totalAmountToConvert << std::endl;
            std::cout << "Please try again letter " << std::endl;
            continue;
        }
        std::cout << "From:";
        std::cout << convertFrom << std::endl;
        std::cout << "To:";
        std::cin >> convertTo;
        ErrorCode::CCurrencyConversionResult result = ErrorCode::CCurrencyConversionResult::CONVERSION_FAIL;
        auto convertedAmt = INVALIDAMT;
        convertedAmt = CCurrencyConversion::getInstance().convertCurrency(convertFrom, convertTo, totalAmountToConvert, result);
        if (ErrorCode::CCurrencyConversionResult::CONVERSION_SUCCESS == result) {
            std::cout << "Total Amount in " << convertTo << " = " << convertedAmt << std::endl;
        }
        std::string choice;
        std::cout << "Do you want to enter your choice" << std::endl;
        std::cout << "Enter Y to continue " << std::endl;
        std::cout << "Enter N to close App " << std::endl;
        std::cin >> choice;
        if (choice == "N" || choice == "n") {
            exit(0);
        }
    }
    return 0;
}
