#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H
#include <iostream>

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {
		char family_name[max_name_length + 1];
		char given_name[max_name_length + 1];
		int SIN;
	public:
		CRA_Account();
		void set(const char*, const char*, int);
		bool isEmpty() const;
		void display() const;
	};
}
#endif // !SICT_CRA_ACCOUNT_H
