#include "UzytkownikMenedzer.h"

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::logowanieUzytkownika(AdresatMenedzer &adresatMenedzer) {
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
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    adresatMenedzer.ustawIdZalogowanegoUzytkownika(itr->pobierzId());
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            adresatMenedzer.ustawIdZalogowanegoUzytkownika(0);
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    adresatMenedzer.ustawIdZalogowanegoUzytkownika(0);
    return;
}

void UzytkownikMenedzer::wylogujUzytkownika() {
    cout << "Zostales wylogowany." << endl;

    idZalogowanegoUzytkownika = 0;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyWczytujace::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr->pobierzId() == pobierzIdZalogowanegoUzytkownika())                   //przypisz raz i porownuj???
        {
            itr->ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku() {
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty())
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {
    for(size_t i = 0; i < uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

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

void UzytkownikMenedzer::wypiszWszytskichUzytkownikow() {
    for(size_t i = 0; i < uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}
