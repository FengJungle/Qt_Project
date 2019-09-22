#include "AddressBook.h"

void showMenu()
{
	printf("\n================��ӭʹ��ͨѶ¼��====================\n\n");
	printf("\t\t1--������ϵ��\n");
	printf("\t\t2--ɾ����ϵ��\n");
	printf("\t\t3--�޸���ϵ����Ϣ\n");
	printf("\t\t4--���ͨѶ¼\n");
	printf("\t\t5--���ͨѶ¼\n");
	printf("\t\t6--�˳�\n");
}	

///�����ϵ��
bool addItem(char* tmpName, char* tmpNum)
{
	if(head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		if(head == NULL)
		{
			printf("�����ڴ�ʧ�ܣ�");
			return false;
		}
		head->name = new char[20];
		head->teleNum = new char[12];
 		strcpy(head->name,tmpName);
 		strcpy(head->teleNum,tmpNum);
		head->NUM = ++index;//ÿ����ϵ��һ��������
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
		tmpNode->NUM = ++index;//ÿ����ϵ��һ��������
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

///ɾ����ϵ��
bool deleteItem()
{
	if(head == NULL)
		return false;
	int delNum = 0;
	printf("������Ҫɾ������ϵ�˵���ţ�");
	scanf("%d",&delNum);
	if(delNum>index || delNum<=0)
	{
		printf("���벻��ȷ��");
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

///�޸���ϵ����Ϣ
bool modifyInfo()
{
	Node *tmpNode= head;
	char *tmpName = new char[20];
	printf("������ϵ��������");
	scanf("%s",tmpName);

	printf("��ѡ��  1--�޸�����\t2--�޸ĵ绰����    ");
	int choice;
	scanf("%d",&choice);
	if(choice == 1)
	{
		while(strcmp(tmpName,tmpNode->name)!=0)
		{
			tmpNode = tmpNode->next;
			if(tmpNode == NULL)
			{
				printf("δ�ҵ���ϵ�ˣ�");
				return false;
			}
		}
		printf("�����޸ĺ��������");
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
				printf("δ�ҵ���ϵ�ˣ�");
				return false;
			}
		}
		printf("�����޸ĺ�ĵ绰���룺");
		scanf("%s",tmpNum);
		strcpy(tmpNode->teleNum,tmpNum);
	}
	else
	{
		printf("�������");
		return false;
	}
	return true;
}

///���ͨѶ¼
void lookThrough()
{
	Node *tmpNode = head;
	while(tmpNode != NULL)
	{
		printf("%d\t������%s\t�ֻ��ţ�%s\n",tmpNode->NUM,tmpNode->name,tmpNode->teleNum);
		tmpNode = tmpNode->next;
	}
}

///���ͨѶ¼
bool clearAddressBook()
{
	Node *tmpNode = head;
	Node *tmpNode2 = head;
	if(head == NULL)//Ҳ����ͨ��index==0���ж�
	{
		printf("ͨѶ¼Ϊ�գ�");
		return true;
	}
	if(head->next == NULL)//Ҳ����ͨ��index==1���ж�
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
		case 1://������ϵ��
			printf("������ϵ��������");
			scanf("%s",tmpName);
			printf("������ϵ�˵绰���룺");
			scanf("%s",tmpNum);
			if(!addItem(tmpName,tmpNum))
			{
				printf("���ʧ�ܣ�");
				break;
			}
			printf("��ӳɹ���");			
			break;
		case 2://ɾ����ϵ��
			if(!deleteItem())
			{
				printf("ɾ��ʧ�ܣ�");
				break;
			}
			printf("ɾ���ɹ���");
			break;
		case 3://�޸���ϵ����Ϣ
			if(!modifyInfo())
			{
				printf("�޸�ʧ�ܣ�");
				break;
			}
			printf("�޸ĳɹ���");
			break;
		case 4://���ͨѶ¼
			lookThrough();
			break;
		case 5://���ͨѶ¼
			if(!clearAddressBook())
			{
				printf("���ͨѶ¼ʧ�ܣ�");
				break;
			}
			printf("���ͨѶ¼�ɹ���");
			break;
		}
		showMenu();
		printf("\n��ѡ��");
		scanf("%d",&choice);
	}
	printf("================��ӭ�´����ã�====================\n\n");
	system("pause");
	return 0;
}