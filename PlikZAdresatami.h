#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "Adresat.h"
#include "MetodyWczytujace.h"
#include "MetodyPomocnicze.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class PlikZAdresatami {
    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    int pobierzAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void dopiszAdresataDoPliku(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

};

#endif
