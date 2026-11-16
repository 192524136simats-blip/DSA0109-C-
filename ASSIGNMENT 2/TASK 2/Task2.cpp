#include <iostream>
using namespace std;

int& highestMark(int marks[], int n) {
    int highestIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (marks[i] > marks[highestIndex]) highestIndex = i;
    }
    return marks[highestIndex];
}

const int& highestMarkConst(const int marks[], int n) {
    int highestIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (marks[i] > marks[highestIndex]) highestIndex = i;
    }
    return marks[highestIndex];
}

int highestMarkCopy(const int marks[], int n) {
    int highestIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (marks[i] > marks[highestIndex]) highestIndex = i;
    }
    return marks[highestIndex];
}

int highestMarkIndex(const int marks[], int n) {
    int highestIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (marks[i] > marks[highestIndex]) highestIndex = i;
    }
    return highestIndex;
}

// DANGEROUS: never use this. It returns a reference to a local variable.
// int& danglingReference() {
//     int local = 50;
//     return local; // compiler warning; using the result is undefined behaviour
// }

int main() {
    int marks[] = {78, 91, 85, 88};
    int n = sizeof(marks) / sizeof(marks[0]);

    cout << "Highest before moderation: " << highestMark(marks, n) << '\n';
    highestMark(marks, n) += 2;
    cout << "Highest after moderation : " << highestMark(marks, n) << '\n';
    cout << "Read-only highest        : " << highestMarkConst(marks, n) << '\n';
    cout << "Copy of highest          : " << highestMarkCopy(marks, n) << '\n';

    int index = highestMarkIndex(marks, n);
    cout << "Index of highest          : " << index << '\n';
    cout << "Value using index         : " << marks[index] << '\n';
}
