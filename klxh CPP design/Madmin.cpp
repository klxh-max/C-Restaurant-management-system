#include "Madmin.h"

void Madmin::addAdmin(string a, string b) {
	anum++;
	admin[anum] = Admin(a, b);
}

int Madmin::Verify(string a, string b) {
	int i;
	for (i = 1;i <= anum;i++)
	{
		if (a == admin[i].getId() && b == admin[i].getPassword())
			return 1;
	}
		cout << "ÈÏÖ¤Ê§°Ü£¡\n";
		return 0;

}