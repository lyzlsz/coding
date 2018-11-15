#include <stdio.h>
#include <stdlib.h>
int Factor(int n)
{
	int result = 1;
	for (int i = 1; i <= n; ++i)
	{
		result *= i;
	}
		return result;
}
int FactorSum(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += Factor(i);
	}
	return sum;
}
int main()
{
	int result = FactorSum(10);
	{
		printf("result=%d\n", result);
	}
	system("pause");
	return 0;
}