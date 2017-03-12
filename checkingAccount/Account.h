//
// Created by blue on 16-12-8.
//

#ifndef CHECKINGACCOUNTCLASS_ACCOUNT_H
#define CHECKINGACCOUNTCLASS_ACCOUNT_H

#include<string>

class Account {

private:
    int id;
    double balance;
    double annualInterestRate;
public:
    Account();
    virtual std::string toString();

public:
    int getId();

    void setId(int id);

    double getBalance();

    void setBalance(double balance);

    double getAnnualInterestRate();

    void setAnnualInterestRate(double annualInterestRate);
};



#endif //CHECKINGACCOUNTCLASS_ACCOUNT_H
