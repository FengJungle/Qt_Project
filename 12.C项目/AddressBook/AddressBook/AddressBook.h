#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

///标准输入输出
#include <stdio.h>
///系统函数
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

//创建一个头指针
Node *head = NULL;
//联系人索引号
static int index = 0;

#endif //ADDRESSBOOK_H