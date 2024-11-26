#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AutaDB.h"

void add(char* znacka, int rok, struct t_auto** uk_prvni) // pridani auta
{
	struct t_auto* noveAuto; // ukazatel pro nove vkladane auto
	struct t_auto* aktAuto; // ukazatel na aktualni auto

	// alokace dynamicke promenne
	noveAuto = (struct t_auto*)malloc(sizeof(struct t_auto));

	strcpy_s(noveAuto->znacka, ZNACKA_SIZE, znacka); // naplneni struktury
	noveAuto->rok = rok;
	noveAuto->dalsi = NULL;

	if (*uk_prvni == NULL) // linearni seznam je prazdny
	{
		*uk_prvni = noveAuto;
		return;
	}
	else if (noveAuto->rok < (*uk_prvni)->rok) // vlozime na zacatek
	{
		noveAuto->dalsi = *uk_prvni;
		*uk_prvni = noveAuto;
		return;
	}

	aktAuto = *uk_prvni;
	while (aktAuto) // prochazeni seznamu
	{
		if (aktAuto->dalsi == NULL) // jsme na poslednim aute
		{
			aktAuto->dalsi = noveAuto; // pridavame na konec
			return;
		}
		else if (noveAuto->rok < aktAuto->dalsi->rok)
		{
			noveAuto->dalsi = aktAuto->dalsi; // vlozime za aktAuto
			aktAuto->dalsi = noveAuto;
			return;
		}
		aktAuto = aktAuto->dalsi; // posun na dalsi auto
	}
}

void del(int rok, struct t_auto** uk_prvni)
{
	struct t_auto* aktAuto;

	while (*uk_prvni && (*uk_prvni)->rok == rok)
	{
		struct t_auto* newPrvni = (*uk_prvni)->dalsi;
		free(*uk_prvni);  // uvolneni auta z pameti
		*uk_prvni = newPrvni;
	}

	aktAuto = *uk_prvni;
	while (aktAuto && aktAuto->dalsi) // prochazeni seznamu
	{
		if (aktAuto->dalsi->rok == rok) // auto je ke smazani
		{
			struct t_auto* newDalsi = aktAuto->dalsi->dalsi;
			free(aktAuto->dalsi);  // uvolneni auta z pameti
			aktAuto->dalsi = newDalsi;
		}
		aktAuto = aktAuto->dalsi; // posun na dalsi auto
	}
}