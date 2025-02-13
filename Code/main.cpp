#include <iostream>
#include <string>
#include "Client.h"
#include"Admin.h"

using namespace std;

int main()
{
    //Person
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

    p2.setPass("2s64dg56sdg15d4f4gf6d4645fd4g6dfgs5d4gdf2b6df4bd");
	p2.display();

	p2.setPass("2s64dg56sdg1");
	p2.display();

	//Client
	Client c1("Sehs", "9000pm2", "which school you learned in?", "Mogamaa", 555, 17, 10000.5);
	c1.display();

	c1.withdraw(5000);
	c1.checkBalance();
	c1.setBalance(600000);
	c1.display();

	cout << c1.getBalance() << endl;

	c1.deposit(25000);
	c1.withdraw(700000);

	Client c2("mohamed", "122223ppoo", "geblro", "fkeng", 1598, 19, 1500);
	c2.display();

	//Employee
	Employee E1("abdo", "264dgdsf6", "Birth Place?", "Mtobas", 111, 32,5500);

	E1.display();
	E1.setSalary(45000);
	cout<<E1.getSalary();


	//Admin
	Admin D1("abdoooo", "264dgdsf6", "Birth Place?", "qwesna", 111, 32,5500);

	D1.display();
	D1.setSalary(45000);
	cout<<D1.getSalary();


}
