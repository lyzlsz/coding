#include <stdio.h>
#include <stdlib.h>
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void BubbleSort(int arr[], int size)
{
	int bound = 0;//[0,bound)已经排好序的区间
	for (; bound < size; ++bound)//[bound,size)待排序区间
	{
		int cur = size - 1;
		for (; cur>bound; --cur)
		{
			if (arr[cur] < arr[cur - 1])
			{
				Swap(arr[cur], &arr[cur - 1]);
			}
		}
	}
}
int main()
{
	int arr[] = { 9, 5, 2, 7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, len);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
}