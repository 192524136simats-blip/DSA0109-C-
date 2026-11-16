#include <iostream>
#include <chrono>
using namespace std;

class Time {
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;
    int difference = first - second;
    return difference < 0 ? -difference : difference;
}

inline bool earlier(const Time& a, const Time& b) {
    return (a.h * 60 + a.m) < (b.h * 60 + b.m);
}

int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    Time same1(12, 0), same2(12, 0);
    cout << minutesBetween(same1, same2) << ' '
         << earlier(same1, same2) << '\n';

    Time beforeNoon(11, 55), afterNoon(12, 5);
    cout << minutesBetween(beforeNoon, afterNoon) << ' '
         << earlier(beforeNoon, afterNoon) << '\n';

    // Simple timing loop. Results depend on compiler, machine and optimisation flags.
    volatile int sink = 0;
    const int repetitions = 10000000;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < repetitions; ++i)
        sink = sink + minutesBetween(departure, arrival);
    auto finish = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(finish - start).count();
    cout << "10,000,000 calls took " << elapsed << " microseconds (machine-dependent)\n";
    (void)sink;
}
