#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::wyswietlMenuGlowne() {
    system("cls");
    cout << "\t< MENU GLOWNE >"                 << endl;
    cout << "-----------------------------"     << endl;
    cout << "1.LOGOWANIE"                       << endl;
    cout << "2.REJESTRACJA"                     << endl;
    cout << "3.ZAMKNIJ KSIAZKE ADRESOWA"        << endl;
    cout << "-----------------------------"     << endl;
    cout << "Wybierz jedna z opcji:\t";
}

void KsiazkaAdresowa::wyswietlMenuUzytkownika() {
    system("cls");
    cout << "\t< MENU UZYTKOWNIKA >"                                << endl;
    cout << "------------------------------------"                  << endl;
    cout << "1. Dodaj adresata do ksiazki adresowej"                << endl;
    cout << "2. Wyszukaj adresata po imieniu"                       << endl;
    cout << "3. Wyszukaj adresata po nazwisku"                      << endl;
    cout << "4. Wyswietl wszystkich adresatow z ksiazki adresowej"  << endl;
    cout << "5. Edytuj wybranego adresata"                          << endl;
    cout << "6. Usun wybranego adresata"                            << endl;
    cout << "------------------------------------"                  << endl;
    cout << "8. Zmien haslo"                                        << endl;
    cout << "9. Wyloguj"                                            << endl;
    cout << "------------------------------------"                  << endl;
    cout << "Wybierz jedna z opcji:\t";
}

int KsiazkaAdresowa::wybierzOpcjeZMenu(const string &kryterium) {
    if (kryterium == "MENU_GLOWNE")
        wyswietlMenuGlowne();
    else if (kryterium == "MENU_UZYTKOWNIKA")
        wyswietlMenuUzytkownika();
    else
        return 0;

    int wyborUzytkownika = MetodyWczytujace::wczytajLiczbe();

    return wyborUzytkownika;
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
    return uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszytskichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszytskichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();

    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatowZalogowanegoUzytkownika() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        adresatMenedzer->wyswietlWszystkichAdresatowZalogowanegoUzytkownika();
    else
        cout << "Brak adresatow do wyswietlenia." << endl;
}

void KsiazkaAdresowa::dodajAdresata() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        adresatMenedzer->dodajAdresata();
    else
        cout << "Nie jestes zalogowany." << endl;
}
