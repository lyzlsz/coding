#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	time_t seed = 0;
	time_t wait_time = 0;
	int show_time = 1;
	unsigned int i = 1;
	char choose = '1';
	char input1;
	unsigned int score = 0;
	unsigned int input2;
	unsigned int flag = 1;

	printf("准备好进行记忆测试了吗？\n");
	printf("屏幕上即将显示一串数字，你是否能记住它们呢？\n");
	printf("输入正确就可以挑战更高的难度了！\n");
	printf("按回车键开始！\n");
	getchar();
	printf("那么就开始吧！\n");
	int length = 3;
	while (choose == '1'){
		for (;; length += 2, show_time++)
		{
			wait_time = clock();
			srand(time(&seed));
			for (i = 1; i <= length; i++)
			{
				printf("%u", rand() % 10);
			}
			for (; clock() - wait_time < show_time * CLOCKS_PER_SEC;);
			for (i = 1; i <= length; i++)
			{
				printf("\b \b");
  		    }
			printf("\n记住了吗？那么就试试吧：");
			srand(seed);

			for (i = 1; i <= length; i++)
			{
				input1 = getchar();
				input2 = (int)input1 - (int)'0';
				if (input2 != rand() % 10)
				{
					printf("很遗憾！错误。正确答案：");
					srand(seed);
					for (i = 1; i <= length; i++)
					{
						printf("%u", rand() % 10);
					}
					flag = 0;
					break;
				}
			}
			fflush(stdin);
			if (flag == 0)
				break;
			score = score + length;
			printf("正确！继续挑战！下一个是：\n");
		}

		printf("\n你本次的分数为：%u\n是否重来？\n是-----1  否-----0\n", score);
		choose = getchar();
		if (choose == '1')
		{
			printf("再来一次：\n");
		}
		else
		{
			printf("本次游戏结束，再见！");
		}
		fflush(stdin);
	}
	return 0;
}







