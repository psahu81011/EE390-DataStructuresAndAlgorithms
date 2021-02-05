#include<iostream>
#include<iomanip>
#include"account.h"
using namespace std;

Account::Account() {
    account_number = 0;
    balance = 0.0;
    pin = 0;
}

Account::Account(int index, double amount, int Pin) {
    account_number = 1001 + index;
    balance = amount;
    pin = Pin;
}

int Account::get_account_number() {
    return account_number;
}

double Account::get_account_balance() {
    return balance;
}

void Account::deposite_money(double amount) {
    balance = balance + amount;
}

bool Account::enough_balance(double amount) {
    return balance >= amount;
}

void Account::withdraw_money(double amount) {
    balance = balance - amount;
}

void Account::add_interest(float rate) {
    double interest = balance * (rate / 100);
    balance = balance + interest;
}

void Account::show_details() {
    cout<<account_number<<"\t\t"<<setprecision(2)<<fixed<<balance;
}