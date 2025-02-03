#include <iostream>
#include "Person.h"
#include "Validation.h"

    Person::Person()
	{
		id = 0;
		age = 0;
	}

	Person::Person(string name, string pass, string ques, string ans, int id, int age)
	{
		this->name = name;
		this->pass = pass;
		this->ques = ques;		// Question and answer for forget password
		this->ans = ans;		// Question and answer for forget password
		this->id = id;
		this->age = age;		// Age to check when opening certain types of accounts	| or to check min working age when adding new employee
	}

	//Setters
	void Person::setName(string name)
	{
	    if (Validation::checkName(name))
            this->name = name;
	}
	void Person::setPass(string pass)
	{
	    if (Validation::checkPass(pass))
            this->pass = pass;
	}
	void Person::setQues(string ques)
	{
		this->ques = ques;
	}
	void Person::setAns(string ans)
	{
		this->ans = ans;
	}
	void Person::setID(int id)
	{
		this->id = id;
	}
	void Person::setAge(int age)
	{
		this->age = age;
	}

	//Getters
	string Person::getName()
	{
		return name;
	}
	string Person::getPass()
	{
		return pass;
	}
	string Person::getQues()
	{
		return ques;
	}
	string Person::getAns()
	{
		return ans;
	}
	int Person::getID()
	{
		return id;
	}
	int Person::getAge()
	{
		return age;
	}

	void Person::display()
	{
		cout << "Name: " << name << endl;
		cout << "Pass: " << pass << endl;
		cout << "Question: " << ques << endl;
		cout << "Answer: " << ans << endl;
		cout << "ID: " << id << endl;
		cout << "Age: " << age << endl;
		cout << "==============================\n";
	}
