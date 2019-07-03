#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 100	/*链表中结构体数组的最大值*/

/*学生信息*/
struct STUDENT
{
	int id;				
	int code;		//编号
	char name[20];	//姓名
};

/*链表*/
typedef struct NODE
{
	STUDENT data;
	NODE* next;
}NODE, * LINKLIST;

/*链表基本操作*/
int ListGetLength(NODE* headNode);									//获取链表总长度(包含头节点)
void ListInit(NODE*& headNode);										//链表的初始化
void ListAppend(NODE* headNode, STUDENT newData);					//增加节点(在末尾追加)
bool ListDeleteByPos(NODE* headNode, int pos);						//删除节点(根据逻辑位置)
bool ListGetNodeByPos(NODE* headNode, int pos, NODE*& node);		//查找节点(根据逻辑位置)
bool ListLocateByCode(NODE* headNode, int studentNumber, int& pos);	//获取逻辑位置(根据编号)
void ListOrderByCode(NODE* headNode);								//链表排序(根据编号,冒泡排序)

/*文件读写操作*/
void SaveData(NODE* headNode);
void LoadData(NODE* headNode);