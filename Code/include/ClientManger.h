#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H

#include "Client.h"
#include <cstdlib>

#define CLRSCRN system("cls")

class ClientManger
{
private:


	static int searchClient(int clID)
	{
		// binary search (id sorted)
        if (emptyVect<Client>(clientVect))
            return -1;

		int start{};
		int ends = clientVect.size() - 1;
		int mid{};
		while (true)
		{
			mid = start + (ends - start) / 2;
			if (clientVect[mid].getID() == clID)
				return mid;

			if (clientVect[mid].getID() > clID)
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
	static void printClientMenu()
	{
		cout << "=================================\n\n";
		cout << "Enter (1) to display account info\n\n";
		cout << "Enter (2) to check balance\n\n";
		cout << "Enter (3) to update password\n\n";
		cout << "Enter (4) to withdraw\n\n";
		cout << "Enter (5) to deposit\n\n";
		cout << "Enter (6) to transfer\n\n";
		cout << "Enter (7) to logout\n\n";
		cout << "=================================\n\n";
	}

	static void updatePassword(Person& person)
	{
		string ans, pass;
		cout << "Answer the following question, please\n\n";
		cout << person.getQues() << endl;
		cout << "Your answer:\n";
		getline(cin >> ws, ans);
		if (ans == person.getAns())
		{
			CLRSCRN;
			cout << "Enter the new password:\n";
			getline(cin >> ws, ans);
			while (!Validation::checkPass(ans))
			{
				cout << "Enter the new password:\n";
				getline(cin >> ws, ans);
			}

			person.setPass(ans);
			CLRSCRN;
			cout << "Password changed successfully\n";
		}
		else
		{
			cout << "Wrong answer\n";
		}
	}

	static int login(int id, string password)
	{
		int index;
		index = searchClient(id);
		if (index < 0)
			return -1;
		if (password != clientVect[index].getPass())
			return -1;
		return index;
	}

	static bool clientOptions(int index)
	{
		int choice{}, id{}, recipIndex{};
		double amount{};

		cout << "Your choice: ";
		cin >> choice;
		cin.ignore();
		CLRSCRN;

		switch (choice)
		{
		case 1:
			clientVect[index].display();
			cout << "\nPress Enter to continue...\n";
			cin.get();
			CLRSCRN;
			break;

		case 2:
			cout << "Balance: " << clientVect[index].getBalance() << endl;
			cout << "\nPress Enter to continue...\n";
			cin.get();
			CLRSCRN;
			break;

		case 3:
			updatePassword(clientVect[index]);
			cout << "\nPress Enter to continue...\n";
			cin.get();
			CLRSCRN;
			break;

		case 4:
			cout << "Enter the amount to withdraw:\n";
			cin >> amount;
			clientVect[index].withdraw(amount);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 5:
			cout << "Enter the amount to deposit:\n";
			cin >> amount;
			clientVect[index].deposit(amount);
			cout << "\nPress Enter to continue...\n";
			cin.ignore();
			cin.get();
			CLRSCRN;
			break;

		case 6:
			cout << "Enter the amount to transfer:\n";
			cin >> amount;
			cout << "Enter the ID of the recipient:\n";
			cin >> id;
			recipIndex = searchClient(id);
			if (recipIndex >= 0)
				clientVect[index].transferTo(amount, clientVect[recipIndex]);
			else
				cout << "ID not found\n";
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

#endif // CLIENTMANGER_H


/*cout << "Press Enter to continue...\n";
		cin.get();*/
