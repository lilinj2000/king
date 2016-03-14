#ifndef _C_KMDS_USER_API_H_
#define _C_KMDS_USER_API_H_
#include "ckmdsdef.h"

_BEGIN_KMDSAPI_DEF

    C_KMDSAPI_Export KMDSUSERAPIHANDLE KMDSSTDCALL KmdsUserApi_Create();

    C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_Destory(KMDSUSERAPIHANDLE hhandle);

    /*************************************************
	Function:       KmdsUserApi_Init
	Description:    ��ʼ��
	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
	                KMDSUSERAPIHANDLE hhandle �û�API���
	                const char* szcfgpath	  ���������ļ���

	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:         ��ɶԱ���������Ϣ��װ�ء�����ͨѶ����ĳ�ʼ����
	                �û��ӿڿ���سɹ������
	ex:
	*************************************************/
	C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_Init(KMDSUSERAPIHANDLE hhandle,const char* szcfgpath = NULL);

	/*************************************************
	Function:       KmdsUserApi_UnInit
	Description:    �˳���������ļ������˳��������̣߳��ͷ���Ӧ��Դ
	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
	               KMDSUSERAPIHANDLE hhandle �û�API���
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:         �ͻ����˳�ʱ����
	ex:
	*************************************************/
	C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_UnInit(KMDSUSERAPIHANDLE hhandle);

	/*************************************************
	Function:       KmdsUserApi_Login
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
	                KMDSUSERAPIHANDLE hhandle �û�API���
	                const char* szname  ��Ȩ���û���
				    const char* szpass  �û�����
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:
			        ��ʼ��֮����ã����÷��سɹ�����ܽ����������
	ex:
	*************************************************/
	C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_Login(KMDSUSERAPIHANDLE hhandle,const char* szname,const char* szpass);

    /*************************************************
	Function:       KmdsUserApi_Logout
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
    C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_Logout(KMDSUSERAPIHANDLE hhandle);

    /*************************************************
	Function:       KmdsUserApi_GetHqData
	Description:    ��ȡ����
	Input:          int ncmd               ����� �μ� ENUM_KMDS_DATA_TYPE
	                CMsgData* preqdata     �������,�μ�LBM�ӿ��ĵ�
	                CMsgData** ppansdata   Ӧ������
	Output:
	Return:         0��ʾ�޴���������ʾ�����
	Others:
	ex:
	*************************************************/
    C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_GetHqData(KMDSUSERAPIHANDLE hhandle,int ncmd,MSGDATAHANDLE preqdata,MSGDATAHANDLE* ppansdata);

	/*************************************************
	Function:       KmdsUserApi_SyncCallLBM
	Description:    ͬ��KCBP����
	                ��Զ��KCBP���������е�Ե��ͨѶ��ͬ����ȡ���ص�����Ӧ������
	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
	                KMDSUSERAPIHANDLE hhandle �û�API���
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
	C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_SyncCallLBM(KMDSUSERAPIHANDLE hhandle,const char* szlbmno,MSGDATAHANDLE preqdata, MSGDATAHANDLE* ppansdata,int ntimeout = -1);


	/*************************************************
	Function:       KmdsUserApi_Subscribe
	Description:    ���ö����������Ҫִ�е���Ϣ�ص�����(���⴮)

	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
	                KMDSUSERAPIHANDLE hhandle �û�API���
	                const char* sztopic   �������⴮
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:
			        �û���¼��֤�ӿڵ��óɹ���ʹ�á��û�ģ�齫У�鶩�ĵ����⴮��
			        ���޴˶���Ȩ���򷵻ش���
	ex:
	*************************************************/
	C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_Subscribe(KMDSUSERAPIHANDLE hhandle,const char* sztopic);

	/*************************************************
	Function:       KmdsUserApi_UnSubscribe
	Description:    ȡ����������(���⴮)

	Calls:
	Called By:
	Table Accessed:
	Table Updated:
	Input:
	                KMDSUSERAPIHANDLE    hhandle  �û�API���
	                const char*          sztopic  �������������,Ϊ��ʱȡ��ȫ������
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:

	ex:
	*************************************************/
	C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_UnSubscribe(KMDSUSERAPIHANDLE hhandle,const char* sztopic);

	/*************************************************
	Function:       KmdsUserApi_SetSubscribe
	Description:    ���ö����������Ҫִ�е���Ϣ�ص�����
	Input:
	                KMDSUSERAPIHANDLE hhandle       �û�API���
					int               nSubType      ���ķ�ʽ: 0��ȫ���ⶩ 1������  2:ɾ��  3: ȫ������
					char*             szMarketCode  �����г�  CHAR2  �� ���ֵ�-�г���
					char*             szMqType		�������  CHAR4  �� ���ֵ�-�������͡�
					char*             szWkType      ��������  CHAR2  �������ͱ�ʶ������ģ�⣬0Ϊ��������������Ϊ��ͬ��ģ����
					char*             szDsLevel     ��������  CHAR   �ַ�'1': һ��������'2':��������
					char*             szDsCode      ������Դ  CHAR4  ������Դ��ʶ������Դ��ţ�ȡֵΪ1..n��0��ʾ�Ƚϴ���󷢲�������
					char*             szPsCode      �����ڵ�  CHAR2	�����ڵ��ʶ���鷢���ڵ��ţ���01,02��, ��ҪΪ��RVRD��ͬ�ڵ㴫��
	Output:
	Return:			0��ʾ�ɹ��� ����ʧ��
	Others:
					�û���¼��֤�ӿڵ��óɹ���ʹ�á��û�ģ�齫У�鶩�ĵ����⣬���޴˶���Ȩ���򷵻ش���
					nSubType = 3ʱ���������û�Ȩ�޵�ȫ������
	ex:
	*************************************************/
	C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_SetSubscribe(KMDSUSERAPIHANDLE hhandle,int nSubType,
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
	                KMDSUSERAPIHANDLE hhandle       �û�API���
	                CKmdsMsgCB*       pMsgCB  �ص���ӿ�
					���ΪNULL��ȡ�����Ļص�
	Output:
	Return:         0��ʾ�ɹ��� ����ʧ��
	Others:
			        �û���¼��֤�ӿڵ��óɹ���ʹ�á�
	ex:
	*************************************************/
	C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_SetKmdsMsgCB(KMDSUSERAPIHANDLE hhandle,ON_MSG_RECV_CALLBACK pmsgcb);

	/*************************************************
	Function:       KmdsUserApi_SubscribeStkCode
	Description:    ��֤ȯ���붩������
	Input:
	                KMDSUSERAPIHANDLE   hhandle       �û�API���
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
	C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_SubscribeStkCode(KMDSUSERAPIHANDLE hhandle,int nType,int nMarketCode, const char *lpszStkCode);

	/*************************************************
	Function:       KmdsUserApi_GetErrCode
	Description:    ��ȡ���һ�ε��õĴ����
	Input:
				KMDSUSERAPIHANDLE hhandle       �û�API���
	Output:
	Return:         0��ʾ�޴���������ʾ�����
	Others:
	ex:
	*************************************************/
	C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_GetErrCode(KMDSUSERAPIHANDLE hhandle);

	/*************************************************
	Function:       KmdsUserApi_GetErrMsg
	Description:    ��ȡ���һ�ε��õĴ�����Ϣ
	Input:
				KMDSUSERAPIHANDLE hhandle       �û�API���
	Output:
	Return:         ����Ϊ�����޴���
	Others:      	�ڵ��������ӿں�������ֵ��Ϊ0ʱ����
	ex:
	*************************************************/
	C_KMDSAPI_Export const char* KMDSSTDCALL  KmdsUserApi_GetErrMsg(KMDSUSERAPIHANDLE hhandle);

	/*************************************************
	Function:       KmdsUserApi_Version
	Description:    ��ȡ����汾��Ϣ
	Input:
				KMDSUSERAPIHANDLE hhandle       �û�API���
	Output:
	Return:         ����汾��Ϣ�ַ���
	Others:
	ex:
	*************************************************/
	C_KMDSAPI_Export const char* KMDSSTDCALL  KmdsUserApi_Version(KMDSUSERAPIHANDLE hhandle);

    /*************************************************
	Function:       KmdsUserApi_GetTopicJurisdiction
	Description:    ��ȡ�û�Ȩ��
	Input:
	Output:         CMsgData * * ppansdata  �����б�
	Return:         0��ʾ�޴���������ʾ�����
	Others:
	ex:
	*************************************************/
    C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_GetTopicJurisdiction(KMDSUSERAPIHANDLE hhandle, MSGDATAHANDLE* ppansdata);

    /*************************************************
    Function:       KmdsUserApi_GetHqData
    Description:    �����ط�
    Input:          CMsgData* preqdata     �������,�μ��ӿ��ĵ�
    Output:
    Return:         0��ʾ�޴���������ʾ�����
    Others:
    ex:
    *************************************************/
    C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_StartPlayBackData(KMDSUSERAPIHANDLE hhandle, MSGDATAHANDLE preqdata);

    /*************************************************
    Function:       KmdsUserApi_StopPlayBackData
    Description:    ֹͣ�ط�
    Input:
    Output:
    Return:         0��ʾ�޴���������ʾ�����
    Others:
    ex:
    *************************************************/
    C_KMDSAPI_Export int KMDSSTDCALL KmdsUserApi_StopPlayBackData(KMDSUSERAPIHANDLE hhandle);

_END_KMDSAPI_DEF

#endif
