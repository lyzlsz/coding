#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	for (; i < 3; ++i)
	{
		char password[1024] = { 0 };
		printf("����������:");
		scanf("%s", password);
		if (strcmp(password,"123456") == 0)
		{
			printf("��¼�ɹ�!\n");
			break;
		}
		else
		{
			printf("��¼ʧ��!\n");
		}
		if (i == 3)
		{
			printf("����ʧ��!�����µ�¼!");
		}
		else
		{
		}
	}
	system("pause");
	return 0;
}