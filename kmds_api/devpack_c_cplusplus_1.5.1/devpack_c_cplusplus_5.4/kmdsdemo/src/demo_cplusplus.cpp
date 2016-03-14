#include "stdafx.h"

#if  _DEMO_TYPE_ == _DEMO_TYPE_CPLUSPLUS_
#if defined(_WIN32)
	#if defined(_WIN64)
        #ifdef _DEBUG
          #pragma comment(lib, "../../../lib_win64/kmdsapi_x64d.lib")
          #pragma comment(lib, "../../../lib_win64/lcomm_x64d.lib")           
        #else
		  #pragma comment(lib, "../../../lib_win64/kmdsapi_x64.lib")
		  #pragma comment(lib, "../../../lib_win64/lcomm_x64.lib")
        #endif
	#else  
        #ifdef _DEBUG
          #pragma comment(lib, "../../../lib_win32/kmdsapid.lib")
          #pragma comment(lib, "../../../lib_win32/lcommd.lib")
        #else
		  #pragma comment(lib, "../../../lib_win32/kmdsapi.lib")
		  #pragma comment(lib, "../../../lib_win32/lcomm.lib")
        #endif
	#endif
#endif

char g_szTopic[256];
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "kmdsapidef.h"
#include "kmdsuserapi.h"
#include "msgdata.h"

#define LBM_RS_TABLE0				"DATA0"         // LBM返回的第一结果集KEY名, 多结果集为 DATA0, [DATA1,DATA2,...]    

class CTestKmds : public CKmdsMsgCB
{
public:
	CTestKmds()
	{
		m_pclient = new CKmdsUserApi();   
	}
	~CTestKmds()
	{
		if(m_pclient)
		{
			m_pclient->Logout();
			m_pclient->UnInit();
			delete m_pclient;
			m_pclient = NULL;
		}
	}
public:
	//初始化
	int Init()
	{		//初始化API
	    int nret = m_pclient->Init();    		            
		if (nret != 0)
		{
			printf("%d,%s\n", m_pclient->GetErrCode(),m_pclient->GetErrMsg());
			m_pclient->UnInit();
			delete m_pclient;
			m_pclient = NULL;
			return nret;
		}
		char szusername[32] = "test";
		char szpassword[32] = "888888";
		//登录
		nret = m_pclient->Login(szusername,szpassword);   
		if (nret == 0)
		{
			printf("login successfully\n");
		}
		else
		{
			printf("login failure:%s\n",m_pclient->GetErrMsg());
			m_pclient->UnInit();
			delete m_pclient;
			m_pclient = NULL;
			return nret;
		}
		//设置回调
		m_pclient->SetKmdsMsgCB(this);   
		return 0;
	}
// 订阅信息回调类
	void  OnKmdsMsg(void* pmsgdesc, void* pmsgopts,int ncmd ,CMsgData * pmsg)
	{
	if(pmsg == NULL)   {  return; }
	switch(ncmd)
	{
		case 6010:  //CMD_HQSERVER_HQ_STK_SNAPSHOT. 具体参考 server.xml
			{
				int  ntotalcount = 0;
				int  nmarket = 0;
				CTableData * ptable = NULL;
				CMsgData *  prow = NULL;
				char   szstkcode[32] = {0};
				int  nrowcount = 0;
				int  i = 0;

				pmsg->GetData_Int32("TOT_RECORD", &ntotalcount);
				pmsg->GetData_Int32("MKT_TP_CODE", &nmarket);
				printf("Receive CMD_HQSERVER_HQ_STK_SNAPSHOT, market:%d, totalcount:%d \n", nmarket, ntotalcount);
				pmsg->GetData_TableData("SEQ_HQ_SNAPSHOT", &ptable);
				if(ptable)
				{
					ptable->GetCount(&nrowcount); //该结果集记录数
					for(i=0; i<nrowcount; ++i)
					{
						ptable->GetRow(i, &prow);
						if(prow)
						{
							prow->GetData_String("SCR_CODE", (unsigned char *)&szstkcode, sizeof(szstkcode));
						}
					}
					ptable->Release();
					ptable = NULL;
				}
			}
			break;
	  case 6011:
	  case 6012:
	  	{
	  	}
	  	break;
		default:
			{
				if (pmsgdesc)
				{
					printf("Receive Subject:%s %d\n",pmsgdesc, ncmd);
					std::string str;
          pmsg->Dump(EM_DUMP_FORMAT_COLDETAIL, str);
          printf("%s\n", str.c_str());
				}
			}
			break;
	}
	}
	// 测试订阅信息
	void TestSubscribeMsg()
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
		nret = m_pclient->Subscribe(sztopic);
		if (nret != 0)
		{
			printf("subscribe failure! %d,%s\n",m_pclient->GetErrCode(), m_pclient->GetErrMsg());
		}
		else
		{
			printf("Subscribe %s success\n", sztopic);
		}
	}
private:
	CKmdsUserApi * m_pclient;
};

int main(int argc, char* argv[])
{
	//创建KMDSUSERAPI对象
	CTestKmds * cltestkmds = new CTestKmds();    
	if (cltestkmds == NULL)
	{
		return -1;
	}  
  
	g_szTopic[0] = 0;
	printf("please input sub topic : ");
	scanf("%s", g_szTopic);	
	g_szTopic[sizeof(g_szTopic) - 1] = 0;
	//printf("topic=%s\n",g_szTopic);  

	if(cltestkmds->Init() != 0)
	{
		delete cltestkmds;
		return -3;
	}
                                      									
	//测试订阅主题
	cltestkmds->TestSubscribeMsg(); 

	char  ch;
	while(true)
	{
		scanf("%c", &ch);
		if(ch == 'e' || ch == 'E')  {   break;   }
	}

	delete cltestkmds;
	return 0;
}

#endif