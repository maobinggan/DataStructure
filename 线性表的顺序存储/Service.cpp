#include "Service.h"

/**
* �� �� ��: Service_PrintAllStuInfo
* ˵    ������ӡ����ѧ����Ϣ
* ��    ��: SQLIST & sqList -
* �� �� ֵ: void
*/
void Service_PrintAllStuInfo(SQLIST& sqList)
{
	printf("[��ӡ����ѧ����Ϣ]\n");
	int i = 0;
	for (i = 0; i < sqList.length; i++)
	{
		printf("ѧ��=%08d\t", sqList.elements[i].sCode);
		printf("����=%5s\t", sqList.elements[i].name);
		printf("\n");
	}
	system("pause");
}
/**
* �� �� ��: Service_InputStuInfo
* ˵    ����¼��ѧ����Ϣ
* ��    ��: SQLIST & sqList -
* �� �� ֵ: void
*/
void Service_InputStuInfo(SQLIST& sqList)
{
	STUDENT student;
	printf("ѧ�ţ�"); scanf("%d", &student.sCode);
	printf("������");  scanf("%s", student.name);

	//����˳���ڵ�
	ListInsert(sqList, student, sqList.length + 1);

	//�����ļ�
	SaveSqList(sqList, filePath);

	printf("[¼��ѧ����Ϣ�ɹ�...]\n");
	system("pause");
}


/**
* �� �� ��: Service_DropBySCode
* ˵    ��������ѧ��ɾ��ѧ����Ϣ
* ��    ��: SQLIST & sqList -
* �� �� ֵ: void
*/
void Service_DropBySCode(SQLIST& sqList)
{
	printf("������Ҫɾ����ѧ����ѧ�ţ�");
	int destSCode = 0;
	scanf("%d", &destSCode);

	//�жϸ�ѧ���Ƿ����
	int destPos = ListFindPosBySCode(sqList, destSCode);
	if (destPos == 0) { printf("[ɾ��ʧ��,��ѧ�Ų�����]\n"); system("pause"); return; }

	//��˳�����ɾ��
	ListDelete(sqList, destPos);

	//д���ļ�
	SaveSqList(sqList, filePath);

	printf("[ɾ���ɹ�]\n");
	system("pause");
	return;
}

/**
* �� �� ��: Service_AlterBySCode
* ˵    ��������ѧ���޸�ѧ����Ϣ
* ��    ��: SQLIST & sqList -
* �� �� ֵ: void
*/
void Service_AlterBySCode(SQLIST& sqList)
{
	STUDENT student;
	STUDENT oldStu;
	printf("������ѧ�ţ�"); scanf("%d", &student.sCode);

	//�жϸ�ѧ���Ƿ����
	int destPos = ListFindPosBySCode(sqList, student.sCode);
	if (destPos == 0) { printf("[�޸�ʧ��,��ѧ�Ų�����]\n"); system("pause"); return; }

	//¼���µ�ѧ����Ϣ
	printf("������");  scanf("%s", student.name);

	//����˳���ڵ�
	ListUpdate(sqList, student, destPos);

	//д���ļ�
	SaveSqList(sqList, filePath);

	printf("[���³ɹ�]\n");
	system("pause");
	return;

}

/**
* �� �� ��: Service_SearchStuBySCode
* ˵    ����ͨ��ѧ�Ų�ѯѧ����Ϣ
* ��    ��: SQLIST & sqList -
* �� �� ֵ: void
*/
void Service_SearchStuBySCode(SQLIST& sqList)
{
	printf("����Ҫ��ѯ��ѧ�ţ�");
	int destSCode = 0;
	scanf("%d", &destSCode);

	//�жϸ�ѧ���Ƿ����
	int destPos = ListFindPosBySCode(sqList, destSCode);
	if (destPos == 0) { printf("[��ѯʧ��,��ѧ�Ų�����]\n"); system("pause"); return; }

	//��ѯ
	STUDENT destStu;
	ListGetElem(sqList, destPos, destStu);
	printf("[��ѯ���] ѧ��=%d\t����=%s\n", destStu.sCode, destStu.name);

	system("pause"); 
	return;
}