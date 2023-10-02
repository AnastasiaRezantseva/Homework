#include "function.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// C:\Users\Anastasiya\Desktop\Homework\homework3\homework3\Group.txt
int main() {

	// get path 
	std::string filepath = getFilePath(); 
	std::cout << filepath << endl; //for check

	//read and print group from file
	Group group;
	group.readGroupFile(filepath);
	group.printGroup(); //for check

	string lastname, name, surname, phone;
	char mode;
	 // add student
			group.addStudent();
			group.printGroup();

	 //removeByInitials
			
	std::cout << "Enter student's lastname, name and surname \n";
	std::cin >> lastname >> name >> surname;
	group.removeByInitials(lastname, name, surname);
	group.printGroup();

	//removeByPhone
	std::cout << "Enter student's phone number \n";
	std::cin >> phone;
	group.removeByPhone(phone);
	group.printGroup();
	return 0;
}