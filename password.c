#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	for (; i < 3; ++i)
	{
		char password[1024] = { 0 };
		printf("ÇëÊäÈëÃÜÂë:");
		scanf("%s", password);
		if (strcmp(password,"123456") == 0)
		{
			printf("µÇÂ¼³É¹¦!\n");
			break;
		}
		else
		{
			printf("µÇÂ¼Ê§°Ü!\n");
		}
		if (i == 3)
		{
			printf("Èý´ÎÊ§°Ü!ÇëÖØÐÂµÇÂ¼!");
		}
		else
		{
		}
	}
	system("pause");
	return 0;
}