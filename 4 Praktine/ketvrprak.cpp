#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct MeniuElementas {
    string pavadinimas;
    double kaina;
};

void rodytiMeniu(MeniuElementas meniu[], int dydis) {
    cout << "Sveiki atvyke i restorana \"Goblinas\"\n";
    for (int i = 0; i < dydis; i++) {
        cout << i + 1 << ". " << meniu[i].pavadinimas << " - "
             << fixed << setprecision(2) << meniu[i].kaina << " EUR\n";
    }
}

int gautiPasirinkima(int maxNumeris) {
    int pasirinkimas;
    cout << "Pasirinkite patiekalo numeri (arba 0 baigti): ";
    while (true) {
        cin >> pasirinkimas;
        if (cin.fail() || pasirinkimas < 0 || pasirinkimas > maxNumeris) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Netinkamas pasirinkimas. Bandykite dar karta: ";
        } else {
            return pasirinkimas;
        }
    }
}

int gautiKieki() {
    int kiekis;
    cout << "Iveskite norima kieki: ";
    while (true) {
        cin >> kiekis;
        if (cin.fail() || kiekis <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Netinkamas kiekis. Bandykite dar karta: ";
        } else {
            return kiekis;
        }
    }
}

void spausdintiSaskaita(MeniuElementas meniu[], int pasirinkimai[], int kiekiai[], int pasirinktuKiekis) {
    double bendraSuma = 0.0;
    ofstream failas("saskaita.txt");

    cout << "\n--- Jusu saskaita ---\n";
    failas << "Sveiki atvyke i restorana \"Goblinas\"\n";

    for (int i = 0; i < pasirinktuKiekis; i++) {
        int indeksas = pasirinkimai[i] - 1;
        double kaina = meniu[indeksas].kaina * kiekiai[i];
        bendraSuma += kaina;

        cout << kiekiai[i] << " x " << meniu[indeksas].pavadinimas << " - "
             << fixed << setprecision(2) << kaina << " EUR\n";
        failas << kiekiai[i] << " x " << meniu[indeksas].pavadinimas << " - "
               << fixed << setprecision(2) << kaina << " EUR\n";
    }

    double pvm = bendraSuma * 0.21;
    double galutineSuma = bendraSuma + pvm;

    cout << "PVM (21%): " << fixed << setprecision(2) << pvm << " EUR\n";
    cout << "Galutine suma: " << fixed << setprecision(2) << galutineSuma << " EUR\n";

    failas << "PVM (21%): " << fixed << setprecision(2) << pvm << " EUR\n";
    failas << "Galutine suma: " << fixed << setprecision(2) << galutineSuma << " EUR\n";

    failas.close();
    cout << "Saskaita issaugota faile 'saskaita.txt'.\n";
}

int main() {
    MeniuElementas pusryciuMeniu[] = {
        {"Kiausiniene", 1.45},
        {"Kiaulienos sonine su keptu kiausiniu", 2.45},
        {"Keksiukas su vysnia", 0.99},
        {"Prancuziskas skrebutis", 1.99},
        {"Vaisiu salotos", 2.49},
        {"Pusryciu dribsniai", 0.69},
        {"Kava", 0.50},
        {"Arbata", 0.75}
    };

    const int meniuDydis = 8;

    int pasirinkimai[100];
    int kiekiai[100];
    int pasirinktuKiekis = 0;

    while (true) {
        rodytiMeniu(pusryciuMeniu, meniuDydis);
        int pasirinkimas = gautiPasirinkima(meniuDydis);
        if (pasirinkimas == 0) break;

        int kiekis = gautiKieki();

        pasirinkimai[pasirinktuKiekis] = pasirinkimas;
        kiekiai[pasirinktuKiekis] = kiekis;
        pasirinktuKiekis++;
    }

    if (pasirinktuKiekis > 0) {
        spausdintiSaskaita(pusryciuMeniu, pasirinkimai, kiekiai, pasirinktuKiekis);
    } else {
        cout << "Jusu uzsakymas tuscias. Aciu uz apsilankyma!\n";
    }

    return 0;
}
