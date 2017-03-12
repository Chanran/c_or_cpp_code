//
// Created by blue on 16-12-8.
//

#ifndef CHECKINGACCOUNTCLASS_CHECKINGACCOUNT_H
#define CHECKINGACCOUNTCLASS_CHECKINGACCOUNT_H
#include "Account.h"
class CheckingAccount : public Account {
private:
    bool allowedOverdraft;
    double overdraft;
    std::string createAt;
public:
    std::string toString() override;
    bool deposit(int id,double money);
    bool withdrawal(int id,double money);
public:
    CheckingAccount();
    const std::string &getCreateAt() const;
    bool isAllowedOverdraft() const;
    double getOverdraft() const;
    void setOverdraft(double overdraft);
};
#endif //CHECKINGACCOUNTCLASS_CHECKINGACCOUNT_H
