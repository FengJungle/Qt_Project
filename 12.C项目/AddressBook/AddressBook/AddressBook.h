#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

///��׼�������
#include <stdio.h>
///ϵͳ����
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct node
{
	int NUM;
	char* teleNum;
	char* name;
	struct node *next;
}Node;

//����һ��ͷָ��
Node *head = NULL;
//��ϵ��������
static int index = 0;

#endif //ADDRESSBOOK_H