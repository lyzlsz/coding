#include <stdio.h> 
#include <stdlib.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int to_find = 4;
	int left = 0;       //右边=数组总长度除以当前所在元素
	int right = sizeof(arr) / sizeof(arr[0]) - 1; //所在位置-1(减1是因为数组小标
	int mid = 0;                            //从0开始
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (to_find < arr[mid])
		{
			right = mid - 1;
		}
		else if (to_find>arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			break;
		}
	}
	if (left <= right)
	{
		printf("找到了!下标为:%d\n", mid);
	}
	else
	{
		printf("没找到\n");
	}
	system("pause");
	return 0;
}                       