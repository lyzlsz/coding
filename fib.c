#include <stdio.h>
#include <stdlib.h>  
//int Fib(int n)     
//{                   
//	if (n == 1 || n == 2)  
//	{
//		return 1;
//	}
//	return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	printf("%d\n", Fib(6));
//	system("pause");
//	return 0;
//}


int Fib(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	int num1 = 1;
	int num2 = 1;
	int result = 0;
	for (int i = 3; i <= n; ++i)
	{
		result = num1 + num2;
		num1 = num2;
		num2 = result;
	}
	return result;
}
int main()
{
	printf("%d\n", Fib(6));
	system("pause");
	return 0;
}
//쳲�������������:1 1 2 3 5 8 13 21 33 -------
//�ӵ����ʼ,��һ����ǰ����֮��
//�����ٶȺܿ�,��ָ����ʽ����
//��һ�ַ���,�����ٶ���,���һ����
//�ڶ��ַ����ǵ�һ�ֵ��Ż�,�����ٶȲ����ȵ�һ�ֿ���ҿ��ǵ������

