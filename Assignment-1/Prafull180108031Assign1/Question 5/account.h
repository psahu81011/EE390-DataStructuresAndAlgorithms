#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
    private:
        int account_number;
        double balance;
        int pin;
    public:
        Account();
        Account(int index,double amount,int Pin);
        int get_account_number();
        double get_account_balance();
        void deposite_money(double amount);
        bool enough_balance(double amount);
        void withdraw_money(double amount);
        void add_interest(float rate);
        void show_details();
};

#endif