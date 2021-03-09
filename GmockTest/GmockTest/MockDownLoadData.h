#pragma once
#include <string>
#include "pch.h"
#include "gmock/gmock.h"
#include "../../CurrencyConverter/Interface/ICDownLoadData.h"
#include "../../CurrencyConverter/DownLoadData/CDownLoadData.h"
class MockDownloadData : public ICDownLoadData
{
public:
	MOCK_METHOD(std::string,dataRequestCommand,(const std::string from),(override));
};