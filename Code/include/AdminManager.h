#ifndef  ADMINMANAGER_H
#define  ADMINMANAGER_H

#include "Admin.h"
#include "EmployeeManager.h"

class  AdminManager : public EmployeeManager
{
private:

    static int searchAdmin(int adID)
	{
		// binary search (id sorted)

		int start{};
		int ends = adminVect.size() - 1;
		int mid{};
		while (true)
		{
			mid = start + (ends - start) / 2;
			if (adminVect[mid].getID() == adID)
				return mid;

			if (adminVect[mid].getID() > adID)
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
	static void printAdminMenu()
	{
		cout << "=================================\n\n";
		cout << "Enter (1) to display your info\n\n";
		cout << "Enter (2) to update password\n\n";
		cout << "Enter (3) to add new client\n\n";
		cout << "Enter (4) to search for client\n\n";
		cout << "Enter (5) to list all clients\n\n";
		cout << "Enter (6) to edit client info\n\n";
		cout << "Enter (7) to add new employee\n\n";
		cout << "Enter (8) to search for employee\n\n";
		cout << "Enter (9) to list all employee\n\n";
		cout << "Enter (10) to edit employee info\n\n";
		cout << "Enter (11) to logout\n\n";
		cout << "=================================\n\n";
	}

	static void newEmployee(Admin& admin)
	{
		char choice{};
		int age{};
		string name, pass, ques, ans;
		double salary{};

		cout << "The minimum salary limit is 5000\n";
		cout << "Continue? (y/n)\n";
		cin >> choice;

		if (choice == 'y' || choice == 'Y')
		{
			CLRSCRN;
			cout << "Enter employee name:\n";
			getline(cin >> ws, name);
			while (!Validation::checkName(name))
			{
				cout << "Enter employee name:\n";
				getline(cin >> ws, name);
			}
			CLRSCRN;

			cout << "Enter employee age:\n";
			cin >> age;
			CLRSCRN;

			cout << "Enter employee password:\n";
			cin.ignore();
			getline(cin >> ws, pass);
			while (!Validation::checkPass(pass))
			{
				cout << "Enter employee password:\n";
				getline(cin >> ws, pass);
			}
			CLRSCRN;

			cout << "Enter employee question:\n";
			getline(cin >> ws, ques);
			CLRSCRN;

			cout << "Enter employee answer:\n";
			getline(cin >> ws, ans);
			CLRSCRN;

			cout << "Enter the amount:\n";
			cin >> salary;
			while (!Validation::checkSal(salary))
			{
				cout << "Enter the amount:\n";
				cin >> salary;
			}
			CLRSCRN;

			Employee em(name, pass, ques, ans, employeeLastID + 1, age, salary);
			admin.addEmployee(em);

			cout << "Employee account created successfully\n";
			cout << "Employee's ID: " << em.getID() << endl;

			cin.ignore();
			cout << "\nPress Enter to continue...\n";
			cin.get();
		}
		CLRSCRN;
	}

	static void newAdmin()
	{
		char choice{};
		int age{};
		string name, pass, ques, ans;
		double salary{};

		cout << "The minimum salary limit is 5000\n";
		cout << "Continue? (y/n)\n";
		cin >> choice;

		if (choice == 'y' || choice == 'Y')
		{
			CLRSCRN;
			cout << "Enter admin name:\n";
			getline(cin >> ws, name);
			while (!Validation::checkName(name))
			{
				cout << "Enter admin name:\n";
				getline(cin >> ws, name);
			}
			CLRSCRN;

			cout << "Enter admin age:\n";
			cin >> age;
			CLRSCRN;

			cout << "Enter admin password:\n";
			cin.ignore();
			getline(cin >> ws, pass);
			while (!Validation::checkPass(pass))
			{
				cout << "Enter admin password:\n";
				getline(cin >> ws, pass);
			}
			CLRSCRN;

			cout << "Enter admin question:\n";
			getline(cin >> ws, ques);
			CLRSCRN;

			cout << "Enter admin answer:\n";
			getline(cin >> ws, ans);
			CLRSCRN;

			cout << "Enter the amount:\n";
			cin >> salary;
			while (!Validation::checkSal(salary))
			{
				cout << "Enter the amount:\n";
				cin >> salary;
			}
			CLRSCRN;

			Admin ad(name, pass, ques, ans, adminLastID + 1, age, salary);
			adminVect.push_back(ad);
			adminLastID++;

			cout << "Admin account created successfully\n";
			cout << "Admin's ID: " << ad.getID() << endl;

			cin.ignore();
			cout << "\nPress Enter to continue...\n";
			cin.get();
		}
		CLRSCRN;
	}

	static void listAllEmployees(Admin& admin)
	{
		admin.listEmployee();
	}

	static void searchForEmployee(Admin& admin)
	{
		int id;
		cout << "Enter employee's ID\n";
		cin >> id;
		int index = admin.searchEmployee(id);
		if (index < 0)
		{
			cout << "ID not found\n";
		}
		else
		{
			CLRSCRN;
			employeeVect[index].display();
		}
	}

	static void editEmployeeInfo(Admin& admin)
	{
		int id;
		cout << "Enter employee's ID\n";
		cin >> id;
		int index = admin.searchEmployee(id);
		if (index < 0)
		{
			cout << "ID not found\n";
		}
		else
		{
			CLRSCRN;
			admin.editEmployee(index);
		}
	}

	static int login(int id, string password)
	{
		int index;
		index = searchAdmin(id);
		if (index < 0)
			return -1;
		if (password != adminVect[index].getPass())
			return -1;
		return index;
	}

	static bool adminOptions(int index)
	{
		int choice{};

		cout << "Your choice: ";
		cin >> choice;
		cin.ignore();
		CLRSCRN;

		switch (choice)
		{
		case 1:
			adminVect[index].display();
			cout << "\nPress Enter to continue...\n";
			cin.get();
			CLRSCRN;
			break;

		case 2:
			ClientManger::updatePassword(adminVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.get();
			CLRSCRN;
			break;

		case 3:
			newClient(adminVect[index]);
			break;

		case 4:
			searchForClient(adminVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 5:
			listAllClients(adminVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 6:
			editClientInfo(adminVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 7:
			newEmployee(adminVect[index]);
			break;

		case 8:
			searchForEmployee(adminVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 9:
			listAllEmployees(adminVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 10:
			editEmployeeInfo(adminVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 11:
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

#endif //  ADMINMANAGER_H
