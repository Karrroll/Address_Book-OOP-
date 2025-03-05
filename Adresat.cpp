#include "Adresat.h"

void Adresat::ustawId(const int &noweId) {
    if (noweId >= 0)
        id = noweId;
}

void Adresat::ustawIdUzytkownika(const int &noweIdUzytkownika) {
    if (noweIdUzytkownika >= 0)
        idUzytkownika = noweIdUzytkownika;
}

