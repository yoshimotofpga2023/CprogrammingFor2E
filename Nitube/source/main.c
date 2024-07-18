#include "nitube.h"

int main(void)
{
    struct MOVIE *movie;
    struct NITUBE *nitube;
    nitube = (struct NITUBE*)malloc(sizeof(struct NITUBE));

    int num;

    nitube_load(nitube);

    num = 1;
    while (num != 0)
    {
        nitube_main_menu();
        num = my_scanf_integer();
        switch(num)
        {
            case 1:
                nitube_play(nitube); break;
            case 2:
                nitube_edit_original(nitube); 
                break;
            case 3:
                nitube_edit_mylist(nitube);
                break;
            case 4:
                nitube_save(nitube); break;
            case 0:
                printf("プログラムを終了します\n");
                break;
            default: break;
        }
    }
    return 0;
}

void nitube_main_menu()
{
    printf("=========== MAIN MENU =============\n");
    printf("1... Play MOVIE \n");
    printf("2... Edit MOVIE LIST \n");
    printf("3... Edit My MOVIE LIST\n");
    printf("4... Save data\n");
    printf("0... Exit \n");
    printf("===================================\n");
    printf("番号を選択してください > ");
    return;
}

/* ========   豎守畑髢｢謨ｰ     =====*/

int my_scanf_integer()
{
    int i, chk;
    char buffer[100];

    while(1) {
        scanf("%99s", buffer); i = 0; chk = 1;
        while(buffer[i] != '\0')
        {
            if (buffer[i] < '0' || '9' < buffer[i]) chk = 0;
            i++;
        }
        if (chk) return atoi(buffer);

        printf("整数値を入力してください。\n");
    }
    return -1;
}

int strcmpare(char word1[MN], char word2[MN])
{
    int i, j, k;
    int cmp;
    cmp = -1;

    char tmp1[MN], tmp2[MN];

    j = 0;
    while( word1[j] != '\0')
    {
        j++;
    } 

    k = 0;
    while ( word2[k] != '\0')
    {
        k++;
    }

    if ( j != k ) return -1;

    i = 0;
    while ( word1[i] != '\0' )
    {
        if ( word1[i] == word2[i] )
        {
            cmp = 1;
        } else 
        {
            cmp = -1;
        }
        i++;
    }
    return cmp;

}

int my_strcmp(char word1[MN], char word2[MN])
{
    int i = 0, j = 0;

    while ( word1[i] != '\0' )
    {
        i++;
    }

    while ( word2[j] != '\0')
    {
        j++;
    }

    if ( i > j )
    {
        return 1;
    } else if ( i < j )
    {
        return 2;
    } else if ( i == j )
    {
        return 3;
    }

    return -1;

}