#include "cv9.h"
#include <iostream>
#include <cmath>

using namespace std;

struct vector3d operace(struct vector3d u, struct vector3d v, enum typOperace typ) {
    struct vector3d w = { 0, 0, 0 };

    switch (typ) {
    case soucet:
        w.x = u.x + v.x;
        w.y = u.y + v.y;
        w.z = u.z + v.z;
        break;
    case skalarniSoucin:
        w.x = u.x * v.x + u.y * v.y + u.z * v.z;
        break;
    case vektorovySoucin:
        w.x = u.y * v.z - u.z * v.y;
        w.y = u.z * v.x - u.x * v.z;
        w.z = u.x * v.y - u.y * v.x;
        break;
    }

    return w;
}

void tisk(struct vector3d u) {
    double velikost = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
    cout << "w = (" << u.x << ", " << u.y << ", " << u.z << ")\n";
    cout << "|w| = " << velikost << endl;
}

void rotuj(struct vector3d* vec, char osa) {
    double temp;
    switch (osa) {
    case 'x':
    case 'X':
        temp = vec->y;
        vec->y = -vec->z;
        vec->z = temp;
        break;
    case 'y':
    case 'Y':
        temp = vec->x;
        vec->x = vec->z;
        vec->z = -temp;
        break;
    case 'z':
    case 'Z':
        temp = vec->x;
        vec->x = -vec->y;
        vec->y = temp;
        break;
    default:
        cerr << "Neplatna osa rotace. Pouzijte 'x', 'y' nebo 'z'." << endl;
    }
}