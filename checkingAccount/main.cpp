#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main() {

    SavingsAccount savingsAccount;
    CheckingAccount checkingAccount;

    cout << "SavingsAccount:" << savingsAccount.toString() << endl;
    cout << "CheckingAccount" << checkingAccount.toString() << endl;

    return 0;
}
