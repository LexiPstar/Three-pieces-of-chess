#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//��ʼ������
void InitChess_board(char chess_board[ROW][COL], int row, int col);

//��ӡ����
void DisplayChess_board(char chess_board[ROW][COL], int row, int col);

//�������
void PlayerChess(char chess_board[ROW][COL], int row, int col);

//��������
//����¿հ�λ��
void ComputerChess(char chess_board[ROW][COL], int row, int col);

//�ж���Ӯ
//1.���Ӯ-'*'
//2.����Ӯ-'#'
//3.ƽ��-'B'
//4.����-'C'
char Judgment(char chess_board[ROW][COL], int row, int col);