#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Kontaktas {
    int id;
    string vardas;
    string pavarde;
    string telefonas;
};

int main() {
    vector<Kontaktas> kontaktai;
    int idSkaiciuokle = 1;

    while (true) {
        cout << "Pasirinkite veiksma:\n";
        cout << "1. Prideti kontakta\n";
        cout << "2. Perziureti visus kontaktus\n";
        cout << "3. Atnaujinti kontakta\n";
        cout << "4. Istrinti kontakta\n";
        cout << "0. Iseiti\n";
        cout << "Pasirinkite: ";

        int pasirinkimas;
        cin >> pasirinkimas;

        if (pasirinkimas == 0) {
            cout << "Programa baigta.\n";
            break;
        }

        if (pasirinkimas == 1) {
            Kontaktas naujasKontaktas;
            naujasKontaktas.id = idSkaiciuokle++;
            cout << "Iveskite varda: ";
            cin >> naujasKontaktas.vardas;
            cout << "Iveskite pavarde: ";
            cin >> naujasKontaktas.pavarde;
            cout << "Iveskite telefona: ";
            cin >> naujasKontaktas.telefonas;

            kontaktai.push_back(naujasKontaktas);
            cout << "Kontaktas pridetas!\n";
        }
        else if (pasirinkimas == 2) {
            if (kontaktai.empty()) {
                cout << "Kontaktai dar neprideti.\n";
            } else {
                cout << "Visi kontaktai:\n";
                for (size_t i = 0; i < kontaktai.size(); ++i) {
                    cout << "ID: " << kontaktai[i].id << " | Vardas: " << kontaktai[i].vardas << " | Pavarde: " << kontaktai[i].pavarde << " | Telefonas: " << kontaktai[i].telefonas << "\n";
                }
            }
        }
        else if (pasirinkimas == 3) {
            cout << "Iveskite ID kontaktui atnaujinti: ";
            int id;
            cin >> id;

            bool rasta = false;
            for (size_t i = 0; i < kontaktai.size(); ++i) {
                if (kontaktai[i].id == id) {
                    cout << "Naujas vardas (dabartinis: " << kontaktai[i].vardas << "): ";
                    cin >> kontaktai[i].vardas;
                    cout << "Nauja pavarde (dabartine: " << kontaktai[i].pavarde << "): ";
                    cin >> kontaktai[i].pavarde;
                    cout << "Naujas telefonas (dabartinis: " << kontaktai[i].telefonas << "): ";
                    cin >> kontaktai[i].telefonas;
                    cout << "Kontaktas atnaujintas.\n";
                    rasta = true;
                    break;
                }
            }

            if (!rasta) {
                cout << "Kontaktas su ID " << id << " nerastas.\n";
            }
        }
        else if (pasirinkimas == 4) {
            cout << "Iveskite ID kontaktui istrinti: ";
            int id;
            cin >> id;

            bool istrintas = false;
            for (size_t i = 0; i < kontaktai.size(); ++i) {
                if (kontaktai[i].id == id) {
                    kontaktai.erase(kontaktai.begin() + i);
                    cout << "Kontaktas istrintas.\n";
                    istrintas = true;
                    break;
                }
            }

            if (!istrintas) {
                cout << "Kontaktas su ID " << id << " nerastas.\n";
            }
        }
        else {
            cout << "Netinkamas pasirinkimas.\n";
        }
    }

    return 0;
}
