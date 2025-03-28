#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "MetodyWczytujace.h"

#include <iostream>
#include <vector>

using namespace std;

class PlikZAdresatami {
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(const Adresat &adresat);
    Adresat pobierzDaneAdresata(const string &daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(const string &daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(const string &daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {} ;
    int pobierzIdOstatniegoAdresata() const { return idOstatniegoAdresata; };
    void ustawIdOstatniegoAdresata(const int &noweId) { idOstatniegoAdresata = noweId; };

    bool dopiszAdresataDoPliku(const Adresat &adresat);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, const int idZalogowanegoUzytkownika);
};

#endif
