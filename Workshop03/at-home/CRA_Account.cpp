#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>

#include "CRA_Account.h"

sict::CRA_Account::CRA_Account()
{
	family_name[0] = '\0';
	given_name[0] = '\0';
	SIN = 0;
}
void sict::CRA_Account::set(int years, double balance)
{
	if (!isEmpty() && numOfYears <= max_years) {
		tax_year[numOfYears] = years;
		tax_balance[numOfYears] = balance;
		numOfYears++;
	}
}
void sict::CRA_Account::set(const char* familyName, const char* givenName, int sin)
{
	if (validateSin(sin) && 
		familyName[0] != '\0' && givenName[0] != '\0') {
		SIN = sin;
		strncpy(family_name, familyName, max_name_length);
		strncpy(given_name, givenName, max_name_length);
		numOfYears = 0;
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

bool sict::CRA_Account::validateSin(int sin)
{
	int check = 0;
	int valid = 0;

	if (sin <= max_sin && sin >= min_sin) {
		int validateSin[sinDigits];
		int tempSin = sin;
		int count = 0;

		for (int i = sinDigits; i >= 1; --i) {
			validateSin[i- 1] = tempSin % 10;
			tempSin = tempSin / 10;
			count++;
		}
		int doubleAdditionSet = 0;
		int additionSet = 0;
		int tempPlaceHolder[4];
		int countTwo = 0;

		for (int i = 0, ii = 0; i < count - 1; i++) {
			if (i % 2 != 0) {
				tempPlaceHolder[ii] = validateSin[i] * 2;
				countTwo++;
				ii++;
			}
			else if (i % 2 == 0) {
				additionSet += validateSin[i];
			}
		}

		for (int i = 0; i < countTwo; i++) {
			int temp = (tempPlaceHolder[i] / 10) + (tempPlaceHolder[i] % 10);
			doubleAdditionSet += temp;
		}
		int total = additionSet + doubleAdditionSet;
		int multipleOfTen = 10;
		while (multipleOfTen < total) {
			multipleOfTen += 10;
		}
		check = sin % 10;
		valid = multipleOfTen - total;
	}
	return valid == check;
}

void sict::CRA_Account::display() const
{
	if (!isEmpty()) {
		std::cout << "Family Name : " << family_name << std::endl
			      << "Given Name  : " << given_name << std::endl
			      << "CRA Account : " << SIN << std::endl;
		for (int i = 0; i < max_years; i++) {
			if (tax_balance[i] > 2) {
				std::cout << "year (" << tax_year[i]
					      << std::fixed << std::setprecision(2) 
					      << ") balance owing: " << tax_balance[i]
					      << std::endl;
			}
			else if (tax_balance[i] < -2) {
				std::cout << "year (" << tax_year[i]
					      << std::fixed << std::setprecision(2)
					      << ") refund due: " << fabs(tax_balance[i])
					      << std::endl;
			}
			else {
				std::cout << "year (" << tax_year[i]
					      << ") No balance owing or refund due! "
					      << std::endl;
			}
		}
	}
	else {
		std::cout << "Account object is emty" << std::endl;
	}
}

