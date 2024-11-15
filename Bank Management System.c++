#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// BANK MANAGEMENT SYSTEM -
class Account {
public:
    long int accountNumber;
    string username;
    float balance = 0;

    Account(long int accountNumber, string username, float initial_amount) {
        this->accountNumber = accountNumber;
        this->username = username;
        this->balance = initial_amount;
        cout << "____________________________" << endl;
        cout << "Account Created" << endl;
        cout << "____________________________" << endl;
    }

    void CheckBalance() { cout << "Balance: " << balance << endl; }

    void DepositMoney(float amount) { 
        balance += amount; 
        cout << "Deposit successful!" << endl;
    }

    void WithdrawMoney(float amount) {
        if (amount > balance) {
            cout << "____________________________" << endl;
            cout << "Insufficient balance." << endl;
            cout << "____________________________" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        }
    }
};

int main() {
    int choice;
    string username;
    long int accountNumber;
    float amount;
    vector<Account> accounts;

    int run = 1;
    while (run) {
        cout << "____________________________" << endl << endl;
        cout << "Enter your choice: B/w 1 - 4" << endl;
        cout << "1 : Create Your Account" << endl;
        cout << "2 : Deposit Money" << endl;
        cout << "3 : Withdraw Money" << endl;
        cout << "4 : Check Balance" << endl;
        cout << "0 : Exit" << endl;
        cout << "____________________________" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Create Your Account." << endl;
            cout << "Enter Your Name: ";
            cin >> username;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter Initial Amount: ";
            cin >> amount;

            bool accountExists = false;
            for (const auto &account : accounts) {
                if (account.accountNumber == accountNumber) {
                    accountExists = true;
                    break;
                }
            }
            if (accountExists) {
                cout << "____________________________" << endl;
                cout << "Account already exists." << endl;
                cout << "____________________________" << endl;
            } else {
                accounts.push_back(Account(accountNumber, username, amount));
            }
            break;
        }
        case 2: {
            cout << "Deposit Money" << endl;
            cout << "Enter Your Account Number: ";
            cin >> accountNumber;
            cout << "Enter Amount: ";
            cin >> amount;

            bool found = false;
            for (auto &account : accounts) {
                if (account.accountNumber == accountNumber) {
                    account.DepositMoney(amount);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found!" << endl;
            }
            break;
        }
        case 3: {
            cout << "Withdraw Money" << endl;
            cout << "Enter Your Account Number: ";
            cin >> accountNumber;
            cout << "Enter Amount: ";
            cin >> amount;

            bool found = false;
            for (auto &account : accounts) {
                if (account.accountNumber == accountNumber) {
                    account.WithdrawMoney(amount);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found!" << endl;
            }
            break;
        }
        case 4: {
            cout << "Check Balance" << endl;
            cout << "Enter Your Account Number: ";
            cin >> accountNumber;

            bool found = false;
            for (auto &account : accounts) {
                if (account.accountNumber == accountNumber) {
                    account.CheckBalance();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found!" << endl;
            }
            break;
        }
        case 0:
            run = 0;
            cout << "____________________________" << endl;
            cout << "Exiting..." << endl;
            cout << "____________________________" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
