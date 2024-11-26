#include "Hudba.h"

#include <stdio.h>
#include <ctype.h>              
#include <stdlib.h>             

#include "HudbaDB.h"

struct t_song* first = NULL; 

void OnAdd()
{
    char author[STRING_SIZE];
    char title[STRING_SIZE];
    int year;

    printf("\nAuthor: ");      
    scanf_s("%50s", author, STRING_SIZE);
    while (getchar() != '\n');

    printf("\nTitle: ");
    scanf_s("%50s", title, STRING_SIZE);
    while (getchar() != '\n');

    printf("\nYear: ");
    scanf_s("%d", &year);
    while (getchar() != '\n');

    add(author, title, year, &first);
}

void OnDel()
{
    int year;

    printf("\nYear: ");
    scanf_s("%d", &year);
    while (getchar() != '\n');

    del(year, &first);  
}

void ShowSongs()
{
    struct t_song* current = first;
    printf("\n\n");
    while (current) 
    {
        printf("%s - %s (%d)\n", current->author, current->title, current->year); 
        current = current->next; 
    }
    getchar();
}

int main()
{
    char cmd;

    do
    {
        system("cls");    
        printf("A: Add     ");
        printf("D: Delete     ");
        printf("P: Print     ");
        printf("Q: Quit\n\n");

        cmd = tolower(getchar());
        while (getchar() != '\n');

        switch (cmd)
        {
        case 'a':
            OnAdd();          
            break;
        case 'd':
            OnDel();          
            break;
        case 'p':
            ShowSongs();      
            break;
        }
    } while (cmd != 'q');     
    return 0;
}
