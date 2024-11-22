#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


const char SIMBOLIAI[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 "
                         "!\"#$%&'()*+,-./:;<=>?@[\1\]^_`{|}~";


void sifravimasSuMasyvu() {
    char tekstas[100];
    char raktas[100];
    char uzsifruotas[100];
    char desifruotas[100];
    int tekstoIlgis, raktoIlgis;

    cout << "Iveskite teksta kuri norite uzsifruoti: ";
    cin.ignore();
    cin.getline(tekstas, 100);
    cout << "Iveskite sifravimo rakta: ";
    cin.getline(raktas, 100);

    tekstoIlgis = strlen(tekstas);
    raktoIlgis = strlen(raktas);

    for (int i = 0; i < tekstoIlgis; i++) {
        const char* pozicijaTekste = strchr(SIMBOLIAI, tekstas[i]);
        const char* pozicijaRakte = strchr(SIMBOLIAI, raktas[i % raktoIlgis]);

        if (pozicijaTekste && pozicijaRakte) {
            int indeksasTekste = pozicijaTekste - SIMBOLIAI;
            int indeksasRakte = pozicijaRakte - SIMBOLIAI;
            uzsifruotas[i] = SIMBOLIAI[(indeksasTekste + indeksasRakte) % strlen(SIMBOLIAI)];
        } else {
            uzsifruotas[i] = tekstas[i];
        }
    }
    uzsifruotas[tekstoIlgis] = '\0';
    cout << "Uzsifruotas tekstas: " << uzsifruotas << endl;

    // Dešifravimas
    for (int i = 0; i < tekstoIlgis; i++) {
        const char* pozicijaTekste = strchr(SIMBOLIAI, uzsifruotas[i]);
        const char* pozicijaRakte = strchr(SIMBOLIAI, raktas[i % raktoIlgis]);

        if (pozicijaTekste && pozicijaRakte) {
            int indeksasTekste = pozicijaTekste - SIMBOLIAI;
            int indeksasRakte = pozicijaRakte - SIMBOLIAI;
            desifruotas[i] = SIMBOLIAI[(indeksasTekste - indeksasRakte + strlen(SIMBOLIAI)) % strlen(SIMBOLIAI)];
        } else {
            desifruotas[i] = uzsifruotas[i];
        }
    }
    desifruotas[tekstoIlgis] = '\0';
    cout << "Desifruotas tekstas: " << desifruotas << endl;
}

void sifravimasASCII() {
    char tekstas[128];
    char raktas[128];
    char uzsifruotas[128];
    char desifruotas[128];
    int tekstoIlgis, raktoIlgis;

    cout << "Iveskite teksta kuri norite uzsifruoti: ";
    cin.ignore();
    cin.getline(tekstas, 128);
    cout << "Iveskite sifravimo rakta: ";
    cin.getline(raktas, 128);

    tekstoIlgis = strlen(tekstas);
    raktoIlgis = strlen(raktas);


    for (int i = 0; i < tekstoIlgis; i++) {
        uzsifruotas[i] = (tekstas[i] + raktas[i % raktoIlgis]) % 128;
    }
    uzsifruotas[tekstoIlgis] = '\0';
    cout << "Uzsifruotas tekstas: " << uzsifruotas << endl;


    for (int i = 0; i < tekstoIlgis; i++) {
        desifruotas[i] = (uzsifruotas[i] - raktas[i % raktoIlgis] + 128) % 128;
    }
    desifruotas[tekstoIlgis] = '\0';
    cout << "Desifruotas tekstas: " << desifruotas << endl;
}

int main() {
    int pasirinkimas;
    bool testi = true;

    while (testi) {
        cout << "Pasirinkite sifravimo buda:\n";
        cout << "1. Sifravimas naudojant abecele\n";
        cout << "2. Sifravimas naudojant ASCII kodus\n";
        cout << "3. Uzdaryti programa\n";
        cout << "Iveskite pasirinkima: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                sifravimasSuMasyvu();
                break;
            case 2:
                sifravimasASCII();
                break;
            case 3:
                testi = false;
                cout << "Programa uzdaryta.\n";
                break;
            default:
                cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
        }
        cout << endl;
    }

    return 0;
}
