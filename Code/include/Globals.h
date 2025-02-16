#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#include <vector>
#include "Client.h"
#include "Admin.h"

extern vector<Client> clientVect;
extern int clientLastID;

extern vector<Employee> employeeVect;
extern int employeeLastID;

extern vector<Admin> adminVect;
extern int adminLastID;

#endif // GLOBALS_H_INCLUDED
