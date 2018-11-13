#include <stdio.h>
#include <stdlib.h>
#include <math.h>   //2+22+222+2222+22222
int CreateNum(int a, int n)
{
	if (a <= 0 || a >= 10 || n <= 0)	
	{
		return 0;
	}
	int num = 0; //要构造的数字
	int i = 0;   //i表示10的指数
	for (; i < n; ++i)
	{
		num += a*pow(10,i);
	}
	return num;
}
int main()
{
	int i = 1;
	int a = 2;
	int sum = 0;
	for (; i <= 5; ++i)
	{
		sum += CreateNum(a, i);
	}
	{
		printf("%d\n", sum);
	}
	system("pause");
	return 0;
}