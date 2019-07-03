// 线性表的链式存储.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"Service.h"
#include"链表.h"

int main()
{
	//链表初始化
	NODE* headNode;
	ListInit(headNode);

	//从文件中读取记录
	LoadData(headNode);

	while (true)
	{
		//主菜单
		system("cls");
		printf("\t\t************************\n");
		printf("\t\t**学生成绩管理系统\n");
		printf("\t\t*1.增加学生信息\n");
		printf("\t\t*2.删除学生信息\n");
		printf("\t\t*3.修改学生信息\n");
		printf("\t\t*4.查找学生信息 (根据编号)\n");
		printf("\t\t*5.排序学生信息 (按编号升序)\n");
		printf("\t\t*6.写入文件\n");
		printf("\t\t************************\n");

		int option = 0;
		scanf("%d", &option);
		switch (option)
		{
			case 1:Service_AddInfo(headNode);					break;
			case 2:Service_DropInfoByCode(headNode);			break;
			case 3:Service_AlterInfoByCode(headNode);			break;
			case 4:Service_SearchInfoByCode(headNode);			break;
			case 5:Service_ShowAllInfo_OrderByCode(headNode);	break;
			case 6:SaveData(headNode);							break;
			default:break;
		}

		system("pause");
		getchar();
	}
}
