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
	//初始化棋盘的函数
	InitChess_board(chess_board, ROW, COL);
	DisplayChess_board(chess_board, ROW, COL);
	printf("\n");

	//开始下棋
	while (1) 
	{
		PlayerChess(chess_board,ROW,COL);
		//判断输赢
		ret = Judgment(chess_board, ROW, COL);
		if (ret != 'C') 
		{
			break;
		}
		printf("\n");
		DisplayChess_board(chess_board, ROW, COL);
		printf("\n");

		ComputerChess(chess_board, ROW, COL);
		//判断输赢
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
		printf("玩家赢\n");
	}
	else if (ret == '#') 		
	{
		printf("电脑赢\n");
	}
	else
		printf("平局\n");
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
		printf("请选择:>");
		scanf("%d", &input);
		printf("\n");
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default :
			printf("选择1或者0\n");
			break;
		}
		printf("\n");
	} 
	while (input);

	return 0;
}