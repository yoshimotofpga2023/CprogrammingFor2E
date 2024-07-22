#include "nitube.h"

/* =================  讖溯・ ====================*/
void nitube_load ( struct NITUBE *pt_nitube )
{
    nitube_load_original( pt_nitube );
    nitube_load_mylist( pt_nitube );
    return;
}

/* =================  讖溯・ ====================*/
void nitube_load_original( struct NITUBE *pt_nitube )
{
    struct MOVIE *start, *index, *end, *pnew;
    int i, number;
    FILE *fp;

    start = (struct MOVIE *)malloc(sizeof(struct MOVIE));
    end = (struct MOVIE *)malloc(sizeof(struct MOVIE));
    pnew= (struct MOVIE *)malloc(sizeof(struct MOVIE));

    start->mylistlink = NULL;
    end->mylistlink = NULL;

    end->next = NULL;
    start->next = end;
    index = start;

    errno_t err;

    err = fopen_s(&fp, ORIGINAL, "r");
    fscanf(fp, "%d", &number);

    for ( i = 0; i < number; i++ )
    {
        pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
        fscanf(fp, "%d", &pnew->date);
        fscanf(fp, "%s", &pnew->title[0]);
        fscanf(fp, "%s", &pnew->channel[0]);
        fscanf(fp, "%s", &pnew->tag[0]);
        pnew->mylistlink = NULL;

        pnew->next = end;
        index->next = pnew;
        index = pnew;
    }
    fclose(fp);
    printf("\n %d 件のデータを取得しました\n", i);

    pt_nitube->start = start;
    pt_nitube->max = number;

    return;
}

/* =================  讖溯・ ====================*/
void nitube_load_mylist( struct NITUBE *pt_nitube )
{
    struct MOVIE *index, *end, *start, *pnew, *hogeindex;
    int i, ii, number, mov;
    char titlename[MN];
    FILE *fp;

    start = (struct MOVIE *)malloc(sizeof(struct MOVIE));
    end = (struct MOVIE *)malloc(sizeof(struct MOVIE));
    pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
    hogeindex = (struct MOVIE *)malloc(sizeof(struct MOVIE));

    i = ii = 0;
    end->next = NULL;
    start->next = end;
    index = start;
    pt_nitube->mylist1.start = start;

    errno_t err;
    err = fopen_s(&fp, MYLIST1, "r");
    fscanf(fp, "%s", &pt_nitube->mylist1.name[0]);
    fscanf(fp, "%d", &number);

    for ( i = 0; i < number; i++ )
    {
        fscanf(fp, "%d", &mov);
        pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
        hogeindex = pt_nitube->start;

        ii = 0;

        while ( ii < mov )
        {
            hogeindex = hogeindex -> next;
            ii++;
        }

        pnew->mylistlink = hogeindex;
        pnew->next = end;
        index->next = pnew;
        index = pnew;
    }
    fclose(fp);


    index = pt_nitube->mylist1.start;
    for (i = 0; i < number; i++)
    {
        index = index->next;
        printf("%s \n", index->mylistlink->channel);
    }

    pt_nitube->mylist1.max = number;
    printf("\n %d 件のマイリスト %s を読み込みました\n", number, pt_nitube->mylist1.name);


    return;
}