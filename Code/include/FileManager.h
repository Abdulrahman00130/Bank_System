#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager :public DataSourceInterface
{
    public:
		static void addClient(Client c)
		{
			FilesHelper::saveClient(c);
		}

		static void addEmployee(Employee e)
		{
		    FilesHelper::saveEmployee("Employee.txt", "EmployeeLastID.txt", e);
		}

		static void addAdmin(Admin a)
		{
		    FilesHelper::saveEmployee("Admin.txt", "AdminLastID.txt", a);
		}

		static void getAllClients()
		{
		    FilesHelper::getClients();
		}

		static void getAllEmployees()
		{
		    FilesHelper::getEmployees();
		}

		static void getAllAdmins()
		{
		    FilesHelper::getAdmins();
		}

		static void removeAllClients()
		{
		    FilesHelper::clearFile("Client.txt", "ClientLastID.txt");
		}

		static void removeAllEmployees()
		{
		    FilesHelper::clearFile("Employee.txt", "EmployeeLastID.txt");
		}

		static void removeAllAdmins()
		{
		    FilesHelper::clearFile("Admin.txt", "AdminLastID.txt");
		}

		static void saveEverything()
		{
            removeAllClients();
            for (int i = 0; i < clientVect.size(); i++)
            {
                addClient(clientVect[i]);
            }

            removeAllEmployees();
            for (int i = 0; i < employeeVect.size(); i++)
            {
                addEmployee(employeeVect[i]);
            }

            removeAllAdmins();
            for (int i = 0; i < adminVect.size(); i++)
            {
                addAdmin(adminVect[i]);
            }
		}
};

#endif // FILEMANAGER_H
