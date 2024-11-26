#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HudbaDB.h"

void add(char* author, char* title, int year, struct t_song** head) 
{
    struct t_song* newSong;    
    struct t_song* current;   

    
    newSong = (struct t_song*)malloc(sizeof(struct t_song));
    if (!newSong) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy_s(newSong->author, STRING_SIZE, author);
    strcpy_s(newSong->title, STRING_SIZE, title);
    newSong->year = year;
    newSong->next = NULL;

    if (*head == NULL || strcmp(newSong->title, (*head)->title) < 0) {
        newSong->next = *head;
        *head = newSong;
        return;
    }

    current = *head;
    while (current->next && strcmp(newSong->title, current->next->title) > 0) {
        current = current->next;
    }

    newSong->next = current->next;
    current->next = newSong;
}

void del(int year, struct t_song** head)
{
    struct t_song* current;

    while (*head && (*head)->year == year) {
        struct t_song* toDelete = *head;
        *head = (*head)->next;
        free(toDelete); 
    }

    current = *head;
    while (current && current->next) {
        if (current->next->year == year) {
            struct t_song* toDelete = current->next;
            current->next = current->next->next;
            free(toDelete); 
        } else {
            current = current->next;
        }
    }
}
