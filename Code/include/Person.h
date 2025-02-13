#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "Validation.h"

using namespace std;

class Person
{
protected:
	string name, pass, ques, ans;
	int id, age;

public:
	//Constructors
	Person()
	{
		id = 0;
		age = 0;
	}

	Person(string name, string pass, string ques, string ans, int id, int age)
	{
		if (Validation::checkName(name))
            this->name = name;
		if (Validation::checkPass(pass))
            this->pass = pass;
		this->ques = ques;		// Question and answer for forget password
		this->ans = ans;		// Question and answer for forget password
		this->id = id;
		this->age = age;		// Age to check when opening certain types of accounts	| or to check min working age when adding new employee
	}

	//Setters
	void setName(string name)
	{
	    if (Validation::checkName(name))
            this->name = name;
	}

	void setPass(string pass)
	{
	    if (Validation::checkPass(pass))
            this->pass = pass;
	}

	void setQues(string ques)
	{
		this->ques = ques;
	}

	void setAns(string ans)
	{
		this->ans = ans;
	}

	void setID(int id)
	{
		this->id = id;
	}

	void setAge(int age)
	{
		this->age = age;
	}

	//Getters
	string getName()
	{
		return name;
	}
	string getPass()
	{
		return pass;
	}
	string getQues()
	{
		return ques;
	}
	string getAns()
	{
		return ans;
	}
	int getID()
	{
		return id;
	}
	int getAge()
	{
		return age;
	}

	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Pass: " << pass << endl;
		cout << "Question: " << ques << endl;
		cout << "Answer: " << ans << endl;
		cout << "ID: " << id << endl;
		cout << "Age: " << age << endl;
		cout << "==============================\n";
	}
};

#endif // PERSON_H
