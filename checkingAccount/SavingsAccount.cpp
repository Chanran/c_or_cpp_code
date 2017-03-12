//
// Created by blue on 16-12-8.
//
#include "iostream"
#include "sstream"
#include "SavingsAccount.h"
#include "Date.h"
bool SavingsAccount::deposit(int id,double money){
    if (id == SavingsAccount::getId()){
        SavingsAccount::setBalance(SavingsAccount::getBalance()+money);
        return true;
    }
    return false;
}
bool SavingsAccount::withdrawal(int id,double money){
    if (id == SavingsAccount::getId()){
        if (SavingsAccount::getBalance() < money){
            return false;
        }else{
            SavingsAccount::setBalance(SavingsAccount::getBalance()-money);
            return true;
        }
    }
    return false;
}
const std::string &SavingsAccount::getCreateAt() const {
    return createAt;
}
SavingsAccount::SavingsAccount() {
    SavingsAccount::createAt = DateTime::currentTime();
}
bool SavingsAccount::isAllowedOverdraft() const {
    return allowedOverdraft;
}
std::string SavingsAccount:: toString(){
    std::ostringstream ostring;
    ostring <<  "Account:" << SavingsAccount::getId() << " balance:" << SavingsAccount::getBalance() << " CreateAt:" << SavingsAccount::getCreateAt();
    return ostring.str();
};