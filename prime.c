#include <stdio.h>
#include <stdlib.h>
int IsPrime(int x)
{
	int num = 2;
	while (num < x)
	{
		if (x % num == 0)
		{
			return 0;
		}
		num = num + 1;
	}
		return 1;
	}
int main()
{
	int i = 100;
	while (i < 200)
	{
		if (IsPrime(i) == 1)
		{
			printf("%d\n", i);
		}
		i += 1;
	}
	system("pause");
	return 0;
}



