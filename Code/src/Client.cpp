#include<iostream>
#include "Client.h"
#include "Validation.h"


    Client::Client(){
        balance = 0;
    }


    ////////////////////////////
    Client::Client(string name, string pass, string ques, string ans, int id, int age, double balance) : Person(name, pass, ques, ans, id, age){
        Validation::checkBal
        this->balance = balance;
    }
    ///////////////////////////////
    void Client::setBalance(double balance){
        this->balance = balance;
    }
    double Client::getBalance(){
        return balance;
    }
    void Client::deposit(double amount){
        balance += amount;
    }
    //////////////////////////////////////////////////////////////////////////
    void Client::withdraw(double amount){
        balance -= amount;
    }
    ///////////////////////////////////////////////////////////////////////////
    void Client::transferTo(double amount, Client& recipient){
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

