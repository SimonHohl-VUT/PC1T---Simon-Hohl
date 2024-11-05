// FunExt.cpp : Defines the entry point for the application.
#include <limits.h>
#include <float.h>
#include "FunExt.h"

using namespace std;

int main()
{
    double maxY = -200000; // Pro maximum nastavíme počáteční hodnotu na velmi malé číslo
    int maxX = 0;

    for (int x = 10; x <= 20; ++x)
    {
        double y = 5 - 3 * x + 2 * (x - 5) * (x - 5) - (x - 10) * (x - 10) * (x - 10);

        if (y > maxY) // Změna podmínky pro hledání maxima
        {
            maxY = y;
            maxX = x;
        }
    }
    printf("Maximum value: %lf at x=%d\n", maxY, maxX);
    return 0;
}
