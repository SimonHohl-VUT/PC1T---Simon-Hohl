#include "cv8.h"

using namespace std;

int main()
{
    double zacatek1, konec1, zacatek2, konec2;
    double vysl_zacatek, vysl_konec;

    cout << "Zadejte zacatek a konec prvniho intervalu (zacatek1 konec1): ";
    cin >> zacatek1 >> konec1;

    cout << "Zadejte zacatek a konec druheho intervalu (zacatek2 konec2): ";
    cin >> zacatek2 >> konec2;

    int result = prunik1(zacatek1, konec1, zacatek2, konec2, &vysl_zacatek, &vysl_konec);

    if (result == 1) {
        cout << "Prunik existuje. Prunik je: (" << vysl_zacatek << ", " << vysl_konec << ")" << endl;
    }
    else {
        cout << "Nema prunik." << endl;
    }

    result = prunik2(zacatek1, konec1, zacatek2, konec2, &vysl_zacatek, &vysl_konec);
    if (result == 1) {
        cout << "Prunik po upravach existuje. Prunik je: (" << vysl_zacatek << ", " << vysl_konec << ")" << endl;
    }
    else {
        cout << "Nema prunik." << endl;
    }

	return 0;
}
