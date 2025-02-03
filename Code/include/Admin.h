#ifndef ADMIN_H
#define ADMIN_H
#include"Employee.h"

class Admin:public Employee
{
    public:
        Admin();
        Admin(string name, string pass, string ques, string ans, int id, int age, double salary);

    protected:

    private:
};

#endif // ADMIN_H
