#include "MetodyWczytujace.h"

string MetodyWczytujace::wczytajLinie() {
    string wejscie = "";

    getline(cin, wejscie);
    return wejscie;
}

string MetodyWczytujace::pobierzLiczbe(const string &tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku])) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int MetodyWczytujace::wczytajLiczbeCalkowita() {
    int liczba = 0;
    string wejscie = "";

    while (true) {
        getline(cin, wejscie);
        stringstream myStream(wejscie);

        if (myStream >> liczba)
            return liczba;
        else
            cout << "To nie jest liczba. Wpisz ponownie." << endl;
    }
}

int MetodyWczytujace::podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;

    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

char MetodyWczytujace::wczytajZnak() {
    string wejscie = "";
    char znak  = {0};

    while (true) {
        getline(cin, wejscie);

        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}
