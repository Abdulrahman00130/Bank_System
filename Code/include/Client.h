#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"

class Client : public Person{
    double balance;
public:
    Client(){
        balance = 0;
    }
    Client(string name, string pass, string ques, string ans, int id, int age, double balance) : Person(name, pass, ques, ans, id, age){
        if(Validation::checkBal(balance)){
            this->balance = balance;
        }
        else this->balance = 0;
    }
    void setBalance(double balance){
        if(Validation::checkBal(balance)){
            this->balance = balance;
        }
    }
    double getBalance(){
        return balance;
    }
    void deposit(double amount){
        balance += amount;
    }
    void withdraw(double amount){
        if(amount > balance){
            cout << "Not enough balance\n";
            return;
            }
        balance -= amount;
    }
    void transferTo(double amount, Client& recipient){
        if(amount > balance){
            cout << "Not enough balance\n";
            return;
        }
        balance -= amount;
        recipient.balance += amount;
    }
    void checkBalance(){
        cout << "Balance: " << balance << endl;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Age: " << age << endl;
        cout << "Balance: " << balance << endl;
        cout << "===============================\n";
    }
};

#endif // CLIENT_H
