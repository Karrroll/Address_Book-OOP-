#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszytskichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszytskichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
    cout << idZalogowanegoUzytkownika << endl;
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    idZalogowanegoUzytkownika = uzytkownikMenedzer.wylogujUzytkownika();
    cout << idZalogowanegoUzytkownika << endl;
}
