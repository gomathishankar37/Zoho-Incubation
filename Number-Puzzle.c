#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <stdbool.h>
#define LIMIT 4

int board[6][6], i, j, temp, flag, moves, row, col;

void welcome();
int chooseLevel();
void shuffle(int level);
void swapper(int r1, int c1, int r2, int c2);
void display();
int makePlay(int rowval, int colVal, int play);
bool isResult();

int main()
{
    int level, keyPress;
    bool gameOver;
    welcome();
MENU:
    level = chooseLevel();
    switch (level)
    {
    case 1:
        printf("\n\tLooks like Your a Beginner!\n");
        gameOver = false;
        break;
    case 2:
        printf("\n\tWhoa! Hope You could Crack me!\n");
        gameOver = false;
        break;
    case 3:
        printf("\n\tLet's See how much you got Master!\n");
        gameOver = false;
        break;
    default:
        printf("\n\tSorry Mate! INVALID CHOICE");
        system("clear");
        goto MENU;
    }
    while (!gameOver)
    {
        shuffle(level);
        row = 4;
        col = 4;
        moves = 0;
        shuffle(level);
        display();
        while (true)
        {
            getch();
            keyPress = getch();
            switch (keyPress)
            {
            case 72:
                system("clear");
                row = makePlay(row - 1, col, 1);
                display();
                break;
            case 80:
                system("clear");
                row = makePlay(row + 1, col, 2);
                display();
                break;
            case 75:
                system("clear");
                col = makePlay(row, col - 1, 3);
                display();
                break;
            case 77:
                system("clear");
                col = makePlay(row, col + 1, 4);
                display();
                break;
            case 88:
                printf("\n\t See you! Sherlock!!");
                exit(0);
            }
            if (isResult())
            {
                system("clear");
                display();
                printf("\t<<<<<<<<<<<<< You Have Won the GAME >>>>>>>>>>>>>>>");
                gameOver = true;
                break;
            }
        }
    }
    return 0;
}

//welcome UI
void welcome()
{
    system("clear");
    char greet[40] = "Hi there Sherlock!";
    for (i = 0; i < strlen(greet); i++)
    {
        printf("%c", greet[i]);
        usleep(3500000);
    }
    printf("\n\tWelcome to PUZZLE!\a\n");
}

//level Selector
int chooseLevel()
{
    int level;
    printf("\n\tChoose your LEVEL ");
    printf("\n\t(1) NOOB\n\t(2) PRO\n\t(3) MASTER\n\n\tYour Choice: \a");
    scanf("%d", &level);
}

//shuffle Board
void shuffle(int level)
{
    for (i = 1, temp = 1; i <= LIMIT; i++)
    {
        for (j = 1; j <= LIMIT; j++)
        {
            board[i][j] = temp++;
        }
    }
    int param = level * 2 + 1;
    while (param--)
    {
        int tempCol = rand() % 5;
        int tempRow = rand() % 5;
        if (tempCol != tempRow)
        {
            swapper(tempRow, tempCol, tempCol, tempRow);
        }
    }
    display();
}

//Coordinate Swaps utility
void swapper(int r1, int c1, int r2, int c2)
{
    int dummy = board[r1][c1];
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = dummy;
}

//Playing Utility
int makePlay(int rowVal, int colVal, int dir)
{
    int rowcol;
    switch (dir)
    {
    case 1:
        if (rowVal > 0)
        {
            moves++;
            rowcol = rowVal;
            swapper(rowVal + 1, colVal, rowVal, colVal);
        }
        else
        {
            rowcol = rowVal + 1;
            system("beep");
        }
        break;
    case 2:
        if (rowVal <= 4)
        {
            moves++;
            rowcol = rowVal;
            swapper(rowVal - 1, colVal, rowVal, colVal);
        }
        else
        {
            rowcol = rowVal - 1;
            system("beep");
        }
        break;
    case 3:
        if (colVal > 0)
        {
            moves++;
            rowcol = colVal;
            swapper(rowVal, colVal + 1, rowVal, colVal);
        }
        else
        {
            rowcol = colVal + 1;
            system("beep");
        }
        break;
    case 4:
        if (colVal <= 4)
        {
            moves++;
            rowcol = colVal;
            swapper(rowVal, colVal - 1, rowVal, colVal);
        }
        else
        {
            rowcol = colVal - 1;
            system("beep");
        }
        break;
    }
    return rowcol;
}

//Result Checker
bool isResult()
{
    for (i = 1, flag = 1; i <= 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            if (board[i][j] != flag++)
            {
                return false;
            }
        }
    }
    return true;
}

//display utility
void display()
{
    printf("\n\n\t Moves: %d\n", moves);

    for (int i = 1; i <= LIMIT; i++)
    {
        for (int j = 1; j <= LIMIT; j++)
        {
            printf("\xB2 %3d \xB2", board[i][j]);
        }
        printf("\n");
    }

    printf("\n\tPRESS Arrow Keys to Play\n\t Press [X] to exit: ");
}