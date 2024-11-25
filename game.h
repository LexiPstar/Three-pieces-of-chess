#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//初始化棋盘
void InitChess_board(char chess_board[ROW][COL], int row, int col);

//打印棋盘
void DisplayChess_board(char chess_board[ROW][COL], int row, int col);

//玩家下棋
void PlayerChess(char chess_board[ROW][COL], int row, int col);

//电脑下棋
//随机下空白位置
void ComputerChess(char chess_board[ROW][COL], int row, int col);

//判断输赢
//1.玩家赢-'*'
//2.电脑赢-'#'
//3.平局-'B'
//4.继续-'C'
char Judgment(char chess_board[ROW][COL], int row, int col);