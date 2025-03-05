#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat {
    int id, idUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;

public:
    int pobierzId() { return id; };
    int pobierzIdUzytkownika() { return idUzytkownika; };
    string pobierzImie() { return imie; };
    string pobierzNazwisko() { return nazwisko; };
    string pobierzNumerTelefonu() { return numerTelefonu; };
    string pobierzEmail() { return email; };
    string pobierzAdres() { return adres; };

    void ustawId(int noweId);
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawImie(string noweImie) { imie = noweImie; };
    void ustawNazwisko(string noweNazwisko) { nazwisko = noweNazwisko; };
    void ustawNumerTelefonu(string nowyNumerTelefonu) { imie = nowyNumerTelefonu; };
    void ustawEmail(string nowyEmail) { email = nowyEmail; };
    void ustawAdres(string nowyAdres) { adres = nowyAdres; };
};

#endif
