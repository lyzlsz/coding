#include <stdio.h>
#include <stdlib.h>  
//int Fib(int n)     
//{                   
//	if (n == 1 || n == 2)  
//	{
//		return 1;
//	}
//	return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	printf("%d\n", Fib(6));
//	system("pause");
//	return 0;
//}


int Fib(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	int num1 = 1;
	int num2 = 1;
	int result = 0;
	for (int i = 3; i <= n; ++i)
	{
		result = num1 + num2;
		num1 = num2;
		num2 = result;
	}
	return result;
}
int main()
{
	printf("%d\n", Fib(6));
	system("pause");
	return 0;
}
//斐波那契数列数列:1 1 2 3 5 8 13 21 33 -------
//从第三项开始,后一项是前两项之和
//增长速度很快,以指数形式增长
//第一种方法,运算速度慢,而且会溢出
//第二种方法是第一种的优化,运算速度不但比第一种快而且考虑到了溢出

