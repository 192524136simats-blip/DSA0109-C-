#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    long long balance;
    long long transactions[10]; // positive = deposit, negative = withdrawal
    int count;
    int next; // next position to overwrite when full

    void record(long long amount) {
        transactions[next] = amount;
        next = (next + 1) % 10;
        if (count < 10) ++count;
    }

public:
    SavingsAccount(const string& number, long long openingBalance)
        : accountNumber(number), balance(openingBalance), count(0), next(0) {}

    void deposit(long long amount) {
        if (amount <= 0) return;
        balance += amount;
        record(amount);
    }

    bool withdraw(long long amount) {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount;
        record(-amount);
        return true;
    }

    void miniStatement() const {
        cout << "Account: " << accountNumber << '\n';
        cout << "Balance: " << balance << '\n';
        cout << "Last " << count << " transactions:\n";
        int start = (count == 10) ? next : 0;
        for (int i = 0; i < count; ++i) {
            int index = (start + i) % 10;
            if (transactions[index] >= 0)
                cout << "Deposit: " << transactions[index] << '\n';
            else
                cout << "Withdrawal: " << -transactions[index] << '\n';
        }
    }
};

int main() {
    SavingsAccount account("SA1001", 1000);
    account.deposit(200);
    account.withdraw(150);
    account.deposit(500);
    account.withdraw(100);
    account.deposit(50);
    account.miniStatement();
}
