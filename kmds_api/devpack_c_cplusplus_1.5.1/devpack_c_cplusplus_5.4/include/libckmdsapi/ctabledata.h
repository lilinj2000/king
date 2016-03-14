#ifndef _C_TABLE_DATA_H_
#define _C_TABLE_DATA_H_
#include "ckmdsdef.h"

_BEGIN_KMDSAPI_DEF

/*************************************************
	Function:       CTableData_Create
	Description:    ����ʵ��
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:
	Output:
	Return:         ����CTableData��� ʧ�ܷ���NULL
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export TABLEDATAHANDLE KMDSSTDCALL CTableData_Create(void);

/*************************************************
	Function:       CTableData_Release
	Description:    �ͷ�
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE hhandle		Y		CTableData���
	Output:
	Return:         �������ü���
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_Release(TABLEDATAHANDLE hhandle);

/*************************************************
	Function:       CTableData_AddRef
	Description:    ��������
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE hhandle		Y		CTableData���
	Output:
	Return:         �������ü���
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_AddRef(TABLEDATAHANDLE hhandle);

/*************************************************
	Function:       CTableData_Reset
	Description:    ���CTableData����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE hhandle		Y		CTableData���
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_Reset(TABLEDATAHANDLE hhandle);

/*************************************************
	Function:       CTableData_AddRow
	Description:    ����������
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE    hhandle		  Y		  CTableData���
	                MSGDATAHANDLE*     pmsghandle     Y       CMsgData���,��Ҫ���ӵ�������
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_AddRow(TABLEDATAHANDLE hhandle,MSGDATAHANDLE* pmsghandle);

/*************************************************
	Function:       CTableData_SaveRow
	Description:    ����������
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE    hhandle		  Y		  CTableData���
	               
	Output:
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_SaveRow(TABLEDATAHANDLE hhandle);

/*************************************************
	Function:       CTableData_GetCount
	Description:    ��ȡCTableData������
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE hhandle		        Y		CTableData���
	                unsigned int    *pnCount			Y		����
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_GetCount(TABLEDATAHANDLE hhandle,unsigned int *pnCount);

/*************************************************
	Function:       CTableData_GetRow
	Description:    ��ȡCTableDataָ���е�����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE  hhandle		   Y		CTableData���
					int              nRow			   Y		CTableDataָ������
	                MSGDATAHANDLE*   pHandle           Y	    ��ȡ�����ݵ�CMsgData
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_GetRow(TABLEDATAHANDLE hhandle,int nrow, MSGDATAHANDLE* prowmsgdata);

/*************************************************
	Function:       CTableData_GetFieldCount
	Description:    ��ȡ��ά����ֶ���
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE hhandle		Y		CTableData���
                    unsigned int *pnFieldCount		Y		�ֶ���
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_GetFieldCount(TABLEDATAHANDLE hhandle,unsigned int *pnfieldcount);

/*************************************************
	Function:       CTableData_GetFieldName
	Description:    ȡ�ֶ�����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE hhandle		Y		CTableData���
					int nFieldno					Y		�ֶ����
					int nMaxLen						Y		�ֶ�������󳤶�
	Output:			unsigned char *pszFieldName				�ֶ���
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_GetFieldName(TABLEDATAHANDLE hhandle,int nfieldno,unsigned char *szfieldname,int nmaxlen);

/*************************************************
	Function:       CTableData_GetFieldType
	Description:    ȡ�ֶ�����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE hhandle		Y		CTableData���
					int nFieldno					Y		�ֶ����
	     			unsigned int *pnFieldType		Y		�ֶ�����
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_GetFieldType(TABLEDATAHANDLE hhandle,int nfieldno,unsigned int *pnfieldtype);

/*************************************************
	Function:       CTableData_GetFieldNo
	Description:    ȡ�ֶ����
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE hhandle		Y		CTableData���
					unsigned char *pszFieldName				�ֶ���
	    			unsigned int *pnFieldno					�ֶ����
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_GetFieldNo(TABLEDATAHANDLE hhandle,char *szfieldname,int *pnfieldno);

/*************************************************
	Function:       CTableData_AddFieldNo
	Description:    �����ֶ�
	Calls:          
	Called By:      
	Table Accessed: 
	Table Updated:  
	Input:			TABLEDATAHANDLE hhandle		Y		CTableData���
					unsigned char *pszFieldName				�ֶ���
	    			unsigned int *pnFieldno					�ֶ����
	Return:         0 - �ɹ� ���� - ʧ��
	Others:         // ����˵��
	ex:             
*************************************************/
C_KMDSAPI_Export int KMDSSTDCALL CTableData_AddFieldNo(TABLEDATAHANDLE hhandle,char *szfieldname,int *pnfieldno);

_END_KMDSAPI_DEF

#endif