#pragma once
#include "����.h"

/*ҵ���߼�*/
void Service_AddInfo(NODE*& headNode);					//����ѧ����Ϣ
void Service_DropInfoByCode(NODE* headNode);			//ɾ��ѧ����Ϣ
void Service_AlterInfoByCode(NODE* headNode);			//�޸�ѧ����Ϣ������ѧ�ţ�
void Service_SearchInfoByCode(NODE* headNode);				//��ʾѧ����Ϣ������ѧ�ţ�
void Service_ShowAllInfo_OrderByCode(NODE*& headNode);  //��ʾ����ѧ����Ϣ����ѧ������


