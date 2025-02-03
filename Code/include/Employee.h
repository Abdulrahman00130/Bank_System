#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"

class Employee :public Person
{
protected:
    double salary;
    public:
        //cons
        Employee();
        Employee(string name, string pass, string ques, string ans, int id, int age, double salary);

        //methods
        void setSalary(double salary);
        double getSalary();
        void display();

};

#endif // EMPLOYEE_H
