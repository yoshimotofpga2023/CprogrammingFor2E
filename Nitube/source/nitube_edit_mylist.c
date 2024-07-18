#include "nitube.h"

/* ================    マイリスト編雁E��イン機�E　　======================*/
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
            printf("�}�C���X�g������� \n >");
            printf("�ύX�O: %s\n", pt_nitube->mylist1.name);
            scanf("%s", pt_nitube->mylist1.name);
            printf("�ύX��: %s\n", pt_nitube->mylist1.name);
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

/* ================    マイリスト編雁E��ニュー表示　　======================*/
void nitube_edit_mylist_menu()
{
    printf("== �}�C���X�g�ҏW menu == \n");
    printf("1... �}�C���X�g���̕ύX \n");
    printf("2... ����̒ǉ� \n ");
    printf("3... ����̍폜 \n");
    printf("4... ����̓���ւ� \n");
    printf("0... ���C����ʂɖ߂� \n");
    printf("�ԍ������ > ");
    return;
}

/* ================    マイリスチE件削除　　======================*/
void nitube_edit_mylist_delete( struct NITUBE *pt_nitube)
{
    struct MOVIE *index, *ato , *mae;
    int ans, i;

    index = nitube_movie_select( pt_nitube->mylist1.start, 2);
    if ( index == NULL ) return;

    ans = nitube_movie_count_index(pt_nitube->mylist1.start, index);
    if ( ans < 1 || ans > pt_nitube->mylist1.max )
    {
        printf( " �Y�����铮��͂���܂��� \n ");
        return;
    }

    ato = index->next;
    mae->next = ato;
    pt_nitube->mylist1.max--;

    free(index);

    return;
}

/* ================    マイリスチE件追�?　　======================*/
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

    printf("�}�C���X�g�ɓ��� %s ��ǉ����܂����B\n", index->title);

    return;
}