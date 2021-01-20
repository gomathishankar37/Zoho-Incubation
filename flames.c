#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    system("clear");
    printf("\tWelcome to F.L.A.M.E.S!!");

    int userLen1, userLen2, totalLen, common = 0, l = 0, i, j, k, change, input;
    char user1[20], user2[20], personA[20];

    printf("\n\n\tUser 1 Name: ");
    scanf("%s", user1);
    strcpy(personA, user1);
    printf("\n\tUser 2 Name: ");
    scanf("%s", user2);

    userLen1 = strlen(user1);
    userLen2 = strlen(user2);
    totalLen = userLen1 + userLen2;
    for (i = 0; i < userLen1; i++)
    {
        for (j = 0; j < userLen2; j++)
        {
            if (user1[i] == user2[j])
            {
                common++;
                l = 0;
                for (k = 0; k <= userLen1; k++)
                {
                    if (k == j)
                    {
                        continue;
                    }
                    else
                    {
                        user1[l] = user1[k];
                        l++;
                    }
                }
                break;
            }
        }
    }

    system("clear");
    printf("\n\tThe Destiny Says...!\n\n\t");
    usleep(350000);

    printf("\n\n");
    change = totalLen - 2 * common;
    if (change == 3 || change == 5 || change == 14 || change == 16 || change == 18 || change == 21 || change == 23)
    {
        printf("%s and %s are Friends\n", personA, user2);
    }
    else if (change == 10 || change == 19)
    {
        printf("%s and %s are in Love\n", personA, user2);
    }
    else if (change == 8 || change == 12 || change == 13 || change == 17 || change == 28)
    {
        printf("%s and %s are Affectionate to each others\n", personA, user2);
    }
    else if (change == 6 || change == 11 || change == 15 || change == 26)
    {
        printf("%s and %s set to Marry\n", personA, user2);
    }
    else if (change == 2 || change == 4 || change == 7 || change == 9 || change == 20 || change == 22 || change == 24 || change == 25)
    {
        printf("%s and %s are Enemies\n", personA, user2);
    }
    else if (change == 1 || change == 27)
    {
        printf("%s and %s are like Siblings\n", personA, user2);
    }
    printf("\n\nTo continue Enter 1 else any number:: ");
    scanf("%d", &input);
    if (input == 1)
    {
        main();
    }
    else
    {
        printf("\n\nThank You\n\n");
    }
    return 0;
}