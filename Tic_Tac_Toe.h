#pragma once

/*

    ������ʵ�֣��������� a b ��

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

void menu()
{
    printf("��ѡ��\n");
    printf("*************************\n");
    printf("******  1.��ʼ��Ϸ ******\n");
    printf("******  0.������Ϸ ******\n");
    printf("*************************\n");
}

void init_game(char board[ROW][COL], int row, int col)
{
    int i = 0, j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void print_board(char board[ROW][COL], int row, int col)
{
    int i = 0, j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
        }
        printf("\n");

        if (i < row - 1)
        {
            for (j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                    printf("|");
            }
            printf("\n");
        }

    }
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0, y = 0;
    printf("�����:>\n");
    while (1)
    {
        printf("������Ҫ�µ�����:>\n");
        scanf("%d%d", &x, &y);
        //�ж�x,y����ĺϷ���
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
                printf("�����걻ռ��\n");
        }
        else
        {
            printf("����Ƿ�������������!\n:>");
        }
    }
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0, y = 0;
    printf("������:>\n");
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

//����1 ���ˣ�����0��û��
int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0, j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
                return 0;//û��
        }
    }
    return 1;//����
}

//����������Ϸ״̬ ���Ӯ--*  ����Ӯ--#  ƽ��--Q  ����--C
char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)//������
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
            return board[i][1];
    }
    for (i = 0; i < row; i++)//������
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
            return board[1][i];
    }
    //�����Խ���
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
        return board[1][1];
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
        return board[1][1];

    //�ж��Ƿ�ƽ��
    if (1 == IsFull(board, ROW, COL))
        return 'Q';

    return 'C';
}

void start_game()
{
    char board[ROW][COL] = { 0 };
    char ret = 0;
    init_game(board, ROW, COL);//��ʼ����Ϸ
    print_board(board, ROW, COL);//��ӡ����

    //��ʼ����
    while (1)
    {
        //�������
        PlayerMove(board, ROW, COL);
        print_board(board, ROW, COL);
        //�ж�����Ƿ�Ӯ
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
        //��������
        ComputerMove(board, ROW, COL);
        print_board(board, ROW, COL);
        //�ж�����Ƿ�Ӯ
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
    }
    if (ret == '*')
        printf("���Ӯ��\n");
    else if (ret == '#')
        printf("����Ӯ��\n");
    else
        printf("ƽ��! \n");
}

void game()    //��ʼ������Ϸ  main����������ô˺������ɿ�ʼ��Ϸ
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("��Ϸ��ʼ\n");
            start_game();
            break;
        case 0:
            printf("��Ϸ����!\n");
            break;
        default:
            printf("����������!\n");
            break;
        }
    } while (input);
}

