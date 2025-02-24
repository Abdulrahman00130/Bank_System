#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include "ClientManger.h"

class EmployeeManager
{
protected:

	static int searchEmployee(int emID)
	{
		// binary search (id sorted)

		int start{};
		int ends = employeeVect.size() - 1;
		int mid{};
		while (true)
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
	}

public:
	static void printEmployeMenu()
	{
		cout << "=================================\n\n";
		cout << "Enter (1) to display your info\n\n";
		cout << "Enter (2) to update password\n\n";
		cout << "Enter (3) to add new client\n\n";
		cout << "Enter (4) to search for client\n\n";
		cout << "Enter (5) to list all clients\n\n";
		cout << "Enter (6) to edit client info\n\n";
		cout << "Enter (7) to logout\n\n";
		cout << "=================================\n\n";
	}

	static void newClient(Employee& employee)
	{
		char choice{};
		int age{};
		string name, pass, ques, ans;
		double bal{};

		cout << "The minimum balance limit is 1500\n";
		cout << "Continue? (y/n)\n";
		cin >> choice;

		if (choice == 'y' || choice == 'Y')
		{
			CLRSCRN;
			cout << "Enter client name:\n";
			getline(cin >> ws, name);
			while (!Validation::checkName(name))
			{
				cout << "Enter client name:\n";
				getline(cin >> ws, name);
			}
			CLRSCRN;

			cout << "Enter client age:\n";
			cin >> age;
			CLRSCRN;

			cout << "Enter client password:\n";
			cin.ignore();
			getline(cin >> ws, pass);
			while (!Validation::checkPass(pass))
			{
				cout << "Enter client password:\n";
				getline(cin >> ws, pass);
			}
			CLRSCRN;

			cout << "Enter client question:\n";
			getline(cin >> ws, ques);
			CLRSCRN;

			cout << "Enter client answer:\n";
			getline(cin >> ws, ans);
			CLRSCRN;

			cout << "Enter the amount:\n";
			cin >> bal;
			while (!Validation::checkBal(bal))
			{
				cout << "Enter the amount:\n";
				cin >> bal;
			}
			CLRSCRN;

			Client cl(name, pass, ques, ans, clientLastID + 1, age, bal);
			employee.addClient(cl);

			cout << "Client account created successfully\n";
			cout << "Client's ID: " << cl.getID() << endl;

			cin.ignore();
			cout << "\nPress Enter to continue...\n";
			cin.get();
		}
		CLRSCRN;
	}

	static void listAllClients(Employee& employee)
	{
		employee.listClient();
	}

	static void searchForClient(Employee& employee)
	{
		int id;
		cout << "Enter client's ID\n";
		cin >> id;
		int index = employee.searchClient(id);
		if (index < 0)
		{
			cout << "ID not found\n";
		}
		else
		{
			CLRSCRN;
			clientVect[index].display();
		}
	}

	static void editClientInfo(Employee& employee)
	{
		int id;
		cout << "Enter client's ID\n";
		cin >> id;
		int index = employee.searchClient(id);
		if (index < 0)
		{
			cout << "ID not found\n";
		}
		else
		{
			CLRSCRN;
			employee.editClient(index);
		}
	}

	static int login(int id, string password)
	{
		int index;
		index = searchEmployee(id);
		if (index < 0)
			return -1;
		if (password != employeeVect[index].getPass())
			return -1;
		return index;
	}

	static bool employeeOptions(int index)
	{
		int choice{};

		cout << "Your choice: ";
		cin >> choice;
		cin.ignore();
		CLRSCRN;

		switch (choice)
		{
		case 1:
			employeeVect[index].display();
			cout << "\nPress Enter to continue...\n";
			cin.get();
			CLRSCRN;
			break;

		case 2:
			ClientManger::updatePassword(employeeVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.get();
			CLRSCRN;
			break;

		case 3:
			newClient(employeeVect[index]);
			break;

		case 4:
			searchForClient(employeeVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 5:
			listAllClients(employeeVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 6:
			editClientInfo(employeeVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 7:
			return true;
			break;

		default:
			cout << "Invalid input choice\n";
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;
		}
		return false;
	}
};

#endif // EMPLOYEEMANAGER_H
