#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H
#include <iostream>

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_years = 4;
	const int sinDigits = 9;	// 0-8, nine digits

	class CRA_Account {
		char family_name[max_name_length + 1];
		char given_name[max_name_length + 1];
		int SIN;
		int tax_year[max_years + 1];
		double tax_balance[max_years + 1];
		int numOfYears;
	public:
		CRA_Account();
		void set(int, double);
		void set(const char*, const char*, int);
		bool isEmpty() const;
		bool validateSin(int);
		void display() const;
	};
}
#endif // !SICT_CRA_ACCOUNT_H
