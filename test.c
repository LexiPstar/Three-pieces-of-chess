#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~ 1.play  0.exit ~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int game()
{
	char ret = 0;
	char chess_board[ROW][COL] = { 0 };
	//��ʼ�����̵ĺ���
	InitChess_board(chess_board, ROW, COL);
	DisplayChess_board(chess_board, ROW, COL);
	printf("\n");

	//��ʼ����
	while (1) 
	{
		PlayerChess(chess_board,ROW,COL);
		//�ж���Ӯ
		ret = Judgment(chess_board, ROW, COL);
		if (ret != 'C') 
		{
			break;
		}
		printf("\n");
		DisplayChess_board(chess_board, ROW, COL);
		printf("\n");

		ComputerChess(chess_board, ROW, COL);
		//�ж���Ӯ
		ret = Judgment(chess_board, ROW, COL);
		if (ret != 'C') 
		{
			break;
		}
		printf("\n");
		DisplayChess_board(chess_board, ROW, COL);
		printf("\n");

	}
	if (ret == '*') 
	{
		printf("\n");
		printf("���Ӯ\n");
	}
	else if (ret == '#') 		
	{
		printf("����Ӯ\n");
	}
	else
		printf("ƽ��\n");
	DisplayChess_board(chess_board, ROW, COL);
	printf("\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do 
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		printf("\n");
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default :
			printf("ѡ��1����0\n");
			break;
		}
		printf("\n");
	} 
	while (input);

	return 0;
}