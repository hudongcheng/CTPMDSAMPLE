// testTraderApi.cpp : 定义控制台应用程序的入口点。
//

#include ".\ThostTraderApi\ThostFtdcMdApi.h"
#include "MdSpi.h"

// UserApi对象
CThostFtdcMdApi* pUserApi;

// 配置参数
//char FRONT_ADDR[] = "tcp://asp-sim2-md1.financial-trading-platform.com:26213";		// 前置地址
char FRONT_ADDR[] = "tcp://180.166.80.97:41213";	//中金所CFFEX
TThostFtdcBrokerIDType	BROKER_ID = "xxxx";				// 经纪公司代码(需要联系一家期货公司的技术提供给你)
TThostFtdcInvestorIDType INVESTOR_ID = "xxxxx";			// 投资者代码(需要联系期货公司技术提供)
TThostFtdcPasswordType  PASSWORD = "xxxxxxxx";			// 用户密码(需要联系期货公司技术提供)
char *ppInstrumentID[] = {"IF1407"/*, "ru1301"*/};			// 行情订阅列表(需要设置正在发布行情的合约过期合约没用行情)
int iInstrumentID = 1;									// 行情订阅数量
//说明：上述参数因期货公司不同而不同，这个不难，你联系一家期货公司技术就说搞CTP程序化交易，人家会提供给你
//参数已设置，在VS2012下一编译，你就看到忽忽的行情出来了啊
//真搞不定有可以联系我，bj9595@qq.com
int iRequestID = 0;// 请求编号

void main(void)
{
	// 初始化UserApi
	pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();			// 创建UserApi
	CThostFtdcMdSpi* pUserSpi = new CMdSpi();
	pUserApi->RegisterSpi(pUserSpi);						// 注册事件类
	pUserApi->RegisterFront(FRONT_ADDR);					// connect
	pUserApi->Init();
	pUserApi->Join();
//	pUserApi->Release();
}