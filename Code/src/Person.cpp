#include <iostream>
#include "Person.h"

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

	//Keys
    bool Person::isAlpha(string name)
    {
        for (int i = 0; i < name.size(); i++)
        {
            if ((name[i] < 'a') || (name[i] > 'z'))
            {
                if ((name[i] < 'A') || (name[i] > 'Z'))
                {
                    return false;
                }

            }
        }
        return true;
    }

	//Setters
	void Person::setName(string name)
	{
	    if (!isAlpha(name))
        {
            cout << "Name must be alphabetic\n";
            return;
        }
        if (name.size() < 5 || name.size() > 20)
        {
            cout << "Name must be between 5 and 20 letters\n";
            return;
        }
		this->name = name;
	}
	void Person::setPass(string pass)
	{
	    if (pass.size() < 8 || pass.size() > 20)
        {
            cout << "Password must be between 8 and 20 characters\n";
            return;
        }
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
