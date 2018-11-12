#include <stdio.h>  //定义一个含有十个元素的数组
#include <stdlib.h> //求除数组长度,从第一个数依次与后面的元素进行比较
int main()
{
	int a[] = { 23, 12, 43, 78, 76, 54, 90, 11, 3, 88 };
	int size = sizeof(a) / sizeof(a[0]);
	int max = a[0];
	int i = 1;
	for (i = 1; i <= size;i++)
	if (max < a[i])
	{
		max = a[i]; //如果max小于a[i],就说明max还不是最大的
	}               //将它赋值给a[i]继续与下一个元素进行比较
	printf("%d\n", max);
	system("pause");
	return 0;
}