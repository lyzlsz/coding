#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  //������Զ�����һ���������,���û�����һ������,��������û�
#include <stdlib.h> 
#include <math.h>   //�������������������Ľ��бȽ�,��ʾ����,���˻��ǲ¶���
int Menu() //��ӡ�˵����û�ѡ��
{
	printf("================\n");
	printf("|  1.��ʼ��Ϸ  |\n");
	printf("|  0.�˳���Ϸ  |\n");
	printf("================\n");
	printf("����������ѡ��:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Game() 
{
	int result = rand() % 100 + 1;
	while (1)
	{
		printf("������һ������:\n");
		int num = 0;
		scanf("%d", &num);
		if (num < result)
		{
			printf("����!\n");
		}
		else if (num>result)
		{
			printf("����!\n");
		}
		else
		{
			printf("�¶���!��ϲ��!\n");
			break;
		}
	}
}
int main()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 1)
		{
			Game();
		}
		else if (choice == 0)
		{
			printf("�˳���Ϸ!");
			break;
		}
		else
		{
			printf("������������!\n");
		}
	}
		system("pause");
		return 0;
}




