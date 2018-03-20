#include<iostream>
#include "Fstring.h"
#include "Windows.h"

Fstring::Fstring()
{
}

Fstring::Fstring(const Fstring &fstr)
{
	c_strarr = NULL;
	strarr = new char[fstr.strlen];

	// copy the given fstring into the new fstring object
	for (int i = fstr.strlen -1; i >= 0; i--)
	{
		strarr[i] = fstr.strarr[i];
	}

	strlen = fstr.strlen;
}


Fstring::Fstring(const char* str)
{

	c_strarr = NULL;
	int index = 0;

	if (str != NULL) 
	{
		strarr = new char[c_strlen(str)];

		//populate strarr untill we reach null terminator
		while (str[index] != '\0')
		{
			strarr[index] = str[index++];
		}

		strlen = index;
	}
	if (str == NULL)
	{
		strlen = 0;
		strarr = NULL; 
		c_strarr = NULL;
	}
}

Fstring::~Fstring()
{
}

Fstring & Fstring::operator=(const Fstring & rhs)
{
	if (this == &rhs) 
		return *this;
		delete[] strarr;
	
	//Create a new string array and populate it with rhs
		strarr = new char[rhs.strlen];

		for (int i = 0; i < rhs.strlen; i++)
		{
			strarr[i] = rhs.strarr[i];
		}

		strlen = rhs.strlen;

		return *this;
}

Fstring & Fstring::operator+(const Fstring & rhs)
{
	//Allocate a char array with enough space for the string
	char* newstr = new char[strlen + rhs.strlen];
	
	//First inssert the current string into the new string
	for (int i = 0; i < strlen; i++)
	{
		newstr[i] = strarr[i];
	}

	//Now insert the rhs into the new string
	for (int i = 0; i < rhs.strlen; i++)
	{
		newstr[strlen + i] = rhs.strarr[i];
	}

	//Declear new Fstring to return, and clean up memory
	Fstring* newFstring = new Fstring(newstr);
	newFstring->strlen = strlen + rhs.strlen;

	delete[] newstr;
	return *newFstring;
}

int Fstring::c_strlen(const char * c_str)
{
	return 100;
}

std::ostream & operator<<(std::ostream& os, const Fstring& str)
{
	for(int i=0; i<str.strlen; i++)
	{
		os << str.strarr[i];
	}

	return os;
}
