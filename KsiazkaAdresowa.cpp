#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszytskichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszytskichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();

    idZalogowanegoUzytkownika = uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
    adresatMenedzer.ustawIdZalogowanegoUzytkownika(idZalogowanegoUzytkownika);

//    adresatMenedzer.pobierzAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);

    cout << uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    uzytkownikMenedzer.wylogujUzytkownika();

    cout << uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
