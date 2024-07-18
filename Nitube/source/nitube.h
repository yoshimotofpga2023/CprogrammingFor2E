#include<stdio.h>
#include<stdlib.h>

#define MN 100

#define ORIGINAL "original.dat"
#define MYLIST1 "mylist.dat"

struct MOVIE
{
    int date;
    char title[MN];
    char channel[MN];
    char tag[MN];
    struct MOVIE *next, *mylistlink;

};

struct MYLIST
{
    int max;
    char name[MN];
    struct MOVIE *start;
};

struct PLAYBUFFER
{
    int max;
    struct MOVIE *list[MN];
};

struct NITUBE
{
    int max;
    struct MOVIE *start;
    struct PLAYBUFFER playbuffer;
    struct MYLIST mylist1;

};

void nitube_main_menu();
int my_scanf_integer();
int my_strcmp( char word1[MN], char word2[MN]);
int strcmpare(char word1[MN], char word2[MN]);
int nitube_movie_count_index( struct MOVIE *start, struct MOVIE *count);
void nitube_movie_print( struct MOVIE *start, int type, int rule);
struct MOVIE *nitube_movie_select( struct MOVIE *start, int type);
void nitube_movie_select_menu();

void nitube_edit_original( struct NITUBE *pt_nitube);
void nitube_edit_original_menu();
void nitube_edit_mylist( struct NITUBE *pt_nitube);
void nitube_edit_mylist_menu();
void nitube_edit_original_delete( struct NITUBE *pt_nitube);
void nitube_edit_mylist_delete( struct NITUBE *pt_nitube);
void nitube_edit_original_add( struct NITUBE *pt_nitube);
void nitube_edit_mylist_add( struct NITUBE *pt_nitube);
void nitube_edit_swap( struct MOVIE *start);
void nitube_swap_otonari( struct MOVIE *start, int num1, int num2);
void nitube_swap_no_otonari( struct MOVIE *start, int num1, int num2);

void nitube_load( struct NITUBE *pt_nitube);
void nitube_load_original( struct NITUBE *pt_nitube);
void nitube_load_mylist( struct NITUBE *pt_nitube);
void nitube_save( struct NITUBE *pt_nitube);
void nitube_save_original( struct NITUBE *pt_nitube );
void nitube_save_mylist( struct NITUBE *pt_nitube);

void nitube_play( struct NITUBE *pt_nitube);
void nitube_play_menu();
void nitube_makebuffer_original( struct NITUBE *pt_nitube, int rule);
void nitube_makebuffer_mylist( struct NITUBE *pt_nitube);
void nitube_playing( struct NITUBE *pt_nitube, int type);
void nitube_playing_menu();