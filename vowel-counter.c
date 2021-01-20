
#include <stdio.h>
#include <string.h>
int main()
{
    int sample[5] = {0}, i;
    char samplechar[5] = {'a', 'e', 'i', 'o', 'u'};
    char name[20];
    scanf("%[^\n]s", name);
    for (i = 0; i < strlen(name); ++i)
    {
        name[i] = tolower((char)name[i]);
        switch (name[i])
        {
        case 'a':
            sample[0]++;
            break;
        case 'e':
            sample[1]++;
            break;
        case 'i':
            sample[2]++;
            break;
        case 'o':
            sample[3]++;
            break;
        case 'u':
            sample[4]++;
            break;
        default:
            continue;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (sample[i] > 0)
        {
            printf("%c is %d times\n", samplechar[i], sample[i]);
        }
    }
}