#include "nitube.h"

/*======================== オリジナル動画編雁E��イン機�E ===============================*/
void nitube_edit_original( struct NITUBE *pt_nitube )
{
    struct MOVIE *index;
    int num, year;
    char aname[MN], mname[MN], gname[MN];

    nitube_edit_mylist_menu();
    num = my_scanf_integer();

    switch( num )
    {
        case 1:
            printf("変更前！E%s\n", pt_nitube->mylist1.name);
            printf("プレイリスト名を�E劁E\n >");
            scanf("%s", pt_nitube->mylist1.name);
            printf("変更しました�E�E%s\n", pt_nitube->mylist1.name);
            break;
        case 2:
            nitube_edit_mylist_add(pt_nitube);
            break;
        case 3:
            nitube_edit_mylist_delete(pt_nitube);
            break;
        case 4:
            nitube_edit_swap(pt_nitube->mylist1.start);
            break;
        case 0:
            break;
        default:
            break;
    }

    return;
}

/*======================== 動画惁E��編雁E��ニュー表示機�E ===============================*/
void nitube_edit_original_menu()
{
    printf("== マイリスト編雁Eenu == \n");
    printf("1... マイリスト名の変更 \n");
    printf("2... マイリスト動画の追加 \n");
    printf("3... マイリストから動画を削除 \n");
    printf("4... マイリスト動画の入れ替ぁE\n");
    printf("0... メイン画面へ戻めE\n");
    printf("番号を�E劁E> ");
    return;
}

/*======================== 動画1件削除機�E ===============================*/
void nitube_edit_original_delete( struct NITUBE *pt_nitube )
{
    struct MOVIE *index, *ato, *mae;
    int ans, i;

    index = nitube_movie_select(pt_nitube->mylist1.start, 2);
    if ( index == NULL ) return;

    ans = nitube_movie_count_index(pt_nitube->mylist1.start, index);
    if ( ans < 1 || ans > pt_nitube->mylist1.max )
    {
        printf("該当する動画はありません \n");
        return;        
    }

    mae = pt_nitube->mylist1.start->next;
    for ( i = 0; i < ans - 1; i++ )
    {
        mae = mae->next;
    }

    ato = index->next;
    mae->next = ato;
    pt_nitube->mylist1.max--;

    free(index);

    return;
}

/*======================== 動画1件追加機�E ===============================*/
void nitube_edit_original_add ( struct NITUBE *pt_nitube )
{
    struct MOVIE *index, *pnew, *pato;

    pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
    index = nitube_movie_select(pt_nitube->start, 1);
    pt_nitube->mylist1.start->next = pnew;
    pt_nitube->mylist1.max++;

    printf("マイリストに %s を追加しました�E�\n", index->title );
    return;
}