#pragma once
#include "Main.h"
//定义结构体
struct STUDENT
{
	int sCode;		//学号
	char name[20];		//姓名
};

/*
* 定义顺序表：线性表的顺序存储结构
* 用数组存储线性表中的各Elem元素，以保证逻辑上相邻的元素在物理存储上也是相邻的
*/
#define SIZE_SQLIST 100	//线性表中数组的最大长度
struct SQLIST
{
	STUDENT* elements;	//实际上是数组：STUDENT elements[SIZE_SQLIST]，但因为结构体声明位于其他头文件，所以只能使用指针。
	int length;
};
//顺序表的基本操作
void ListInit(SQLIST& sqList);
bool ListInsert(SQLIST& sqList, STUDENT destNode, int pos);
bool ListDelete(SQLIST& sqList, int pos);
bool ListUpdate(SQLIST& sqList, STUDENT destNode, int pos);
bool ListGetElem(SQLIST& sqList, int pos, OUT STUDENT& elem);
int ListLocate(SQLIST& sqList, STUDENT destNode);
int ListFindPosBySCode(SQLIST& sqList, int destScode);//【可选】

//顺序表的文件读写操作
extern const char* filePath;
void SaveSqList(SQLIST& sqList, const char* filePath);
void LoadSqList(SQLIST& sqList, const char* filePath);




