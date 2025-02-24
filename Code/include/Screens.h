#ifndef SCREENS_H
#define SCREENS_H

#include <windows.h>
#include "AdminManager.h"
#include "FileManager.h"

FileManager myFile;

class Screens
{
public:
	static void bankName()
	{
        cout << "\n\n\n\n";
		cout << R"(
		 __      __          ___
		/\ \  __/\ \        /\_ \
		\ \ \/\ \ \ \     __\//\ \     ___    ___     ___ ___      __
		 \ \ \ \ \ \ \  /'__`\\ \ \   /'___\ / __`\ /' __` __`\  /'__`\
		  \ \ \_/ \_\ \/\  __/ \_\ \_/\ \__//\ \L\ \/\ \/\ \/\ \/\  __/
		   \ `\___x___/\ \____\/\____\ \____\ \____/\ \_\ \_\ \_\ \____\
		    '\/__//__/__\/____/\/____/\/____/\/___/__\/_/\/_/\/_/\/____/
		              ___    ______  ______       ___                     __
		            /\  _`\ /\__  _\/\__  _\    /\  _`\                  /\ \
		            \ \ \L\ \/_/\ \/\/_/\ \/    \ \ \L\ \     __      ___\ \ \/'\
		             \ \  _ <  \ \ \   \ \ \     \ \  _ <   /'__`\  /' _ `\ \ , <
		              \ \ \L\ \ \_\ \__ \ \ \     \ \ \L\ \/\ \L\.\_/\ \/\ \ \ \\`\
		               \ \____/ /\_____\ \ \_\     \ \____/\ \__/.\_\ \_\ \_\ \_\ \_\
		                \/___/  \/_____/  \/_/      \/___/  \/__/\/_/\/_/\/_/\/_/\/_/)";
	}

	static void welcome()
	{
	    system("COLOR 71");
        bankName();
        Sleep(4000);
        CLRSCRN;
        system("COLOR 70");
	}

	static void loginOptions()
	{
	    cout << "=======================================\n\n";
        cout << "Enter (1) to login as a client\n\n";
        cout << "Enter (2) to login as an employee\n\n";
        cout << "Enter (3) to login as an admin\n\n";
        cout << "=======================================\n\n";
	}

	static int loginAs()
	{
	    cout << "Your choice: ";
	    int choice{};
	    cin >> choice;
	    return choice;
	}

	static void invalid(int c)
	{

	}

	static void logout()
	{
	    CLRSCRN;
        loginOptions();
        loginScreen(loginAs());
	}

	static void loginScreen(int c)
	{
        int id{}, index{};
	    string pass;

	    CLRSCRN;
	    cout << "Enter ID\n";
	    cin >> id;

	    cout << "Enter password\n";
	    cin.ignore();
	    getline(cin>>ws, pass);

        switch(c)
        {
        case 1:
            index = ClientManger::login(id, pass);

            if (index < 0)
            {
                cout << "ID or password is incorrect\n";
                cin.ignore();
                cout << "\nPress Enter to continue...\n";
                cin.get();
            }
            else
            {
                CLRSCRN;
                ClientManger::printClientMenu();
                while (!ClientManger::clientOptions(index))
                    ClientManger::printClientMenu();

                myFile.saveEverything();
            }
            break;

            case 2:
            index = EmployeeManager::login(id, pass);

            if (index < 0)
            {
                cout << "ID or password is incorrect\n";
                cin.ignore();
                cout << "\nPress Enter to continue...\n";
                cin.get();
            }
            else
            {
                CLRSCRN;
                EmployeeManager::printEmployeMenu();
                while (!EmployeeManager::employeeOptions(index))
                    EmployeeManager::printEmployeMenu();

                myFile.saveEverything();
            }
            break;

            case 3:
            index = AdminManager::login(id, pass);

            if (index < 0)
            {
                cout << "ID or password is incorrect\n";
                cin.ignore();
                cout << "\nPress Enter to continue...\n";
                cin.get();
            }
            else
            {
                CLRSCRN;
                AdminManager::printAdminMenu();
                while (!AdminManager::adminOptions(index))
                    AdminManager::printAdminMenu();

                myFile.saveEverything();
            }
            break;
        }
	}

	static void runApp()
	{
        welcome();
        myFile.getEverything();
        loginOptions();
        loginScreen(loginAs());
        while(true)
            logout();
	}

};

#endif // SCREENS_H
