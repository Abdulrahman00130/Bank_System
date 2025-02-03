#ifndef CLIENT_H
#define CLIENT_H
#include "Person.h"


class Client : public Person
{
    double balance;
public:
    Client();
    Client(string name, string pass, string ques, string ans, int id, int age, double balance);
    void setBalance(double balance){
        this->balance = balance;
    }
    double getBalance(){
        return balance;
    }
    void deposit(double amount){
        balance += amount;
    }
    void withdraw(double amount){
        balance -= amount;
    }
    void transferTo(double amount, Client& recipient){
        balance -= amount;
        recipient.balance += amount;
    }
    void checkBalance(){
        cout << " Balance: " << balance;
    }
    void displayFunction
};

#endif // CLIENT_H
