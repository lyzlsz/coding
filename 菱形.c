#include <stdio.h>
#include <stdlib.h>
void PrintLine(int blank_count, int star_count)
{
	int i = 0;
	for (; i < blank_count; ++i)
	{
		printf(" ");
	}
	for (i = 0; i < star_count; ++i)
	{
		printf("*");
	}
	printf("\n");
}
void PrintLingXing(int n)
{
	int i = 1;   
	for (; i < n; ++i)
	{
		PrintLine(n - i, 2 * i - 1);//打印上半部分
	}
	PrintLine(0, 2 * n - 1); //打印中间
	for (i = n - 1; i>0; --i)
	{
		PrintLine(n - i, 2 * i - 1); //打印下半部分
	}
}
int main()
{
	PrintLingXing(7);
	system("pause");
}