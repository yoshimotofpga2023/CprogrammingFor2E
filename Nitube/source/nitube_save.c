#include "nitube.h"

/*===========     プレイリストアルバム保存機�E     ==============*/
void nitube_save( struct NITUBE *pt_nitube )
{
    nitube_save_original( pt_nitube );
    nitube_save_mylist( pt_nitube );
    return;
}

/*===========     オリジナルアルバム保存機�E     ==============*/
void nitube_save_original( struct NITUBE *pt_nitube )
{
    FILE *fp;
    struct MOVIE *index;
    int i, number;

    fp = fopen(ORIGINAL, "w");

    index = pt_nitube->start;
    fprintf(fp, "%d\n", pt_nitube->max);

    for ( i = 0; i < pt_nitube->max; i++ )
    {
        index = index->next;
        fprintf(fp, "%d", index->date);
        fprintf(fp, "%s", index->title);
        fprintf(fp, "%s", index->channel);
        fprintf(fp, "%s \n", index->tag);
    }
    fclose(fp);

    printf("\n %d ���̃f�[�^��ۑ����܂���\n", i);

    return;
}

/*===========     プレイリストアルバム保存機�E     ==============*/
void nitube_save_mylist( struct NITUBE *pt_nitube )
{
    FILE *fp;
    struct MOVIE *aindex;
    int i, number;

    fp = fopen(MYLIST1, "w");

    fprintf(fp, "%s\n", pt_nitube->mylist1.name);
    fprintf(fp, "%d\n", pt_nitube->mylist1.max);

    aindex = pt_nitube->mylist1.start;

    for ( i = 0; i < pt_nitube->mylist1.max; i++ )
    {
        aindex = aindex->next;
        number = nitube_movie_count_index(pt_nitube->start, aindex->mylistlink);
        fprintf(fp, "%d\n", number);
    }
    printf("\n %d ���}�C���X�g�f�[�^��ۑ����܂��� \n", pt_nitube->mylist1.max);
    fclose(fp);
    
    return;
}