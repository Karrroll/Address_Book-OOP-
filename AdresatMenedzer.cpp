#include "AdresatMenedzer.h"

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int idAktualnieZalogowanegoUzytkownika) {
    idZalogowanegoUzytkownika = idAktualnieZalogowanegoUzytkownika;                              //walidacja?
}

int AdresatMenedzer::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

void AdresatMenedzer::ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata) {
    idOstatniegoAdresata = noweIdOstatniegoAdresata;
}

void AdresatMenedzer::pobierzAdresatowZalogowanegoUzytkownikaZPliku() {
    PlikZAdresatami plikZAdresatami;
    ustawIdOstatniegoAdresata(plikZAdresatami.pobierzAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika));
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
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl;
    cout << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
