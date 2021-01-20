#include <stdio.h>

void sieve(int n)
{
    int temp[n];
    for (int i = 1; i <= n; i++)
    {
        temp[i - 1] = 1;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (temp[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                temp[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (temp[i])
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int input;
    printf("\n\t Enter Number: ");
    scanf("%d ", &input);
    sieve(input);
    return 0;
}