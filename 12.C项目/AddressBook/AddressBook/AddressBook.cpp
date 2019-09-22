#include "AddressBook.h"

void showMenu()
{
	printf("\n================欢迎使用通讯录！====================\n\n");
	printf("\t\t1--增加联系人\n");
	printf("\t\t2--删除联系人\n");
	printf("\t\t3--修改联系人信息\n");
	printf("\t\t4--浏览通讯录\n");
	printf("\t\t5--清空通讯录\n");
	printf("\t\t6--退出\n");
}	

///添加联系人
bool addItem(char* tmpName, char* tmpNum)
{
	if(head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		if(head == NULL)
		{
			printf("分配内存失败！");
			return false;
		}
		head->name = new char[20];
		head->teleNum = new char[12];
 		strcpy(head->name,tmpName);
 		strcpy(head->teleNum,tmpNum);
		head->NUM = ++index;//每个联系人一个索引号
		head->next = NULL;
	}
	else
	{
		Node *tmpNode = head;
		Node *foreHead;
		while(tmpNode->next!=NULL)
			tmpNode = tmpNode->next;
		foreHead = tmpNode;

		tmpNode = (Node*)malloc(sizeof(Node));
		tmpNode->name = new char[20];
		tmpNode->teleNum = new char[12];
		strcpy(tmpNode->name,tmpName);
		strcpy(tmpNode->teleNum,tmpNum);
		tmpNode->NUM = ++index;//每个联系人一个索引号
		tmpNode->next = NULL;
		foreHead->next = tmpNode;
	}
	return true;
}

Node* findNode(int iNum)
{
	Node *tmpNode = head;
	if(tmpNode == NULL)
		return NULL;
	while(tmpNode->next->NUM != iNum)
	{
		tmpNode = tmpNode->next;
		if(tmpNode == NULL)
			return false;
	}
	return tmpNode;
}

///删除联系人
bool deleteItem()
{
	if(head == NULL)
		return false;
	int delNum = 0;
	printf("请输入要删除的联系人的序号：");
	scanf("%d",&delNum);
	if(delNum>index || delNum<=0)
	{
		printf("输入不正确！");
		return false;
	}
	Node *foreNode = NULL;
	Node *tempNode = head;
	while(tempNode->NUM != delNum)
	{
		foreNode = tempNode;
		tempNode = tempNode->next;
		if(tempNode == NULL)
			return false;
	}

	if(foreNode == NULL)
	{
		head = tempNode->next;
		free(tempNode);
	}
	else
	{
		foreNode->next = tempNode->next;
		free(tempNode);
	}

	return true;
}

///修改联系人信息
bool modifyInfo()
{
	Node *tmpNode= head;
	char *tmpName = new char[20];
	printf("输入联系人姓名：");
	scanf("%s",tmpName);

	printf("请选择：  1--修改姓名\t2--修改电话号码    ");
	int choice;
	scanf("%d",&choice);
	if(choice == 1)
	{
		while(strcmp(tmpName,tmpNode->name)!=0)
		{
			tmpNode = tmpNode->next;
			if(tmpNode == NULL)
			{
				printf("未找到联系人！");
				return false;
			}
		}
		printf("输入修改后的姓名：");
		scanf("%s",tmpName);
		strcpy(tmpNode->name,tmpName);
	}
	else if(choice == 2)
	{
		char *tmpNum = new char[12];
		while(strcmp(tmpName,tmpNode->name)!=0)
		{
			tmpNode = tmpNode->next;
			if(tmpNode == NULL)
			{
				printf("未找到联系人！");
				return false;
			}
		}
		printf("输入修改后的电话号码：");
		scanf("%s",tmpNum);
		strcpy(tmpNode->teleNum,tmpNum);
	}
	else
	{
		printf("输入错误！");
		return false;
	}
	return true;
}

///浏览通讯录
void lookThrough()
{
	Node *tmpNode = head;
	while(tmpNode != NULL)
	{
		printf("%d\t姓名：%s\t手机号：%s\n",tmpNode->NUM,tmpNode->name,tmpNode->teleNum);
		tmpNode = tmpNode->next;
	}
}

///清空通讯录
bool clearAddressBook()
{
	Node *tmpNode = head;
	Node *tmpNode2 = head;
	if(head == NULL)//也可以通过index==0来判断
	{
		printf("通讯录为空！");
		return true;
	}
	if(head->next == NULL)//也可以通过index==1来判断
	{
		free(head);
		head = NULL;
		return true;
	}
	tmpNode2 = tmpNode2->next;
	while(tmpNode2!=NULL)
	{
		free(tmpNode);
		tmpNode = tmpNode2;
		tmpNode2 = tmpNode->next;
	}
	head = NULL;
	index = 0;
	return true;
}

int main()
{
	showMenu();
	int choice = 0;
	scanf("%d",&choice);

	char *tmpName = new char[20];
	char *tmpNum = new char[12];
	while(choice != 6)
	{
		switch(choice)
		{
		case 1://增加联系人
			printf("输入联系人姓名：");
			scanf("%s",tmpName);
			printf("输入联系人电话号码：");
			scanf("%s",tmpNum);
			if(!addItem(tmpName,tmpNum))
			{
				printf("添加失败！");
				break;
			}
			printf("添加成功！");			
			break;
		case 2://删除联系人
			if(!deleteItem())
			{
				printf("删除失败！");
				break;
			}
			printf("删除成功！");
			break;
		case 3://修改联系人信息
			if(!modifyInfo())
			{
				printf("修改失败！");
				break;
			}
			printf("修改成功！");
			break;
		case 4://浏览通讯录
			lookThrough();
			break;
		case 5://清空通讯录
			if(!clearAddressBook())
			{
				printf("清空通讯录失败！");
				break;
			}
			printf("清空通讯录成功！");
			break;
		}
		showMenu();
		printf("\n请选择：");
		scanf("%d",&choice);
	}
	printf("================欢迎下次再用！====================\n\n");
	system("pause");
	return 0;
}