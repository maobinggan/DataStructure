#pragma once
#include "顺序表.h"
const char* filePath = "data.txt";
/**
* 函 数 名: SaveSqList
* 说    明：将顺序表中的记录写入至文件
* 参    数: SQLIST & sqList -
* 参    数: const char * filePath - 文件路径
* 返 回 值: void
*/
void SaveSqList(SQLIST& sqList, const char* filePath)
{
	FILE* pFile = fopen(filePath, "wb");//打开用于写入的空文件。 如果给定文件存在，则其内容会被销毁。
	if (pFile == NULL) { printf("【error】pFile is null..."); return; }
	for (int i = 0; i < sqList.length; i++)
	{
		fwrite(&sqList.elements[i], sizeof(STUDENT), 1, pFile);
		fwrite("\n", 1, 1, pFile); //多写入一个换行符，方便查看
	}
	fclose(pFile);
}

/**
* 函 数 名: LoadData
* 说    明：从文件中读取记录至顺序表
* 参    数: SQLIST & stuList -
* 参    数: const char * filePath - 文件路径
* 返 回 值: void
*/
void LoadSqList(SQLIST& sqList, const char* filePath)
{
	FILE* pFile = fopen(filePath, "rb");//打开以便读取。 如果文件不存在或无法找到fopen调用失败。
	if (pFile == NULL) { return; }
	while (fread(&sqList.elements[sqList.length], sizeof(STUDENT), 1, pFile) != 0)
	{
		char tempBuffer;
		fread(&tempBuffer, 1, 1, pFile); //多读一个换行符
		sqList.length++;
	}
	fclose(pFile);
}

/**
* 函 数 名: ListInit
* 说    明：顺序表的初始化
* 参    数: SQLIST & stuList -
* 返 回 值: void
*/
void ListInit(SQLIST& sqList)
{
	//为顺序表中的结构体数组申请内存空间
	//sqList.elements = (STUDENT*)malloc(SIZE_SQLIST * sizeof(STUDENT));

	//把结构体数组清零，方便对结构体进行比较(memcmp)
	memset(sqList.elements, 0x0, sizeof(SIZE_SQLIST * sizeof(STUDENT)));

	//把顺序表的长度设置为0
	sqList.length = 0;
}

/**
* 函 数 名: ListInsert
* 说    明：向顺序表插入新节点，使长度为n的线性表变成长度为n+1的线性表,时间复杂度O(n)
* 参    数: SQLIST & stuList -
* 参    数: STUDENT destNode - 要插入的目标节点
* 参    数: int pos - 要插入的逻辑位置（在长度为n的顺序表中，逻辑位置从1至n）
*					- 如果希望在顺序表末尾添加节点，则传入的pos应该为n+1
* 返 回 值: void
*/
bool ListInsert(SQLIST& sqList, STUDENT destNode, int pos)
{
	//判断目标逻辑位置pos的合法性（pos的合法范围是 1<= pos <= n+1 ） 
	if (pos < 1 || pos > sqList.length + 1) { printf("【error】逻辑位置错误，无法插入新节点\n"); return false; }
	//判断线性表是否已满
	if (sqList.length == SIZE_SQLIST) { printf("【error】顺序表已满，无法插入新节点\n"); return false; }

	//从第n个元素即最后一个元素开始，依次向后移动一个位置，直至第pos个元素。（共需移动 n-pos+1 次）
	for (int i = sqList.length; i >= pos; i--)
	{
		sqList.elements[i] = sqList.elements[i - 1];
	}
	//将要插入的新节点放入第pos个位置
	sqList.elements[pos - 1] = destNode;
	//线性表长度加一
	sqList.length++;
	return true;
}

/**
* 函 数 名: ListDelete
* 说    明：从顺序表中删除节点,时间复杂度O(n)
* 参    数: SQLIST & sqList -
* 参    数: int pos - 要删除的节点的逻辑位置（在长度为n的顺序表中，逻辑位置从1至n）
* 返 回 值: bool
*/
bool ListDelete(SQLIST& sqList, int pos)
{
	//判断目标逻辑位置pos的合法性（pos的范围是 1 <= pos <= n）
	if (pos<1 || pos>sqList.length) { printf("【error】逻辑位置错误，无法删除节点\n");  return false; }
	//判断线性表是否为空
	if (sqList.length < 1) { printf("【error】顺序表为空，无法删除节点\n");  return false; }

	//要删除第pos个元素，就需要将第pos+1个至第n个元素依次向前移动一个位置
	for (int i = pos; i <= sqList.length; i++)
	{
		sqList.elements[i - 1] = sqList.elements[i];
	}
	//线性表长度减一
	sqList.length--;
	return true;
}


/**
* 函 数 名: ListUpdate
* 说    明：更新替换顺序表的某个节点,时间复杂度O(n)
* 参    数: SQLIST & sqList -
* 参    数: STUDENT destNode -
* 参    数: int pos -
* 返 回 值: bool
*/
bool ListUpdate(SQLIST& sqList, STUDENT destNode, int pos)
{
	//判断目标逻辑位置pos的合法性（pos的范围是 1 <= pos <= n）
	if (pos<1 || pos>sqList.length) { printf("【error】逻辑位置错误，无法修改节点\n");  return false; }
	//elements[pos-1]存储的就是第pos个元素
	sqList.elements[pos - 1] = destNode;
	return true;
}

/**
* 函 数 名: ListLocate
* 说    明：查找与目标节点的数据相同的节点的逻辑位置（按内容查找）,时间复杂度O(n)
* 参    数: SQLIST & sqList -
* 参    数: STUDENT destNode -
* 返 回 值: int - 返回的是逻辑位置，如果返回0，则说明找不到相同的节点
*/
int ListLocate(SQLIST& sqList, STUDENT destNode)
{
	for (int i = 0; i < sqList.length; i++)
	{
		if (memcmp(&sqList.elements[i], &destNode, sizeof(destNode)) == 0)
		{
			return i + 1;//逻辑位置需要加1
		}
	}
	return 0;
}

/**
* 函 数 名: ListGetElem
* 说    明：按逻辑位置查找，时间复杂度O(1)
* 参    数: SQLIST & sqList -
* 参    数: int pos - 逻辑位置
* 参    数: OUT STUDENT elem - 查找的结果
* 返 回 值: bool
*/
bool ListGetElem(SQLIST& sqList, int pos, OUT STUDENT& elem)
{
	//判断目标逻辑位置pos的合法性（pos的范围是 1 <= pos <= n）
	if (pos<1 || pos>sqList.length) { printf("【error】逻辑位置错误，无法查找节点\n");  return false; }
	//elements[pos-1]存储的就是第pos个元素
	elem = sqList.elements[pos - 1];
	return true;
}

/**
* 函 数 名: ListFindPosBySCode
* 说    明：根据某个字段（学号）查询逻辑位置
* 参    数: SQLIST & sqList -
* 参    数: int destScode -
* 返 回 值: int - 逻辑位置
*/
int ListFindPosBySCode(SQLIST& sqList, int destScode)
{
	int i = 0;
	for (i = 0; i < sqList.length; i++)
	{
		if (sqList.elements[i].sCode == destScode)
		{
			return i + 1;
		}
	}
	return 0;
}