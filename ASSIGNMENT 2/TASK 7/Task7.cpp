#include <iostream>
using namespace std;

const int CAPACITY = 50;
const int INSERTIONS = 10000;

// Original design: shift all retained items left when full.
long long testShifting(int& lastValue) {
    int data[CAPACITY] = {};
    int count = 0;
    long long assignments = 0;

    for (int value = 1; value <= INSERTIONS; ++value) {
        if (count < CAPACITY) {
            data[count++] = value;
            ++assignments;
        } else {
            for (int i = 1; i < CAPACITY; ++i) {
                data[i - 1] = data[i];
                ++assignments;
            }
            data[CAPACITY - 1] = value;
            ++assignments;
        }
    }
    lastValue = data[CAPACITY - 1];
    return assignments;
}

// Redesigned: circular buffer overwrites the oldest item in O(1).
long long testCircular(int& lastValue) {
    int data[CAPACITY] = {};
    int next = 0;
    for (int value = 1; value <= INSERTIONS; ++value) {
        data[next] = value;
        next = (next + 1) % CAPACITY;
    }
    // The most recently inserted value is immediately before next.
    lastValue = data[(next + CAPACITY - 1) % CAPACITY];
    return INSERTIONS; // one array assignment per insertion
}

int main() {
    int shiftLast = 0, circularLast = 0;
    long long shiftAssignments = testShifting(shiftLast);
    long long circularAssignments = testCircular(circularLast);

    cout << "Insertions: " << INSERTIONS << '\n';
    cout << "Capacity: " << CAPACITY << '\n';
    cout << "Shifting assignments: " << shiftAssignments << '\n';
    cout << "Circular assignments: " << circularAssignments << '\n';
    cout << "Last value (shifting): " << shiftLast << '\n';
    cout << "Last value (circular): " << circularLast << '\n';
}
