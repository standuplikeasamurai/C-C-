#pragma once

/*

    井字棋实现（坐标输入 a b ）

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

void menu()
{
    printf("请选择：\n");
    printf("*************************\n");
    printf("******  1.开始游戏 ******\n");
    printf("******  0.结束游戏 ******\n");
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
    printf("玩家走:>\n");
    while (1)
    {
        printf("请输入要下的坐标:>\n");
        scanf("%d%d", &x, &y);
        //判断x,y坐标的合法性
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
                printf("该坐标被占用\n");
        }
        else
        {
            printf("坐标非法，请重新输入!\n:>");
        }
    }
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0, y = 0;
    printf("电脑走:>\n");
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

//返回1 满了，返回0，没满
int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0, j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
                return 0;//没满
        }
    }
    return 1;//满了
}

//返回四种游戏状态 玩家赢--*  电脑赢--#  平局--Q  继续--C
char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)//横三行
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
            return board[i][1];
    }
    for (i = 0; i < row; i++)//竖三列
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
            return board[1][i];
    }
    //两个对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
        return board[1][1];
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
        return board[1][1];

    //判断是否平局
    if (1 == IsFull(board, ROW, COL))
        return 'Q';

    return 'C';
}

void start_game()
{
    char board[ROW][COL] = { 0 };
    char ret = 0;
    init_game(board, ROW, COL);//初始化游戏
    print_board(board, ROW, COL);//打印棋盘

    //开始下棋
    while (1)
    {
        //玩家下棋
        PlayerMove(board, ROW, COL);
        print_board(board, ROW, COL);
        //判断玩家是否赢
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
        //电脑下棋
        ComputerMove(board, ROW, COL);
        print_board(board, ROW, COL);
        //判断玩家是否赢
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
            break;
    }
    if (ret == '*')
        printf("玩家赢！\n");
    else if (ret == '#')
        printf("电脑赢！\n");
    else
        printf("平局! \n");
}

void game()    //开始整个游戏  main函数里面调用此函数即可开始游戏
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("游戏开始\n");
            start_game();
            break;
        case 0:
            printf("游戏结束!\n");
            break;
        default:
            printf("请重新输入!\n");
            break;
        }
    } while (input);
}

