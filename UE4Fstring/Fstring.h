#pragma once

#include<iostream>

class Fstring
{
public:
	Fstring();
	Fstring(const Fstring &fstr);
	Fstring(const char* str);
	~Fstring();

	//Operator overloads 
	Fstring& operator=(const Fstring& rhs);
	Fstring& operator+(const Fstring& rhs);

	friend std::ostream& operator<<(std::ostream&, const Fstring& str);
	

private:
	int strlen;
	char* strarr;
	char* c_strarr;

	int c_strlen(const char* c_str);
};

