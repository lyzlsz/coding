#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int Menu()
{
	printf("1.��ʼ��Ϸ\n");//��ӡ�˵�,��ȡ�û�ѡ��,����ʼ��Ϸ�����������Ϸ����
	printf("0.�˳���Ϸ\n");    
	printf("����������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
#define MINE_COUNT 10 //���׸���
#define ROW 9   //ʹ�ö�ά��������ʾɨ�׵ĵ�ͼ,һ����ʾ����
#define COL 9                   //һ����ʾ�û������ĵ�ͼ,��ͼ��һ��9*9�ľ���
char mine_map[ROW + 2][COL + 2];//��������Ϊ�˷�������ʵ��,����Ϊһ��11*11��
char show_map[ROW + 2][COL + 2];//��ʱ��ͼ��Ч��ΧΪ[1,ROW]��[1,COL]
void Init(char mine_map[ROW + 2][COL + 2],//��������г�ʼ��
	      char show_map[ROW + 2][COL + 2])
{
	memset(mine_map, '0', (ROW + 2)*(COL + 2));//�Ȱ������Ԫ�س�ʼ��Ϊ'0'
	memset(show_map, '*', (ROW + 2)*(COL + 2));//�Ȱ������Ԫ�س�ʼ��Ϊ'*'
    srand(time(0));
        //�������,����һ�����뼶���ʱ��
	int mine_count = MINE_COUNT;
	while (mine_count > 0)//�����ѭ����������õ���,ÿ���������һ����--                             mine_count
	{                     //���ѽ�����µ�show_map��
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
	int not_mine_count = 0;//1.������׸���Ϊ0
	Init(mine_map, show_map);//2.��ʼ����ͼ
	DisplayMap(show_map);    //3.�ȴ�ӡshow_map
	while (1)
	{
		int row = 0;
		int col = 0;
		printf("������Ҫ�����ķ��������(row,col):");//���귶Χ[1,ROW][1,COL]
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > ROW || col <= 0 || col > COL)
		{      //4.���û�����������ж�,��������,��ʾ�û���������
			printf("������������!����������:\n");
			continue;
		}
		if (mine_map[row][col] == '1')//5.�ж�����Ƿ����,�����,��Ϸ������ӡ��
		{
			printf("��Ϸ����!\n");
			DisplayMap(mine_map);
			break;
		}
		++not_mine_count;//6.��û�в���,�ж�����Ƿ�ʤ��
		if (not_mine_count == ROW*COL - MINE_COUNT)
		{//ʤ�����������Ѿ������ķ������ﵽ�˵�ͼ��������-���׸���,����Ϸʤ��
			printf("ɨ�׳ɹ�!\n");
			DisplayMap(mine_map);
			break;
		}
		UpdateShowMap(show_map, mine_map, row, col);
		DisplayMap(show_map);//7.����Ϸû��ʤ��,��ͳ�Ƶ�ǰλ����Χ�׵ĸ���
	}
}//8.��ӡshow_map,�ٻص�������
void Start()
{
			while (1)
			{
				int choice = Menu();
				if (choice == 0)
				{
					printf("�˳���Ϸ!\n");
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