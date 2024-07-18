#include "nitube.h"

/* ================    繝槭う繝ｪ繧ｹ繝育ｷｨ髮・Γ繧､繝ｳ讖溯・縲縲======================*/
void nitube_edit_mylist( struct NITUBE *pt_nitube )
{
    struct MOVIE *index;
    int num, year;
    char aname[MN], mname[MN], gname[MN];

    nitube_edit_mylist_menu();
    num = my_scanf_integer();

    switch( num )
    {
        case 1:
            printf("マイリスト名を入力 \n >");
            printf("変更前: %s\n", pt_nitube->mylist1.name);
            scanf("%s", pt_nitube->mylist1.name);
            printf("変更後: %s\n", pt_nitube->mylist1.name);
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
        case 0: break;
        default: break;
    }

    return;

}

/* ================    繝槭う繝ｪ繧ｹ繝育ｷｨ髮・Γ繝九Η繝ｼ陦ｨ遉ｺ縲縲======================*/
void nitube_edit_mylist_menu()
{
    printf("== マイリスト編集 menu == \n");
    printf("1... マイリスト名の変更 \n");
    printf("2... 動画の追加 \n ");
    printf("3... 動画の削除 \n");
    printf("4... 動画の入れ替え \n");
    printf("0... メイン画面に戻る \n");
    printf("番号を入力 > ");
    return;
}

/* ================    繝槭う繝ｪ繧ｹ繝・莉ｶ蜑企勁縲縲======================*/
void nitube_edit_mylist_delete( struct NITUBE *pt_nitube)
{
    struct MOVIE *index, *ato , *mae;
    int ans, i;

    index = nitube_movie_select( pt_nitube->mylist1.start, 2);
    if ( index == NULL ) return;

    ans = nitube_movie_count_index(pt_nitube->mylist1.start, index);
    if ( ans < 1 || ans > pt_nitube->mylist1.max )
    {
        printf( " 該当する動画はありません \n ");
        return;
    }

    ato = index->next;
    mae->next = ato;
    pt_nitube->mylist1.max--;

    free(index);

    return;
}

/* ================    繝槭う繝ｪ繧ｹ繝・莉ｶ霑ｽ蜉?縲縲======================*/
void nitube_edit_mylist_add( struct NITUBE *pt_nitube )
{
    struct MOVIE *index, *pnew, *pato;

    pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
    index = nitube_movie_select(pt_nitube->start, 1);
    if ( index == NULL ) return;

    pnew->mylistlink = index;
    pnew->next = pt_nitube->mylist1.start->next;
    pt_nitube->mylist1.start->next = pnew;
    pt_nitube->mylist1.max++;

    printf("マイリストに動画 %s を追加しました。\n", index->title);

    return;
}