#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int Menu()
{
	printf("1.开始游戏\n");//打印菜单,读取用户选择,若开始游戏则进入具体的游戏环节
	printf("0.退出游戏\n");    
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
#define MINE_COUNT 10 //地雷个数
#define ROW 9   //使用二维数组来表示扫雷的地图,一个表示雷阵
#define COL 9                   //一个表示用户看到的地图,地图是一个9*9的矩阵
char mine_map[ROW + 2][COL + 2];//但是我们为了方便代码的实现,定义为一个11*11的
char show_map[ROW + 2][COL + 2];//此时地图有效范围为[1,ROW]和[1,COL]
void Init(char mine_map[ROW + 2][COL + 2],//把数组进行初始化
	      char show_map[ROW + 2][COL + 2])
{
	memset(mine_map, '0', (ROW + 2)*(COL + 2));//先把里面的元素初始化为'0'
	memset(show_map, '*', (ROW + 2)*(COL + 2));//先把里面的元素初始化为'*'
    srand(time(0));
        //随机种子,产生一个毫秒级别的时间
	int mine_count = MINE_COUNT;
	while (mine_count > 0)//在这个循环中随机设置地雷,每次设置完成一个就--                             mine_count
	{                     //并把结果更新到show_map中
		int row = rand() % 9 + 1;
		int col = rand() % 9 + 1;
		if (mine_map[row][col] == '0')
		{
			mine_map[row][col]= '1';
			--mine_count;
		}
	}
}
void DisplayMap(char map[ROW + 2][COL + 2])
{
	printf("    ");
	for (int col = 1; col <= COL; ++col)
	{
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 1; col <= COL; ++col)
	{
		printf("---");
	}
	printf("\n");
	for (int row = 1; row <= ROW; ++row)
	{
		printf("%02d| ", row);
		for (int col = 1; col <= COL; ++col)
		{
			printf("%c ", map[row][col]);
		}
				printf("\n");
	}
}
void UpdateShowMap(char show_map[ROW + 2][COL + 2],
	char mine_map[ROW + 2][COL + 2], int row, int col)
{
	    int mine_count = 0;
		mine_count = (mine_map[row - 1][col - 1] - '0')
			+ (mine_map[row - 1][col - 1] - '0')
			+ (mine_map[row - 1][col + 1] - '0')
			+ (mine_map[row][col - 1] - '0')
			+ (mine_map[row][col + 1] - '0')
			+ (mine_map[row + 1][col - 1] - '0')
			+ (mine_map[row + 1][col] - '0')
			+ (mine_map[row + 1][col + 1] - '0');
		show_map[row][col] = '0' + mine_count;
}
void Game()
{
	int not_mine_count = 0;//1.定义地雷个数为0
	Init(mine_map, show_map);//2.初始化地图
	DisplayMap(show_map);    //3.先打印show_map
	while (1)
	{
		int row = 0;
		int col = 0;
		printf("请输入要翻开的方块的坐标(row,col):");//坐标范围[1,ROW][1,COL]
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > ROW || col <= 0 || col > COL)
		{      //4.对用户的输入进行判定,若不合理,提示用户重新输入
			printf("您的输入有误!请重新输入:\n");
			continue;
		}
		if (mine_map[row][col] == '1')//5.判定玩家是否踩雷,如踩雷,游戏结束打印阵
		{
			printf("游戏结束!\n");
			DisplayMap(mine_map);
			break;
		}
		++not_mine_count;//6.如没有踩雷,判定玩家是否胜利
		if (not_mine_count == ROW*COL - MINE_COUNT)
		{//胜利的条件是已经翻开的方块数达到了地图方块总数-地雷个数,则游戏胜利
			printf("扫雷成功!\n");
			DisplayMap(mine_map);
			break;
		}
		UpdateShowMap(show_map, mine_map, row, col);
		DisplayMap(show_map);//7.如游戏没有胜利,就统计当前位置周围雷的个数
	}
}//8.打印show_map,再回到第三步
void Start()
{
			while (1)
			{
				int choice = Menu();
				if (choice == 0)
				{
					printf("退出游戏!\n");
					break;
				}
				Game();
			}
}
int main()
{
	Start();
	system("pause");
	return 0;
}