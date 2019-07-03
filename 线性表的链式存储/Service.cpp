#pragma once
#include "Service.h"
#include "����.h"

/**
* �� �� ��: ShowAllStuInfo
* ˵    ������ʾ����ѧ����Ϣ(��ѧ������)
* ��    ��: NODE * & headNode -
* �� �� ֵ: void
*/
void Service_ShowAllInfo_OrderByCode(NODE*& headNode)
{
	//�������򣺰�ѧ������
	ListOrderByCode(headNode);

	//��ӡ����
	NODE* tempNode = headNode->next;
	printf("[��ʾ����ѧ��]\n");
	while (tempNode != NULL)
	{
		printf("ѧ��=%08d\t����=%s\n", tempNode->data.code, tempNode->data.name);
		tempNode = tempNode->next;
	}
}

/**
* �� �� ��: Service_AddStu
* ˵    ��������ѧ��
* ��    ��: NODE * & headNode -
* �� �� ֵ: void
*/
void Service_AddInfo(NODE*& headNode)
{
	//��ʼ���½ṹ��
	STUDENT newData;

	//¼��ѧ����Ϣ
	printf("ѧ����ţ�");
	scanf("%d", &newData.code);
	printf("���֣�");
	scanf("%s", newData.name);

	//Ψһ���ж�
	int pos = 0;
	if (ListLocateByCode(headNode, newData.code, pos) == true) { printf("[¼��ʧ�ܣ��˱���Ѵ���]\n"); return; }

	//��������ĩβ
	ListAppend(headNode, newData);
	printf("[¼��ɹ�]\n");
}


/**
* �� �� ��: Service_AlterStuBySCode
* ˵    �����޸�ѧ����Ϣ������ѧ��
* ��    ��: NODE * headNode -
* �� �� ֵ: void
*/
void Service_AlterInfoByCode(NODE* headNode)
{
	int destSCode = 0;
	printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%d", &destSCode);

	//���Ҵ�ѧ�����ڽڵ���߼�λ��
	int pos = 0;
	if (ListLocateByCode(headNode, destSCode, pos))
	{
		//���ݽڵ���߼�λ�û�ȡ�ڵ㡢ֱ���޸Ĵ˽ڵ㼴��
		NODE* destNode;
		ListGetNodeByPos(headNode, pos, destNode);

		//¼���µ�ѧ����Ϣ
		printf("�µ�������");
		scanf("%s", destNode->data.name);

		printf("[�޸�ѧ����Ϣ�ɹ�]\n");
		return;
	}

	printf("[�޸�ѧ����Ϣʧ�ܣ��Ҳ�����ѧ��]\n");
	return;
}

/**
* �� �� ��: Service_SearchBySCode
* ˵    ������ѯѧ����Ϣ(����ѧ��)
* ��    ��: NODE * headNode -
* �� �� ֵ: void
*/
void Service_SearchInfoByCode(NODE* headNode)
{
	int destSCode = 0;
	printf("������Ҫ��ѯ��ѧ����ѧ�ţ�");
	scanf("%d", &destSCode);

	//����ָ��ѧ�ŵĽڵ��߼�λ��
	int pos = 0;
	if (ListLocateByCode(headNode, destSCode, pos))
	{
		//���ݽڵ��߼�λ�ã���ȡ�ڵ�
		NODE* tempNode;
		ListGetNodeByPos(headNode, pos, tempNode);

		//��ӡ�ڵ��������
		printf("ѧ��=%d\t����=%s\t\n", tempNode->data.code, tempNode->data.name);
		return;
	}
	printf("[��ѯʧ�ܣ��Ҳ�����ѧ��]\n");
	return;
}

/**
* �� �� ��: Service_DropStuBySCode
* ˵    �����Ƴ�ѧ����Ϣ��ͨ��ѧ�ţ�
* ��    ��: NODE * headNode -
* �� �� ֵ: void
*/
void Service_DropInfoByCode(NODE* headNode)
{
	int destSCode = 0;
	printf("������Ҫɾ����ѧ����ѧ�ţ�");
	scanf("%d", &destSCode);

	//������������ָ��ѧ�ŵĽڵ��߼�λ��
	int pos = 0;
	if (ListLocateByCode(headNode, destSCode, pos))
	{
		//ɾ���ýڵ�
		ListDeleteByPos(headNode, pos);
		printf("[ɾ���ɹ�]\n");
		return;
	}
	printf("[ɾ��ʧ�ܣ��Ҳ�����ѧ��]\n");
	return;
}