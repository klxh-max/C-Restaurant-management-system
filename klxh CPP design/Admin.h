#pragma once
#ifndef ADMIN
#define ADMIN

#include<bits/stdc++.h>
using namespace std;

class Admin
{
private:
	string id, password;
public:
	Admin();
	Admin(string, string);

	void setId(string);
	void setPassword(string);

	string getId();
	string getPassword();
};


#endif // !ADMIN