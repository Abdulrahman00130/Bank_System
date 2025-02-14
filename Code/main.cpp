#include "FilesHelper.h"

int main()
{
    FilesHelper::getAdmins();

    cout << "Admins:\n";
    for (int i = 0; i < adminVect.size(); i++)
    {
        adminVect[i].display();
    }

    cout << "adminLastID: " << adminLastID << endl;

    FilesHelper::getClients();

    cout << "Clients:\n";
    for (int i = 0; i < clientVect.size(); i++)
    {
        clientVect[i].display();
    }

    cout << "clientLastID: " << clientLastID << endl;

    FilesHelper::getEmployees();

    cout << "Employee:\n";
    for (int i = 0; i < employeeVect.size(); i++)
    {
        employeeVect[i].display();
    }

    cout << "employeeLastID: " << employeeLastID << endl;
}
