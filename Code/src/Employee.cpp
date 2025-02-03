#include "Employee.h"
#include "Validation.h"

//cons
    Employee::Employee()
        {
            this->salary=0;
        }
    Employee::Employee(string name, string pass, string ques, string ans, int id, int age, double salary):Person(name, pass, ques, ans, id, age)
        {
            if(Validation::checkSal(salary))
                this->salary=salary;

            else this->salary=0;
        }
//methods
       void Employee::setSalary(double salary)
        {
            if(Validation::checkSal(salary))
            this->salary=salary;
        }
       double Employee::getSalary()
        {
            return salary;
        }

        void Employee::display ()
        {
            cout << "Name: " << name << endl;
            cout << "Id: " << id << endl;
            cout << "Age: " << age << endl;
            cout << "Salary: " << salary << endl;
            cout << "===============================\n";
        }
