#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
protected:
    double salary;
    public:
    //cons
    Employee()
        {
            this->salary=0;
        }
    Employee(string name, string pass, string ques, string ans, int id, int age, double salary):Person(name, pass, ques, ans, id, age)
        {
            if(Validation::checkSal(salary))
                this->salary=salary;

            else this->salary=0;
        }
    //methods
       void setSalary(double salary)
        {
            if(Validation::checkSal(salary))
            this->salary=salary;
        }
       double getSalary()
        {
            return salary;
        }

        void display ()
        {
            cout << "Name: " << name << endl;
            cout << "Id: " << id << endl;
            cout << "Age: " << age << endl;
            cout << "Salary: " << salary << endl;
            cout << "===============================\n";
        }

};

#endif // EMPLOYEE_H
