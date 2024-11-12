// cv9.cpp: Definuje vstupní bod pro aplikaci.
//

#include "cv9.h"
#include <iostream>

using namespace std;

int main() {
    vector3d u, v;
    int operaceTyp;

    cout << "Zadejte slozky prvniho vektoru (x, y, z): ";
    scanf("%lf,%lf,%lf", &u.x, &u.y, &u.z);

    cout << "Zadejte slozky druheho vektoru (x, y, z): ";
    scanf("%lf,%lf,%lf", &v.x, &v.y, &v.z);

    cout << "Zadejte typ operace (1 = soucet, 2 = vektorovySoucin, 3 = skalarniSoucin): ";
    cin >> operaceTyp;

    vector3d w = operace(u, v, static_cast<typOperace>(operaceTyp));

    cout << "Vysledek:\n";
    tisk(w);

    char osa;
    cout << "Zadejte osu rotace (x, y, nebo z): ";
    cin >> osa;

    rotuj(&w, osa);

    cout << "Vektor po rotaci:\n";
    tisk(w);
    
    return 0;
}