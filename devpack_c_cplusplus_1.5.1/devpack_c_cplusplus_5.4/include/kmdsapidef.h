#ifndef _KMDS_API_DEF_HH_
#define _KMDS_API_DEF_HH_
/************************************************************************/
/*  windows ����dll����������,�����ʱ��Ҫ�� KMDSAPI_EXPORT_DEF KMDSAPI_BUILD_DLL�����������ȷ���ɡ�
            ʹ��dllʱ�����ִ�г������ʱ��Ҫ����KMDSAPI_EXPORT_DEF�궨�塣
	Ĭ�������ʹ�þ�̬��Lib���������ӵġ�
            */
/************************************************************************/

#if defined (_WIN32)|| defined(_WIN64)
#  if defined(KMDSAPI_EXPORT_DEF)
#    if defined (KMDSAPI_BUILD_DLL)
#      define KMDSAPI_Export __declspec(dllexport)
#    else /* KMDSAPI_BUILD_DLL */
#      define KMDSAPI_Export __declspec(dllimport)
#    endif /* KMDSAPI_BUILD_DLL */
#  else
#    define KMDSAPI_Export
#  endif

#  else /* !_WIN32 || !_WIN64 */
#    define KMDSAPI_Export
#  endif /* !_WIN32 || !_WIN64 */

#include "msgdata.h"
#include "kdhqplayback_define.h"


// kmds�û�API-����汾��
#define KMDS_USER_API_VERSION           "1.5.1"

// kmds�û�API-��������
enum ENUM_KMDS_DATA_TYPE
{
	KMDS_HQ_SYNC_REQ_DATA_MIN = 1000,
	KMDS_HQ_CODETABLE         = 1001,	// ֤ȯ�����	����
	KMDS_HQ_LAST_PART_SNPST    = 1002, // ����һ���������
	KMDS_HQ_MIN_K_LINE         = 1003,	// ����������	    ����
	KMDS_HQ_SYNC_REQ_DATA_MAX = 1100,

    KMDS_HQ_CODETABLE_SNPST   = 2061,   // ʵʱ�����䶯����  ����


	KMDS_HQ_SPQA_SNAPSHOT = 6005,                   // �ƽ������ֻ�����ر�  ����
	KMDS_HQ_FWQA_SNAPSHOT = 6006,                   // �ƽ�����Զ������ر�  ����
	KMDS_HQ_DFQA_SNAPSHOT = KMDS_HQ_FWQA_SNAPSHOT,  // �ƽ�������������ر�  ����
	KMDS_HQ_SPIS_SNAPSHOT = 6007,                   // �ƽ������ֻ���Լ״̬�ı��¼�  ����
	KMDS_HQ_FWIS_SNAPSHOT = KMDS_HQ_SPIS_SNAPSHOT,  // �ƽ�����Զ�ں�Լ״̬�ı��¼�  ����
	KMDS_HQ_DFIS_SNAPSHOT = KMDS_HQ_SPIS_SNAPSHOT,  // �ƽ��������ں�Լ״̬�ı��¼�  ����

	KMDS_HQ_STK_PART_SNPST    = 6010,	// ��Ʊ��������	����
	KMDS_HQ_FT_PART_SNPST     = 6011,	// �ڻ���������	����
	KMDS_HQ_INDEX_PART_SNPST  = 6012,	// ָ����������	����
	KMDS_HQ_STKOP_PART_SNPST  = 6014,   // ������Ȩ��������  ����
	KMDS_HQ_RDM_PART_SNPST    = 6015,   // ·͸�������� ����
	KMDS_HQ_CMDS_PART_SNPST   = 6016,   // ��̩���м�����  ����
	KMDS_HQ_ORDR_QU           = 6020,	// ��������	    ����
	KMDS_HQ_PER_STRK_ENTRT    = 6030,	// ���ί��	    ����
	KMDS_HQ_PER_STRK_BGN      = 6040,	// ��ʳɽ�	    ����

	// add by hanpc
	KMDS_HQ_HISTORY_CODETABLE    = 7010,	// ��ʷ�����
	KMDS_HQ_HISTORY_PART_SNPST   = 7020,   // ��ʷ�ֱʿ���
	KMDS_HQ_HISTORY_ORDR_QU      = 7030,	// ��ʷ��������
	KMDS_HQ_HISTORY_PER_STRK_ENTRT = 7040,  // ��ʷ���ί��
	KMDS_HQ_HISTORY_PER_STRK_BGN	= 7050,   // ��ʷ��ʳɽ�
	KMDS_HQ_HISTORY_DAY_K_LINE     = 7060,     // ��ʷ��K��
	KMDS_HQ_HISTORY_MIN_K_LINE     = 7070,		// ��ʷ������

	// add by hanpc
	KMDS_HQ_INFO = 8010,   // ��ѯ��ѯ�ӿ�

    // add by lind
    KMDS_HQ_CHECK_PART_SNPST = 9010,  // ������ղ�ѯ(��ʷ��ʵʱ����)

    KMDS_HQ_HGT_REFF = 9021,
    KMDS_HQ_HGT_EXRA = 9022,
};

// ��������
enum ENUM_KMDS_SUB_TYPE
{
	KMDS_SUB_REMOVE_ALL = 0,            //ȫ���ⶩ
	KMDS_SUB_ADD,                       //����
	KMDS_SUB_REMOVE,                    //ɾ��
	KMDS_SUB_ADD_ALL                    //ȫ������
};

//---------------------------------------------------------------------
//�¼��ص��ӿ���

// ��Ϣ�ص��ӿ�
class CKmdsMsgCB
{
public:
	CKmdsMsgCB(){}
	virtual ~CKmdsMsgCB(){}
public:
	// ������Ϣ�ص�����
	virtual void OnKmdsMsg(void* pmsgdesc, void* pmsgopts,int ncmd ,CMsgData* pmsg){}

	// FT��Ⱥ��Ӧ�¼��ص�����(��������API�ӿڵ���)
	// enum MOM_FTAction enaction  momdef.h��
	virtual void OnRvFtAction(const char *pgroupname, int enaction){}
};

// ��¼����ص��ӿ�
class CKmdsLoginCB
{
public:
	CKmdsLoginCB(){}
	virtual ~CKmdsLoginCB(){}
public:
	virtual int OnKmdsLoginCB(int nid,char* pszmsg) = 0;
};

//������Ϣ�ص��ӿ�(��������API�ӿڵ���)
class CKmdsMsgReqCB
{
public:
	CKmdsMsgReqCB(){}
	virtual ~CKmdsMsgReqCB(){}
public:
	virtual void OnKmdsReqMsg(void* pmsgdesc, void* pmsgopts,int ncmd ,CMsgData* pmsg) = 0;
};
//------------------------------------------------------------------------


#endif
