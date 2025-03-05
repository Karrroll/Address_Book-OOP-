#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

//#include "AdresatMenedzer.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "MetodyWczytujace.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class PlikZAdresatami {
    int idOstatniegoAdresata;
    const string nazwaPlikuZAdresatami;

    bool czyPlikJestPusty(fstream &plikTekstowy);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {} ;
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata(int noweID);

    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(const int idZalogowanegoUzytkownika);
};

#endif
