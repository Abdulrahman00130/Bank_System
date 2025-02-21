#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include "Client.h"

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

        void addClient(Client& client)
        {
            clientVect.push_back(client);
            clientLastID= client.getID();
        }
        int searchClient(int clID)
        {
          // binary search (id sorted)

          int start{};
          int ends= clientVect.size()-1;
          int mid ;
          while(true)
          {
              mid=(ends-start)/2;
              if(clientVect[mid].getID()==clID)
              return mid;

              if(clientVect[mid].getID()>clID)
              {
                  ends=mid-1;
              }
              else
              {
                  start=mid+1;
              }
              if(ends<start) return -1;

          }
          //add remove one client function to employee
        }

        void listClient()
        {
            cout << "All Clients:\n";
    for (unsigned long long i = 0; i < clientVect.size(); i++)
    {
        clientVect[i].display();
    }

        }

     void editClientName(string clName ,int index)
     {
         clientVect[index].setName(clName);
     }

      void editClientAge(int clAge ,int index)
     {
         clientVect[index].setAge(clAge);
     }

      void editClientPassword(string clPass ,int index)
     {
         clientVect[index].setPass(clPass);
     }

      void editClientBalance(double clbal ,int index)
     {
         clientVect[index].setBalance(clbal);
     }

     void editClient(int index, int choice)
     {
        string clName;
        int clAge{};
        string clPass;
        double clBalance{};
        switch(choice)
        {
        case 1:
          cout<<"current name: "<<clientVect[index].getName()<<endl;
          cout<<"enter new name\n";
          getline(cin>>ws,clName);
          editClientName(clName,index);
          cout<<"Name edited successfully\n";
          break;

        case 2:
            cout<<"current age: "<<clientVect[index].getAge()<<endl;
            cout<<"enter new age\n";
            cin>>clAge;
            editClientAge(clAge,index);
            cout<<"Age edited successfully\n";
            break;

         case 3:
            cout<<"current password: "<<clientVect[index].getPass()<<endl;
            cout<<"enter new pass\n";
            cin>>clPass;
            editClientPassword(clPass,index);
            cout<<"Password edited successfully\n";
            break;

         case 4:
            cout<<"current balance: "<<clientVect[index].getBalance()<<endl;
            cout<<"enter new balance\n";
            cin>>clBalance;
            editClientBalance(clBalance,index);
            cout<<"Balance edited successfully\n";
            break;
        }
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

static vector<Employee> employeeVect;
static int employeeLastID;

#endif // EMPLOYEE_H
