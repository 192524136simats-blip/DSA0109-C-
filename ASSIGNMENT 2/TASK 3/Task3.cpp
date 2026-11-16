#include <iostream>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

double charge(int weightGrams) {
    cout << "int grams overload: ";
    return (weightGrams / 1000.0) * 50.0;
}

double charge(double weightKg, bool express = false, bool insured = false) {
    cout << "double kg overload: ";
    double total = weightKg * 50.0;
    if (express) total += 20.0;
    if (insured) total += 10.0;
    return total;
}

double charge(const Parcel& p) {
    cout << "Parcel overload: ";
    return charge(p.weightKg, p.express, p.insured);
}

int main() {
    cout << "charge(2) = " << charge(2) << '\n';
    cout << "charge(2.0f) = " << charge(2.0f) << '\n';
    cout << "charge(2.0) = " << charge(2.0) << '\n';
    cout << "charge(2.0, true) = " << charge(2.0, true) << '\n';
    cout << "charge(2.0, true, true) = " << charge(2.0, true, true) << '\n';

    Parcel p{3.0, false, true};
    cout << "charge(parcel) = " << charge(p) << '\n';
}
