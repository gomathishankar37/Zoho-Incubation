#include <stdio.h>

float babylonian(int n)
{
    float param = 0.000001; //for accuracy
    float temp = n;
    float dummy = 1;
    while (temp - dummy > param)
    {
        temp = (temp + dummy) / 2;
        dummy = n / temp;
    }
    return temp;
}

int main()
{
    int input;
    printf("\n\t Enter Number: ");
    scanf("%d ", &input);
    float result = babylonian(input);
    printf("%f", result);
    return 0;
}