#ifndef ADMIN_H
#define ADMIN_H
#include"Employee.h"

class Admin:public Employee
{
    public:
    //cons
    Admin(){}
    Admin(string name, string pass, string ques, string ans, int id, int age, double salary):Employee(name, pass, ques, ans, id, age,salary)
    {

    }
};

#endif // ADMIN_H
