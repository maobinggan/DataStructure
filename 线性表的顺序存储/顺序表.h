#pragma once
#include "Main.h"
//����ṹ��
struct STUDENT
{
	int sCode;		//ѧ��
	char name[20];		//����
};

/*
* ����˳������Ա��˳��洢�ṹ
* ������洢���Ա��еĸ�ElemԪ�أ��Ա�֤�߼������ڵ�Ԫ��������洢��Ҳ�����ڵ�
*/
#define SIZE_SQLIST 100	//���Ա����������󳤶�
struct SQLIST
{
	STUDENT* elements;	//ʵ���������飺STUDENT elements[SIZE_SQLIST]������Ϊ�ṹ������λ������ͷ�ļ�������ֻ��ʹ��ָ�롣
	int length;
};
//˳���Ļ�������
void ListInit(SQLIST& sqList);
bool ListInsert(SQLIST& sqList, STUDENT destNode, int pos);
bool ListDelete(SQLIST& sqList, int pos);
bool ListUpdate(SQLIST& sqList, STUDENT destNode, int pos);
bool ListGetElem(SQLIST& sqList, int pos, OUT STUDENT& elem);
int ListLocate(SQLIST& sqList, STUDENT destNode);
int ListFindPosBySCode(SQLIST& sqList, int destScode);//����ѡ��

//˳�����ļ���д����
extern const char* filePath;
void SaveSqList(SQLIST& sqList, const char* filePath);
void LoadSqList(SQLIST& sqList, const char* filePath);




