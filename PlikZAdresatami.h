#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "MetodyWczytujace.h"

#include <iostream>
#include <vector>

using namespace std;

class PlikZAdresatami {
    int idOstatniegoAdresata;
    const string nazwaPlikuZAdresatami;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(const Adresat &adresat);
    Adresat pobierzDaneAdresata(const string &daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(const string &daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(const string &daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string NAZWA_PLIKU_Z_ADRESATAMI) : nazwaPlikuZAdresatami(NAZWA_PLIKU_Z_ADRESATAMI) {} ;
    int pobierzIdOstatniegoAdresata() const { return idOstatniegoAdresata; };
    void ustawIdOstatniegoAdresata(const int &noweId) { idOstatniegoAdresata = noweId; };

    void dopiszAdresataDoPliku(const Adresat &adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(const int idZalogowanegoUzytkownika);
};

#endif
