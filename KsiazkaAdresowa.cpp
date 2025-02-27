#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa() {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszytskichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszytskichUzytkownikow();
}
