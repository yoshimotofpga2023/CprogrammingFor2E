#include "nitube.h"

/*======================= 蜍慕判豎守畑讖溯・ ===============================*/
int nitube_movie_count_index( struct MOVIE *start, struct MOVIE *count)
{
    struct MOVIE *index;
    int cnt = 0;
    index = start->next;

    while ( index != count )
    {
        cnt++;
        index = index->next;
    }
    return cnt;
}

/*======================= 繧｢繝ｫ繝舌Β繝ｪ繧ｹ繝郁｡ｨ遉ｺ讖溯・ ===============================*/
void nitube_movie_print( struct MOVIE *start, int type, int rule)
{
    struct MOVIE *index;
    index = start->next;

    if ( type == 1 )
    {
        if ( rule == 1 )
        {
            while ( index->next != NULL )
            {
                printf("%d %s %s %s\n", index->date, index->title, index->channel, index->tag);
                index = index->next;
            }
        } else
        {
            while ( index->next != NULL )
            {
                printf("%d %s %s %s \n", index->mylistlink->date, index->mylistlink->title, index->mylistlink->channel, index->mylistlink->tag);
                index = index->next;
            }
        }
    } else if ( type == 2 )
    {
        while ( index->next != NULL )
        {
            printf("%d %s %s %s \n", index->mylistlink->date, index->mylistlink->title, index->mylistlink->channel, index->mylistlink->tag);
            index = index->next;
        }
    }
    return;
}

/*======================= 繧｢繝ｫ繝舌Β驕ｸ謚樊ｩ溯・ ===============================*/
struct MOVIE *nitube_movie_select( struct MOVIE *start, int type)
{
    struct MOVIE *index, *pnew, *pstart, *pend, *pmovie;
    int number, rule, cmp, i, j;
    char title[MN], channel[MN], tag[MN];
    i = 0; j = 0; cmp = 0;

    pstart = (struct MOVIE *)malloc(sizeof(struct MOVIE));
    pend = (struct MOVIE *)malloc(sizeof(struct MOVIE));

    pend->next = NULL;
    pstart->next = pend;

    nitube_movie_select_menu();
    printf(" > ");
    rule = my_scanf_integer();

    if ( type == 1 )
    {
        switch( rule )
        {
            case 1:
                nitube_movie_print(start, type, rule);
                printf("番号を選択 > ");
                number = my_scanf_integer();
                number--;
                printf("\n");

                index = start->next;
                i = 0;
                while ( i < number )
                {
                    index = index->next;
                    i++;
                }
                pmovie = index;
                break;

            case 2:
                index = start->next;
                printf("投稿日を選択 > ");
                number = my_scanf_integer();
                printf("\n");

                while ( index->next != NULL )
                {
                    if ( number == index->date )
                    {
                        pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
                        pnew->next = pstart->next;
                        pstart->next = pnew;
                        pnew->mylistlink = index;
                    }
                    index = index->next;
                }

                nitube_movie_print(pstart, type, rule);
                printf("番号を選択 > ");
                number = my_scanf_integer();
                number--;
                printf("\n");

                i = 0;
                index = pstart->next;
                while ( i < number )
                {
                    index = index->next;
                    i++;
                }
                pmovie = index->mylistlink;
                break;

            case 3:
                index = start->next;
                printf("チャンネル名を入力 > ");
                scanf("%s", channel);
                printf("\n");

                while ( index->next != NULL )
                {
                    cmp = strcmpare(channel, index->channel);
                    if ( cmp == 1 )
                    {
                        pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
                        pnew->next = pstart->next;
                        pstart->next = pnew;
                        pnew->mylistlink = index;
                    }
                    index = index->next;
                }

                nitube_movie_print( pstart, type, rule );

                printf("番号を選択 > ");
                number = my_scanf_integer();
                number--;
                printf("\n");

                i = 0;
                index = pstart->next;
                while ( i < number )
                {
                    index = index->next;
                    i++;
                }
                pmovie = index->mylistlink;
                break;

            case 4:
                index = start->next;
                printf("タグ名を入力 > ");
                scanf("%s", tag);
                printf("\n");
                while ( index->next != NULL )
                {
                    cmp = strcmpare( tag, index->tag );
                    if ( cmp == 1 )
                    {
                        pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
                        pnew->next = pstart->next;
                        pstart->next = pnew;
                        pnew->mylistlink = index;
                    }
                    index = index->next;
                }

                nitube_movie_print( pstart, type, rule );

                printf("番号を選択 > ");
                number = my_scanf_integer();
                number--;
                printf("\n");

                i = 0;
                index = pstart->next;
                while ( i < number )
                {
                    index = index->next;
                    i++;
                }
                pmovie = index->mylistlink;
                break;

            case 0:
                pmovie = NULL;
                break;

            default:
                return pmovie;
                break;
        }

    } else if ( type == 2 )
    {
        switch( rule )
        {
            case 1:
                nitube_movie_print(start, type, rule);
                printf("番号を入力 > ");
                number = my_scanf_integer();
                number--;
                printf("\n");

                index = start->next;
                i = 0;
                while ( i < number )
                {
                    index = index->next;
                    i++;
                }
                pmovie = index;
                break;

            case 2:
                index = start->next;
                printf("投稿日を入力 > ");
                number = my_scanf_integer();
                printf("\n");

                while ( index->next != NULL )
                {
                    if ( number == index->date )
                    {
                        pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
                        pnew->next = pstart->next;
                        pstart->next = pnew;
                        pnew->mylistlink = index;
                    }
                    index = index->next;
                }

                nitube_movie_print(pstart, type, rule);
                printf("番号を選択 > ");
                number = my_scanf_integer();
                number--;
                printf("\n");

                i = 0;
                index = pstart->next;
                while ( i < number )
                {
                    index = index->next;
                    i++;
                }
                pmovie = index;
                break;

            case 3:
                index = start->next;
                printf("チャンネル名を入力 > ");
                scanf("%s", channel);
                printf("\n");

                while ( index->next != NULL )
                {
                    cmp = strcmpare(channel, index->channel);
                    if ( cmp == 1 )
                    {
                        pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
                        pnew->next = pstart->next;
                        pstart->next = pnew;
                        pnew->mylistlink = index;
                    }
                    index = index->next;
                }

                nitube_movie_print( pstart, type, rule );

                printf("番号を選択 > ");
                number = my_scanf_integer();
                number--;
                printf("\n");

                i = 0;
                index = pstart->next;
                while ( i < number )
                {
                    index = index->next;
                    i++;
                }
                pmovie = index;
                break;

            case 4:
                index = start->next;
                printf("タグ名を入力 > ");
                scanf("%s", tag);
                printf("\n");
                while ( index->next != NULL )
                {
                    cmp = strcmpare( tag, index->tag );
                    if ( cmp == 1 )
                    {
                        pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
                        pnew->next = pstart->next;
                        pstart->next = pnew;
                        pnew->mylistlink = index;
                    }
                    index = index->next;
                }

                nitube_movie_print( pstart, type, rule );

                printf("番号を選択 > ");
                number = my_scanf_integer();
                number--;
                printf("\n");

                i = 0;
                index = pstart->next;
                while ( i < number )
                {
                    index = index->next;
                    i++;
                }
                pmovie = index;
                break;

            case 0:
                pmovie = NULL;
                break;

            default:
                return pmovie;
                break;
        }
    }

    return pmovie;
}

/*======================  繧｢繝ｫ繝舌Β驕ｸ謚槭Γ繝九Η繝ｼ陦ｨ遉ｺ讖溯・  ==========================*/
void nitube_movie_select_menu()
{
    printf("===== 動画選択 =====\n");
    printf("1... 全動画一覧より選択\n");
    printf("2... 指定した動画投稿日一覧より選択\n");
    printf("3... 指定したチャンネル名一覧より選択\n");
    printf("4... 指定したタグ名一覧より選択\n");
    printf("0... キャンセル\n");
    printf("番号を選択してください\n");
    return;
}

/*======================  蜍慕判繝ｪ繧ｹ繝亥・繧梧崛縺医Γ繧､繝ｳ讖溯・  ==========================*/
void nitube_edit_swap( struct MOVIE *start )
{
    struct MOVIE *pa1, *pa2;
    int pa1num, pa2num;
    int type, loc, k;
    loc = 0;
    type = 2;

    if ( start->next->mylistlink == NULL ) type = 1;

    pa1 = nitube_movie_select( start, type );
    pa2 = nitube_movie_select( start, type );

    if ( pa1 == NULL || pa2 == NULL ) return;

    pa1num = nitube_movie_count_index( start, pa1 );
    pa2num = nitube_movie_count_index( start, pa2 );

    if ( pa1num - pa2num == 1 || pa2num - pa1num == 1 )
    {
        loc = 1;
        if ( pa1num > pa2num )
        {
            k = pa1num;
            pa1num = pa2num;
            pa2num = k;
        }
    } 

    if ( loc == 0 )
    {
        nitube_swap_no_otonari( start, pa1num, pa2num );
    } else if ( loc == 1 )
    {
        nitube_swap_otonari( start, pa1num, pa2num );
    }

    return;
}

/*======================  騾｣逡ｪ縺ｧ縺ｪ縺・虚逕ｻ繝ｪ繧ｹ繝亥・繧梧崛縺域ｩ溯・  ==========================*/
void nitube_swap_otonari( struct MOVIE *start, int num1, int num2)
{
    struct MOVIE *index;
    struct MOVIE *A, *Amae;
    struct MOVIE *B, *Bato;
    int i;

    index = start;

    for ( i = 0; i < num1 - 1; i++ )
    {
        index = index->next;
    }

    Amae = index;
    A = index->next;

    index = start;
    for ( i = 0; i < num2; i++ )
    {
        index = index->next;
    }
    B = index;
    Bato = index->next;

    Amae->next = B;
    B->next = A;
    A->next = Bato;

    printf(" 動画 %s と %s を入れ替えました\n", A->title, B->title );
    return;
}

/*======================  騾｣逡ｪ縺ｧ縺ゅｋ蜍慕判繝ｪ繧ｹ繝亥・繧梧崛縺域ｩ溯・  ==========================*/
void nitube_swap_no_otonari( struct MOVIE *start, int num1, int num2)
{
    struct MOVIE *index;
    struct MOVIE *A, *Amae, *Aato;
    struct MOVIE *B, *Bmae, *Bato;
    int i;

    index = start;
    for ( i = 0; i < num1 - 1; i++ )
    {
        index = index->next;
    }
    Amae = index;
    A = index->next;
    Aato = index->next->next;

    index = start;
    for ( i = 0; i < num2 - 1; i++ )
    {
        index = index->next;
    }
    Bmae = index;
    B = index->next;
    Bato = index->next->next;

    A->next = Bato;
    B->next = Aato;
    Amae->next = B;
    Bmae->next = A;

    printf("動画 %s と %s を入れ替えました\n", A->title, B->title);
    return;
}