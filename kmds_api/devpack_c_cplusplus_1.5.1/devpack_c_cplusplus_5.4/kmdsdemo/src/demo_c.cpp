#include "stdafx.h"

#if  _DEMO_TYPE_ == _DEMO_TYPE_C_
#if defined(_WIN32)   
#if defined(_WIN64) 
#ifdef _DEBUG
#pragma comment(lib, "../../../lib_win64/libckmdsapi_x64d.lib")
#pragma comment(lib, "../../../lib_win64/lcomm_x64d.lib") 
#else
#pragma comment(lib, "../../../lib_win64/libckmdsapi_x64.lib")
#pragma comment(lib, "../../../lib_win64/lcomm_x64.lib")  
#endif
#else
#ifdef _DEBUG
#pragma comment(lib, "../../../lib_win32/libckmdsapid.lib")   
#pragma comment(lib, "../../../lib_win32/lcommd.lib")
#else
#pragma comment(lib, "../../../lib_win32/libckmdsapi.lib")   
#pragma comment(lib, "../../../lib_win32/lcomm.lib") 
#endif
#endif
#endif

char g_szTopic[256];
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "libckmdsapi/ckmdsdef.h"
#include "libckmdsapi/ckmdsuserapi.h"
#include "libckmdsapi/cmsgdata.h"
#include "libckmdsapi/ctabledata.h"

#define LBM_RS_TABLE0				"DATA0"         // LBM返回的第一结果集KEY名, 多结果集为 DATA0, [DATA1,DATA2,...]

// 订阅信息回调类
void OnKmdsMsg(void* pmsgdesc, void* pmsgopts,int ncmd ,MSGDATAHANDLE pmsg)
{
	printf("recv %d\n", ncmd);
	if(pmsg == NULL)   {  return; }
	switch(ncmd)
	{
		case 6010:  //CMD_HQSERVER_HQ_STK_SNAPSHOT. 具体参考 server.xml
			{
				int  ntotalcount = 0;
				int  nmarket = 0;
				TABLEDATAHANDLE ptable = NULL;
				MSGDATAHANDLE   prow = NULL;
				char   szstkcode[32] = {0};
				int  nrowcount = 0;
				int  i = 0;

				CMsgData_GetData_Int32(pmsg, "TOT_RECORD", &ntotalcount);
				CMsgData_GetData_Int32(pmsg, "MKT_TP_CODE", &nmarket);
				printf("Receive CMD_HQSERVER_HQ_STK_SNAPSHOT, market:%d, totalcount:%d \n", nmarket, ntotalcount);
				CMsgData_GetData_TableData(pmsg, "SEQ_HQ_SNAPSHOT", &ptable);
				if(ptable)
				{
					CTableData_GetCount(ptable, (unsigned int *)&nrowcount); //该结果集记录数
					for(i=0; i<nrowcount; ++i)
					{
						CTableData_GetRow(ptable, i, &prow);
						if(prow)
						{
							CMsgData_GetData_String(prow, "SCR_CODE", (unsigned char *)&szstkcode, sizeof(szstkcode));
						}
					}
					CTableData_Release(ptable);
					ptable = NULL;
				}
			}
			break;
		default:
			{
				if (pmsgdesc)
				{
					printf("Receive Subject:%s\n",pmsgdesc);
				}
			}
			break;
	}
}
// 测试订阅信息
void TestSubscribeMsg(KMDSUSERAPIHANDLE pclient)
{
	//用户根据自己的权限范围，订阅主题. 下列主题为测试主题.

	char sztopic[256] = {0};
	if (g_szTopic[0] != 0)
	{
		strncpy(sztopic, g_szTopic, sizeof(sztopic) - 1);
	}
	else
	{
		strncpy(sztopic, "0.*.1.1.*.*", sizeof(sztopic) - 1);
	}
	sztopic[sizeof(sztopic) - 1] = 0;     
	int nret = -1;
	nret = KmdsUserApi_Subscribe(pclient,sztopic);
	if (nret != 0)
	{
		printf("subscribe failure! %d,%s\n",KmdsUserApi_GetErrCode(pclient),KmdsUserApi_GetErrMsg(pclient));
	}
	else
	{
		printf("Subscribe success\n");
	}
}

int main(int argc, char* argv[])
{
	g_szTopic[0] = 0;
	printf("please input sub topic : ");
	scanf("%s", g_szTopic);	
	g_szTopic[sizeof(g_szTopic) - 1] = 0;
	//printf("topic=%s\n",g_szTopic); 

	//创建KMDSUSERAPI对象
	KMDSUSERAPIHANDLE pclient = KmdsUserApi_Create();    
	if (pclient == NULL)
	{
		return 0;
	}
	//初始化API
	int nret = KmdsUserApi_Init(pclient);               
	if (nret != 0)
	{
		printf("%d,%s",KmdsUserApi_GetErrCode(pclient),KmdsUserApi_GetErrMsg(pclient));
		KmdsUserApi_UnInit(pclient);
		KmdsUserApi_Destory(pclient);
		return nret;
	}
	char szusername[32] = "test";
	char szpassword[32] = "888888";
	//登录
	nret = KmdsUserApi_Login(pclient,szusername,szpassword);   
	if (nret == 0)
	{
		printf("login successfully\n");
	}
	else
	{
		printf("login failure:%s\n",KmdsUserApi_GetErrMsg(pclient));
		KmdsUserApi_UnInit(pclient);
		KmdsUserApi_Destory(pclient);
		
		return nret;
	}
	//设置回调
	KmdsUserApi_SetKmdsMsgCB(pclient,OnKmdsMsg);                                           									
	//测试订阅主题
	TestSubscribeMsg(pclient); 

	char  ch;
	while(true)
	{
		scanf("%c", &ch);
		if(ch == 'e' || ch == 'E')  {   break;   }
	}

	KmdsUserApi_Logout(pclient);
	KmdsUserApi_UnInit(pclient);	
	KmdsUserApi_Destory(pclient);
	return 0;
}

#endif