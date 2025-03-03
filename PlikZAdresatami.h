#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

#include "AdresatMenedzer.h"
#include "Adresat.h"

#include <iostream>

using namespace std;

class PlikZAdresatami {
    int idOstatniegoAdresata;

    bool czyPlikJestPusty(fstream &plikTekstowy);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(Adresat adresat, string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata(int noweID);

    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(const int idZalogowanegoUzytkownika);
};

#endif
