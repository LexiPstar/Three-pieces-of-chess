#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitChess_board(char chess_board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) 
		{
			chess_board[i][j] = ' ';
		}
	}
}

//void DisplayChess_board(char chess_board[ROW][COL], int row, int col)//不能指定棋盘规格信息
//{
//	int i = 0;
//	for (i = 0; i < row; i++) {
//		//打印数据
//		printf(" %c | %c | %c \n", chess_board[i][0], chess_board[i][1], chess_board[i][2]);
//		if (i < row - 1) {
//			printf("---|---|---\n");//打印分隔符
//		}
//	}
//}

void DisplayChess_board(char chess_board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++) 
	{
		//打印数据
		int j = 0;
		for (j = 0; j < col; j++) 
		{
			printf(" %c ", chess_board[i][j]);
			if (j < col - 1) 
			{
				printf("|");
			}
		}
		printf("\n");
		//打印分割信息
		if (i < row - 1) 
		{
			int j = 0;
			for (j = 0; j < col; j++) 
			{
				printf("---");
				if (j < col - 1) 
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerChess(char chess_board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋:>\n");
	printf("请输入坐标:>");
scan:	
	scanf("%d %d", &x, &y);
	//坐标范围合法判断
	while(1)
	{ 
		if (x >= 1 && x <= row && y >= 1 && y <= col) 
		{
			if (chess_board[x - 1][y - 1] == ' ') 
			{
				chess_board[x - 1][y - 1] = '*';
				break;
			}
			else
			{ 
				printf("坐标被占用，请重新输入！\n");
				goto scan;
			}
		}
		else
		{
			printf("坐标非法，请重新输入坐标！\n");
			goto scan;
		}
	}
}

void ComputerChess(char chess_board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");
	printf("\n");

	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//0-2
		y = rand() % col;//0-2
		if (chess_board[x][y] == ' ') 
		{
			chess_board[x][y] = '#';
			break;
		}
	}	
}


//满了返回1
//不满返回0
int Is_Full(char chess_board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) 
	{
		for (j = 0; j < col; j++) 
		{
			if (chess_board[i][j] == ' ') 
			{
				return 0;
			}
		}
	}
	return 1;
}

char Judgment(char chess_board[ROW][COL], int row, int col)
{
	//行
	int i = 0;
	for (i = 0; i < row; i++) 
	{
		if (chess_board[i][0] == chess_board[i][1] && chess_board[i][1] == chess_board[i][2] && chess_board[i][1] != ' ') 
		{
			return chess_board[i][1];
		}
	}
	//列
	int j = 0;
	for (j = 0; j < col; j++) 
	{
		if (chess_board[0][j] == chess_board[1][j] && chess_board[1][j] == chess_board[2][j] && chess_board[1][j] != ' ') 
		{
			return chess_board[1][j];
		}
	}
	//对角线	
	if (chess_board[0][0] == chess_board[1][1] && chess_board[1][1] == chess_board[2][2] && chess_board[1][1] != ' ') 
	{
		return chess_board[1][1];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[1][1] == chess_board[2][0] && chess_board[1][1] != ' ') 
	{
		return chess_board[1][1];
	}
	//平局
	if (Is_Full(chess_board, row, col)) 
	{
		return 'B';
	}
	//游戏继续
	return 'C';
}