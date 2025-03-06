#ifndef MetodyPomocnicze_H
#define MetodyPomocnicze_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze {

public:
    static string konwerjsaIntNaString(const int &liczba);
    static int konwersjaStringNaInt(const string &liczba);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif
