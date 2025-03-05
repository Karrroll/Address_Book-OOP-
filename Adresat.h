#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat {
    int id, idUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;

public:
    int pobierzId() const { return id; };
    int pobierzIdUzytkownika() const { return idUzytkownika; };
    string pobierzImie() const { return imie; };
    string pobierzNazwisko() const { return nazwisko; };
    string pobierzNumerTelefonu() const { return numerTelefonu; };
    string pobierzEmail() const { return email; };
    string pobierzAdres() const { return adres; };

    void ustawId(const int &noweId);
    void ustawIdUzytkownika(const int &noweIdUzytkownika);
    void ustawImie(const string &noweImie) { imie = noweImie; };
    void ustawNazwisko(const string &noweNazwisko) { nazwisko = noweNazwisko; };
    void ustawNumerTelefonu(const string &nowyNumerTelefonu) { imie = nowyNumerTelefonu; };
    void ustawEmail(const string &nowyEmail) { email = nowyEmail; };
    void ustawAdres(const string &nowyAdres) { adres = nowyAdres; };
};

#endif
