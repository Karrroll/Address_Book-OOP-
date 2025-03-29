#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int _main() {
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    while (true) {
        if (ksiazkaAdresowa.czyUzytkownikJestZalogowany() == false) {
            int wybranaOpcja = ksiazkaAdresowa.wybierzOpcjeZMenu("MENU_GLOWNE");

            switch (wybranaOpcja) {
                case 1: ksiazkaAdresowa.logowanieUzytkownika();     break;
                case 2: ksiazkaAdresowa.rejestracjaUzytkownika();   break;
                case 3: exit(0);
                default:
                    cout << endl << "Nieprawidlowy wybor! Sprobuj ponownie." << endl;
                    system("pause");
            }

        } else {
            int wybranaOpcja = ksiazkaAdresowa.wybierzOpcjeZMenu("MENU_UZYTKOWNIKA");

            switch (wybranaOpcja) {
                case 1: ksiazkaAdresowa.dodajAdresata();                                        break;
                case 2: /* ksiazkaAdresowa.wyszukajAdresataPoImieniu(); */                      break;
                case 3: /* ksiazkaAdresowa.wyszukajAdresataPoNazwisku(); */                     break;
                case 4: ksiazkaAdresowa.wyswietlWszystkichAdresatowZalogowanegoUzytkownika();   break;
                case 5: /*ksiazkaAdresowa.edytujAdresata();*/                                   break;
                case 6: ksiazkaAdresowa.usunAdresata();                                         break;
                case 8: ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();                   break;
                case 9: ksiazkaAdresowa.wylogujUzytkownika();                                   break;
                default:
                    cout << endl << "Nieprawidlowy wybor! Sprobuj ponownie." << endl;
                    system("pause");
            }

        }
    }
    return 0;
}

