 #include<iostream>
#include"Fstring.h"

using namespace std;

int main()
{
	Fstring myName = "Jimbo ";
	Fstring lastName = "Jones. the man with no bones";
	
	Fstring fullName = myName + lastName;

	cout << fullName << endl;

	system("pause");

}