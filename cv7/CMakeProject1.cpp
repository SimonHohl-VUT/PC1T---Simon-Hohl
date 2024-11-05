
#include "CMakeProject1.h"

using namespace std;

#define POCET_BODU 10

int main() {
    int body[POCET_BODU][2] = {
        {5, 10},
        {-14, 2},
        {45, 4},
        {-9, 8},
        {58, -3},
        {47, 5},
        {-18, -86},
        {75, 7},
        {-25, 51},
        {17, 98}
    };

    int referencniX, referencniY;

    cout << "Zadejte souradnice referencniho bodu (X Y): ";
    cin >> referencniX >> referencniY;

    int index = indexNejblizsi(POCET_BODU, body, referencniX, referencniY);
    double prumernaVzdalenostHodnota = prumernaVzdalenost(POCET_BODU, body, referencniX, referencniY);
    int kvadrant;
    cout << "Index nejblizsiho bodu je: " << index << "\n";
    cout << "Souradnice nejblizsiho bodu jsou: (" << body[index][0] << ", " << body[index][1] << ")\n";
    cout << "Prumerna vzdalenost bodu k referencnimu bodu je: " << prumernaVzdalenostHodnota << std::endl;
    cout << "Zvolte si kvadrant vuci kteremu bude kazdy bod porovnan: ";
    cin >> kvadrant;
    bodyVKvadrantu(POCET_BODU, body, referencniX, referencniY, kvadrant);

    return 0;
}


