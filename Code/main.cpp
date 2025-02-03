#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"

using namespace std;

int main()
{
	Person p1("Ahmed", "264dgdsf6", "Birth Place?", "Cairo", 1, 32), p2;

	p1.display();
	p2.display();

	p2.setName("abdo");
	p2.display();

	p2.setName("abdo6");
	p2.display();

	p2.setName("ahmed");
	p2.display();

	p2.setPass("6sd4g");
	p2.display();

	p2.setPass("2s64dg56sdg1");
	p2.display();

	Client c1("Sehs", "9000pm2", "which school you learned in?", "Mogamaa", 555, 17, 10000.5);
	c1.display();

	c1.withdraw(5000);
	c1.checkBalance();
	c1.setBalance(600000);
	c1.display();
	cout << c1.getBalance();
	c1.deposit(25000);
}
