#include "FileManager.h"

int main()
{
    FileManager::getAllAdmins();

    cout << "Admins:\n";
    for (int i = 0; i < adminVect.size(); i++)
    {
        adminVect[i].display();
    }

    cout << "adminLastID: " << adminLastID << endl;

    FileManager::getAllClients();

    cout << "Clients:\n";
    for (int i = 0; i < clientVect.size(); i++)
    {
        clientVect[i].display();
    }

    cout << "clientLastID: " << clientLastID << endl;

    FileManager::getAllEmployees();

    cout << "Employee:\n";
    for (int i = 0; i < employeeVect.size(); i++)
    {
        employeeVect[i].display();
    }

    cout << "employeeLastID: " << employeeLastID << endl;

    FileManager::saveEverything();

//    Client c1("Mohamed", "9000pm25df4g", "which school you learned in?", "Mogamaa", ++clientLastID, 17, 10000.5);
//    clientVect.push_back(c1);
//
//    Employee e1("abdelrahman", "264dgdsf6", "Birth Place?", "Mtobas", ++employeeLastID, 32, 5500);
//    employeeVect.push_back(e1);
//
//    Admin a1("abdoooo", "264dgdsf6", "Birth Place?", "qwesna", ++adminLastID, 32, 5500);
//    adminVect.push_back(a1);
//
//    FileManager::saveEverything();
}
