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
		PrintLine(n - i, 2 * i - 1);//��ӡ�ϰ벿��
	}
	PrintLine(0, 2 * n - 1); //��ӡ�м�
	for (i = n - 1; i>0; --i)
	{
		PrintLine(n - i, 2 * i - 1); //��ӡ�°벿��
	}
}
int main()
{
	PrintLingXing(7);
	system("pause");
}