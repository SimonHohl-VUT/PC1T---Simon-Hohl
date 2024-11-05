#include "vector.h"
#include "vectorMult.h"
using namespace std;

void soucet(double a[3], double b[3], double c[3]) {
    c[0] = a[0] + b[0];
    c[1] = a[1] + b[1];
    c[2] = a[2] + b[2];
    printf("soucet A + B: (%f,%f,%f)\n", c[0], c[1], c[2]);
}

double velikost(double a[3]) {
    return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

double skalarniSoucin(double a[3], double b[3]) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

int main() {
    double a[3], b[3], c[3];

    printf("Vektor A (3 hodnoty oddelene carkou): ");
    scanf("%lf,%lf,%lf", &a[0], &a[1], &a[2]);
    printf("Vektor B (3 hodnoty oddelene carkou): ");
    scanf("%lf,%lf,%lf", &b[0], &b[1], &b[2]);

    soucet(a, b, c);

    printf("velikost A: %lf \n", velikost(a));
    printf("skalarni soucin AB: %lf \n", skalarniSoucin(a, b));
    vektorovySoucin(a, b, c);
    return 0;
}