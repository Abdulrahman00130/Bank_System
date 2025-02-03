#include<iostream>
#include "Client.h"
#include "Validation.h"

    Client::Client(){
        balance = 0;
    }
    Client::Client(string name, string pass, string ques, string ans, int id, int age, double balance) : Person(name, pass, ques, ans, id, age){
        if(Validation::checkBal(balance)){
            this->balance = balance;
        }
        else this->balance = 0;
    }
    void Client::setBalance(double balance){
        if(Validation::checkBal(balance)){
            this->balance = balance;
        }
    }
    double Client::getBalance(){
        return balance;
    }
    void Client::deposit(double amount){
        balance += amount;
    }
    void Client::withdraw(double amount){
        if(amount > balance){
            cout << "Not enough balance\n";
            return;
            }
        balance -= amount;
    }
    void Client::transferTo(double amount, Client& recipient){
        if(amount > balance){
            cout << "Not enough balance\n";
            return;
        }
        balance -= amount;
        recipient.balance += amount;
    }
    void Client::checkBalance(){
        cout << "Balance: " << balance << endl;
    }
    void Client::display(){
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Age: " << age << endl;
        cout << "Balance: " << balance << endl;
        cout << "===============================\n";
    }
