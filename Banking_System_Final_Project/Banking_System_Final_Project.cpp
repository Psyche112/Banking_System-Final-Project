#include <iostream>
#include <string>
/*Create new account (sign-up)
Login with PIN or password
View account details (name, account number, balance)
 Transactions
Deposit money
Withdraw money (with balance check)
Check balance
Simple transaction confirmation (Y/N)
Show last transaction
Menu System
Main menu (Deposit, Withdraw, Balance, Exit)
Input validation (check if user enters invalid input)
Logout option*/
using std::cout;
using std::cin;
using std::endl;

std::string AccUsername;
int AccPin{};
int AccountNumber = 1000;
double AccBalance = 0;
char again{};

static void CreateAccount() {
    
    cout << "==Create Account==" << '\n';
    cout << "Enter a username : ";
    cin >> AccUsername; 
    cout << "Enter a pin (4-didgit):  ";
    cin >> AccPin;
    AccountNumber =  (AccPin * 19) + 2689;

    }


static bool Login() {
    std::string username;
    int pin, LoginCounter = 3;
    while(LoginCounter > 0){
        cout << "\n== LOGIN ==\n";
        cout << "Enter username:  ";
        cin >> username;
        cout << "Enter pin: ";
        cin >> pin;
        if (username == AccUsername && pin == AccPin) {
            cout << "Access Granted!" << '\n';
            return true;
        }
        LoginCounter--;
        cout << "Incorrect Credentials" << '\n';
    }
    cout << "Access Denied!" << '\n';
    return false;
}
static void ViewAccount() {
    cout << "\n == Account == " << endl;
    cout << "Username: " << AccUsername << endl;
    cout << "Account Number: " << AccountNumber << endl;
    cout << "Balance: " << AccBalance << endl;
}
static void DepositMoney() {
    while (true) {
        double moneyDeposit;
        cout << "==Money Deposit == " << endl;
        cout << " Deposit: ";
        cin >> moneyDeposit;
        if (moneyDeposit <= 0) {
            cout << "Invalid Fund" << '\n';
            cout << "Enter a positive number" << '\n';
        }
        if (moneyDeposit > 500000) {
            cout << "500,000 limit exceeded!" << '\n';
            cout << "Deposit need to be 500,000 below" << '\n';

        }

        AccBalance = AccBalance + moneyDeposit;
        cout << "Deposit Successful" << '\n';
        cout << "Do you want to do another transaction(y/n)? ";
        cin >> again;
        if (again == 'Y' || again == 'y') {
            DepositMoney();
        }
        else if (again == 'N' || again == 'n') {
            break;
        }
    }
}

    static void WithdrawMoney() {
        double moneyWithdraw;
        cout << "== Withdraw Money" << '\n';
        cout << "Withdraw Funds: ";
        cin >> moneyWithdraw;
        if (moneyWithdraw > AccBalance) {
            cout << "Insufficient Funds" << '\n';
            return;
        }
        AccBalance = AccBalance - moneyWithdraw;
        cout << "New Balance: " << AccBalance << endl; 

        cout << "Do you want to do another transaction(y/n)? ";
        cin >> again;
        if (again == 'Y' || again == 'y') {
            WithdrawMoney();

        }
        else if (again == 'N' || again == 'n') {
            return;
        }
    }
    static void MainMenu() {
        int menu;
        char again = 'y';

        while (again == 'y' || again == 'Y') {
            cout << " \nMain Menu:"<< '\n';
            cout << "1. Deposit Money" << '\n';
            cout << "2. Withdraw Money" << '\n';
            cout << "3. View Account" << '\n';
            cout << "Enter choice: ";
            cin >> menu;

            if (menu == 1) {
                DepositMoney();
            }
            else if (menu == 2) {
                WithdrawMoney();
            }
            else if (menu == 3) {
                ViewAccount();
            }
            else {
                cout << "Invalid choice!" << '\n';
            }

            cout << "Do you want to return to main menu? (y/n): ";
            cin >> again;
        }
    }



int main()
{
    CreateAccount();
    if (!Login()) {
        return false;
    }
    MainMenu();

}

