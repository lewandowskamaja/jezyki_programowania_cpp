//
//autor: Maja Lewandowska
//

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
using namespace std;

vector<unsigned long long> collatz(unsigned long long c0) {
    // funkcja zwracajaca elementy ciagu

    if (c0 == 0) {
        throw invalid_argument("Liczba musi być dodatnia!");
    }

    vector<unsigned long long> result;

    //ostatni element to zawsze 1
    while (c0 != 1) {

        result.push_back(c0);

        if (c0 % 2 == 0) {
            // jesli parzysta
            c0 = c0 / 2;
        }
        else {
            // jesli nieparzysta
            c0 = 3 * c0 + 1;
        }
    }

    result.push_back(1);

    return result;
}

void ciekawostka() {

    unsigned long long maksymalna_wartosc = 0;
    unsigned long long c0_maksymalna = 0;

    unsigned long long najdluzszy_ciag = 0;
    unsigned long long c0_najdluzszy = 0;

    for (unsigned long long i = 1; i <= 100000; i++) {
        vector<unsigned long long> result = collatz(i);

        unsigned long long maksimum = 0;

        // szukanie maksimum
        for (unsigned long long x : result) {
            if (x > maksimum) {
                maksimum = x;
            }
        }

        // szukanie c0 dla maksimum
        if (maksimum > maksymalna_wartosc) {
            maksymalna_wartosc = maksimum;
            c0_maksymalna = i;
        }

        // szukanie najdluzszego ciagu
        if (result.size() > najdluzszy_ciag) {
            najdluzszy_ciag = result.size();
            c0_najdluzszy = i;
        }
    }
    cout << "Najwieksza wartosc: " << maksymalna_wartosc << endl;
    cout << "Dla c0: " << c0_maksymalna << endl;

    cout << "Najdluzszy ciag: " << najdluzszy_ciag << " elementow." << endl;
    cout << "Dla c0: " << c0_najdluzszy << endl;


}

// TESTY

void test_1() {
    // poprawne dane

    vector<unsigned long long> result = collatz(6);

    assert(result.size() == 9);
    assert(result[0] == 6);
    assert(result[1] == 3);
    assert(result[2] == 10);
    assert(result[3] == 5);
    assert(result[4] == 16);
    assert(result[5] == 8);
    assert(result[6] == 4);
    assert(result[7] == 2);
    assert(result[8] == 1);
}

void test_2() {
    // niepoprawna wartość

    try {
        collatz(0);
        assert(false);
    }
    catch (invalid_argument&) {
    }
}

// MAIN

int main() {

    test_1();
    test_2();
    ciekawostka();

    unsigned long long c0 = 6;

    try {
        vector<unsigned long long> result = collatz(c0);

        cout << endl;
        cout << "Ciag collatza: ";

        for (unsigned long long x : result) {
            cout << x << ", ";
        }
    }
    catch(const invalid_argument& e) {
        cout << e.what();
    }
    return 0;
}
