#include <stdio.h>
#include <string.h>

int main()
{
    system("clear");
    char input[6][4] = {"11", "10", "1", "22", "100", "33"};
    char temp[4];

    for (int i = 0; i < 5; i++)
    {
        int dummy = i;
        for (int j = i + 1; j < 6; j++)
        {
            if (strlen(input[dummy]) > strlen(input[j]) || (strlen(input[dummy]) == strlen(input[j]) && strcmp(input[j], input[dummy]) < 0))
            {
                dummy = j;
            }
        }
        strcpy(temp, input[i]);
        strcpy(input[i], input[dummy]);
        strcpy(input[dummy], temp);
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%s ", input[i]);
    }

    printf("\n");
    return 0;
}