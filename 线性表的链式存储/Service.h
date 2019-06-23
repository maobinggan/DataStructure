#pragma once
#include "链表.h"

/*业务逻辑*/
void Service_AddStu(NODE*& headNode);					//新增学生信息
void Service_DropStuBySCode(NODE* headNode);			//删除学生信息
void Service_AlterStuBySCode(NODE* headNode);			//修改学生信息（根据学号）
void Service_SearchBySCode(NODE* headNode);				//显示学生信息（根据学号）
void Service_ShowAllStu_OrderBySCode(NODE*& headNode);  //显示所有学生信息（按学号升序）


