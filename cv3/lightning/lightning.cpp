// lightning.cpp : Defines the entry point for the application.
#include <limits.h>
#include <float.h>
#include "lightning.h"

using namespace std;

int main()
{
    int distance_m, distance_km = 0, input;
    printf("V sekundach zadejte cas za ktery se ozval hrom\n");
    scanf("%d", &input);
    distance_m = input * 340;
    if (distance_m > 1000) {
    distance_km = distance_m / 1000;
    distance_m = distance_m % 1000;
    }
    printf("Blesk uhodil ");
    if (distance_km > 0){
        printf("%d km a ",distance_km);
    }
    printf("%d m od vas.",distance_m);
    return 0;
}
