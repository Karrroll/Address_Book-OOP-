#include "MetodyWczytujace.h"

string MetodyWczytujace::wczytajLinie() {
    string wejscie = "";                            // do naglowkowego i wprowadzic zabezpieczenia

    getline(cin, wejscie);
    return wejscie;
}
