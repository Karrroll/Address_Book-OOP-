#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat {
    int id, idUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;

public:
    Adresat(int id = 0, int idUzytkownika = 0, string imie = "", string nazwisko = "", string numerTelefonu = "", string email = "", string adres = "") {
        this->id = id;
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;
    }

    int pobierzId() const { return id; };
    int pobierzIdUzytkownika() const { return idUzytkownika; };
    string pobierzImie() const { return imie; };
    string pobierzNazwisko() const { return nazwisko; };
    string pobierzNumerTelefonu() const { return numerTelefonu; };
    string pobierzEmail() const { return email; };
    string pobierzAdres() const { return adres; };

    void ustawId(const int &id);
    void ustawIdUzytkownika(const int &idUzytkownika);
    void ustawImie(const string &imie) { this->imie = imie; };
    void ustawNazwisko(const string &nazwisko) { this->nazwisko = nazwisko; };
    void ustawNumerTelefonu(const string &numerTelefonu) { this->numerTelefonu = numerTelefonu; };
    void ustawEmail(const string &email) { this->email = email; };
    void ustawAdres(const string &adres) { this->adres = adres; };
};

#endif
