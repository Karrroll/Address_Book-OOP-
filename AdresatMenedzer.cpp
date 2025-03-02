#include "AdresatMenedzer.h"

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int idAktualnieZalogowanegoUzytkownika) {
    idZalogowanegoUzytkownika = idAktualnieZalogowanegoUzytkownika;                              //walidacja?
}

int AdresatMenedzer::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

void AdresatMenedzer::ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata) {
    idOstatniegoAdresata = noweIdOstatniegoAdresata;
}

void AdresatMenedzer::pobierzAdresatowZalogowanegoUzytkownikaZPliku() {
    PlikZAdresatami plikZAdresatami;
    ustawIdOstatniegoAdresata(plikZAdresatami.pobierzAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika));
    cout << pobierzIdOstatniegoAdresata() << endl;
}
