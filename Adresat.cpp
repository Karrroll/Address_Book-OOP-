#include "Adresat.h"

void Adresat::ustawId(const int &id) {
    if (id >= 0)
        this->id = id;
}

void Adresat::ustawIdUzytkownika(const int &idUzytkownika) {
    if (idUzytkownika >= 0)
        this->idUzytkownika = idUzytkownika;
}

