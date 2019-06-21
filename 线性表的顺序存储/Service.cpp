#include "Service.h"

/**
* 函 数 名: Service_PrintAllStuInfo
* 说    明：打印所有学生信息
* 参    数: SQLIST & sqList -
* 返 回 值: void
*/
void Service_PrintAllStuInfo(SQLIST& sqList)
{
	printf("[打印所有学生信息]\n");
	int i = 0;
	for (i = 0; i < sqList.length; i++)
	{
		printf("学号=%08d\t", sqList.elements[i].sCode);
		printf("姓名=%5s\t", sqList.elements[i].name);
		printf("\n");
	}
	system("pause");
}
/**
* 函 数 名: Service_InputStuInfo
* 说    明：录入学生信息
* 参    数: SQLIST & sqList -
* 返 回 值: void
*/
void Service_InputStuInfo(SQLIST& sqList)
{
	STUDENT student;
	printf("学号："); scanf("%d", &student.sCode);
	printf("姓名：");  scanf("%s", student.name);

	//新增顺序表节点
	ListInsert(sqList, student, sqList.length + 1);

	//存入文件
	SaveSqList(sqList, filePath);

	printf("[录入学生信息成功...]\n");
	system("pause");
}


/**
* 函 数 名: Service_DropBySCode
* 说    明：根据学号删除学生信息
* 参    数: SQLIST & sqList -
* 返 回 值: void
*/
void Service_DropBySCode(SQLIST& sqList)
{
	printf("请输入要删除的学生的学号：");
	int destSCode = 0;
	scanf("%d", &destSCode);

	//判断该学号是否存在
	int destPos = ListFindPosBySCode(sqList, destSCode);
	if (destPos == 0) { printf("[删除失败,该学号不存在]\n"); system("pause"); return; }

	//从顺序表中删除
	ListDelete(sqList, destPos);

	//写入文件
	SaveSqList(sqList, filePath);

	printf("[删除成功]\n");
	system("pause");
	return;
}

/**
* 函 数 名: Service_AlterBySCode
* 说    明：根据学号修改学生信息
* 参    数: SQLIST & sqList -
* 返 回 值: void
*/
void Service_AlterBySCode(SQLIST& sqList)
{
	STUDENT student;
	STUDENT oldStu;
	printf("请输入学号："); scanf("%d", &student.sCode);

	//判断该学号是否存在
	int destPos = ListFindPosBySCode(sqList, student.sCode);
	if (destPos == 0) { printf("[修改失败,该学号不存在]\n"); system("pause"); return; }

	//录入新的学生信息
	printf("姓名：");  scanf("%s", student.name);

	//更新顺序表节点
	ListUpdate(sqList, student, destPos);

	//写入文件
	SaveSqList(sqList, filePath);

	printf("[更新成功]\n");
	system("pause");
	return;

}

/**
* 函 数 名: Service_SearchStuBySCode
* 说    明：通过学号查询学生信息
* 参    数: SQLIST & sqList -
* 返 回 值: void
*/
void Service_SearchStuBySCode(SQLIST& sqList)
{
	printf("输入要查询的学号：");
	int destSCode = 0;
	scanf("%d", &destSCode);

	//判断该学号是否存在
	int destPos = ListFindPosBySCode(sqList, destSCode);
	if (destPos == 0) { printf("[查询失败,该学号不存在]\n"); system("pause"); return; }

	//查询
	STUDENT destStu;
	ListGetElem(sqList, destPos, destStu);
	printf("[查询结果] 学号=%d\t姓名=%s\n", destStu.sCode, destStu.name);

	system("pause"); 
	return;
}