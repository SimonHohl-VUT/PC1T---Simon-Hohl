#include "CMakeProject1.h"


using namespace std;

int indexNejblizsi(int velikost, int (*poleBodu)[2], int referencniX, int referencniY) {
    int nejblizsiIndex = -1;
    double nejmensiVzdalenost = numeric_limits<double>::max();

    for (int i = 0; i < velikost; ++i) {
        double vzdalenost = sqrt(pow(poleBodu[i][0] - referencniX, 2) +
            pow(poleBodu[i][1] - referencniY, 2));
        if (vzdalenost < nejmensiVzdalenost) {
            nejmensiVzdalenost = vzdalenost;
            nejblizsiIndex = i;
        }
    }

    return nejblizsiIndex;
}

double prumernaVzdalenost(int velikost, int (*poleBodu)[2], int referencniX, int referencniY) {
    double soucetVzdalenosti = 0;

    for (int i = 0; i < velikost; ++i) {
        soucetVzdalenosti += sqrt(pow(poleBodu[i][0] - referencniX, 2) +
            pow(poleBodu[i][1] - referencniY, 2));
    }

    return soucetVzdalenosti / velikost;
}

void bodyVKvadrantu(int velikost, int (*poleBodu)[2], int referencniX, int referencniY, int kvadrant) {
    cout << "Souradnice bodu ve zvolenem kvadrantu: " << endl;
    for (int i = 0; i < velikost; i++) {
        switch(kvadrant){
            case 1:
                if (poleBodu[i][0] >= referencniX && poleBodu[i][1] >= referencniY) {
                    cout << poleBodu[i][0] << " " << poleBodu[i][1] << endl;
                }
                break;
            case 2:
                if (poleBodu[i][0] <= referencniX && poleBodu[i][1] >= referencniY) {
                    cout << poleBodu[i][0] << " " << poleBodu[i][1] << endl;
                }
                break;
            case 3:
                if (poleBodu[i][0] <= referencniX && poleBodu[i][1] <= referencniY) {
                    cout << poleBodu[i][0] << " " << poleBodu[i][1] << endl;
                }
                break;
            case 4:
                if (poleBodu[i][0] >= referencniX && poleBodu[i][1] <= referencniY) {
                    cout << poleBodu[i][0] << " " << poleBodu[i][1] << endl;
                }
                break;
            default:
                break;

        }
    }

}

