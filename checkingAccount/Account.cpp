//
// Created by blue on 16-12-8.
//

#include "iostream"
#include "sstream"
#include "Account.h"

Account::Account() {
    Account::id = 0;
    Account::balance = 0;
    Account::annualInterestRate = 0;
}

int Account::getId() {
    return id;
}

void Account::setId(int id) {
    Account::id = id;
}

double Account::getBalance() {
    return balance;
}

void Account::setBalance(double balance) {
    Account::balance = balance;
}

double Account::getAnnualInterestRate() {
    return annualInterestRate;
}

void Account::setAnnualInterestRate(double annualInterestRate) {
    Account::annualInterestRate = annualInterestRate;
}

std::string Account:: toString(){

    std::ostringstream ostring;
    ostring <<  "Account:" << Account::getId() << " balance:" << Account::getBalance();

    return ostring.str();
};
