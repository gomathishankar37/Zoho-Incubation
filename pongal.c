#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char wish[] = "HAPPY PONGAL";
    for (int i = 0; i < 12; i++)
    {
        usleep(350000);
        printf("%c \n", wish[i]);
    }
}