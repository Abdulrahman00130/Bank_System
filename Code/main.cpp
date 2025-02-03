#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;

int main()
{

	Admin E1("abdoooo", "264dgdsf6", "Birth Place?", "qwesna", 111, 32,5500);

	E1.display();
	E1.setSalary(45000);
	cout<<E1.getSalary();



}
