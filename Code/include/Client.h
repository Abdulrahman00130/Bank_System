#ifndef CLIENT_H
#define CLIENT_H
#include "Person.h"

class Client : public Person{
    double balance;
public:
    Client();
    Client(string name, string pass, string ques, string ans, int id, int age, double balance);
    void setBalance(double balance);
    double getBalance();
    void deposit(double amount);
    void withdraw(double amount);
    void transferTo(double amount, Client& recipient);
    void checkBalance();
    void display();
};

#endif // CLIENT_H
