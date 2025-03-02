#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

#include "UzytkownikMenedzer.h"
#include "Adresat.h"
#include "MetodyWczytujace.h"
#include "MetodyPomocnicze.h"

#include <iostream>
//#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class PlikZAdresatami {
    Adresat adresat;
    vector <Adresat> adresaci;
public:
    int pobierzAdresatowZalogowanegoUzytkownikaZPliku(int id);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
};

#endif
