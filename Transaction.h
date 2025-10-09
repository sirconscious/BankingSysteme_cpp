#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
using namespace std;
enum TransactionType
{
    DEPOSIT,
    WITHDRAWAL,
    TRANSFER
};
class Transaction
{
private:
    int transactionId;
    TransactionType transactionType;
    double amount;
    string timestamp;
    string fromAccount;
    string toAccount;
    double balanceAfter;

public:
    Transaction(int transactionId, TransactionType transactionType, double amount, string timestamp, string fromAccount, string toAccount, double balanceAfter);
    int get_transactionId();
    TransactionType get_transactionType();
    double get_amount();
    string get_fromAcount();
    string get_toAccount();
    double get_balanceAfter();
    void displayTransaction();
};
#endif
