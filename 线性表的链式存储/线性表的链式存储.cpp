//
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "service.h"

int main()
{
	//链表初始化
	NODE* headNode;
	ListInit(headNode);

	//从文件中读取记录
	LoadData(headNode);

	while (true)
	{
		//打印主菜单
		menu();

		int option = 0;
		scanf("%d", &option);
		switch (option)
		{
			case 1:Service_AddStuInfo(headNode);							break;
			case 2:Service_DropStuInfoByStuNumber(headNode);				break;
			case 3:Service_AlterStuInfoByStuNumber(headNode);				break;
			case 4:Service_SearchByStuNumber(headNode);						break;
			case 5:Service_SearchByStuName(headNode);						break;
			case 6:Service_ShowAllStuInfo_OrderByStuNum(headNode);			break;
			default:break;
		}

		system("pause");
		getchar();
	}
}
