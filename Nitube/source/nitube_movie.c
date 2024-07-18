#include "nitube.h"

/*======================= 動画汎用機�E ===============================*/
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

/*======================= アルバムリスト表示機�E ===============================*/
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

/*======================= アルバム選択機�E ===============================*/
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
                printf("�ԍ���I�� > ");
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
                printf("���e����I�� > ");
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
                printf("�ԍ���I�� > ");
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
                printf("�`�����l��������� > ");
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

                printf("�ԍ���I�� > ");
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
                printf("�^�O������� > ");
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

                printf("�ԍ���I�� > ");
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
                printf("�ԍ������ > ");
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
                printf("���e������� > ");
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
                printf("�ԍ���I�� > ");
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
                printf("�`�����l��������� > ");
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

                printf("�ԍ���I�� > ");
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
                printf("�^�O������� > ");
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

                printf("�ԍ���I�� > ");
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

/*======================  アルバム選択メニュー表示機�E  ==========================*/
void nitube_movie_select_menu()
{
    printf("===== ����I�� =====\n");
    printf("1... �S����ꗗ���I��\n");
    printf("2... �w�肵�����擊�e���ꗗ���I��\n");
    printf("3... �w�肵���`�����l�����ꗗ���I��\n");
    printf("4... �w�肵���^�O���ꗗ���I��\n");
    printf("0... �L�����Z��\n");
    printf("�ԍ���I�����Ă�������\n");
    return;
}

/*======================  動画リスト�Eれ替えメイン機�E  ==========================*/
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

/*======================  連番でなぁE��画リスト�Eれ替え機�E  ==========================*/
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

    printf(" ���� %s �� %s �����ւ��܂���\n", A->title, B->title );
    return;
}

/*======================  連番である動画リスト�Eれ替え機�E  ==========================*/
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

    printf("���� %s �� %s �����ւ��܂���\n", A->title, B->title);
    return;
}