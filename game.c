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

//void DisplayChess_board(char chess_board[ROW][COL], int row, int col)//����ָ�����̹����Ϣ
//{
//	int i = 0;
//	for (i = 0; i < row; i++) {
//		//��ӡ����
//		printf(" %c | %c | %c \n", chess_board[i][0], chess_board[i][1], chess_board[i][2]);
//		if (i < row - 1) {
//			printf("---|---|---\n");//��ӡ�ָ���
//		}
//	}
//}

void DisplayChess_board(char chess_board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++) 
	{
		//��ӡ����
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
		//��ӡ�ָ���Ϣ
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
	printf("�������:>\n");
	printf("����������:>");
scan:	
	scanf("%d %d", &x, &y);
	//���귶Χ�Ϸ��ж�
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
				printf("���걻ռ�ã����������룡\n");
				goto scan;
			}
		}
		else
		{
			printf("����Ƿ����������������꣡\n");
			goto scan;
		}
	}
}

void ComputerChess(char chess_board[ROW][COL], int row, int col)
{
	printf("��������:>\n");
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


//���˷���1
//��������0
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
	//��
	int i = 0;
	for (i = 0; i < row; i++) 
	{
		if (chess_board[i][0] == chess_board[i][1] && chess_board[i][1] == chess_board[i][2] && chess_board[i][1] != ' ') 
		{
			return chess_board[i][1];
		}
	}
	//��
	int j = 0;
	for (j = 0; j < col; j++) 
	{
		if (chess_board[0][j] == chess_board[1][j] && chess_board[1][j] == chess_board[2][j] && chess_board[1][j] != ' ') 
		{
			return chess_board[1][j];
		}
	}
	//�Խ���	
	if (chess_board[0][0] == chess_board[1][1] && chess_board[1][1] == chess_board[2][2] && chess_board[1][1] != ' ') 
	{
		return chess_board[1][1];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[1][1] == chess_board[2][0] && chess_board[1][1] != ' ') 
	{
		return chess_board[1][1];
	}
	//ƽ��
	if (Is_Full(chess_board, row, col)) 
	{
		return 'B';
	}
	//��Ϸ����
	return 'C';
}