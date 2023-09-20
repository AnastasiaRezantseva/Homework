#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <string>
class Group {
private: 
	struct date
	{
		int day;
		int month;
		int year;

	};

	struct Student 
	{
		std::string Lastname; // фамилия
		std::string Name;
		std::string Surname; //отчество
		date birthday; //date of birth
		std::string phone;
	};

public:

};

#endif
