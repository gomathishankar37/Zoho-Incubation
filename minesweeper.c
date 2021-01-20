#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int bombCount;
int size;
int Board[10][10];
int Track[10][10];
int i, j;
int moveCount = 0;
int HighScore = 0;
int MarkCount = 0;

void welcome();
void instructions();
void levelSelect();
void buildBoard(int size);
void displayBoard(int size);
void setBomb(int size);
void counter(int size);
bool isBomb(int value);
void counterUtility(int x, int y, int size);
void play();
void moveChecker(int x, int y, int size);
bool isWin(int size);
bool boundaryCheck(int x, int y, int size);

int main()
{
    system("clear");
    welcome();
}

void welcome()
{
    printf("\n\t\t\t\t**********************  WELCOME TO MINESWEEPER  *************************");
    levelSelect();
}

void levelSelect()
{
    int level;

    if (HighScore == 0)
    {
        HighScore = moveCount;
    }
    if (moveCount <= HighScore)
    {
        HighScore = moveCount;
    }

    moveCount = 0;
    MarkCount = 0;
    printf("\n\n\n\t\t\t\t\t\t\tMENU ");
    printf("\n\n\t\t\t\t\t\t1.Noob       (8 X 8)");
    printf("\n\t\t\t\t\t\t2.Pro        (10 X 10)");
    printf("\n\t\t\t\t\t\t3.Exit        ");
    printf("\n\t\t Select Option: ");
    scanf("%d", &level);
    if (level == 1)
    {
        size = 8;
        buildBoard(8);
    }
    else if (level == 2)
    {
        size = 10;
        buildBoard(10);
    }
    else if (level == 3)
    {
        exit(0);
    }
    else
    {
        system("clear");
        levelSelect();
    }
}

void displayBoard(int size)
{

    usleep(5000000);
    system("clear");
    printf("\n\n\t\t\t\t Your Score: %d\t\t\t\t Mark Count: %d \t\t\t\t High Score: %d", moveCount, MarkCount, HighScore);

    printf("\n\n\t\t\t\t\t");
    for (int i = 0; i < size; i++)
    {
        printf("     %d", i + 1);
    }
    printf("\n\n\t\t\t\t");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == 0)
            {
                printf("| %d |>  ", i + 1);
            }
            printf("  %d   ", Board[i][j]);
        }
        printf("\n\n\t\t\t\t");
    }
}

bool isBomb(int value)
{
    if (value == -1)
    {
        return true;
    }
    return false;
}

void counterUtility(int i, int j, int size)
{
    if (i >= 0 && i < size && j >= 0 && j < size && !isBomb(Track[i][j]))
    {
        Track[i][j] += 1;
    }
}

void counter(int size)
{
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (isBomb(Track[i][j]))
            {

                counterUtility(i, j + 1, size);
                counterUtility(i, j - 1, size);

                counterUtility(i + 1, j + 1, size);
                counterUtility(i + 1, j, size);
                counterUtility(i + 1, j - 1, size);

                counterUtility(i - 1, j - 1, size);
                counterUtility(i - 1, j, size);
                counterUtility(i - 1, j + 1, size);
            }
        }
    }
}

void setBomb(int size)
{
    srand(time(0));
    int temp;
    bombCount = size;
    temp = bombCount;
    while (temp)
    {
        i = rand() % 8;
        j = rand() % 8;
        if (Track[i][j] != -1)
        {
            Track[i][j] = -1;
            temp--;
        }
    }
    counter(size);
}

void buildBoard(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Board[i][j] = 9;
            Track[i][j] = 0;
        }
    }
    setBomb(size);
    instructions();
    displayBoard(size);
    play();
}

bool boundaryCheck(int i, int j, int size)
{
    if (i >= 0 && i < size && j >= 0 && j < size && !isBomb(Track[i][j]))
    {
        return true;
    }
    return false;
}

void moveChecker(int i, int j, int size)
{
    Board[i][j] = Track[i][j];

    if (boundaryCheck(i - 1, j, size))
    {
        Board[i - 1][j] = Track[i - 1][j];
    }
    if (boundaryCheck(i, j + 1, size))
    {
        Board[i][j + 1] = Track[i][j + 1];
    }
    if (boundaryCheck(i + 1, j, size))
    {
        Board[i + 1][j] = Track[i + 1][j];
    }
    if (boundaryCheck(i, j - 1, size))
    {
        Board[i][j - 1] = Track[i][j - 1];
    }
    if (boundaryCheck(i - 1, j - 1, size))
    {
        Board[i - 1][j - 1] = Track[i - 1][j - 1];
    }
    if (boundaryCheck(i - 1, j + 1, size))
    {
        Board[i - 1][j + 1] = Track[i - 1][j + 1];
    }
    if (boundaryCheck(i + 1, j - 1, size))
    {
        Board[i + 1][j - 1] = Track[i + 1][j - 1];
    }
    if (boundaryCheck(i + 1, j + 1, size))
    {
        Board[i + 1][j + 1] = Track[i + 1][j + 1];
    }
}

bool isWin(int size)
{
    int wintemp = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (Board[i][j] == -2 && Track[i][j] == -1)
            {
                wintemp = wintemp + 1;
            }
        }
    }
    printf("\n\t\t%d", wintemp);
    if (wintemp == bombCount)
    {
        return true;
    }
    return false;
}

void play()
{
    int x, y;
    char out = 'n';
    do
    {
        int choice;
        printf("\n\t\t Enter (1) to click or (2) to mark : ");
        scanf("%d", &choice);
        printf("\n\t\tEnter x :");
        scanf("%d", &x);
        printf("\n\t\tEnter y :");
        scanf("%d", &y);
        if (choice == 2)
        {
            Board[x - 1][y - 1] = -2;
            MarkCount++;
            moveCount++;
            displayBoard(size);
            printf("\n\n%d\n", bombCount);
            if (MarkCount == bombCount)
            {
                if (isWin(size))
                {
                    out = 'y';
                    printf("\n\n\t\tYou have WON the GAME! 😎");
                    levelSelect();
                }
                else
                {
                    printf("\n\t\t You lost the game");
                    printf("\n\t\tYou have exhausted your Mine Markers, GAME OVER!! 😔");
                    levelSelect();
                }
            }
        }
        else if (choice == 1)
        {
            if (isBomb(Track[x - 1][y - 1]))
            {
                out = 'y';
                printf("\n\t\tOops! You stepped on a Mine 😢");
                levelSelect();
            }
            else
            {
                moveChecker(x - 1, y - 1, size);
                moveCount++;
                displayBoard(size);
            }
        }
        else
        {
            printf("\n\t\t\a\a\aInvalid input");
        }

    } while (out != 'y');
}

void instructions()
{
    system("clear");
    printf("\n\n\n\t\t\t\t\t\t\tINSTRUCTIONS ");
    printf("\n\n\t\t > You are presented with a board of squares, each with a cover. Some squares contain mines (bombs) under the covers\n\t\t If you open a square containing a bomb, you loose. If you open all squares without bombs, you win.");
    printf("\n\n\t\t> Opening a square which doesn't have a bomb reveals the number of neighboring squares contain bombs\n\t\t Use this information plus some guess work to avoid the bombs.");
    printf("\n\n\t\t> A squares 'neighbors' are the squares adjacent above, below, left, right, and all 4 diagonals. Squares on the sides of the board or in a corner have fewer neighbors.\n\t\t The board does not wrap around the edges.");
    printf("\n\n\t\t> If you open a square with 0 neighboring bombs, all its neighbors will automatically open. This can cause a large area to automatically open.");
    printf("\n\n\t\t> To remove a bomb marker from a square, point at it and right-click again.");
    printf("\n\n\t\t> If you mark a bomb incorrectly, you will have to correct the mistake before you can win. Incorrect bomb marking doesn't kill you, but it can easily lead to mistakes which do.");
    printf("\n\n\t\t> You don't have to mark all bombs to win; you just need to open all non-bomb squares.");
}