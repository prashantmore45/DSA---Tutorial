/*
Question 2 : Create a class BankAccount with private attributes accountNumber and 
balance. Implement public methods deposit(), withdraw(), and getBalance() to 
manage the account.
*/

#include <iostream>
using namespace std;

class BankAccount {

    private:
        int accountNumber;
        float balance;

    public:
        
        BankAccount(int accountNumber, float balance) {
            this->accountNumber = accountNumber;
            this->balance = balance;
        }

        void deposit(float amount) {
           balance += amount;
           cout << "Deposited: " << amount << endl;
           cout << "Current Balance: " << balance << endl;
        }

        void withdraw(float amount) {
            if (amount > balance) {
                cout << "Insufficient Balance" << endl;
            } else {
                balance -= amount;
                cout << "Withdrawn: " << amount <<endl;
                cout << "Current Balance: " << balance << endl;
            }
        }

        void getBalance() {
            cout << "Account Number : " << accountNumber << "\n";
            cout << "Total Available Balance : " << balance << "\n";
        }
};

int main() {
    BankAccount user1(123456789, 0);

    user1.getBalance();

    user1.deposit(25000);
    user1.getBalance();

    user1.withdraw(5000);
    user1.getBalance();

    return 0;
}