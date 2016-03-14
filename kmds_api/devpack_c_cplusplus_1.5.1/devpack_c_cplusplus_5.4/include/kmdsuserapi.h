/******************************************************************************
*
*									KMDS V1.0
*
*           Copyright (C) 2013-2014, SHENZHEN KINGDOM Co., Ltd.
*
*                             All Rights Reserved.
*
* ===========================================================================
*
* �� �� ����kmdsuserapi.h
* ģ�����ƣ��û��ӿ�API
* ����˵�����ṩͬ���������ӷ��������û���������ȹ���
* ��    �ߣ�malin
* �������ڣ�2013-08-22
* �� �� �ţ�1.0
* �޸���ʷ��
*
* �޸�����       ����            ����
* ---------------------------------------------------------------------------
* 2013-08-22     malin           ��ʼ�汾
* 2013-12-02     fanw	         ��ʼ�����汾
******************************************************************************/

#ifndef __KMDS_USER_API_HH_
#define __KMDS_USER_API_HH_

#include "msgdata.h"
#include "kmdsapidef.h"
#define ERR_BUFSIZE   1024

class KMDSAPI_Export CKmdsUserApi
{
public:
	CKmdsUserApi();

	~CKmdsUserApi();
public:
	/*************************************************
	Function:       Init
	Description:    ��ʼ��
	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
	                const char* szcfgpath	 ���������ļ���

	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:         ��ɶԱ���������Ϣ��װ�ء�����ͨѶ����ĳ�ʼ����
	                �û��ӿڿ���سɹ������
	ex:
	*************************************************/
	int Init(const char* szcfgpath = NULL);

	/*************************************************
	Function:       UnInit
	Description:    �˳���������ļ������˳��������̣߳��ͷ���Ӧ��Դ
	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:

	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:         �ͻ����˳�ʱ����
	ex:
	*************************************************/
	int UnInit();

	/*************************************************
	Function:       Login
	Description:    �û���¼��֤
	                �����߹�������������û�Ȩ����֤��
	                �����֤ͨ����ӷ�������ȡ��Ӧ���û����鶩�������
					ͨѶЭ������ļ���FastЭ��ģ���ļ�����ͨѶ�м������
					��������Ϣ�� Ȼ���ٸ�����Щ��������������ͨѶͨ����
					׼����ʼ������������
	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
	                const char* szname  ��Ȩ���û���
				    const char* szpass  �û�����
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:
			        ��ʼ��֮����ã����÷��سɹ�����ܽ����������
	ex:
	*************************************************/
	int Login(const char* szname,const char* szpass);

    /*************************************************
	Function:       Logout
	Description:    �û��ǳ�
	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:
	ex:
	*************************************************/
    int Logout();

	/*************************************************
	Function:       SyncCallLBM
	Description:    ͬ��KCBP����
	                ��Զ��KCBP���������е�Ե��ͨѶ��ͬ����ȡ���ص�����Ӧ������
	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
					const char*  szlbmno      �������������
					CMsgData*    preqdata     ���������
					CMsgData**   ppansdata    Ӧ�����ݼ�
					int		     ntimeout	  ����ʱֵ
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:
			        �û���¼��֤�ӿڵ��óɹ���ʹ��
	ex:
	*************************************************/
	int SyncCallLBM(const char* szlbmno,CMsgData* preqdata, CMsgData **ppansdata,int ntimeout = -1);


	/*************************************************
	Function:       Subscribe
	Description:    ���ö����������Ҫִ�е���Ϣ�ص�����(���⴮)

	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
	                const char* sztopic   �������⴮
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:
			        �û���¼��֤�ӿڵ��óɹ���ʹ�á��û�ģ�齫У�鶩�ĵ����⴮��
			        ���޴˶���Ȩ���򷵻ش���
	ex:
	*************************************************/
	int Subscribe(const char* sztopic);

	/*************************************************
	Function:       UnSubscribe
	Description:    ȡ����������(���⴮)

	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
	                const char* sztopic  �������������,Ϊ��ʱȡ��ȫ������
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:

	ex:
	*************************************************/
	int UnSubscribe(const char* sztopic);

	/*************************************************
	Function:       Subscribe
	Description:    ���ö����������Ҫִ�е���Ϣ�ص�����
	Input:
					int    nSubType       ���ķ�ʽ: 0��ȫ���ⶩ 1������  2:ɾ��  3: ȫ������
					char*  szMarketCode   �����г�  CHAR2  �� ���ֵ�-�г���
					char*  szMqType		  �������  CHAR4  �� ���ֵ�-�������͡�
					char*  szWkType       ��������  CHAR2  �������ͱ�ʶ������ģ�⣬0Ϊ��������������Ϊ��ͬ��ģ����
					char*  szDsLevel      ��������  CHAR   �ַ�'1': һ��������'2':��������
					char*  szDsCode       ������Դ  CHAR4  ������Դ��ʶ������Դ��ţ�ȡֵΪ1..n��0��ʾ�Ƚϴ���󷢲�������
					char*  szPsCode       �����ڵ�  CHAR2	�����ڵ��ʶ���鷢���ڵ��ţ���01,02��, ��ҪΪ��RVRD��ͬ�ڵ㴫��
	Output:
	Return:			0��ʾ�ɹ��� ����ʧ��
	Others:
					�û���¼��֤�ӿڵ��óɹ���ʹ�á��û�ģ�齫У�鶩�ĵ����⣬���޴˶���Ȩ���򷵻ش���
					nSubType = 3ʱ���������û�Ȩ�޵�ȫ������
	ex:
	*************************************************/
	int Subscribe(int nSubType,
				  char* szMarketCode = NULL,
				  char* szMqType = NULL,
				  char* szWkType = NULL,
				  char* szDsLevel = NULL,
				  char* szDsCode = NULL,
				  char* szPsCode = NULL
				 );

	/*************************************************
	Function:       SetKmdsMsgCB
	Description:    ���ö�����Ϣ�ص���ָ��
	Input:
	                CKmdsMsgCB* pMsgCB  �ص���ӿ�
					���ΪNULL��ȡ�����Ļص�
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:
			        �û���¼��֤�ӿڵ��óɹ���ʹ�á�
	ex:
	*************************************************/
	int SetKmdsMsgCB(CKmdsMsgCB* pMsgCB);

	/*************************************************
	Function:       SubscribeByStkCode
	Description:    ��֤ȯ���붩������
	Input:
					int nType  1:���  2��ɾ��  3����ԭ��ȫ��ɾ����
	                int nMarketCode            �г�
	                const char *lpszStkCode    ֤ȯ����

	Output:
	Return:         0��ʾ�޴���������ʾ�����
	Others:         ����֤ȯ�����������յ����г��������ݣ�
					���Լӿ�API�����ٶȡ���������֤ȯ���룬�����
					ȫ�г�����
	ex:
	*************************************************/
	int SubscribeStkCode(int nType,int nMarketCode, const char *lpszStkCode);

	/*************************************************
	Function:       GetHqData
	Description:    ��ȡ����
	Input:          int ncmd               ����� �μ� ENUM_KMDS_DATA_TYPE
	                CMsgData* preqdata     �������,�μ�LBM�ӿ��ĵ�
	                CMsgData** ppansdata   Ӧ������
	Output:
	Return:         0��ʾ�޴���������ʾ�����
	Others:
	ex:
	*************************************************/
	int GetHqData(int ncmd,CMsgData* preqdata,CMsgData** ppansdata);

	/*************************************************
	Function:       GetErrCode
	Description:    ��ȡ���һ�ε��õĴ����
	Input:			��
	Output:
	Return:         0��ʾ�޴���������ʾ�����
	Others:
	ex:
	*************************************************/
	int GetErrCode();

	/*************************************************
	Function:       GetErrMsg
	Description:    ��ȡ���һ�ε��õĴ�����Ϣ
	Input:			��
	Output:
	Return:         ����Ϊ�����޴���
	Others:      	�ڵ��������ӿں�������ֵ��Ϊ0ʱ����
	ex:
	*************************************************/
	const char* GetErrMsg();

	/*************************************************
	Function:       Version
	Description:    ��ȡ����汾��Ϣ
	Input:			��
	Output:
	Return:         ����汾��Ϣ�ַ���
	Others:
	ex:
	*************************************************/
	const char* Version();

    /*************************************************
	Function:       GetTopicJurisdiction
	Description:    ��ȡ�û�Ȩ��
	Input:
	Output:         CMsgData * * ppansdata  �����б�
	Return:         0��ʾ�޴���������ʾ�����
	Others:
	ex:
	*************************************************/
    int GetTopicJurisdiction(CMsgData * * ppansdata);

    /*************************************************
	Function:       StartPlayBackData
	Description:    �����ط�
	Input:          CMsgData *pclReq  �������
	Output:
	Return:         0��ʾ�޴���������ʾ�����
	Others:
	ex:
	*************************************************/
    int StartPlayBackData(CMsgData *pclReq);

    /*************************************************
	Function:       StopPlayBackData
	Description:    ֹͣ�ط�
	Input:
	Output:
	Return:         0��ʾ�޴���������ʾ�����
	Others:
	ex:
	*************************************************/
    int StopPlayBackData();

private:
	void*             m_pkmdsuserapiimp;

};
#endif
