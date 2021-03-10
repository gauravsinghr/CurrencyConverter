# CurrencyConverter

This project uses conversion rate obtained from https://fixer.io/ using REST API to convert a given amount from base currency to target currrency. Due to the limitation on the account (usage of a free fixer.io account), user can only set base currency code to EUR.

REST APIs have used by using cURL library. Data is obtained using REST API and then parsed in JSON format using jsoncpp library.
```
jsoncpp project link: https://github.com/open-source-parsers/jsoncpp
```
curl project link: https://github.com/curl/curl

# Design : 

CurrencyConverter.cpp is a main function which create a main thread. This function take input from user Via command prompt
and send this information to other class as input. Other classes process this input and provide output. The final result(ouput
of other classes) is displayed on command prompt.

CurrencyConverter.cpp is a singleton class. This class uses CFindCurrencyConversionRate class to obtain conversion rate. The final 
output of this class is total converted target currency ammount.

CFindCurrencyConversionRate class uses CDownLoadData(REST) and CDataParser(JSON) classes . CDownLoadData is usesd for downloading 
data(currency conversion rate ) and then this downloaded data is parsed using CDataParser then currency conversion rate is read and
returned.

cURL APIs are used in CDownLoadData class. This class retrieve data from https://fixer.io/

CCurrencyConversionData class return currency conversion after reading same from JSON::Value object. This class inhert CDataParser.
CDataParser has defined how to parse a string (in JSON format) to a JSON::Value.

# Steps to execute code :

Set the CurrencyConverter project as a static library and GmockTest as Application(.exe). This can be achieved in Visual Studio
(Right click on project( CurrencyConverter ) -> properties->general Tab->Configuration Type to "Static Library (.lib)" and ( Right click on project(GmockTest) -> properties->general Tab->Configuration Type to "Application(.exe)".

a)Clean the solution
b)Build the GmockTest Project
c)execute the test cases.
