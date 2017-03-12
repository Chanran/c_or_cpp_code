//
// Created by blue on 16-12-8.
//

#include "iostream"
#include "sstream"
#include "CheckingAccount.h"
#include "Date.h"
bool CheckingAccount::deposit(int id,double money){
    if (id == CheckingAccount::getId()){
        CheckingAccount::setBalance(CheckingAccount::getBalance()+money);
        return true;
    }
    return false;
}
bool CheckingAccount::withdrawal(int id,double money){
    if (id == CheckingAccount::getId()){
        if (CheckingAccount::getBalance()-money <= (-CheckingAccount::getOverdraft())){
            return false;
        }else{
            CheckingAccount::setBalance(CheckingAccount::getBalance()-money);
            return true;
        }
    }
    return false;
}
const std::string &CheckingAccount::getCreateAt() const {
    return createAt;
}
CheckingAccount::CheckingAccount() {
    CheckingAccount::overdraft = 10000;
    CheckingAccount::createAt = DateTime::currentTime();
}
bool CheckingAccount::isAllowedOverdraft() const {
    return allowedOverdraft;
}
double CheckingAccount::getOverdraft() const {
    return CheckingAccount::overdraft;
}
void CheckingAccount::setOverdraft(double overdraft) {
    CheckingAccount::overdraft = overdraft;
}
std::string CheckingAccount:: toString(){
    std::ostringstream ostring;
    ostring << "Account:" << CheckingAccount::getId() << " balance:" << CheckingAccount::getBalance() << " CreateAt:" << CheckingAccount::getCreateAt();
    return ostring.str();
};