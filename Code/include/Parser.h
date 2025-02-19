#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "Admin.h"
#include "Client.h"

class Parser
{
public:
	static vector<string> split(string line)
	{
		vector<string> data;
		int wordLength{};

		while (line.size() > 0)
		{
			wordLength = line.find('#');
			data.push_back(line.substr(0, wordLength));
			wordLength++;
			line.erase(0, wordLength);
			if (line.find('#') > line.size())
				break;
		}
		data.push_back(line);
		return data;
	}

	static Client parseToClient(string line)
	{
	    vector<string> data = split(line);
	    Client c(data[0], data[2], data[4], data[5], stoi(data[1]), stoi(data[3]), stod(data[6]));
	    return c;
	}

	static Employee parseToEmployee(string line)
	{
	    vector<string> data = split(line);
	    Employee e(data[0], data[2], data[4], data[5], stoi(data[1]), stoi(data[3]), stod(data[6]));
	    return e;
	}

	static Admin parseToAdmin(string line)
	{
	    vector<string> data = split(line);
	    Admin A(data[0], data[2], data[4], data[5], stoi(data[1]), stoi(data[3]), stod(data[6]));
	    return A;
	}
};

#endif // PARSER_H
