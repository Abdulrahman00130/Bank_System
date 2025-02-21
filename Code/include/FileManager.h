#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
    public:
		void addClient(Client c)
		{
			FilesHelper::saveClient(c);
		}

		void addEmployee(Employee e)
		{
		    FilesHelper::saveEmployee("Employee.txt", "EmployeeLastID.txt", e);
		}

		void addAdmin(Admin a)
		{
		    FilesHelper::saveEmployee("Admin.txt", "AdminLastID.txt", a);
		}

		void getAllClients()
		{
		    FilesHelper::getClients();
		}

		void getAllEmployees()
		{
		    FilesHelper::getEmployees();
		}

		void getAllAdmins()
		{
		    FilesHelper::getAdmins();
		}

		void removeAllClients()
		{
		    FilesHelper::clearFile("Client.txt", "ClientLastID.txt");
		}

		void removeAllEmployees()
		{
		    FilesHelper::clearFile("Employee.txt", "EmployeeLastID.txt");
		}

		void removeAllAdmins()
		{
		    FilesHelper::clearFile("Admin.txt", "AdminLastID.txt");
		}

		void saveEverything()
		{
            removeAllClients();
            for (unsigned long long i = 0; i < clientVect.size(); i++)
            {
                addClient(clientVect[i]);
            }

            removeAllEmployees();
            for (unsigned long long i = 0; i < employeeVect.size(); i++)
            {
                addEmployee(employeeVect[i]);
            }

            removeAllAdmins();
            for (unsigned long long i = 0; i < adminVect.size(); i++)
            {
                addAdmin(adminVect[i]);
            }
		}
};

#endif // FILEMANAGER_H
