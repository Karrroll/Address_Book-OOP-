#include "MetodyWczytujace.h"

string MetodyWczytujace::wczytajLinie() {
    string wejscie = "";

    getline(cin, wejscie);
    return wejscie;
}

string MetodyWczytujace::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku])) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}
