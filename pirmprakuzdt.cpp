#include <iostream>
#include <iomanip>
using namespace std;

// pritaikomas valiutu kainos funkcijoms
const double GBP_Bendras = 0.8593, GBP_Pirkti = 0.8450, GBP_Parduoti = 0.9060;
const double USD_Bendras = 1.0713, USD_Pirkti = 1.0547, USD_Parduoti = 1.1309;
const double INR_Bendras = 88.8260, INR_Pirkti = 85.2614, INR_Parduoti = 92.8334;

// deklaruojamos funkcijos
void valiutosPalyginimas();
void valiutosPirkimas();
void valiutosPardavimas();
void iseiti();

// sukuriama isvestis pasirinkimams su funkciju iskvietimu
int main() {
    int pasirinkimas;
    cout << "Pasirinkite paslaugos numeri:\n";
    cout << "1 - Valiutos palyginimas\n";
    cout << "2 - Pirkti valiuta\n";
    cout << "3 - Parduoti valiuta\n";
    cout << "4 - Iseiti is programos\n";
    cin >> pasirinkimas;

    switch (pasirinkimas) {
        case 1:
            valiutosPalyginimas();
            break;
        case 2:
            valiutosPirkimas();
            break;
        case 3:
            valiutosPardavimas();
            break;
        case 4:
            iseiti();
        default:
            cout << "Neteisingas pasirinkimas\n";
            break;

    }

    return 0;
}

// kuriama funkcija valiutos kursu palyginimui
void valiutosPalyginimas() {
    int pasirinktaValiuta;
    cout << "Pasirinkite valiutos numeri palyginimui:\n";
    cout << "1 - GBP\n";
    cout << "2 - USD\n";
    cout << "3 - INR\n";
    cin >> pasirinktaValiuta;

    if (pasirinktaValiuta == 1) {
        cout << "1 EUR = " << GBP_Bendras << " GBP\n";
    } else if (pasirinktaValiuta == 2) {
        cout << "1 EUR = " << USD_Bendras << " USD\n";
    } else if (pasirinktaValiuta == 3) {
        cout << "1 EUR = " << INR_Bendras << " INR\n";
    } else {
        cout << "Neteisingas pasirinkimas\n";
    }
}

// Funkcija valiutos pirkimui
void valiutosPirkimas() {
    int pasirinktaValiuta;
    double kiekis;
    cout << "Pasirinkite valiutą pirkimui:\n";
    cout << "1 - GBP\n";
    cout << "2 - USD\n";
    cout << "3 - INR\n";
    cin >> pasirinktaValiuta;

    cout << "Įveskite euru kieki: ";
    cin >> kiekis;

    cout << fixed << setprecision(2);

    if (pasirinktaValiuta == 1) {
        cout << "Jūs gausite " << kiekis / GBP_Pirkti << " GBP\n";
    } else if (pasirinktaValiuta == 2) {
        cout << "Jūs gausite " << kiekis / USD_Pirkti << " USD\n";
    } else if (pasirinktaValiuta == 3) {
        cout << "Jūs gausite " << kiekis / INR_Pirkti << " INR\n";
    } else {
        cout << "Neteisingas pasirinkimas\n";
    }
}

// Funkcija valiutos pardavimui
void valiutosPardavimas() {
    int pasirinktaValiuta;
    double kiekis;
    cout << "Pasirinkite valiutos numeri pardavimui:\n";
    cout << "1 - GBP\n";
    cout << "2 - USD\n";
    cout << "3 - INR\n";
    cin >> pasirinktaValiuta;

    cout << "Įveskite parduodamos valiutos kiekį: ";
    cin >> kiekis;

    cout << fixed << setprecision(2);

    if (pasirinktaValiuta == 1) {
        cout << "Jūs gausite " << kiekis * GBP_Parduoti << " EUR\n";
    } else if (pasirinktaValiuta == 2) {
        cout << "Jūs gausite " << kiekis * USD_Parduoti << " EUR\n";
    } else if (pasirinktaValiuta == 3) {
        cout << "Jūs gausite " << kiekis * INR_Parduoti << " EUR\n";
    } else {
        cout << "Neteisingas pasirinkimas\n";
    }
}
void iseiti() {
    cout << "Iseinate is programos.\n";
    exit(0); // iseiti is programos
}