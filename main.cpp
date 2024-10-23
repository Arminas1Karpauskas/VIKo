#include <iostream>
using namespace std;

// Funkcija, kuri apskaičiuoja kvadrato perimetrą
int suskaičiuotiPerimetra(int krastine) {
    return 4 * krastine;
}

// Funkcija, kuri apskaičiuoja kvadrato plotą
void suskaiciuotiPlota(int krastine, int& plotas) {
    plotas = krastine * krastine;
}

int main() {
    int krastine = 5;
    int plotas;

    // Apskaičiuojame perimetrą
    int perimetras = suskaičiuotiPerimetra(krastine);
    cout << "Kvadrato perimetras: " << perimetras << endl;

    // Apskaičiuojame plotą
    suskaiciuotiPlota(krastine, plotas);
    cout << "Kvadrato plotas: " << plotas << endl;

    return 0;
}
