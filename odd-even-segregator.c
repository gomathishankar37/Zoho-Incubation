#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int input, i, j;
    scanf("%d", &input);
    int array[input], odd[input], even[input];
    int oddPos = 0, evenPos = 0;
    for (i = 0; i < input; ++i)
    {
        scanf("%d", &array[i]);
        if (array[i] % 2)
        {
            odd[oddPos++] = array[i];
        }
        else
        {
            even[evenPos++] = array[i];
        }
    }
    printArray(odd, oddPos);
    printArray(even, evenPos);
    return 0;
}