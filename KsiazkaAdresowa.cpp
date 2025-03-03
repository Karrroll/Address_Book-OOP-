#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszytskichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszytskichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    int idZalogowanegoUzytkownika = 0;

    idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
    adresatMenedzer.ustawIdZalogowanegoUzytkownika(idZalogowanegoUzytkownika);

    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    uzytkownikMenedzer.wylogujUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatowZalogowanegoUzytkownika() {
    adresatMenedzer.wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatMenedzer.dodajAdresata();
}
