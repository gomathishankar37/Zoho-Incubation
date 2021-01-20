#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char wish[] = "HAPPY PONGAL";
    for (int i = 0; i < 12; i++)
    {
        system("clear");
        for (int j = 0; j <= i; j++)
        {
            usleep(350000);
            printf("%c\n", wish[j]);
        }
    }
    return 0;
}