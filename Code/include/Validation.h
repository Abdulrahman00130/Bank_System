#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>
using namespace std;

class Validation
{
    public:

        Validation(){}

        static bool isAlpha(string name)
        {
            for (int i = 0; i < name.size(); i++)
            {
                if ((name[i] < 'a') || (name[i] > 'z'))
                {
                    if ((name[i] < 'A') || (name[i] > 'Z'))
                    {
                        return false;
                    }

                }
            }
            return true;
        }

        static bool checkName(string name)
        {
            if (!isAlpha(name))
            {
                cout << "Name must be alphabetic\n";
                return false;
            }

            if (name.size() < 5 || name.size() > 20)
            {
                cout << "Name must be between 5 and 20 letters\n";
                return false;
            }

            return true;
        }

        static bool checkPass(string pass)
        {
            if (pass.size() < 8 || pass.size() > 20)
            {
                cout << "Password must be between 8 and 20 characters\n";
                return false;
            }
            return true;
        }

        static bool checkBal(double balance)
        {
            if (balance < 1500)
            {
                cout << "Balance can not be less than 1500\n";
                return false;
            }
            return true;
        }

        static bool checkSal(double salary)
        {
            if (salary < 5000)
            {
                cout << "Salary can not be less than 5000\n";
                return false;
            }
            return true;
        }

};

#endif // VALIDATION_H
