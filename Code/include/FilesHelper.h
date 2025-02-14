#ifndef FILESHELPER_H
#define FILESHELPER_H

#include "Globals.h"
#include <Parser.h>
#include <fstream>

class FilesHelper
{
public:

	static void saveLast(string fileName, int id)
	{
		ofstream write(fileName);
		write << to_string(id);
		write.close();
	}

	static int getLast(string fileName)
	{
		string id;
		ifstream read(fileName);
		getline(read, id);
		read.close();
		return stoi(id);
	}

	static void saveClient(Client c)
	{
		string client;
		client = c.getName() + '#' + to_string(c.getID()) + '#' + c.getPass() + '#' + to_string(c.getAge()) + '#' + c.getQues() + '#' + c.getAns() + '#' + to_string(c.getBalance());
		ofstream write("Client.txt", ios::app);
		write << endl << client;
		write.close();

		write.open("ClientLastID.txt");
		write << to_string(c.getID());
		write.close();
	}

	static void saveEmployee(string fileName, string lastIdFile, Employee e)
	{
		string employee;
		employee = e.getName() + '#' + to_string(e.getID()) + '#' + e.getPass() + '#' + to_string(e.getAge()) + '#' + e.getQues() + '#' + e.getAns() + '#' + to_string(e.getSalary());
		ofstream write(fileName, ios::app);
		write << endl << employee;
		write.close();

		write.open(lastIdFile);
		write << to_string(e.getID());
		write.close();
	}

	static void getClients()
	{
		string client;
		clientVect.clear();
		Client c;
		ifstream read("Client.txt");
		while (!read.eof())
		{
			getline(read, client);
			c = Parser::parseToClient(client);
			clientVect.push_back(c);
		}
		read.close();

		clientLastID = FilesHelper::getLast("ClientLastID.txt");
	}

	static void getEmployees()
	{
		string employee;
		employeeVect.clear();
		Employee e;
		ifstream read("Employee.txt");
		while (!read.eof())
		{
			getline(read, employee);
			e = Parser::parseToEmployee(employee);
			employeeVect.push_back(e);
		}
		read.close();

		employeeLastID = FilesHelper::getLast("EmployeeLastID.txt");
	}

	static void getAdmins()
	{
		string admin;
		adminVect.clear();
		Admin a;
		ifstream read("Admin.txt");
		while (!read.eof())
		{
			getline(read, admin);
			a = Parser::parseToAdmin(admin);
			adminVect.push_back(a);
		}
		read.close();

		adminLastID = FilesHelper::getLast("AdminLastID.txt");
	}

	static void clearFile(string fileName, string lastIdFile)
	{
		ofstream write(fileName);
		write.clear();
		write.close();

		write.open(lastIdFile);
		write.clear();
		write << "0";
		write.close();
	}
};

#endif // FILESHELPER_H
