#pragma once
#include "Service.h"
#include "链表.h"

/**
* 函 数 名: ShowAllStuInfo
* 说    明：显示所有学生信息(按学号升序)
* 参    数: NODE * & headNode -
* 返 回 值: void
*/
void Service_ShowAllStu_OrderBySCode(NODE*& headNode)
{
	//链表排序：按学号升序
	ListOrderBySCode(headNode);

	//打印链表
	NODE* tempNode = headNode->next;
	printf("[显示所有学生]\n");
	while (tempNode != NULL)
	{
		printf("学号=%08d\t姓名=%s\n", tempNode->data.sCode, tempNode->data.name);
		tempNode = tempNode->next;
	}
}

/**
* 函 数 名: Service_AddStu
* 说    明：新增学生
* 参    数: NODE * & headNode -
* 返 回 值: void
*/
void Service_AddStu(NODE*& headNode)
{
	//初始化一个新节点
	NODE* newNode;
	ListInit(newNode);

	//录入学生信息
	printf("学号：");
	scanf("%d", &newNode->data.sCode);
	printf("名字：");
	scanf("%s", newNode->data.name);

	//插入链表末尾
	ListAppend(headNode, newNode);
}


/**
* 函 数 名: Service_AlterStuBySCode
* 说    明：修改学生信息：根据学号
* 参    数: NODE * headNode -
* 返 回 值: void
*/
void Service_AlterStuBySCode(NODE* headNode)
{
	int destSCode = 0;
	printf("请输入要修改的学生的学号：");
	scanf("%d", &destSCode);

	//查找此学号所在节点的逻辑位置
	int pos = 0;
	if (ListLocateBySCode(headNode, destSCode, pos))
	{
		//根据节点的逻辑位置获取节点、直接修改此节点即可
		NODE* destNode;
		ListGetNodeByPos(headNode, pos, destNode);

		//录入新的学生信息
		printf("新的姓名：");
		scanf("%s", destNode->data.name);

		printf("[修改学生信息成功]\n");
		return;
	}

	printf("[修改学生信息失败，找不到此学号]\n");
	return;
}

/**
* 函 数 名: Service_SearchBySCode
* 说    明：查询学生信息(根据学号)
* 参    数: NODE * headNode -
* 返 回 值: void
*/
void Service_SearchBySCode(NODE* headNode)
{
	int destSCode = 0;
	printf("请输入要查询的学生的学号：");
	scanf("%d", &destSCode);

	//查找指定学号的节点逻辑位置
	int pos = 0;
	if (ListLocateBySCode(headNode, destSCode, pos))
	{
		//根据节点逻辑位置，获取节点
		NODE* tempNode;
		ListGetNodeByPos(headNode, pos, tempNode);

		//打印节点的数据域
		printf("学号=%d\t姓名=%s\t\n",tempNode->data.sCode,tempNode->data.name);
		return;
	}
	printf("[查询失败，找不到此学号]\n");
	return;
}

/**
* 函 数 名: Service_DropStuBySCode
* 说    明：移除学生信息（通过学号）
* 参    数: NODE * headNode -
* 返 回 值: void
*/
void Service_DropStuBySCode(NODE* headNode)
{
	int destSCode = 0;
	printf("请输入要删除的学生的学号：");
	scanf("%d", &destSCode);

	//遍历链表，查找指定学号的节点逻辑位置
	int pos = 0;
	if (ListLocateBySCode(headNode, destSCode, pos))
	{
		//删除该节点
		ListDeleteByPos(headNode, pos);
		printf("[删除成功]\n");
		return;
	}
	printf("[删除失败，找不到此学号]\n");
	return;
}