#define _CRT_SECURE_NO_WARNINGS
//#include <cstring>
#include <iostream>

#include "CRA_Account.h"

int share_name_length = sict::max_name_length;
sict::CRA_Account::CRA_Account()
{
	family_name[0] = '\0';
	given_name[0] = '\0';
	SIN = 0;
}
void sict::CRA_Account::set(const char* familyName, const char* givenName, int sin)
{
	if (sin <= max_sin && sin >= min_sin) {
		SIN = sin;
		strncpy(family_name, familyName, max_name_length);
		strncpy(given_name, givenName, max_name_length);
	}
	else {
		family_name[0] = '\0';
		given_name[0] = '\0';
		SIN = 0; 
	}
}

bool sict::CRA_Account::isEmpty() const
{
	return SIN == 0;
}

void sict::CRA_Account::display() const
{
	if (!isEmpty()) {
		std::cout << "Family Name : " << family_name << std::endl
			      << "Given Name  : " << given_name << std::endl
			      << "CRA Account : " << SIN << std::endl;
	}
	else {
		std::cout << "Account object is emty" << std::endl;
	}
}

