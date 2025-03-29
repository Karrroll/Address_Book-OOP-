#include "PlikZAdresatami.h"

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(const Adresat &adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(const string &daneAdresataOddzielonePionowymiKreskami) {
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;
    Adresat adresat;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch (numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(const string &daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyWczytujace::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(const string &daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyWczytujace::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));

    return idAdresata;
}

void PlikZAdresatami::usunPlik(const string &nazwaPliku) {
    if (remove(nazwaPliku.c_str()) != 0)
        cout << "Nie udalo sie usunac pliku " << nazwaPliku << endl;
}

void PlikZAdresatami::zmienNazwePliku(const string &staraNazwa, const string &nowaNazwa) {
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) != 0)
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(const Adresat &adresat) {
    string liniaZDanymiAdresata = "";

    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good()) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (MetodyPomocnicze::czyPlikJestPusty(plikTekstowy))
            plikTekstowy << liniaZDanymiAdresata;
        else
            plikTekstowy << endl << liniaZDanymiAdresata ;

        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

void PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, const int idZalogowanegoUzytkownika) {
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    Adresat adresat;

    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good()) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    } else {
        if (errno != ENOENT) // jesli == to brak pliku Adresaci i zignoruj. W przeciwnym razie wypisz:
            cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
    }

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        ustawIdOstatniegoAdresata(idOstatniegoAdresata);
    } else {
        ustawIdOstatniegoAdresata(idOstatniegoAdresata);
    }
    return;
}

void PlikZAdresatami::usunAdresataZPlikuTekstowego(const int &idUsuwanegoAdresata, const bool &czyUsuwanyAdresatJestPierwszymAdresatem) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";

    string liniaZDanymiAdresata = "";
    int idAdresataZOdczytywanejLinii = 0, numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0) {
        while (getline(odczytywanyPlikTekstowy, liniaZDanymiAdresata)) {
            idAdresataZOdczytywanejLinii = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(liniaZDanymiAdresata);

            if (idAdresataZOdczytywanejLinii == idUsuwanegoAdresata) {}
            else if (numerWczytanejLinii == 1)
                tymczasowyPlikTekstowy << liniaZDanymiAdresata;
            else if (numerWczytanejLinii == 2 && tymczasowyPlikTekstowy.tellp() == 0)
                tymczasowyPlikTekstowy << liniaZDanymiAdresata;
            else if (numerWczytanejLinii > 1)
                tymczasowyPlikTekstowy << endl << liniaZDanymiAdresata;

            numerWczytanejLinii++;
        }


//            if (idAdresataZOdczytywanejLinii == idUsuwanegoAdresata) {}
//            else if (numerWczytanejLinii == 1/* && idAdresataZOdczytywanejLinii != idUsuwanegoAdresata*/)
//                tymczasowyPlikTekstowy << liniaZDanymiAdresata;
//            else if (numerWczytanejLinii == 2 && czyUsuwanyAdresatJestPierwszymAdresatem == true)
//                tymczasowyPlikTekstowy << liniaZDanymiAdresata;
//            else if (numerWczytanejLinii > 2 && czyUsuwanyAdresatJestPierwszymAdresatem == true)
//                tymczasowyPlikTekstowy << endl << liniaZDanymiAdresata;
//            else if (numerWczytanejLinii > 1 && czyUsuwanyAdresatJestPierwszymAdresatem != true)
//                tymczasowyPlikTekstowy << endl << liniaZDanymiAdresata;
//
//            numerWczytanejLinii++;
//        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
    }
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat &adresat) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";

    int numerWczytanejLinii = 1;
    string wczytanaLinia = "";
    string liniaZDanymiAdresata = "";

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true) {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {

            if (pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia) == adresat.pobierzId()) {
                liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresata;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresata;
            } else {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);      //walidacja
    }

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}
