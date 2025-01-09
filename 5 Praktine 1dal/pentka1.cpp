#include <iostream>
#include <vector>
using namespace std;

void spausdintiLentele(const vector<vector<int>>& lentele) {
    cout << "Lentele:" << endl;
    for (int i = 0; i < lentele.size(); ++i) {
        for (int j = 0; j < lentele[i].size(); ++j) {
            cout << lentele[i][j] << " ";
        }
        cout << endl;
    }
}

void skaiciuotiEiluciuSumas(const vector<vector<int>>& lentele) {
    for (int i = 0; i < lentele.size(); ++i) {
        int suma = 0;
        for (int j = 0; j < lentele[i].size(); ++j) {
            suma += lentele[i][j];
        }
        cout << "Eilute " << i + 1 << " suma: " << suma << endl;
    }
}

void skaiciuotiStulpeliuSumas(const vector<vector<int>>& lentele) {
    if (lentele.empty()) return;
    for (int j = 0; j < lentele[0].size(); ++j) {
        int suma = 0;
        for (int i = 0; i < lentele.size(); ++i) {
            suma += lentele[i][j];
        }
        cout << "Stulpelis " << j + 1 << " suma: " << suma << endl;
    }
}

void rastiDidziausiaReiksme(const vector<vector<int>>& lentele) {
    int didziausia = lentele[0][0];
    for (int i = 0; i < lentele.size(); ++i) {
        for (int j = 0; j < lentele[i].size(); ++j) {
            if (lentele[i][j] > didziausia) {
                didziausia = lentele[i][j];
            }
        }
    }
    cout << "Didziausia reiksme: " << didziausia << endl;
}

int main() {
    int eilutes, stulpeliai;

    cout << "Iveskite eiluciu skaiciu: ";
    cin >> eilutes;
    cout << "Iveskite stulpeliu skaiciu: ";
    cin >> stulpeliai;

    vector<vector<int>> lentele(eilutes, vector<int>(stulpeliai));

    cout << "Iveskite lenteles reiksmes:" << endl;
    for (int i = 0; i < eilutes; ++i) {
        for (int j = 0; j < stulpeliai; ++j) {
            cout << "Reiksme [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> lentele[i][j];
        }
    }

    spausdintiLentele(lentele);
    skaiciuotiEiluciuSumas(lentele);
    skaiciuotiStulpeliuSumas(lentele);
    rastiDidziausiaReiksme(lentele);

    return 0;
}
