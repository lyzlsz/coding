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

	printf("׼���ý��м����������\n");
	printf("��Ļ�ϼ�����ʾһ�����֣����Ƿ��ܼ�ס�����أ�\n");
	printf("������ȷ�Ϳ�����ս���ߵ��Ѷ��ˣ�\n");
	printf("���س�����ʼ��\n");
	getchar();
	printf("��ô�Ϳ�ʼ�ɣ�\n");
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
			printf("\n��ס������ô�����԰ɣ�");
			srand(seed);

			for (i = 1; i <= length; i++)
			{
				input1 = getchar();
				input2 = (int)input1 - (int)'0';
				if (input2 != rand() % 10)
				{
					printf("���ź���������ȷ�𰸣�");
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
			printf("��ȷ��������ս����һ���ǣ�\n");
		}

		printf("\n�㱾�εķ���Ϊ��%u\n�Ƿ�������\n��-----1  ��-----0\n", score);
		choose = getchar();
		if (choose == '1')
		{
			printf("����һ�Σ�\n");
		}
		else
		{
			printf("������Ϸ�������ټ���");
		}
		fflush(stdin);
	}
	return 0;
}







