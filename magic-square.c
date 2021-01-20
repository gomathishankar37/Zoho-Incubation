#include <stdio.h>

//for an input n => Magic Sum is n*((n^2)+1)/2
// 1 is stored at (n/2, n-1) i.e (i,j)
// 2 at (i-1, j+1) i.e (i,j)
// 3 at (i-1, j+1) .. and so on in circulary array
// if already a value => (i+1, j-2)
// if ROW -> -1 and COL -> n => (0,n-2)

void magicSq(int n)
{
    int Matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Matrix[i][j] = 0;
        }
    }

    int i = n / 2;
    int j = n - 1;

    for (int num = 1; num <= n * n;)
    {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }
        else
        {
            if (j == n)
            {
                j = 0;
            }
            if (i < 0)
            {
                i = n - 1;
            }
        }
        if (Matrix[i][j])
        {
            j -= 2;
            i++;
            continue;
        }
        else
        {
            Matrix[i][j] = num++;
        }
        j++;
        i--;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int input;
    printf("\n Enter Input: ");
    scanf("%d ", &input);
    magicSq(input);
    return 0;
}