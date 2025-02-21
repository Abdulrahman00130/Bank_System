#include "FileManager.h"

int main()
{
    FileManager myFile;
    myFile.getAllAdmins();

    cout << "Admins:\n";
    for (int i = 0; i < adminVect.size(); i++)
    {
        adminVect[i].display();
    }

    cout << "admin last ID: " << adminLastID << endl;

    myFile.getAllClients();

    cout << "Clients:\n";
    for (int i = 0; i < clientVect.size(); i++)
    {
        clientVect[i].display();
    }

    cout << "client last ID: " << clientLastID << endl;

    myFile.getAllEmployees();

    cout << "Employee:\n";
    for (int i = 0; i < employeeVect.size(); i++)
    {
        employeeVect[i].display();
    }

    cout << "employee last ID: " << employeeLastID << endl;

    myFile.saveEverything();

    Client c1("Mohamed", "9000pm25df4g", "which school you learned in?", "Mogamaa", ++clientLastID, 17, 10000.5);
//    clientVect.push_back(c1);
//
    Employee e1("abdelrahman", "264dgdsf6", "Birth Place?", "Mtobas", ++employeeLastID, 32, 5500);
    e1.addClient(c1);

//    employeeVect.push_back(e1);
//
    Admin a1("abdoooo", "264dgdsf6", "Birth Place?", "qwesna", ++adminLastID, 32, 5500);
    a1.addEmployee(e1);
    a1.listClient();
    a1.listEmployee();
//    adminVect.push_back(a1);
//
//    FileManager::saveEverything();
}
