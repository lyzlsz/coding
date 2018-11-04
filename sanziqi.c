#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROW 3              //����ĳ��ȶ���Ϊ��,����Գ�����չ,�޸�Ԫ��
#define COL 3
char g_chess_board[ROW][COL];
void Init()
{
	for(int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col < COL; ++col)//1.�ö�ά�����ʾ����
		{
			g_chess_board[row][col] = ' ';//2.�����̽��г�ʼ��(�ո�)
		}
	}
}                                                                                 
void print()
{
	int row = 0;
	for (row = 0; row < ROW; ++row)//3.�ȴ�ӡ����
	{
		printf("| %c | %c | %c |\n", g_chess_board[row][0],
			g_chess_board[row][1], g_chess_board[row][2]);
		if (row != ROW - 1)
		{
			printf("|---|---|---|\n");
		}
	}
}
void PlayerMove()            //4.���������
{                        
	while (1)            
	{
		printf("���������!(��������):");//(1)��ʾ�������һ������
		int row = -1;//��ֹ��ҵĺ�������
		int col = -1;
		scanf("%d %d", &row, &col);
		if (row  < 0 || row >= ROW || col < 0 || col >= COL)
		{   //(2)����ҵ��������У��,У�������Ƿ�Ϸ�,У�������Ƿ��Ѿ�����
			printf("�������������,����������!\n");
			continue;//(3)�������������Ƿ�,��ʾ��������
		}            //(4)������Ϸ�,���̶�Ӧλ������,��'X'��ʾ
		if (g_chess_board[row][col] != ' ')
		{
			printf("��ǰλ���Ѿ�����,����������!\n");
			continue;
		}
		else
		{
			g_chess_board[row][col] = 'x';
			break;
		}
	}
}
void ComputerMove()  //5.�õ�������
{
	printf("���������!\n"); //(1)������������к���,�����ǰ�к����Ѿ�
	int row = 0;                   //��ռ��,�ͼ�������
	int col = 0;
	while (1)
	{
		row = rand() % ROW;    //����rand����һ��������ʵ�ֲ����������
		col = rand() % COL;   
		if (g_chess_board[row][col] == ' ')
		{
			g_chess_board[row][col] = '0';
			break;
		}
	}
}
int IsFull()      //�ж������Ƿ�����
{
	for (int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col < COL; ++col)
		{
			if (g_chess_board[row][col] == ' ')
			{
				return 0;//������˷���1,û������0
			}
		}
	}
	return 1;
}
char CheckWinner()    //6.�����Ϸ�Ƿ����
{
	for (int row = 0; row < ROW; ++row)//(1)����������ǲ���������������һ��
	{
		if (g_chess_board[row][0] ==
			g_chess_board[row][1] &&
			g_chess_board[row][0] ==
			g_chess_board[row][2] &&
			g_chess_board[row][0] != ' ')
		{
			return g_chess_board[row][0];
		}
	}
	for (int col = 0; col < COL; ++col)
	{                                   //(2)����������Ƿ�����һ��
		if (g_chess_board[0][col] ==
			g_chess_board[1][col] &&
			g_chess_board[0][col] ==
			g_chess_board[2][col] &&
			g_chess_board[0][col] != ' ')
		{
			return g_chess_board[0][col];
		}
	}
	if (g_chess_board[0][0] ==        //(3)���Խ���
		g_chess_board[1][1] &&
		g_chess_board[0][0] ==
		g_chess_board[2][2] &&
		g_chess_board[0][0] != ' ')
	{
		return g_chess_board[0][0];
	}
	if (g_chess_board[2][0] ==
		g_chess_board[1][1] &&
		g_chess_board[2][0] ==
		g_chess_board[0][2] &&
		g_chess_board[2][0] != ' ')
	{
		return g_chess_board[2][0];
	}
	if (IsFull())  //����Ƿ����
	{
		return "q";
	}
	else
	{
		return ' ';
	}
}
int main()
{
	char Winner = ' ';
	Init();
	while (1)
	{
		print();
		PlayerMove();
		Winner = CheckWinner();
		if (Winner != ' ')
		{
			break;
		}
		ComputerMove();
		Winner = CheckWinner();
		if (Winner != ' ')
		{
			break;
		}
	}
	if (Winner == 'x')
	{
		printf("��һ�ʤ!\n");
	}
	else if (Winner == '0')
	{
		printf("���Ի�ʤ!\n");
	}
	else if (Winner == 'q')
	{
		printf("����!\n");
	}
	system("pause");
	return 0;
}