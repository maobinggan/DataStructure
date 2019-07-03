#pragma once
#include "Service.h"
#include "链表.h"

/**
* 函 数 名: ShowAllStuInfo
* 说    明：显示所有学生信息(按学号升序)
* 参    数: NODE * & headNode -
* 返 回 值: void
*/
void Service_ShowAllInfo_OrderByCode(NODE*& headNode)
{
	//链表排序：按学号升序
	ListOrderByCode(headNode);

	//打印链表
	NODE* tempNode = headNode->next;
	printf("[显示所有学生]\n");
	while (tempNode != NULL)
	{
		printf("学号=%08d\t姓名=%s\n", tempNode->data.code, tempNode->data.name);
		tempNode = tempNode->next;
	}
}

/**
* 函 数 名: Service_AddStu
* 说    明：新增学生
* 参    数: NODE * & headNode -
* 返 回 值: void
*/
void Service_AddInfo(NODE*& headNode)
{
	//初始化新结构体
	STUDENT newData;

	//录入学生信息
	printf("学生编号：");
	scanf("%d", &newData.code);
	printf("名字：");
	scanf("%s", newData.name);

	//唯一性判断
	int pos = 0;
	if (ListLocateByCode(headNode, newData.code, pos) == true) { printf("[录入失败，此编号已存在]\n"); return; }

	//插入链表末尾
	ListAppend(headNode, newData);
	printf("[录入成功]\n");
}


/**
* 函 数 名: Service_AlterStuBySCode
* 说    明：修改学生信息：根据学号
* 参    数: NODE * headNode -
* 返 回 值: void
*/
void Service_AlterInfoByCode(NODE* headNode)
{
	int destSCode = 0;
	printf("请输入要修改的学生的学号：");
	scanf("%d", &destSCode);

	//查找此学号所在节点的逻辑位置
	int pos = 0;
	if (ListLocateByCode(headNode, destSCode, pos))
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
void Service_SearchInfoByCode(NODE* headNode)
{
	int destSCode = 0;
	printf("请输入要查询的学生的学号：");
	scanf("%d", &destSCode);

	//查找指定学号的节点逻辑位置
	int pos = 0;
	if (ListLocateByCode(headNode, destSCode, pos))
	{
		//根据节点逻辑位置，获取节点
		NODE* tempNode;
		ListGetNodeByPos(headNode, pos, tempNode);

		//打印节点的数据域
		printf("学号=%d\t姓名=%s\t\n", tempNode->data.code, tempNode->data.name);
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
void Service_DropInfoByCode(NODE* headNode)
{
	int destSCode = 0;
	printf("请输入要删除的学生的学号：");
	scanf("%d", &destSCode);

	//遍历链表，查找指定学号的节点逻辑位置
	int pos = 0;
	if (ListLocateByCode(headNode, destSCode, pos))
	{
		//删除该节点
		ListDeleteByPos(headNode, pos);
		printf("[删除成功]\n");
		return;
	}
	printf("[删除失败，找不到此学号]\n");
	return;
}