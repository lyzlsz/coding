#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  //计算机自动生成一个随机数字,由用户输入一个数字,计算机将用户
#include <stdlib.h> 
#include <math.h>   //输入的数字与自身产生的进行比较,提示高了,低了还是猜对了
int Menu() //打印菜单供用户选择
{
	printf("================\n");
	printf("|  1.开始游戏  |\n");
	printf("|  0.退出游戏  |\n");
	printf("================\n");
	printf("请输入您的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Game() 
{
	int result = rand() % 100 + 1;
	while (1)
	{
		printf("请输入一个数字:\n");
		int num = 0;
		scanf("%d", &num);
		if (num < result)
		{
			printf("低了!\n");
		}
		else if (num>result)
		{
			printf("高了!\n");
		}
		else
		{
			printf("猜对了!恭喜你!\n");
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
			printf("退出游戏!");
			break;
		}
		else
		{
			printf("您的输入有误!\n");
		}
	}
		system("pause");
		return 0;
}




