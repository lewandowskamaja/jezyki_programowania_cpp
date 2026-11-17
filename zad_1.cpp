//
//autor: Maja Lewandowska
//

#include <iostream> //obsluga wejscia i wyjscia
#include <cmath>
#include <iomanip> //formatowanie wyswietlanych danych
#include <cassert>
#include <stdexcept>
using namespace std;

double heron(double a, double b, double c) {
    // funkcja obliczajaca pole trojkata

    if (a <= 0 || b <= 0 || c <= 0) {
        throw invalid_argument("Liczby musza byc dodatnie!");
    }

    if (a + b <= c || a + c <= b || b + c <= a) {
        throw invalid_argument("Niepoprawna dlugosc bokow!");
    }

    double p = (a + b + c)/2; //polowa obwodu
    double S = sqrt(p * (p - a) * (p - b) * (p - c));

    return S;
}

// TESTY

void test_1() {
    // prawidlowe dane

    assert(heron(3, 4, 5) == 6);
}

void test_2() {
    // boki ujemne

    try {
        heron(3, 4, -5);
        assert(false);
    }
    catch (const invalid_argument& e) {}
}

void test_3() {
    // nieprawidlowa dlugosc

    try {
        heron(2, 3, 8);
        assert(false);
    }
    catch (const invalid_argument& e) {}
}

// MAIN

int main() {
    test_1();
    test_2();
    test_3();

    double a, b, c;

    try {
        cout << "Podaj bok a: ";
        if (!(cin >> a)) {
            throw invalid_argument("Niepoprawny typ danych!");
        }

        cout << "Podaj bok b: ";
        if (!(cin >> b)) {
            throw invalid_argument("Niepoprawny typ danych!");
        }

        cout << "Podaj bok c: ";
        if (!(cin >> c)) {
            throw invalid_argument("Niepoprawny typ danych!");
        }

        double S = heron(a, b, c);
        cout << fixed << setprecision(2);
        cout << "Pole trojkata to: " << S;
    }
    catch (const invalid_argument& e) {
        // & oznacza referencje do zmiennej
        cout << e.what();
    }
    return 0;
}