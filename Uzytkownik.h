#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik {
    int id;
    string login, haslo;

public:
    int pobierzId() { return id; };
    string pobierzLogin() { return login; };
    string pobierzHaslo() { return haslo; };

    void ustawId(int noweId);
    void ustawLogin(string nowyLogin) { login = nowyLogin; };
    void ustawHaslo(string noweHaslo) { haslo = noweHaslo; };
};

#endif
