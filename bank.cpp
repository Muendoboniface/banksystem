#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    float accountBalance;
    int PIN;
public:
    BankAccount(int accNum, string accHolderName, float accBalance, int pin) {
        accountNumber = accNum;
        accountHolderName = accHolderName;
        accountBalance = accBalance;
        PIN = pin;
    }

    void deposit(float amount) {
        accountBalance += amount;
        cout << "Deposit successful. New balance: " << accountBalance << endl;
    }

    void withdraw(float amount) {
        if (amount > accountBalance) {
            cout << "Withdrawal unsuccessful. Insufficient balance." << endl;
        } else {
            accountBalance -= amount;
            cout << "Withdrawal successful. New balance: " << accountBalance << endl;
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Balance: " << accountBalance << endl;
    }

    float checkBalance(int pin) {
        if (pin != PIN) {
            cout << "Authentication failed. Incorrect PIN." << endl;
            return -1;
        } else {
            cout << "Your account balance is: " << accountBalance << endl;
            return accountBalance;
        }
    }
};

int main() {
    BankAccount myAccount(4893042, "BONIFACE MUENDO", 5000.0, 1234);
    int choice;
    float amount;
    int pin;
    cout << "Welcome to the RESOURCE BANK!" << endl;
    do {
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Display Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                cout<<"Enter your pin:";
                cin>>pin;
                myAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                cout<<"Enter your pin:";
                cin>>pin;
                myAccount.withdraw(amount);
                break;
            case 3:
                cout << "Enter PIN: ";
                cin >> pin;
                myAccount.checkBalance(pin);
                break;
            case 4:
                myAccount.display();
                break;
            case 5:
                cout << "Thank you for banking with us!" << endl;
                break;
            default:
                cout << "Invalid option selected." << endl;
        }
    } while (choice != 5);
    return 0;
}
