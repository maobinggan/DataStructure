#pragma once
#include "链表.h"

/**
* 函 数 名: ListInit
* 说    明：链表初始化
* 参    数: LINKLIST & headNode -
* 返 回 值: void
*/
void ListInit(NODE*& headNode)
{
	headNode = (NODE*)malloc(sizeof(NODE));			//为头节点分配内存
	memset(&headNode->data, 0x0, sizeof(STUDENT));	//将头节点的数据域清零
	headNode->next = NULL;							//将头节点的指针域置空
	return;
}

/**
* 函 数 名: ListGetNodeByPos
* 说    明：根据逻辑位置序号获取节点
* 参    数: LINKLIST & headNode -
* 参    数: int pos - 逻辑位置（从1开始）
* 参    数: NODE & node - 获取的节点（OUT）
* 返 回 值: bool
*/
bool ListGetNodeByPos(NODE* headNode, int pos, NODE*& node)
{
	//判断逻辑位置是否越界
	if (pos < 1) { return false; }
	if (pos > ListGetLength(headNode)) { return false; }

	//获取该位置的节点
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
* 函 数 名: ListAppend
* 说    明：增加节点（从链表末尾追加）
* 参    数: NODE * & headNode -
* 参    数: NODE * & newNode -
* 返 回 值: void
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
* 函 数 名: ListGetLength
* 说    明：获取链表长度
* 参    数: NODE * headNode -
* 返 回 值: int
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
* 函 数 名: ListDeleteByPos
* 说    明：根据逻辑位置序号删除节点
* 参    数: NODE * & headNode -
* 参    数: int pos - 逻辑位置（从1开始）
* 返 回 值: bool
*/
bool ListDeleteByPos(NODE*& headNode, int pos)
{
	//判断逻辑位置是否越界
	if (pos > ListGetLength(headNode)) { return false; }

	//查找指定逻辑位置的前驱节点
	NODE* preNode;
	ListGetNodeByPos(headNode, pos - 1, preNode);

	//删除节点：即修改目标节点的前驱节点的指针域
	preNode->next = preNode->next->next;
	return true;
}

/**
* 函 数 名: SaveData
* 说    明：将链表保存至文件
* 参    数: NODE * headNode -
* 返 回 值: void
*/
void SaveData(NODE* headNode)
{
	//打开文件
	FILE* pFile = fopen("stu.txt", "w"); //打开用于写入的空文件。 如果给定文件存在，则其内容会被销毁。
	if (pFile == NULL) { printf("【error】pFile is null...\n"); return; }

	//写入学生信息至文件
	NODE* tempNode = headNode->next;
	while (tempNode != NULL)
	{
		fwrite(&tempNode->data, sizeof(STUDENT), 1, pFile);
		tempNode = tempNode->next;
	}

	//关闭文件
	fclose(pFile);
	printf("[写入文件成功]\n");
	return;
}

/**
* 函 数 名: LoadData
* 说    明：从文件加载信息至链表
* 参    数: NODE * headNode -
* 返 回 值: void
*/
void LoadData(NODE* headNode)
{
	//打开文件
	FILE* pFile = fopen("stu.txt", "r"); //打开以便读取。 如果文件不存在或无法找到fopen调用失败。
	if (pFile == NULL) { return; }		//如果文件不存在，说明本系统没有任何学生记录

	//读取
	NODE* newNode;
	ListInit(newNode);
	while (fread(&newNode->data, sizeof(STUDENT), 1., pFile) != 0)
	{
		ListAppend(headNode, newNode);
		ListInit(newNode);
	}

	//关闭文件
	fclose(pFile);
	printf("[读取文件成功]\n");
	return;
}

/**
* 函 数 名: ListLocateBySCode
* 说    明：查找节点的逻辑位置（通过学号）
* 参    数: NODE * headNode -
* 参    数: int studentNumber -
* 参    数: int & pos - 返回逻辑位置（OUT）
* 返 回 值: bool
*/
bool ListLocateBySCode(NODE* headNode, int sCode, int& pos)
{
	NODE* tempNode = headNode;
	pos = 1;//逻辑位置从1开始，表示第一个节点（即头节点）
	while (tempNode->next != NULL)
	{
		if (tempNode->next->data.sCode == sCode)
		{
			return true;
		}
		tempNode = tempNode->next;
		pos++;
	}
	pos = 0;//查不到该学号，置零
	return false;
}

/**
* 函 数 名: ListOrderBySCode
* 说    明：链表排序：按学号升序（冒泡排序）
* 参    数: NODE * headNode -
* 返 回 值: void
*/
void ListOrderBySCode(NODE* headNode)
{
	//获取链表总长度
	int length = ListGetLength(headNode);

	//长度减一，去掉头节点，得到链表有效节点的个数
	length--;

	//冒泡排序
	int i = 0; int j = 0;
	for (i = 0; i < length - 1; i++)
	{
		NODE* tempNode_i = headNode->next;
		NODE* tempNode_j = tempNode_i;
		for (j = 0; j < length - 1 - i; j++)
		{
			if (tempNode_j->data.sCode > tempNode_j->next->data.sCode)
			{
				//交换：仅交换节点数据域即可，指针域不变
				STUDENT tempData = tempNode_j->data;
				tempNode_j->data = tempNode_j->next->data;
				tempNode_j->next->data = tempData;
			}
			tempNode_j = tempNode_j->next;
		}
	}
}
