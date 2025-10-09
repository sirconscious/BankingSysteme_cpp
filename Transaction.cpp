#include "Transaction.h"
#include <iostream>
using namespace std;

Transaction::Transaction(int transactionId, TransactionType transactionType, double amount, string timestamp, string fromAccount, string toAccount, double balanceAfter)
{
    this->transactionId = transactionId;
    this->transactionType = transactionType;
    this->amount = amount;
    this->timestamp = timestamp;
    this->fromAccount = fromAccount;
    this->toAccount = toAccount;
    this->balanceAfter = balanceAfter;
}

int Transaction::get_transactionId() { return transactionId; }
TransactionType Transaction::get_transactionType() { return transactionType; }
double Transaction::get_amount() { return amount; }
string Transaction::get_fromAcount() { return fromAccount; }
string Transaction::get_toAccount() { return toAccount; }
double Transaction::get_balanceAfter() { return balanceAfter; }

void Transaction::displayTransaction()
{
    cout << "*********Transaction*************" << endl;
    cout << "TRANSACTION_ID: " << transactionId << endl;
    cout << "TRANSACTION_TYPE: " << transactionType << endl;
    cout << "AMOUNT: " << amount << endl;
    cout << "FROM: " << fromAccount << endl;
    cout << "TO: " << toAccount << endl;
    cout << "BALANCE_AFTER: " << balanceAfter << endl;
    cout << "*********************************" << endl;
}
