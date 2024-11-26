#pragma once

#define STRING_SIZE 51

struct t_song
{
    char author[STRING_SIZE];
    char title[STRING_SIZE];
    int year;
    struct t_song* next;
};

void add(char* author, char* title, int year, struct t_song** head);
void del(int year, struct t_song** head);
