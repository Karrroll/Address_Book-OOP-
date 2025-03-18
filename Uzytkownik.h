#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik {
    int id;
    string login, haslo;

public:
    Uzytkownik(int id = 0, string login = "", string haslo = "") {
        this->id = id;
        this->login = login;
        this->haslo = haslo;
    }

    int pobierzId() const { return id; };
    string pobierzLogin() const { return login; };
    string pobierzHaslo() const { return haslo; };

    void ustawId(const int &noweId);
    void ustawLogin(const string &login) { this->login = login; };
    void ustawHaslo(const string &haslo) { this->haslo = haslo; };
};

#endif
