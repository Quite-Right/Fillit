
#include "tetramine_move_to_top_left.h"

//Сдвигает строку тетрамины на одну единицу влево, освободившееся пространство заполняется '.'
static void str_move_left_one_char(char *s)
{
    int i;

    i = -1;
    while(++i < 3)
        s[i] = s[i + 1];
    s[i++] = '.';
    s[i] = 0;
}

//Методом свапа удаляется пустые строки сверху(на самом деле меняются местами указатели)
static void tetramine_remove_empty_y(char **tetr)
{
    char *temp;
    int x;
    int y;
    int remove_y;

    y = -1;
    remove_y = 0;
    while(++y < 4) {
        x = 0;
        while(x < 4 && tetr[y][x] == '.')
            ++x;
        if(x != 4)
            break;
        ++remove_y;
    }
    while(remove_y--)
    {
        x = -1;
        temp = tetr[0];
        while(++x < 3)
            tetr[x] = tetr[x + 1];
        tetr[3] = temp;
    }
}

//Используя функцию str_move_left_one_char(char *s) удаляются пустые символы
static void tetramine_remove_empty_x(char **tetr) {
    int x;
    int y;
    int remove_x;

    x = -1;
    remove_x = 0;
    while (++x < 4) {
        y = 0;
        while (y < 4 && tetr[y][x] == '.')
            ++y;
        if (y != 4)
            break;
        ++remove_x;
    }
    while (remove_x--) {
        y = -1;
        while (++y < 3)
            str_move_left_one_char(tetr[y]);
    }
}

//Сдвиг тетрамины вверх влево
void tetramine_move_to_top_left(char **tetr)
{
    tetramine_remove_empty_y(tetr);
    tetramine_remove_empty_x(tetr);
}