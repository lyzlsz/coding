#include <stdio.h>  //����һ������ʮ��Ԫ�ص�����
#include <stdlib.h> //������鳤��,�ӵ�һ��������������Ԫ�ؽ��бȽ�
int main()
{
	int a[] = { 23, 12, 43, 78, 76, 54, 90, 11, 3, 88 };
	int size = sizeof(a) / sizeof(a[0]);
	int max = a[0];
	int i = 1;
	for (i = 1; i <= size;i++)
	if (max < a[i])
	{
		max = a[i]; //���maxС��a[i],��˵��max����������
	}               //������ֵ��a[i]��������һ��Ԫ�ؽ��бȽ�
	printf("%d\n", max);
	system("pause");
	return 0;
}