#include "AdresatMenedzer.h"

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int idAktualnieZalogowanegoUzytkownika) {
    idZalogowanegoUzytkownika = idAktualnieZalogowanegoUzytkownika;                              //walidacja?
}

void AdresatMenedzer::pobierzAdresatowZalogowanegoUzytkownikaZPliku(int id) {
    plikZAdresatami.pobierzAdresatowZalogowanegoUzytkownikaZPliku(id);
}
