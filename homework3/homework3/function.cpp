#include "function.h"
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
using namespace std;

//construct and distruct Group
Group::Group()
{
	 count = 0;
}

Group::Group(int count)
{
	students = new Student[count];
}

Group::~Group() 
{
	delete[] students;
}


//For struct Date
date::date()
{
	day = 0;
	month = 0;
	year = 0;
}

date::date(int d, int m, int y)
{
	this->day = d;
	this->month = m;
	this->year = y;
}


//operators
std::istream& operator>>(std::istream& in, Student& new_student)
{
	std::cout << "Enter student's lastname: ";
	in >> new_student.Lastname;
	std::cout << "Enter student's name: ";
	in >> new_student.Name;
	std::cout << "Enter student's surname: ";
	in >> new_student.Surname;
	std::cout << "Enter student's phone number: ";
	in >> new_student.phone;
	std::cout << "Enter student's birthday (day month year): ";
	in >> new_student.birthday.day >> new_student.birthday.month >> new_student.birthday.year;

	return in;
}
std::ostream& operator<<(std::ostream& out, const Student& new_student)
{
	out << "Lastname: " << new_student.Lastname << "\n";
	cout << "Name: " << new_student.Name << "\n";
	cout << "Surname: " << new_student.Surname << "\n";
	cout << "Birthday: " << new_student.birthday.day << "."
		<< new_student.birthday.month << "."
		<< new_student.birthday.year << "\n";
	cout << "Phone number: " << new_student.phone << "\n\n";
	return out;
}

bool Student::operator!=(const Student& student) const
{
	return !((*this) == student);
}

bool Student::operator==(const Student& student) const
{
	if (Lastname != student.Lastname)
	{
		return false;
	}

	if (Name != student.Name)
	{
		return false;
	}
	
	if (Surname != student.Surname)
	{
		return false;
	}
	if (phone != student.phone)
	{
		return false;
	}
}

//functions

//get path
std::string getFilePath()
{
	string filepath;
	std::cout << "Enter file path: ";
	std::cin >> filepath;
	return filepath;
}

//read file
void Group::readGroupFile(const string& filepath)
{
	ifstream file(filepath);
	if (!file.is_open()) {
		cout << "Error. Can't open file.\n";
		return;
	}

	int _count;
	file >> _count;

	count = _count;
	students = new Student[count];

	for (int i = 0; i < count; i++) {
		Student s;
		char dot;
		file >> s.Lastname >> s.Name >> s.Surname
			>> s.birthday.day >> dot >> s.birthday.month >> dot >> s.birthday.year
			>> s.phone;
		students[i] = s;
	}
}

void Group::printGroup() 
{
	for (int i = 0; i < this->count; i++) {
		if (!this->students[i].Lastname.empty()) {
			std::cout << "¹" << i + 1 << ":\n";
			std::cout << students[i];
		}
	}
}

void Group::addStudent()
{
	count++;
	Student* add = new Student[count];
	for (int i = 0; i < count - 1; i++) {
		add[i] = students[i];
	}
	delete[] students;
	Student new_student;
	std::cin >> new_student;
	add[count - 1] = new_student;
	students = add;
}

//delete by initials
void Group::removeByInitials(const string& lastname, const string& name, const string& surname) //add name and surname 
{
	int id = findInitials(lastname, name, surname);
	if (id == -1)
	{
		return;
	}
	for (int j = id; j < count - 1; j++)
	{
		students[j] = students[j + 1];
	}
	count--;

	Student* remove = new Student[count];
	for (int i = 0; i < count; i++)
	{
		remove[i] = students[i];
	}
	delete[] students;
	students = remove;

}

int Group::findInitials(const string& lastname, const string& name, const string& surname)
{
	int id = -1;
	for (int i = 0; i < count; i++) 
	{
		if ((students[i].Lastname == lastname) && (students[i].Name == name) && (students[i].Surname == surname))
		{
			 id = i;
			 break;
		}
	}
	if (id == -1)
	{
		std::cout << "Student with this initials not found\n";
	}
	return id;
}

// delete be phone number
int Group::findPhone(const string& phone)
{
	int id = -1;
	for (int i = 0; i < count; i++) {
		if (students[i].phone == phone) {
			id = i;
			break;
		}
	}
	if (id == -1)
	{
		std::cout << "Student with this phone number not found\n";
	}
	return id;
}

void Group::removeByPhone(const string& phone)
{
	int id = findPhone(phone);
	if (id == -1)
	{
		return;
	}
	for (int j = id; j < count - 1; j++)
	{
		students[j] = students[j + 1];
	}
	count--;

	Student* remove = new Student[count];
	for (int i = 0; i < count; i++)
	{
		remove[i] = students[i];
	}
	delete[] students;
	students = remove;
}

