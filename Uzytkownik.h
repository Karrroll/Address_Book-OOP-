#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik {
    int id;
    string login, haslo;

public:
    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();

    void ustawId(int noweId);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);
};

#endif
