#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 100	/*�����нṹ����������ֵ*/
/*ѧ����Ϣ*/
struct STUDENT
{
	int sCode;		//ѧ��
	char name[20];	//����
};

/*����*/
typedef struct NODE
{
	STUDENT data;
	NODE* next;
}NODE, * LINKLIST;

/*�����������*/
int ListGetLength(NODE* headNode);										//��ȡ�����ܳ���(����ͷ�ڵ�)
void ListInit(NODE*& headNode);											//����ĳ�ʼ��
void ListAppend(NODE*& headNode, NODE*& newNode);						//���ӽڵ�(��ĩβ׷��)
bool ListDeleteByPos(NODE*& headNode, int pos);							//ɾ���ڵ�(�����߼�λ��)
bool ListGetNodeByPos(NODE* headNode, int pos, NODE*& node);			//���ҽڵ�(�����߼�λ��)
bool ListLocateBySCode(NODE* headNode, int studentNumber, int& pos);	//��ȡ�߼�λ��(����ѧ��)
void ListOrderBySCode(NODE* headNode);									//��������(����ѧ�š�ð������)

/*�ļ���д����*/
void SaveData(NODE* headNode);
void LoadData(NODE* headNode);