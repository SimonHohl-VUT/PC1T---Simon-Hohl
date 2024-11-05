#include "cv6.h"
using namespace std;

int pocetPismen(const char* text) {
    int count = 0;
    
    while (*text) {
        if (isalpha(*text)) {
            count++;
        }
        text++;
    }
    
    return count;
}

int pocetCislic(const char* text) {
    int count = 0;
    
    while (*text) {
        if (isdigit(*text)) {
            count++;
        }
        text++;
    }
    
    return count;
}

int DelkySlov(const char* text, int* delky) {
    int wordLength = 0;
    int wordCount = 0;

    while (*text) {
        if (isalpha(*text)) { 
            wordLength++;
        } else if (wordLength > 0) { 
            if (wordCount < 100) { 
                delky[wordCount++] = wordLength;
            }
            wordLength = 0; 
        }
        text++;
    }

    if (wordLength > 0 && wordCount < 100) {
        delky[wordCount++] = wordLength;
    }

    return wordCount;
}

int main() {
    const char* text = "Toto je testovací text 123!";
    int JednotliveDelky[100];
    int pocetSlov = DelkySlov(text, JednotliveDelky);
    
    int pocet_pismen = pocetPismen(text);
    int pocet_cislic = pocetCislic(text);
    
    printf("Počet písmen v textu: %d\n", pocet_pismen);
    printf("Počet číslic v textu: %d\n", pocet_cislic);
    printf("Počet slov v textu: %d\n", pocetSlov);
    printf("Délky jednotlivých slov: ");
    for (int i = 0; i < pocetSlov; i++) {
        printf("%d", JednotliveDelky[i]);
        if (i < pocetSlov - 1) {
            printf(", ");
        }
    }
    printf("\n");
    
    return 0;
}
