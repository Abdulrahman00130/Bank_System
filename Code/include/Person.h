#ifndef PERSON_H
#define PERSON_H


#include <string>

using namespace std;

class Person
{
protected:
	string name, pass, ques, ans;
	int id, age;

public:
	//Constructors
	Person();

	Person(string name, string pass, string ques, string ans, int id, int age);

	//Setters
	void setName(string name);

	void setPass(string pass);

	void setQues(string ques);

	void setAns(string ans);

	void setID(int id);

	void setAge(int age);

	//Getters
	string getName();

	string getPass();

	string getQues();

	string getAns();

	int getID();

	int getAge();

	void display();
};

#endif // PERSON_H
