﻿// CMakeProject1.h: Soubor k zahrnutí pro standardní systémové soubory k zahrnutí
// nebo soubory k zahrnutí specifické pro projekt.

#pragma once

#include <cmath>
#include <limits>
#include <iostream>

int indexNejblizsi(int velikost, int (*poleBodu)[2], int referencniX, int referencniY);
double prumernaVzdalenost(int velikost, int (*poleBodu)[2], int referencniX, int referencniY);
void bodyVKvadrantu(int velikost, int (*poleBodu)[2], int referencniX, int referencniY, int kvadrant);

// TODO: Zde odkažte na dodatečné hlavičky, které program vyžaduje.
