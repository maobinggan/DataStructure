#pragma once
#include "Main.h"

int main()
{
	//顺序表初始化
	SQLIST sqList;
	ListInit(sqList);

	//从文件中读取顺序表
	LoadSqList(sqList, filePath);

	//主菜单
	int option = 0;
	while (true)
	{
		Sleep(1);
		system("cls");
		printf("\t\t************************\n");
		printf("\t\t**学生信息管理系统\n");
		printf("\t\t*0.浏览所有学生信息\n");
		printf("\t\t*1.录入学生信息\n");
		printf("\t\t*2.删除学生信息\n");
		printf("\t\t*3.根据学号修改学生信息\n");
		printf("\t\t*4.根据学号查询学生信息\n");
		printf("\t\t************************\n");

		scanf("%d", &option);		
		getchar();
		switch (option)
		{
			case 0:Service_PrintAllStuInfo(sqList);  break;
			case 1:Service_InputStuInfo(sqList);	 break;
			case 2:Service_DropBySCode(sqList);		 break;
			case 3:Service_AlterBySCode(sqList);	 break;
			case 4:Service_SearchStuBySCode(sqList); break;
			default:break;
		}
	}
	system("pause");
	return 0;
}
