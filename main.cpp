#include <iostream>
#include <vector>
#include "Transaction.h"
using namespace std;

class Account
{
private:
    int accountNumber;
    double balance;
    string accountHolder;
    string dateCreated;
    bool isActive;

public:
    Account(int accountNumber, double balance, string accountHolder, string dateCreated, bool isActive)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->accountHolder = accountHolder;
        this->dateCreated = dateCreated;
        this->isActive = isActive;
    }
    void deposite(double amount)
    {
        if (amount > 0)
        {
            this->balance += amount;
        }
        else
        {
            cout << "the amount is not valid" << endl;
        }
    }
    void withdraw(double amount)
    {

        this->balance -= amount;
    }
    void displayAccountInfo()
    {
        cout << "**********************************************" << endl;
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Acount balance: " << this->balance << endl;
        cout << "Acount Holder: " << this->accountHolder << endl;
        cout << "Acount date of creating: " << this->dateCreated << endl;
        cout << (isActive ? "the account is acitve" : "the account is not active") << endl;
        cout << "**********************************************" << endl;
    }
    double calculateInterest();
    double getBalance()
    {
        return this->balance;
    }
    int getAccountNumber()
    {
        return this->accountNumber;
    }
};
class SavingsAcount : public Account
{
public:
    static constexpr double IntresetRate = 3.5;
    static constexpr double minimum = 500.0;
    SavingsAcount(int accountNumber, double balance, string accountHolder, string dateCreated, bool isActive)
        : Account(accountNumber, balance, accountHolder, dateCreated, isActive) {};

    void withdraw(double ammount)
    {
        if (this->getBalance() < this->minimum)
        {
            cout << "Cannot withdraw if balance falls below minimum" << endl;
        }
        else
        {
            Account::withdraw(ammount);
        }
    }
    double calculateInterest()
    {
        return this->getBalance() * IntresetRate / 100;
    }
    void applyInterest()
    {
        Account::deposite(this->calculateInterest());
    }
};
class CheckingAccount : public Account
{
public:
    static constexpr double overdraftLimit = 200;
    static constexpr double transactionFee = 0.50;
    int freeTransactions;
    CheckingAccount(int accountNumber, double balance, string accountHolder, string dateCreated, bool isActive, int freeTransactions)
        : Account(accountNumber, balance, accountHolder, dateCreated, isActive)
    {
        this->freeTransactions = freeTransactions;
    };
    void withdraw(double amount)
    {
        if (this->getBalance() - amount >= -this->overdraftLimit)
        {
            Account::withdraw(amount);
            this->freeTransactions--;
        }
        else
        {
            cout << "Too broke for that" << endl;
        }
    }
    double calculateInterest()
    {
        return 0;
    }
    void deductFee()
    {
        if (this->freeTransactions < 0)
        {
            int overFreeLimit = this->freeTransactions * -1;
            Account::withdraw(overFreeLimit * this->transactionFee);
        }
    }
};

class Customer
{
private:
    int customerId;
    string name;
    string email;
    string phone;
    string address;
    vector<Account *> accounts;

public:
    Customer(int customerId, string name, string email, string phone, string address)
    {
        this->customerId = customerId;
        this->name = name;
        this->email = email;
        this->phone = phone;
        this->address = address;
    }
    void addAccount(Account *acc)
    {
        this->accounts.push_back(acc);
    }
    void removeAccount(int accountNum)
    {
        if (!this->accounts.empty())
        {
            for (int i = 0; i < this->accounts.size(); i++)
            {
                if (accountNum == this->accounts[i]->getAccountNumber())
                {
                    this->accounts.erase(this->accounts.begin() + i);
                    break;
                }
            }
        }
    }
    void displayCustmorInfo(){
        cout <<"***********CUSTOMER_INFO************"<<endl;
        cout <<"CUSTOMER_ID: "<< this->customerId <<endl;
        cout << "NAME: "<<this->name<<endl;
        cout << "EMAIL: "<<this->email<<endl;
        cout << "PHONE: "<<this->address<<endl;
        cout << "**************************************";
    }     
    double getTotalBalance(){
        double totale=0.0;
        for (int i = 0; i < this->accounts.size(); i++)
        {
            totale +=this->accounts[i]->getBalance();
        }
        return totale;
    }
    void listAccounts(){
        for (int i = 0; i < this->accounts.size(); i++){
            this->accounts[i]->displayAccountInfo();
        }
    }
};

int main()
{
    // int accountNumber, double balane, string accountHolder, string dateCreated, bool isActive
    SavingsAcount act1(1, 10000.0, "Mehdi", "2025-8", true);
    act1.deposite(500.0);
    act1.withdraw(100.0);
    act1.displayAccountInfo();
    act1.applyInterest();
    act1.displayAccountInfo();
    Transaction t1(1, DEPOSIT, 1000.0, "2025-10-09", "Mehdi", "Bank", 6000.0);

    // Use its methods
    t1.displayTransaction();

    cout << "Amount: " << t1.get_amount() << endl;
    cout << "From Account: " << t1.get_fromAcount() << endl;
    return 0;
}