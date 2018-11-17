#include <stdio.h>
#include <stdlib.h>
//1.
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 4, 5, 6, 7, 8 };
//	int i = 0;
//	int tmp = 0;
//	int len;
//	len = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < len; ++i)
//	{
//		printf("%d", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < len; ++i)
//	{
//		printf("%d", arr2[i]);
//	}
//	printf("\n");
//	printf("---------------\n");
//	for (i = 0; i < len; i += 1)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for (i = 0; i < len; ++i)
//	{
//		printf("%d", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < len; ++i)
//	{
//		printf("%d", arr2[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}


//2.

int main()
{
	int a[] = { 1, 2, 3, 4 };
	int b[] = { 4, 3, 2, 1 };
	int i = 0;
	for (i = 0; i < 4; ++i)
	{
		int tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
	for (i = 0; i < 4; ++i)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	for (i = 0; i < 4; ++i)
	{
		printf("%d", b[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
