#include <stdio.h>
#include <stdlib.h>
//int main()
//{
//	for ( int line = 1; line <= 9; ++line)
//	{
//		for ( int col = 1; col <= line; ++col)
//		{
//			int sum = line*col;
//			printf("%d*%d=%2d ", line,col,sum);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
int main()
{
	int line = 1;
	while (line<10)
	{
		int col = 1;
		while (col <= line)
		{
			printf("%d*%d=%2d ", line, col, line*col);
			col += 1;
		}
		printf("\n");
		line += 1;
	}
	system("pause");
	return 0;
}



