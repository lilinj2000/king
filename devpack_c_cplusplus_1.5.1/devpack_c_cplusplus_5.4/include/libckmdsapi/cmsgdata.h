#ifndef _C_MSGDATA_H_
#define _C_MSGDATA_H_

/************************************************************************/
/* @author ����
/* @date 2013.12.16
/* @descripe CMsgDataת����C�ӿں���
/* ����0��ɹ�
/************************************************************************/
#include "ckmdsdef.h"


_BEGIN_KMDSAPI_DEF

/*************************************************
	Function:       CMsgData_Create
	Description:    ʹ��CMsgDataǰ��ʼ��,�൱�ڻ�ȡʵ��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:
	Output:
	Return:         ����CMsgData��� ʧ�ܷ���NULL
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export MSGDATAHANDLE KMDSSTDCALL CMsgData_Create(void);

/*************************************************
	Function:       CMsgData_Release
	Description:    CMsgData �ͷţ����ü�������һ��֪��������������ʵ��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:
	Output:
	Return:         ���ص�ǰ���ü���
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_Release(MSGDATAHANDLE hhandle);

/*************************************************
	Function:       CMsgData_AddRef
	Description:    CMsgData �������ü��������ü�������һ
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:
	Output:
	Return:         ���ص�ǰ���ü���
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_AddRef(MSGDATAHANDLE hhandle);


/*************************************************
	Function:       CMsgData_ClearAll
	Description:    ����CMsgData�����CMsgData����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		Y		CMsgData���
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int   KMDSSTDCALL CMsgData_ClearAll(MSGDATAHANDLE hhandle);

/*************************************************
	Function:       CMsgData_DeleteItem
	Description:    ɾ��CMsgData��ָ������������
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		Y		CMsgData���
					char* pszkey					Y		Ҫɾ����CMsgData���ݵļ���
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int   KMDSSTDCALL CMsgData_DeleteItem(MSGDATAHANDLE hhandle,char* pszkey);

// ------------------------------------------------------------------------------------------------
// ��������
/*************************************************
	Function:       CMsgData_PutData_Int8
	Description:    ����CMsgData����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		Y		CMsgData���
					char* pszkey					Y		����
					signed char cValue				Y		��ֵ
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_Int8(MSGDATAHANDLE hhandle,char* szkey, int8 cValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_Int16(MSGDATAHANDLE hhandle,char* szkey,int16 shValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_Int32(MSGDATAHANDLE hhandle,char* szkey,int32 iValue);
// linux __int64 long long
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_Int64(MSGDATAHANDLE hhandle,char* szkey, int64 n64Value);

C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_UInt8(MSGDATAHANDLE hhandle,char* szkey, uint8 cValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_UInt16(MSGDATAHANDLE hhandle,char* szkey, uint16 shValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_UInt32(MSGDATAHANDLE hhandle,char* szkey, uint32 iValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_UInt64(MSGDATAHANDLE hhandle,char* szkey, uint64 n64Value);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_Float(MSGDATAHANDLE hhandle,char* szkey, float fValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_Double(MSGDATAHANDLE hhandle,char* szkey, double dValue);
/*************************************************
	Function:       CMsgData_PutData_Buf
	Description:    ����CMsgData����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		Y		CMsgData���
					char* pszkey					Y		����
					unsigned char *pbuf				Y		��ֵ һ�����ڶ��������ݻ��ߴ��ֶ����ݱ���
					unsigned int dwlen              Y       ���ݳ���
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_Buf(MSGDATAHANDLE hhandle,char* szkey, unsigned char *pbuf,unsigned int dwlen);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData(MSGDATAHANDLE hhandle,char* szkey, char* pszValue);
	
// ��ȡ����
/*************************************************
	Function:       CMsgData_GetData_Int8
	Description:    ��ȡCMsgData����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		Y		CMsgData���
					char* pszkey					Y		����
					signed char* cValue				Y		��ֵ
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_Int8(MSGDATAHANDLE hhandle,char* szkey, int8 *pcValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_Int16(MSGDATAHANDLE hhandle,char* szkey,int16 *pshValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_Int32(MSGDATAHANDLE hhandle,char* szkey,int32 *piValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_Int64(MSGDATAHANDLE hhandle,char* szkey,int64 *pn64Value);

C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_UInt8(MSGDATAHANDLE hhandle,char* szkey, uint8 *pcValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_UInt16(MSGDATAHANDLE hhandle,char* szkey,uint16 *pshValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_UInt32(MSGDATAHANDLE hhandle,char* szkey,uint32 *piValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_UInt64(MSGDATAHANDLE hhandle,char* szkey,uint64 *pn64Value);

C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_Float(MSGDATAHANDLE hhandle,char* szkey, float *pfValue);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_Double(MSGDATAHANDLE hhandle,char* szkey, double *pdValue);
/*************************************************
	Function:       CMsgData_GetData_Buf
	Description:    ��ȡCMsgData����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		Y		CMsgData���
					char* pszkey					Y		����
					unsigned char *pbuf				Y		��ֵ һ�����ڶ��������ݻ��ߴ��ֶ�����
					unsigned int dwlen              Y       ��ȡ�������ݳ���
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_Buf(MSGDATAHANDLE hhandle,char* szkey, unsigned char **pbuf,unsigned int *pdwlen);
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_String(MSGDATAHANDLE hhandle,char* szkey,unsigned char *pValue,int nmaxlen);
// �ݹ���Ϣʵ��洢
/*************************************************
	Function:       CMsgData_PutData_MsgData
	Description:    ���õݹ���Ϣʵ��洢(������һ��CMsgData��Ϊ��ֵ�ŵ�CMsgData�У�
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		Y		CMsgData���
					char* pszkey					Y		����
					MSGDATAHANDLE pHandle		Y		CMsgData��Ϣʵ����
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_MsgData(MSGDATAHANDLE hhandle,char* szkey, MSGDATAHANDLE pHandle);
/*************************************************
	Function:       CMsgData_GetData_MsgData
	Description:    ��õݹ���Ϣʵ��洢����һ��CMsgData��ȡCMsgData���͵ļ�ֵ��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		Y		CMsgData���
					char* pszkey					Y		����
					MSGDATAHANDLE* pHandle		Y		CMsgData��Ϣʵ����������ΪNULL
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/	
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_MsgData(MSGDATAHANDLE hhandle,char* szkey, MSGDATAHANDLE* pHandle);
// ��ά���ݴ洢
/*************************************************
	Function:       CMsgData_PutData_TableData
	Description:    ���ö�ά���ݴ洢��CMsgData��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		Y		CMsgData���
					char* pszkey					Y		����
					TABLEDATAHANDLE pHandle		Y		CommTableData��Ϣʵ����
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/	
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_PutData_TableData(MSGDATAHANDLE hhandle,char* szkey,TABLEDATAHANDLE pHandle);
// ��ά���ݴ洢
/*************************************************
	Function:       CMsgData_GetData_TableData
	Description:    ��ȡ��ά���ݴ洢
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		    Y		CMsgData���
					char* pszkey					Y		����
					TABLEDATAHANDLE pHandle		Y		CommTableData��Ϣʵ��������Ҫ����ǰ����TABLEDATAHANDLE���������ΪNULL
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CMsgData_GetData_TableData(MSGDATAHANDLE hhandle,char* szkey,TABLEDATAHANDLE* pHandle);

// ------------------------------------------------------------------------------------------------
/*************************************************
	Function:       CMsgData_HaveData
	Description:    �ж������Ƿ����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			MSGDATAHANDLE hhandle		Y		CMsgData���
					char* pszkey					Y		����
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
 C_KMDSAPI_Export int  KMDSSTDCALL CMsgData_HaveData(MSGDATAHANDLE hhandle,char* szkey);


_END_KMDSAPI_DEF

#endif