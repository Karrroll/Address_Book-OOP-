#include "AdresatMenedzer.h"

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;
    string imie = "", nazwisko = "";

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyWczytujace::wczytajLinie());
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyWczytujace::wczytajLinie());
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyWczytujace::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyWczytujace::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyWczytujace::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::wyswietlDaneAdresata(const Adresat &adresat) {
    cout << endl;
    cout << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << endl << "Adresat zostal dodany" << endl;
    else
        cout << endl << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;

    system("pause");
}

void AdresatMenedzer::usunAdresata() {
    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;

    if (adresaci.empty()) {
        cout << "Nie mozna usuwac adresatow. Ksiazka Adresaowa jest pusta" << endl << endl;
        return;
    }

    int idUsuwanegoAdresata = 0;
    idUsuwanegoAdresata = MetodyWczytujace::podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;
    bool czyUsuwanyAdresatJestPierwszymAdresatem = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (itr->pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyWczytujace::wczytajZnak();

            if (znak == 't' || znak == 'T') {
                if (itr == adresaci.begin())
                    czyUsuwanyAdresatJestPierwszymAdresatem = true;             // zabezpieczenie gdy pierwszy adresat w pliku ma id > 1

                plikZAdresatami.usunAdresataZPlikuTekstowego(idUsuwanegoAdresata, czyUsuwanyAdresatJestPierwszymAdresatem);
                adresaci.erase(itr);
                cout << endl << "Wybrany adresat zostal USUNIETY" << endl;
                system("pause");
                return;
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return;
            }
        }
    }

    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }

    return;
}

void AdresatMenedzer::wyswietlWszystkichAdresatowZalogowanegoUzytkownika() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    } else {
        cout << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}
