#pragma once
#include "˳���.h"
const char* filePath = "data.txt";
/**
* �� �� ��: SaveSqList
* ˵    ������˳����еļ�¼д�����ļ�
* ��    ��: SQLIST & sqList -
* ��    ��: const char * filePath - �ļ�·��
* �� �� ֵ: void
*/
void SaveSqList(SQLIST& sqList, const char* filePath)
{
	FILE* pFile = fopen(filePath, "wb");//������д��Ŀ��ļ��� ��������ļ����ڣ��������ݻᱻ���١�
	if (pFile == NULL) { printf("��error��pFile is null..."); return; }
	for (int i = 0; i < sqList.length; i++)
	{
		fwrite(&sqList.elements[i], sizeof(STUDENT), 1, pFile);
		fwrite("\n", 1, 1, pFile); //��д��һ�����з�������鿴
	}
	fclose(pFile);
}

/**
* �� �� ��: LoadData
* ˵    �������ļ��ж�ȡ��¼��˳���
* ��    ��: SQLIST & stuList -
* ��    ��: const char * filePath - �ļ�·��
* �� �� ֵ: void
*/
void LoadSqList(SQLIST& sqList, const char* filePath)
{
	FILE* pFile = fopen(filePath, "rb");//���Ա��ȡ�� ����ļ������ڻ��޷��ҵ�fopen����ʧ�ܡ�
	if (pFile == NULL) { return; }
	while (fread(&sqList.elements[sqList.length], sizeof(STUDENT), 1, pFile) != 0)
	{
		char tempBuffer;
		fread(&tempBuffer, 1, 1, pFile); //���һ�����з�
		sqList.length++;
	}
	fclose(pFile);
}

/**
* �� �� ��: ListInit
* ˵    ����˳���ĳ�ʼ��
* ��    ��: SQLIST & stuList -
* �� �� ֵ: void
*/
void ListInit(SQLIST& sqList)
{
	//Ϊ˳����еĽṹ�����������ڴ�ռ�
	//sqList.elements = (STUDENT*)malloc(SIZE_SQLIST * sizeof(STUDENT));

	//�ѽṹ���������㣬����Խṹ����бȽ�(memcmp)
	memset(sqList.elements, 0x0, sizeof(SIZE_SQLIST * sizeof(STUDENT)));

	//��˳���ĳ�������Ϊ0
	sqList.length = 0;
}

/**
* �� �� ��: ListInsert
* ˵    ������˳�������½ڵ㣬ʹ����Ϊn�����Ա��ɳ���Ϊn+1�����Ա�,ʱ�临�Ӷ�O(n)
* ��    ��: SQLIST & stuList -
* ��    ��: STUDENT destNode - Ҫ�����Ŀ��ڵ�
* ��    ��: int pos - Ҫ������߼�λ�ã��ڳ���Ϊn��˳����У��߼�λ�ô�1��n��
*					- ���ϣ����˳���ĩβ��ӽڵ㣬�����posӦ��Ϊn+1
* �� �� ֵ: void
*/
bool ListInsert(SQLIST& sqList, STUDENT destNode, int pos)
{
	//�ж�Ŀ���߼�λ��pos�ĺϷ��ԣ�pos�ĺϷ���Χ�� 1<= pos <= n+1 �� 
	if (pos < 1 || pos > sqList.length + 1) { printf("��error���߼�λ�ô����޷������½ڵ�\n"); return false; }
	//�ж����Ա��Ƿ�����
	if (sqList.length == SIZE_SQLIST) { printf("��error��˳����������޷������½ڵ�\n"); return false; }

	//�ӵ�n��Ԫ�ؼ����һ��Ԫ�ؿ�ʼ����������ƶ�һ��λ�ã�ֱ����pos��Ԫ�ء��������ƶ� n-pos+1 �Σ�
	for (int i = sqList.length; i >= pos; i--)
	{
		sqList.elements[i] = sqList.elements[i - 1];
	}
	//��Ҫ������½ڵ�����pos��λ��
	sqList.elements[pos - 1] = destNode;
	//���Ա��ȼ�һ
	sqList.length++;
	return true;
}

/**
* �� �� ��: ListDelete
* ˵    ������˳�����ɾ���ڵ�,ʱ�临�Ӷ�O(n)
* ��    ��: SQLIST & sqList -
* ��    ��: int pos - Ҫɾ���Ľڵ���߼�λ�ã��ڳ���Ϊn��˳����У��߼�λ�ô�1��n��
* �� �� ֵ: bool
*/
bool ListDelete(SQLIST& sqList, int pos)
{
	//�ж�Ŀ���߼�λ��pos�ĺϷ��ԣ�pos�ķ�Χ�� 1 <= pos <= n��
	if (pos<1 || pos>sqList.length) { printf("��error���߼�λ�ô����޷�ɾ���ڵ�\n");  return false; }
	//�ж����Ա��Ƿ�Ϊ��
	if (sqList.length < 1) { printf("��error��˳���Ϊ�գ��޷�ɾ���ڵ�\n");  return false; }

	//Ҫɾ����pos��Ԫ�أ�����Ҫ����pos+1������n��Ԫ��������ǰ�ƶ�һ��λ��
	for (int i = pos; i <= sqList.length; i++)
	{
		sqList.elements[i - 1] = sqList.elements[i];
	}
	//���Ա��ȼ�һ
	sqList.length--;
	return true;
}


/**
* �� �� ��: ListUpdate
* ˵    ���������滻˳����ĳ���ڵ�,ʱ�临�Ӷ�O(n)
* ��    ��: SQLIST & sqList -
* ��    ��: STUDENT destNode -
* ��    ��: int pos -
* �� �� ֵ: bool
*/
bool ListUpdate(SQLIST& sqList, STUDENT destNode, int pos)
{
	//�ж�Ŀ���߼�λ��pos�ĺϷ��ԣ�pos�ķ�Χ�� 1 <= pos <= n��
	if (pos<1 || pos>sqList.length) { printf("��error���߼�λ�ô����޷��޸Ľڵ�\n");  return false; }
	//elements[pos-1]�洢�ľ��ǵ�pos��Ԫ��
	sqList.elements[pos - 1] = destNode;
	return true;
}

/**
* �� �� ��: ListLocate
* ˵    ����������Ŀ��ڵ��������ͬ�Ľڵ���߼�λ�ã������ݲ��ң�,ʱ�临�Ӷ�O(n)
* ��    ��: SQLIST & sqList -
* ��    ��: STUDENT destNode -
* �� �� ֵ: int - ���ص����߼�λ�ã��������0����˵���Ҳ�����ͬ�Ľڵ�
*/
int ListLocate(SQLIST& sqList, STUDENT destNode)
{
	for (int i = 0; i < sqList.length; i++)
	{
		if (memcmp(&sqList.elements[i], &destNode, sizeof(destNode)) == 0)
		{
			return i + 1;//�߼�λ����Ҫ��1
		}
	}
	return 0;
}

/**
* �� �� ��: ListGetElem
* ˵    �������߼�λ�ò��ң�ʱ�临�Ӷ�O(1)
* ��    ��: SQLIST & sqList -
* ��    ��: int pos - �߼�λ��
* ��    ��: OUT STUDENT elem - ���ҵĽ��
* �� �� ֵ: bool
*/
bool ListGetElem(SQLIST& sqList, int pos, OUT STUDENT& elem)
{
	//�ж�Ŀ���߼�λ��pos�ĺϷ��ԣ�pos�ķ�Χ�� 1 <= pos <= n��
	if (pos<1 || pos>sqList.length) { printf("��error���߼�λ�ô����޷����ҽڵ�\n");  return false; }
	//elements[pos-1]�洢�ľ��ǵ�pos��Ԫ��
	elem = sqList.elements[pos - 1];
	return true;
}

/**
* �� �� ��: ListFindPosBySCode
* ˵    ��������ĳ���ֶΣ�ѧ�ţ���ѯ�߼�λ��
* ��    ��: SQLIST & sqList -
* ��    ��: int destScode -
* �� �� ֵ: int - �߼�λ��
*/
int ListFindPosBySCode(SQLIST& sqList, int destScode)
{
	int i = 0;
	for (i = 0; i < sqList.length; i++)
	{
		if (sqList.elements[i].sCode == destScode)
		{
			return i + 1;
		}
	}
	return 0;
}