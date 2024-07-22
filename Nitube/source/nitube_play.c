#include "nitube.h"

/* =================  繧｢繝ｫ繝舌Β蜀咲函繝｡繧､繝ｳ蜃ｦ逅・ =========================*/
void nitube_play( struct NITUBE *pt_nitube )
{
    int number;
    nitube_play_menu();
    number = my_scanf_integer();

    switch ( number )
    {
        case 1:
            nitube_makebuffer_mylist( pt_nitube );
            printf("play mylist\n");
            nitube_playing( pt_nitube, 1);
            break;

        case 2:
        case 3:
        case 4:
        case 5:
            nitube_makebuffer_original( pt_nitube, number );
            nitube_playing( pt_nitube, 2 );
        default:
            break;
    }
    return;
}

/*==============    繝励Ξ繧､繝｡繝九Η繝ｼ陦ｨ遉ｺ讖溯・    =================*/
void nitube_play_menu()
{
    printf("=========   Play Menu   =========== \n");
    printf("1... Play Mylist \n");
    printf("2... Play MOVIE LIST \n");
    printf("3... Play Select Date from MOVIELIST\n");
    printf("4... Play select Channel from MOVIELIST\n");
    printf("5... Play select Tag from MOVIELIST \n");
    printf("0... Back Main Menu\n");

    printf("番号を選んでください。> ");
    return;
}

/* =================  蜀咲函荳ｭ繝｡繝九Η繝ｼ陦ｨ遉ｺ讖溯・  =========================*/
void nitube_playing_menu()
{
    printf(">> Playing Menu<<\n");
    printf(">> 0:STOP, 1:BACK, 2:NEXT << \n");
    return;
}

/* =================  繧ｪ繝ｪ繧ｸ繝翫Ν繧｢繝ｫ繝舌Β蜀咲函繝舌ャ繝輔ぃ譬ｼ邏肴ｩ溯・  =========================*/
void nitube_makebuffer_original( struct NITUBE *pt_nitube, int rule)
{
    struct MOVIE *index;
    int number, i, j, k;
    char cname[MN], tname[MN];
    index = (struct MOVIE *)malloc(sizeof(struct MOVIE));

    index = pt_nitube->start->next;
    printf("start > %p\n", index);

    j =0; k = 0;

    for ( int ii = 0; ii < pt_nitube->max; ii++ )
    {
        pt_nitube->playbuffer.list[ii] = (struct MOVIE *)malloc(sizeof(struct MOVIE));

    }

    if ( rule == 2 )
    {
        while ( j < pt_nitube->max )
        {
            pt_nitube->playbuffer.list[j] = index;

            printf("index > %p\n", index);
            index = index->next;
            printf("list> %p\n", pt_nitube->playbuffer.list[j]);
            j++; 
        }
        pt_nitube->playbuffer.max = j;
    } else 
    {
        if ( rule == 3 )
        {
            printf("動画投稿日を入力してください > ");
            number = my_scanf_integer();
            printf("\n");

            while ( j < pt_nitube->max )
            {
                if ( number == index->date)
                {
                    pt_nitube->playbuffer.list[k] = index;
                    k++;
                }
                index = index->next;
                j++;
            }
            pt_nitube->playbuffer.max = k;
        }  else if ( rule == 4 )
        {
            printf("チャンネル名を入力してください > ");
            scanf("%s", &cname[0]);
            printf("\n");

            while ( j < pt_nitube->max )
            {
                number = strcmpare(cname, index->channel );
                if ( number == 1 )
                {
                    pt_nitube->playbuffer.list[k] = index;
                    k++;
                }
                index = index->next;
                j++;
            }
            pt_nitube->playbuffer.max = k;
        } else if ( rule == 5 )
        {
            printf("タグ名を入力してください > ");
            scanf("%s", &tname[0]);
            printf("\n");
            while ( j < pt_nitube->max )
            {
                number = strcmpare(tname, index->tag );
                if ( number == 1 )
                {
                    pt_nitube->playbuffer.list[k] = index;
                    k++;
                }
                index = index->next;
                j++;
            }
            pt_nitube->playbuffer.max = k;
        }
    }
    return;
}

/* =================  繝励Ξ繧､繝ｪ繧ｹ繝医い繝ｫ繝舌Β縺ｮ蜀咲函繝舌ャ繝輔ぃ譬ｼ邏肴ｩ溯・  =========================*/
void nitube_makebuffer_mylist( struct NITUBE *pt_nitube )
{
    struct MOVIE *index;
    int number, i, j, k;
    char cname[MN], tname[MN];
    index = (struct MOVIE *)malloc(sizeof(struct MOVIE));

    index = pt_nitube->mylist1.start;
    number = pt_nitube->mylist1.max;
    printf("%d\n", number);

    for ( i = 0; i < number; i++ )
    {
        index = index->next;
        pt_nitube->playbuffer.list[i] = index->mylistlink;
    }

    pt_nitube->playbuffer.max = number;
    return;
}

/* =================  蜀咲函繝舌ャ繝輔ぃ蜀咲函讖溯・  =========================*/
void nitube_playing( struct NITUBE *pt_nitube, int type)
{
    int i, number, cmd;
    struct MOVIE *index;

    index = pt_nitube->playbuffer.list[0];
    i = 0;

    cmd = 1;

    while ( cmd != 0 )
    {
        printf("Now Playing : %s \n", index->title );
        nitube_playing_menu();
        printf(" >> "); number = my_scanf_integer();

        if ( number == 0 )
        {
            cmd = 0;
        } else if ( number == 1 )
        {
            i--;
            index = pt_nitube->playbuffer.list[i];
            if ( i < 0 )
            {
                cmd = 0;
                printf("動画が存在しません。終了します\n");
            }
        } else if ( number == 2 )
        {
            i++;
            index = pt_nitube->playbuffer.list[i];
            if ( i >= pt_nitube->playbuffer.max )
            {
                cmd = 0;
                printf("動画が存在しません。終了します\n");
            }
        }
    }

    return;
}