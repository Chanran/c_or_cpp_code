//
// Created by blue on 16-12-8.
//

#ifndef CHECKINGACCOUNTCLASS_SAVINGSACCOUNT_H
#define CHECKINGACCOUNTCLASS_SAVINGSACCOUNT_H
#include <string>
#include "Account.h"
class SavingsAccount : public Account {
private:
    bool allowedOverdraft;
    std::string createAt;
public:
    std::string toString() override;
    bool deposit(int id,double money);
    bool withdrawal(int id,double money);
public:
    SavingsAccount();
    const std::string &getCreateAt() const;
    bool isAllowedOverdraft() const;
};
#endif //CHECKINGACCOUNTCLASS_SAVINGSACCOUNT_H
