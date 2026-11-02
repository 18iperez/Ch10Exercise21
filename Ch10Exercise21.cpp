
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class bankAccount {
private:
    string name;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate;

    static int nextAccountNumber;

public:
    bankAccount() {
        name = "";
        accountNumber = nextAccountNumber++;
        accountType = "";
        balance = 0.0;
        interestRate = 0.0;
    }

    void setAccountInfo(string customerName, string type, double amount, double rate) {
        name = customerName;
        accountType = type;
        balance = amount;
        interestRate = rate;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
        else {
            cout << "Invalid amount." << endl;
        }
    }

    double calculateInterest() {
        return balance * interestRate;
    }

    void displayAccount() {
        cout << fixed << setprecision(2);

        cout << "\nAccount Holder: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
        cout << "Interest Earned: $" << calculateInterest() << endl;
    }
};

int bankAccount::nextAccountNumber = 1;

int main() {
    bankAccount customers[10];

    int numberOfCustomers;
    string name, type;
    double balance, rate;

    cout << "How many customers do you want to enter? (Maximum 10): ";
    cin >> numberOfCustomers;


    for (int i = 0; i < numberOfCustomers; i++) {
        cout << "\nEnter information for customer " << i + 1 << endl;

        cout << "Name: ";
        cin >> name;

        cout << "Account Type (checking/saving): ";
        cin >> type;

        cout << "Balance: ";
        cin >> balance;

        cout << "Interest Rate (example: 0.05 for 5%): ";
        cin >> rate;

        customers[i].setAccountInfo(name, type, balance, rate);
    }

    for (int i = 0; i < numberOfCustomers; i++) {
        customers[i].displayAccount();
    }

    return 0;
}
