#pragma once

#define ZNACKA_SIZE 21

struct t_auto
{
    char  znacka[ZNACKA_SIZE];
    int   rok;
    struct t_auto* dalsi;
};

void add(char* znacka, int rok, struct t_auto** uk_prvni);
void del(int rok, struct t_auto** uk_prvni);
