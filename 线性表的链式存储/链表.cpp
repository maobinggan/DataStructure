#pragma once
#include "����.h"

/**
* �� �� ��: ListInit
* ˵    ���������ʼ��
* ��    ��: LINKLIST & headNode -
* �� �� ֵ: void
*/
void ListInit(NODE*& headNode)
{
	headNode = (NODE*)malloc(sizeof(NODE));			//Ϊͷ�ڵ�����ڴ�
	memset(&headNode->data, 0x0, sizeof(STUDENT));	//��ͷ�ڵ������������
	headNode->next = NULL;							//��ͷ�ڵ��ָ�����ÿ�
	return;
}

/**
* �� �� ��: ListGetNodeByPos
* ˵    ���������߼�λ����Ż�ȡ�ڵ�
* ��    ��: LINKLIST & headNode -
* ��    ��: int pos - �߼�λ�ã���1��ʼ��
* ��    ��: NODE & node - ��ȡ�Ľڵ㣨OUT��
* �� �� ֵ: bool
*/
bool ListGetNodeByPos(NODE* headNode, int pos, NODE*& node)
{
	//�ж��߼�λ���Ƿ�Խ��
	if (pos < 1) { return false; }
	if (pos > ListGetLength(headNode)) { return false; }

	//��ȡ��λ�õĽڵ�
	NODE* tempNode = headNode;
	int count = 1;
	while (count < pos && tempNode->next != NULL)
	{
		tempNode = tempNode->next;
		count++;
	}
	node = tempNode->next;
	return true;
}


/**
* �� �� ��: ListAppend
* ˵    �������ӽڵ㣨������ĩβ׷�ӣ�
* ��    ��: NODE * & headNode -
* ��    ��: NODE * & newNode -
* �� �� ֵ: void
*/
void ListAppend(NODE*& headNode, NODE*& newNode)
{
	NODE* tempNode = headNode;
	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}
	tempNode->next = newNode;
	newNode->next = NULL;
}

/**
* �� �� ��: ListGetLength
* ˵    ������ȡ������
* ��    ��: NODE * headNode -
* �� �� ֵ: int
*/
int ListGetLength(NODE* headNode)
{
	int length = 1;
	NODE* tempNode = headNode;
	while (tempNode->next != NULL)
	{
		length++;
		tempNode = tempNode->next;
	}
	return length;
}

/**
* �� �� ��: ListDeleteByPos
* ˵    ���������߼�λ�����ɾ���ڵ�
* ��    ��: NODE * & headNode -
* ��    ��: int pos - �߼�λ�ã���1��ʼ��
* �� �� ֵ: bool
*/
bool ListDeleteByPos(NODE*& headNode, int pos)
{
	//�ж��߼�λ���Ƿ�Խ��
	if (pos > ListGetLength(headNode)) { return false; }

	//����ָ���߼�λ�õ�ǰ���ڵ�
	NODE* preNode;
	ListGetNodeByPos(headNode, pos - 1, preNode);

	//ɾ���ڵ㣺���޸�Ŀ��ڵ��ǰ���ڵ��ָ����
	preNode->next = preNode->next->next;
	return true;
}

/**
* �� �� ��: SaveData
* ˵    ���������������ļ�
* ��    ��: NODE * headNode -
* �� �� ֵ: void
*/
void SaveData(NODE* headNode)
{
	//���ļ�
	FILE* pFile = fopen("stu.txt", "w"); //������д��Ŀ��ļ��� ��������ļ����ڣ��������ݻᱻ���١�
	if (pFile == NULL) { printf("��error��pFile is null...\n"); return; }

	//д��ѧ����Ϣ���ļ�
	NODE* tempNode = headNode->next;
	while (tempNode != NULL)
	{
		fwrite(&tempNode->data, sizeof(STUDENT), 1, pFile);
		tempNode = tempNode->next;
	}

	//�ر��ļ�
	fclose(pFile);
	printf("[д���ļ��ɹ�]\n");
	return;
}

/**
* �� �� ��: LoadData
* ˵    �������ļ�������Ϣ������
* ��    ��: NODE * headNode -
* �� �� ֵ: void
*/
void LoadData(NODE* headNode)
{
	//���ļ�
	FILE* pFile = fopen("stu.txt", "r"); //���Ա��ȡ�� ����ļ������ڻ��޷��ҵ�fopen����ʧ�ܡ�
	if (pFile == NULL) { return; }		//����ļ������ڣ�˵����ϵͳû���κ�ѧ����¼

	//��ȡ
	NODE* newNode;
	ListInit(newNode);
	while (fread(&newNode->data, sizeof(STUDENT), 1., pFile) != 0)
	{
		ListAppend(headNode, newNode);
		ListInit(newNode);
	}

	//�ر��ļ�
	fclose(pFile);
	printf("[��ȡ�ļ��ɹ�]\n");
	return;
}

/**
* �� �� ��: ListLocateBySCode
* ˵    �������ҽڵ���߼�λ�ã�ͨ��ѧ�ţ�
* ��    ��: NODE * headNode -
* ��    ��: int studentNumber -
* ��    ��: int & pos - �����߼�λ�ã�OUT��
* �� �� ֵ: bool
*/
bool ListLocateBySCode(NODE* headNode, int sCode, int& pos)
{
	NODE* tempNode = headNode;
	pos = 1;//�߼�λ�ô�1��ʼ����ʾ��һ���ڵ㣨��ͷ�ڵ㣩
	while (tempNode->next != NULL)
	{
		if (tempNode->next->data.sCode == sCode)
		{
			return true;
		}
		tempNode = tempNode->next;
		pos++;
	}
	pos = 0;//�鲻����ѧ�ţ�����
	return false;
}

/**
* �� �� ��: ListOrderBySCode
* ˵    �����������򣺰�ѧ������ð������
* ��    ��: NODE * headNode -
* �� �� ֵ: void
*/
void ListOrderBySCode(NODE* headNode)
{
	//��ȡ�����ܳ���
	int length = ListGetLength(headNode);

	//���ȼ�һ��ȥ��ͷ�ڵ㣬�õ�������Ч�ڵ�ĸ���
	length--;

	//ð������
	int i = 0; int j = 0;
	for (i = 0; i < length - 1; i++)
	{
		NODE* tempNode_i = headNode->next;
		NODE* tempNode_j = tempNode_i;
		for (j = 0; j < length - 1 - i; j++)
		{
			if (tempNode_j->data.sCode > tempNode_j->next->data.sCode)
			{
				//�������������ڵ������򼴿ɣ�ָ���򲻱�
				STUDENT tempData = tempNode_j->data;
				tempNode_j->data = tempNode_j->next->data;
				tempNode_j->next->data = tempData;
			}
			tempNode_j = tempNode_j->next;
		}
	}
}
