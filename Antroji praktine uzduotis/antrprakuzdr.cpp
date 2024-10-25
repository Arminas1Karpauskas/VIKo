#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funkcija, kuri tikrina, ar raide yra balse
bool Balse(char raide) {
    char balses[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < 10; ++i) {
        if (raide == balses[i]) {
            return true;
        }
    }
    return false;
}


// int bendrDaliklis(int skaicius1, int skaicius2) {
//     while (skaicius2 != 0) {
//         skaicius1 = skaicius1 % skaicius2;
//         skaicius1 = skaicius1 + skaicius2;
//         skaicius2 = skaicius1 - skaicius2;
//         skaicius1 = skaicius1 - skaicius2;
//     }
//     return skaicius1;
// }



int bendrDaliklis(int skaicius1, int skaicius2) {
    while (skaicius2 != 0) {
        int laikinas = skaicius2;
        skaicius2 = skaicius1 % skaicius2;
        skaicius1 = laikinas;
    }
    return skaicius1;
}


// Zaidimas
void zaidimas() {
    srand(time(0)); // sekla 1970 iki dabar sekundem
    int atsitiktinisSkaicius = rand() % 100 + 1; // skaicius nuo 1 iki 100
    int spejimas;

    while (true) {
        cout << "Atspekite skaiciu nuo 1 iki 100: ";
        cin >> spejimas;

        if (spejimas > atsitiktinisSkaicius) {
            cout << "Per didelis!\n";
        } else if (spejimas < atsitiktinisSkaicius) {
            cout << "Per mazas!\n";
        } else {
            cout << "Atspejai! " << atsitiktinisSkaicius << endl;
            break;
        }
    }
}

void fizzbuzz(int n) {
    for (int i = 1; i <= n; ++i) {
        if (i % 3 == 0 && i % 5 == 0) { // jei liekana 0 tada fizzbuzz
            cout << "FizzBuzz\n";
        } else if (i % 3 == 0) {
            cout << "Fizz\n";
        } else if (i % 5 == 0) {
            cout << "Buzz\n";
        } else {
            cout << i << endl;
        }
    }
}

void meniu() {
    while (true) {
        int pasirinkimas;

        // Tikriname ivesti
        cout << "\nPasirinkite veiksma:\n";
        cout << "1. Patikrinti ar raide yra balse\n";
        cout << "2. Zaidimas 'Atspek skaiciu'\n";
        cout << "3. FizzBuzz\n";
        cout << "4. Rasti didziausia bendra dalikli\n";
        cout << "5. Iseiti is programos\n";
        cout << "Iveskite pasirinkima (nuo 1 iki 5): ";

        if (!(cin >> pasirinkimas)) {  // Jei ivesta ne skaicius
            cout << "ERROR: Ivestis turi buti skaicius nuo 1 iki 5!\n";
            cin.clear();  // Isvalomas pasirinkimas
            cin.ignore(10000, '\n');  // ignoruojama sena ivestis
            continue;
        }

        // meniu pasirinkimai
        switch (pasirinkimas) {
            case 1: {
                char raide;
                cout << "Iveskite raide: ";
                cin >> raide;
                if (Balse(raide)) {
                    cout << "Tai yra balse.\n";
                } else {
                    cout << "Tai nera balse.\n";
                }
                break;
            }

            case 2:
                zaidimas();
                break;
            case 3: {
                int n;
                cout << "Iveskite teigiama skaiciu: ";
                cin >> n;
                fizzbuzz(n);
                break;
            }
            case 4: {
                int skaicius1, skaicius2;
                cout << "Iveskite du sveikuosius skaicius: ";
                cin >> skaicius1 >> skaicius2;
                cout << "Didziausias bendras daliklis: " << bendrDaliklis(skaicius1, skaicius2) << endl;
                break;
            }
            case 5:
                cout << "Programa baigia veikti.\n";
                return;
            default:
                cout << "Neteisingas pasirinkimas. Pasirinkti skaiciu nuo 1 iki 5.\n";
                break;
        }
    }
}

int main() {
    meniu();
    return 0;
}
