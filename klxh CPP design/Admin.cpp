#include "Admin.h"

Admin::Admin(){}

Admin::Admin(string a, string b) {
	id = a;
	password = b;
}

void Admin::setId(string a) {
	id = a;
}

void Admin::setPassword(string a) {
	password = a;
}

string Admin::getId() {
	return id;
}

string Admin::getPassword() {
	return password;
}