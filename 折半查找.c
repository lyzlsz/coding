#include <stdio.h> 
#include <stdlib.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int to_find = 4;
	int left = 0;       //�ұ�=�����ܳ��ȳ��Ե�ǰ����Ԫ��
	int right = sizeof(arr) / sizeof(arr[0]) - 1; //����λ��-1(��1����Ϊ����С��
	int mid = 0;                            //��0��ʼ
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
		printf("�ҵ���!�±�Ϊ:%d\n", mid);
	}
	else
	{
		printf("û�ҵ�\n");
	}
	system("pause");
	return 0;
}                       