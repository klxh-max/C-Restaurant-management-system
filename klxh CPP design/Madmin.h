#pragma once
#ifndef MADMIN
#define MADMIN

#include<bits/stdc++.h>
#include "Admin.h"
using namespace std;

class Madmin
{
private:
	int anum=0;
public:
	Admin admin[50];
	void addAdmin(string a, string b);
	int Verify(string a, string b);
};

#endif // !MADMIN


