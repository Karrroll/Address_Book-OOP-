#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik {
    int id;
    string login, haslo;

public:
    int pobierzId() const { return id; };
    string pobierzLogin() const { return login; };
    string pobierzHaslo() const { return haslo; };

    void ustawId(const int &noweId);
    void ustawLogin(const string &nowyLogin) { login = nowyLogin; };
    void ustawHaslo(const string &noweHaslo) { haslo = noweHaslo; };
};

#endif
