#include "UzytkownikMenedzer.h"

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do {
        cout << "Podaj login: ";
        uzytkownik.ustawLogin(MetodyWczytujace::wczytajLinie());
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()));

    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(MetodyWczytujace::wczytajLinie());

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty())
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(const string &login) {
    for(size_t i = 0; i < uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany() {
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UzytkownikMenedzer::logowanieUzytkownika() {
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyWczytujace::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end()) {
        if (itr->pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyWczytujace::wczytajLinie();

                if (itr->pobierzHaslo() == haslo) {
                    ustawIdZalogowanegoUzytkownika(itr->pobierzId());
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyWczytujace::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
        if (itr->pobierzId() == pobierzIdZalogowanegoUzytkownika()) {
            if (itr->pobierzHaslo() == noweHaslo) {
                cout << endl << "Nowe haslo nie moze byc takie samo!" << endl << endl;
                system("pause");
                return;
            } else {
                itr->ustawHaslo(noweHaslo);
                cout << endl << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wypiszWszytskichUzytkownikow() {
    for (size_t i = 0; i < uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkownikMenedzer::wylogujUzytkownika() {
    idZalogowanegoUzytkownika = 0;
    cout << "Zostales wylogowany." << endl;
}
