#include "nitube.h"

/*======================== 繧ｪ繝ｪ繧ｸ繝翫Ν蜍慕判邱ｨ髮・Γ繧､繝ｳ讖溯・ ===============================*/
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
            printf("螟画峩蜑搾ｼ・%s\n", pt_nitube->mylist1.name);
            printf("繝励Ξ繧､繝ｪ繧ｹ繝亥錐繧貞・蜉・\n >");
            scanf("%s", pt_nitube->mylist1.name);
            printf("螟画峩縺励∪縺励◆・・%s\n", pt_nitube->mylist1.name);
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

/*======================== 蜍慕判諠・ｱ邱ｨ髮・Γ繝九Η繝ｼ陦ｨ遉ｺ讖溯・ ===============================*/
void nitube_edit_original_menu()
{
    printf("== 繝槭う繝ｪ繧ｹ繝育ｷｨ髮・enu == \n");
    printf("1... 繝槭う繝ｪ繧ｹ繝亥錐縺ｮ螟画峩 \n");
    printf("2... 繝槭う繝ｪ繧ｹ繝亥虚逕ｻ縺ｮ霑ｽ蜉 \n");
    printf("3... 繝槭う繝ｪ繧ｹ繝医°繧牙虚逕ｻ繧貞炎髯､ \n");
    printf("4... 繝槭う繝ｪ繧ｹ繝亥虚逕ｻ縺ｮ蜈･繧梧崛縺・\n");
    printf("0... 繝｡繧､繝ｳ逕ｻ髱｢縺ｸ謌ｻ繧・\n");
    printf("逡ｪ蜿ｷ繧貞・蜉・> ");
    return;
}

/*======================== 蜍慕判1莉ｶ蜑企勁讖溯・ ===============================*/
void nitube_edit_original_delete( struct NITUBE *pt_nitube )
{
    struct MOVIE *index, *ato, *mae;
    int ans, i;

    index = nitube_movie_select(pt_nitube->mylist1.start, 2);
    if ( index == NULL ) return;

    ans = nitube_movie_count_index(pt_nitube->mylist1.start, index);
    if ( ans < 1 || ans > pt_nitube->mylist1.max )
    {
        printf("隧ｲ蠖薙☆繧句虚逕ｻ縺ｯ縺ゅｊ縺ｾ縺帙ｓ \n");
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

/*======================== 蜍慕判1莉ｶ霑ｽ蜉讖溯・ ===============================*/
void nitube_edit_original_add ( struct NITUBE *pt_nitube )
{
    struct MOVIE *index, *pnew, *pato;

    pnew = (struct MOVIE *)malloc(sizeof(struct MOVIE));
    index = nitube_movie_select(pt_nitube->start, 1);
    pt_nitube->mylist1.start->next = pnew;
    pt_nitube->mylist1.max++;

    printf("繝槭う繝ｪ繧ｹ繝医↓ %s 繧定ｿｽ蜉縺励∪縺励◆・蚕n", index->title );
    return;
}