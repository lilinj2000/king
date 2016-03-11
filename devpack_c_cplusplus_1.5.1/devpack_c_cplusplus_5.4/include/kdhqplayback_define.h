/******************************************************************************
*
*									KMDS V1.0 
*
*           Copyright (C) 2012-2013, SHENZHEN KINGDOM Co., Ltd.
* 
*                             All Rights Reserved.
*
* ===========================================================================
*
* �� �� ����kdhqplayback_define.h 
* ģ�����ƣ�ģ��ط�ģ��
* ����˵�������������궨��
* ��    �ߣ�liulj
* �������ڣ�2014-08-11
* �� �� �ţ�1.0
* �޸���ʷ��
*
* �޸�����       ����            ����
* ---------------------------------------------------------------------------
* 2014-08-11     liulj         ��ʼ�汾
*
******************************************************************************/
#ifndef _KDHQPLAYBACK_DEFINE_H_
#define _KDHQPLAYBACK_DEFINE_H_

#pragma pack(push,1)

enum ENUM_PLAYBACK_SPEED
{
	ENUM_SPEED_FULL = 0,			// ȫ��
	ENUM_SPEED_NORMAL = 1,			// �����ٶ�
	ENUM_SPEED_DOUBLE = 2,			// �����ٶ�
	ENUM_SPEED_FOUR = 4				// �ı�
};
enum ENUM_PLAYBACK_HQTYPE
{
	ENUM_HQTYPE_SNAPSHOT_1 = 0x01,		// �������Level1
	ENUM_HQTYPE_SNAPSHOT_2 = 0x02,		// �������Level2
	ENUM_HQTYPE_PER_STRK_BGN = 0x04,	// ��ʳɽ�
	ENUM_HQTYPE_PER_STRK_ENTRT = 0x08,	// ���ί��
	ENUM_HQTYPE_ORDR_QU = 0x10,			// ��������
	ENUM_HQTYPE_ALL = 0xFFFF,
};

// ״̬
enum ENUM_STATUS
{
	ENUM_STATUS_NORMAL = 0,		 // ����
	ENUM_STATUS_ABNORMAL,        // �쳣	
};
// ģ��ط���������ṹ
struct ST_HQPLAYBACK
{
	char szUSER_NM[64];				// �û���
	char szStkcode[1024];			// �г�֤ȯ���� ��1:600446;2:000001,֤ȯ����-1��ʾȫ�г�
	char szIP[32];					// IP��ַ
	int nHQTYPE;					// �������� ֧�� |
	int nSPEED;						// �ط��ٶ�
	int nSRT_DT;
	int nEND_DT;
	int nSRT_TM;					// ��ȷ����
	int nEND_TM;
	char szRESERVE[2048];			// ��������
};
#pragma pack(pop)

#endif