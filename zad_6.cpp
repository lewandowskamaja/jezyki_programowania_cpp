//
//autor: Maja Lewandowska
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <stdexcept>
using namespace std;

void validation(string dna) {
    // walidacja zasad azotowych

    for (char base : dna) {
        if (base != 'A' && base != 'T' && base != 'C' && base != 'G') {
            throw invalid_argument("Nieprawidłowa zasada!");
        }
    }
}

string komplement(string dna) {
    // funkcja wyznaczajaca sekwencje nici matrycowej

    validation(dna);

    string matrycowa = "";

    // odczytywanie od ostatniego indeksu
    for (int i = dna.size() - 1; i >= 0; i--) {

        if (dna[i] == 'A') {
            matrycowa += 'T';
        }
        else if (dna[i] == 'T') {
            matrycowa += 'A';
        }
        else if (dna[i] == 'C') {
            matrycowa += 'G';
        }
        else if (dna[i] == 'G') {
            matrycowa += 'C';
        }
    }
    return matrycowa;

}

string transkrybuj(string dna) {
    // funkcja wyznaczajaca sekwencje rna

    validation(dna);

    string rna = "";

    for (int i = dna.size() - 1; i >= 0; i--) {

        if (dna[i] == 'A') {
            rna += 'U';
        }
        else if (dna[i] == 'T') {
            rna += 'A';
        }
        else if (dna[i] == 'C') {
            rna += 'G';
        }
        else if (dna[i] == 'G') {
            rna += 'C';
        }
    }
    return rna;
}

// TESTY

void test_1() {
    // poprawne dane - komplement

    assert(komplement("ATCC") == "GGAT");
}

void test_2() {
    // poprawne dane - transkrybuj

    assert(transkrybuj("GGAT") == "AUCC");
}

void test_3() {
    // niepoprawne dane

    try {
        komplement("ATH");
        assert(false);
    }
    catch (const invalid_argument& e) {}
}

// MAIN

int main() {

    test_1();
    test_2();
    test_3();

    string dna = "ATCGCCA";

    try {
        string matrycowa = komplement(dna);

        string rna = transkrybuj(matrycowa);


        cout << "Sekwencja kodujaca DNA: 5' " << dna << " 3'" << endl;
        cout << "Sekwencja matrycowa DNA: 3' " << matrycowa << " 5'" << endl;
        cout << "Sekwencja RNA: 5' " << rna << " 3'" << endl;
    }
    catch(const invalid_argument& e) {
        cout << e.what();
    }

    return 0;
}
