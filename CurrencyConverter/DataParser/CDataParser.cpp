#include "CdataParser.h"
#include<iostream>
#include<memory>
/// <summary>
/// this function parse downloaded data to JSON format
/// </summary>
/// <param name="data">data inn string format</param>
void CDataParser::parseData(const std::string data)
{
    Json::CharReaderBuilder builder;
    std::string err;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    if (!reader->parse(data.c_str(), data.c_str() + data.length(), &m_data, &err)){
        std::cout << "ERROR in parsing!" << std::endl << err << std::endl;
        return;
    }
}
/// <summary>
/// Parameterise constructor to set input string
/// </summary>
/// <param name="input">string to be converted in JSON format</param>
CDataParser::CDataParser(const std::string input)
{
    parseData(input);
}
/// <summary>
/// return string in JSON format
/// </summary>
/// <returns>string in JSON format</returns>
std::string CDataParser::getStringInJsonFormat()const
{
    return m_data.toStyledString();
}
