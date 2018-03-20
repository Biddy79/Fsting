 #include<iostream>
#include"Fstring.h"

using namespace std;

int main()
{
	Fstring myName = "Adam ";
	Fstring lastName = "Beardsley";
	
	Fstring fullName = myName + lastName;

	cout << fullName << endl;

	system("pause");

}