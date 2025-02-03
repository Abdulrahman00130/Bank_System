#include <iostream>
#include <string>
#include "Person.h"

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
}
