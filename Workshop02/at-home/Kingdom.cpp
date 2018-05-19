/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: include the necessary headers
#include "Kingdom.h"
// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 
	void sict::display(const Kingdom& kingdom)
	{
		std::cout << kingdom.m_name << ", population "
			<< kingdom.m_population << std::endl;
	}
	void display(const Kingdom* kingdom, int numOfKingdoms)
	{
		int incrementer = 1;
		int totalPopulation = 0;
		std::cout << "------------------------------" << std::endl
			      << "Kingdoms of SICT" << std::endl
			      << "------------------------------" << std::endl;
		for (int i = 0; i < numOfKingdoms; i++) {
			std::cout << incrementer++ << ". "
				      << kingdom[i].m_name<< ", population "
				      << kingdom[i].m_population << std::endl;
			totalPopulation += kingdom[i].m_population;
		}
		std::cout << "------------------------------" << std::endl
			      << "Total population of SICT: " << totalPopulation << std::endl
			      << "------------------------------" << std::endl;
	}
}