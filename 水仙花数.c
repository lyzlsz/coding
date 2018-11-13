#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int  IsShuiXian(int num)
{
	if (num<100 || num>999)
	{
		return 0;
	}
	int tmp = num;
	int num1 = num % 10;   //取出个位
	num=num / 10;
	int num2 = num % 10;   //取出十位
	num=num / 10;
	int num3 = num % 10;
	if (pow(num1, 3) + pow(num2, 3) + pow(num3, 3) == tmp)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int i = 100;
	for (i=100; i <= 999; ++i)
	{
		if (IsShuiXian(i))
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}