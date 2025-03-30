#include "AdresatMenedzer.h"

char AdresatMenedzer::wybierzOpcjeZMenuEdycja() {
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyWczytujace::wczytajZnak();

    return wybor;
}

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

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(const int &iloscAdresatow) {
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
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

    if (!adresaci.empty()) {
        char znak;
        bool czyIstniejeAdresat = false;
        int idUsuwanegoAdresata = 0;

        idUsuwanegoAdresata = MetodyWczytujace::podajIdWybranegoAdresata();

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr->pobierzId() == idUsuwanegoAdresata) {
                czyIstniejeAdresat = true;
                cout << endl << "Potwierdz naciskajac klawisz 't': ";
                znak = MetodyWczytujace::wczytajZnak();

                if (znak == 't' || znak == 'T') {
                    plikZAdresatami.usunAdresataZPlikuTekstowego(idUsuwanegoAdresata);
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
    } else {
        cout << "Nie mozna usuwac adresatow. Ksiazka Adresaowa jest pusta" << endl << endl;
        system("pause");
    }
}

void AdresatMenedzer::edytujAdresata() {
    system("cls");
    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;

    if (!adresaci.empty()) {
        char wybor = ' ';
        bool czyIstniejeAdresat = false;
        int idEdytowanegoAdresata = 0;
        string nowaZawartosc = "";
        Adresat edytowanyAdresat;

        idEdytowanegoAdresata = MetodyWczytujace::podajIdWybranegoAdresata();

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr->pobierzId() == idEdytowanegoAdresata) {
                czyIstniejeAdresat = true;
                edytowanyAdresat = *itr;

                wybor = wybierzOpcjeZMenuEdycja();

                switch (wybor) {
                case '1':
                    cout << "Podaj nowe imie: ";
                    nowaZawartosc = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyWczytujace::wczytajLinie());
                    edytowanyAdresat.ustawImie(nowaZawartosc);
                    break;
                case '2':
                    cout << "Podaj nowe nazwisko: ";
                    nowaZawartosc = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyWczytujace::wczytajLinie());
                    edytowanyAdresat.ustawNazwisko(nowaZawartosc);
                    break;
                case '3':
                    cout << "Podaj nowy numer telefonu: ";
                    edytowanyAdresat.ustawNumerTelefonu(MetodyWczytujace::wczytajLinie());
                    break;
                case '4':
                    cout << "Podaj nowy email: ";
                    edytowanyAdresat.ustawEmail(MetodyWczytujace::wczytajLinie());
                    break;
                case '5':
                    cout << "Podaj nowy adres zamieszkania: ";
                    edytowanyAdresat.ustawAdres(MetodyWczytujace::wczytajLinie());
                    break;
                case '6':
                    cout << endl << "Powrot do menu uzytkownika" << endl;
                    system("pause");
                    return;
                default:
                    cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl;
                    system("pause");
                    return;
                }

                plikZAdresatami.zaktualizujDaneWybranegoAdresata(edytowanyAdresat);
                *itr = edytowanyAdresat;
            }
        }

        if (czyIstniejeAdresat == false) {
            cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
            system("pause");
        } else {
            cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
            system("pause");
        }

    } else {
        cout << "Nie mozna edytowac adresatow. Ksiazka Adresaowa jest pusta" << endl << endl;
        system("pause");
    }
}

void AdresatMenedzer::wyszukajAdresataPoImieniu() {
    system("cls");
    cout << ">>> WYSZUKIWANIE ADRESATOW PO IMIENIU <<<" << endl << endl;

    if (!adresaci.empty()) {
        string imiePoszukiwanegoAdresata = "";
        int iloscAdresatow = 0;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyWczytujace::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr->pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }

        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
        system("pause");

    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl;
        system("pause");
    }
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
