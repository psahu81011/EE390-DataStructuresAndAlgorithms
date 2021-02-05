#include<iostream>
#include<cstring>
#include"account.h"
using namespace std;

bool account_existence[100];
Account accounts[100];
int total_acc = 0;

//function to open account
void open_account(double amount, int pin) {
    if (total_acc == 100)
    {
        cout<<"Maximum number of accounts created!!!";
        return;
    }

    for (int i = 0; i < 100; i++)
    {
        if (!account_existence[i])
        {
            account_existence[i] = true;
            Account a(i,amount,pin);
            accounts[i] = a;
            cout<<"\nNew Account number: "<<accounts[i].get_account_number();
            return;
        }        
    }    
}


void balance_enquiry(int account_number, int pin) {
    int index = account_number - 1001;
    if (!account_existence[index])
    {
        cout<<"\nAccount does not exist!!!";
        return;
    }
    cout<<"\nAccount number: "<<account_number;
    cout<<"\nAccount balance: "<<accounts[index].get_account_balance();
    
}


void deposite(int account_number, double amount, int pin) {
    int index = account_number - 1001;
    if (!account_existence[index])
    {
        cout<<"\nAccount does not exist!!!";
        return;
    }
    accounts[index].deposite_money(amount);
    cout<<"\nAccount number: "<<account_number;
    cout<<"\nAccount balance: "<<accounts[index].get_account_balance();
}


void withdraw(int account_number, double amount, int pin) {
    int index = account_number - 1001;
    if (!account_existence[index])
    {
        cout<<"\nAccount does not exist!!!";
        return;
    }
    if (!accounts[index].enough_balance(amount))
    {
        cout<<"Not enough balance!!!";
        return;
    }
    accounts[index].withdraw_money(amount);
    cout<<"\nAccount number: "<<account_number;
    cout<<"\nAccount balance: "<<accounts[index].get_account_balance();
}


void close_account(int account_number, int pin) {
    int index = account_number - 1001;
    if (!account_existence[index])
    {
        cout<<"\nAccount does not exist!!!";
        return;
    }
    account_existence[index] = false;
    Account a;
    accounts[index] = a;
}


void compute_interest(float interest_rate) {
    for (int i = 0; i < 100; i++)
    {
        if (account_existence[i])
        {
            accounts[i].add_interest(interest_rate);
        }        
    }    
}
void print_all() {
    cout<<"\nAccount Number\t\tBalance";
    for (int i = 0; i < 100; i++)
    {
        if (account_existence[i])
        {
            accounts[i].show_details();
        }        
    }  
}

int main(int argc, char const *argv[])
{
    int manager_pin = 0000;
    bool bank_open = false;
    char transaction_type;
    double amount;
    int pin;
    int account_number;
    float interest_rate;
    memset(account_existence,false,sizeof(accounts));
    while (1)
    {
        cout<<"\nTransaction Type?:";
        cin>>transaction_type;
        if (!bank_open)
        {
            if (transaction_type == 'S')
            {
                cout<<"\nPIN?: ";
                cin>>pin;
                if (pin != manager_pin)
                {
                    cout<<"\nAccess Denied!!!";
                    continue;
                }
                else
                {
                    bank_open = true;
                    continue;
                }                
            }
            else
            {
                cout<<"\nBank Closed!!!";
                continue;
            }
            
        }
        switch (transaction_type)
        {
        case 'O':
            cout<<"\nInitial deposite?:";
            cin>>amount;
            cout<<"\nPIN?:";
            cin>>pin;
            open_account(amount,pin);
            break;

        case 'B':
            cout<<"\nAccount number?:";
            cin>>account_number;
            cout<<"\nPIN?:";
            cin>>pin;
            balance_enquiry(account_number,pin);
            break;
        
        case 'D':
            cout<<"\nAccount number?:";
            cin>>account_number;
            cout<<"\nAmount?:";
            cin>>amount;
            cout<<"\nPIN?:";
            cin>>pin;
            deposite(account_number,amount,pin);
            break;

        case 'W':
            cout<<"\nAccount number?:";
            cin>>account_number;
            cout<<"\nAmount?:";
            cin>>amount;
            cout<<"\nPIN?:";
            cin>>pin;
            withdraw(account_number,amount,pin);
            break;

        case 'C':
            cout<<"\nAccount number?:";
            cin>>account_number;
            cout<<"\nPIN?:";
            cin>>pin;
            close_account(account_number,pin);
            break;

        case 'I':
            cout<<"\nManager PIN?:";
            cin>>pin;
            if (pin == manager_pin)
            {
                cout<<"\nInterest Rate?:";
                cin>>interest_rate;
                compute_interest(interest_rate);
            }
            else
            {
                cout<<"\nAccess Denied!!!";
            }            
            break;
            
        case 'P':
            cout<<"\nManager PIN?:";
            cin>>pin;
            if (pin == manager_pin)
            {
                print_all();
            }
            else
            {
                cout<<"\nAccess Denied!!!";
            }            
            break;

        case 'E':
            cout<<"\nManager PIN?:";
            cin>>pin;
            if (pin == manager_pin)
            {
                exit(0);
            }
            else
            {
                cout<<"\nAccess Denied!!!";
            }            
            break;

        default:
            cout<<"Invalid Transaction Type!!!\nTry Again.....";
            break;
        }
    }    
    
    return 0;
}
