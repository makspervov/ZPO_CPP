#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
class BankAccount
{
private:
    std::string last_name_;
    std::string account_number_;
    double balance_;

public:
    BankAccount();
    BankAccount(std::string last_name, std::string account_number, double balance)
        :last_name_(last_name), account_number_(account_number), balance_(balance){};
    void add(double n){
        if(n>0)
            this->balance_ += n;
    }
    void withdraw(double n){
        if(n>0 && this->balance_>=n)
            this->balance_ -= n;
    }
    bool isMillionaire(){
        return this->balance_>=1000000 ? true : false;
    }
};

#endif // BANKACCOUNT_H
