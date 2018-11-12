#include <stdio.h>
#include <stdlib.h>
int MaxFactor(int x, int y)
{
	int i = 1;
	int max = 1;
	while (i <= x && i <= y)
	{
		if (x % i ==0 && y % i == 0)
		{
			max = i;
		}
		i += 1;
	}
	return max;
}
int main()
{
	int max = MaxFactor(100, 200);
	printf("%d\n", max);
	system("pause");
	return 0;
}