#include <iostream>
#include "Stock.h"

Person::Person()
{
	lastName = "";
	firstName = "";
	patronymic = "";
}

Person::Person(const string& ln, const string& fn, const string& pn)
{
	lastName = ln;
	firstName = fn;
	patronymic = pn;
}

void Person::Show()
{
	cout << lastName << " " << firstName << endl;
}

void Person::ShowFormal()
{
	if (patronymic.empty())
	{
		cout << lastName << " " << firstName << endl;
	}
	else
	{
		cout << lastName << " " << firstName << " " << patronymic << endl;
	}
}