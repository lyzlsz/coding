#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROW 3              //数组的长度定义为宏,方便对程序扩展,修改元素
#define COL 3
char g_chess_board[ROW][COL];
void Init()
{
	for(int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col < COL; ++col)//1.用二维数组表示棋盘
		{
			g_chess_board[row][col] = ' ';//2.对棋盘进行初始化(空格)
		}
	}
}                                                                                 
void print()
{
	int row = 0;
	for (row = 0; row < ROW; ++row)//3.先打印棋盘
	{
		printf("| %c | %c | %c |\n", g_chess_board[row][0],
			g_chess_board[row][1], g_chess_board[row][2]);
		if (row != ROW - 1)
		{
			printf("|---|---|---|\n");
		}
	}
}
void PlayerMove()            //4.让玩家落子
{                        
	while (1)            
	{
		printf("请玩家落子!(输入坐标):");//(1)提示玩家输入一个坐标
		int row = -1;//防止玩家的胡乱输入
		int col = -1;
		scanf("%d %d", &row, &col);
		if (row  < 0 || row >= ROW || col < 0 || col >= COL)
		{   //(2)对玩家的输入进行校验,校验坐标是否合法,校验坐标是否已经有子
			printf("输入的坐标有误,请重新输入!\n");
			continue;//(3)若玩家输入坐标非法,提示重新输入
		}            //(4)若输入合法,棋盘对应位置落子,用'X'表示
		if (g_chess_board[row][col] != ' ')
		{
			printf("当前位置已经有子,请重新输入!\n");
			continue;
		}
		else
		{
			g_chess_board[row][col] = 'x';
			break;
		}
	}
}
void ComputerMove()  //5.让电脑落子
{
	printf("请电脑落子!\n"); //(1)靠随机数产生行和列,如果当前行和列已经
	int row = 0;                   //被占用,就继续输入
	int col = 0;
	while (1)
	{
		row = rand() % ROW;    //用了rand这样一个函数来实现产生随机数字
		col = rand() % COL;   
		if (g_chess_board[row][col] == ' ')
		{
			g_chess_board[row][col] = '0';
			break;
		}
	}
}
int IsFull()      //判断棋盘是否满了
{
	for (int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col < COL; ++col)
		{
			if (g_chess_board[row][col] == ' ')
			{
				return 0;//如果满了返回1,没满返回0
			}
		}
	}
	return 1;
}
char CheckWinner()    //6.检查游戏是否继续
{
	for (int row = 0; row < ROW; ++row)//(1)检查所有行是不是三个字连到了一起
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
	{                                   //(2)检查所有列是否连在一起
		if (g_chess_board[0][col] ==
			g_chess_board[1][col] &&
			g_chess_board[0][col] ==
			g_chess_board[2][col] &&
			g_chess_board[0][col] != ' ')
		{
			return g_chess_board[0][col];
		}
	}
	if (g_chess_board[0][0] ==        //(3)检查对角线
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
	if (IsFull())  //检查是否和棋
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
		printf("玩家获胜!\n");
	}
	else if (Winner == '0')
	{
		printf("电脑获胜!\n");
	}
	else if (Winner == 'q')
	{
		printf("和棋!\n");
	}
	system("pause");
	return 0;
}