#ifndef ADMIN_H
#define ADMIN_H

#include"Employee.h"


class Admin : public Employee
{
private:
    void printEmployeeEdit()
    {
        cout << "=================================\n";
        cout << "Enter (1) to edit name\n";
        cout << "Enter (2) to edit age\n";
        cout << "Enter (3) to edit password\n";
        cout << "Enter (4) to edit salary\n";
        cout << "=================================\n\n";
    }

    public:
    //cons
    Admin(){}
    Admin(string name, string pass, string ques, string ans, int id, int age, double salary):Employee(name, pass, ques, ans, id, age,salary)
    {

    }
     void addEmployee(Employee& employee)
        {
            employeeVect.push_back(employee);
            employeeLastID= employee.getID();
        }
        int searchEmployee(int emID)
        {
          // binary search (id sorted)
          if (emptyVect<Employee>(employeeVect))
            return -1;

          int start{};
          int ends = employeeVect.size() - 1;
          int mid{};
          while(true)
          {
              mid = start + (ends - start) / 2;
              if (employeeVect[mid].getID() == emID)
                  return mid;

              if (employeeVect[mid].getID() > emID)
              {
                  ends = mid - 1;
              }
              else
              {
                  start = mid + 1;
              }
              if (ends < start)
                  return -1;

          }
          //add remove one employee function to employee
        }

        void listEmployee()
        {
            cout << "All Employees:\n";
    for (unsigned long long i = 0; i < employeeVect.size(); i++)
    {
        employeeVect[i].display();
    }

        }

     void editEmployeeName(string emName ,int index)
     {
         employeeVect[index].setName(emName);
     }

      void editEmployeeAge(int emAge ,int index)
     {
         employeeVect[index].setAge(emAge);
     }

      void editEmployeePassword(string emPass ,int index)
     {
         employeeVect[index].setPass(emPass);
     }

      void editEmployeeSalary(double embal ,int index)
     {
         employeeVect[index].setSalary(embal);
     }

     void editEmployee(int index)
     {
         string emName;
         int emAge{};
         string emPass;
         double emSalary{};

         int choice{};
         printEmployeeEdit();
         cin >> choice;
         CLRSCRN;

        switch(choice)
        {
         case 1:
            cout<<"current name: "<<employeeVect[index].getName()<<endl;
            cout<<"enter new name\n";
            getline(cin>>ws,emName);
            editEmployeeName(emName,index);
            cout<<"Name edited successfully\n";
            break;

         case 2:
            cout<<"current age: "<<employeeVect[index].getAge()<<endl;
            cout<<"enter new age\n";
            cin>>emAge;
            editEmployeeAge(emAge,index);
            cout<<"Age edited successfully\n";
            break;

         case 3:
            cout<<"current password: "<<employeeVect[index].getPass()<<endl;
            cout<<"enter new pass\n";
            cin>>emPass;
            editEmployeePassword(emPass,index);
            cout<<"Password edited successfully\n";
            break;

         case 4:
            cout<<"current Salary: "<<employeeVect[index].getSalary()<<endl;
            cout<<"enter new Salary\n";
            cin>>emSalary;
            editEmployeeSalary(emSalary,index);
            cout<<"Salary edited successfully\n";
            break;

        }
     }

};
static vector<Admin> adminVect;
static int adminLastID = 3000;
#endif // ADMIN_H
