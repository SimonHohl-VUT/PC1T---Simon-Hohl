#include "cv8.h"

using namespace std;

int prunik1(double zacatek1, double konec1, double zacatek2, double konec2, double* vysl_zacatek, double* vysl_konec) {
    double prunik_zacatek = max(zacatek1, zacatek2);
    double prunik_konec = min(konec1, konec2);

    if (prunik_zacatek <= prunik_konec) {
        *vysl_zacatek = prunik_zacatek;
        *vysl_konec = prunik_konec;
        return 1;
    }
    return 0;
}

int prunik2(double zacatek1, double konec1, double zacatek2, double konec2, double* vysl_zacatek, double* vysl_konec) {
    if (zacatek1 >= konec1) {
        double temp = zacatek1;
        zacatek1 = konec1;
        konec1 = temp;
    }
    if (zacatek2 >= konec2) {
        double temp = zacatek2;
        zacatek2 = konec2;
        konec2 = temp;
    }

    double prunik_zacatek = max(zacatek1, zacatek2);
    double prunik_konec = min(konec1, konec2);

    if (prunik_zacatek <= prunik_konec) {
        *vysl_zacatek = prunik_zacatek;
        *vysl_konec = prunik_konec;
        return 1;
    }
    return 0;
}