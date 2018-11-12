#include <stdio.h>  //定义判断闰年的函数
#include <stdlib.h> //条件:能被100,400整除是闰年
int IsLeapYear(int year)    //     能被4整除是闰年
{
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
		{
		if (year % 4 == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	int year = 1000;
	while (year < 2000)
	{
		if (IsLeapYear(year) == 1)
		{
			printf("%d\n", year);
		}
		year += 1;
	}
	system("pause");
	return 0;
}