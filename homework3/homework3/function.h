#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <string>
using namespace std;

struct date
{
	int day;
	int month;
	int year;
	date();
	date(int d, int m, int y);
}; 

struct Student
{
	std::string Lastname; // фамилия
	std::string Name;
	std::string Surname; //отчество
	date birthday; //date of birth
	std::string phone;
	Student()
	{
		Lastname = " ";
		Name = " ";
		Surname = " ";
		birthday.day = 0;
		birthday.month = 0;
		birthday.year = 0;
		phone = " ";
	};
	Student(std::string _lastname, std::string _name, std::string _surname, date _birthday, std::string _phone)
	{
		Lastname = _lastname;
		Name = _name;
		Surname = _surname;
		birthday = _birthday;
		phone = _phone;
	};
	bool operator==(const Student& student) const;
	bool operator!=(const Student& student) const;
};

class Group {
private:
	Student* students;
	int count;//count of students
	
	
public:
	Group();
	Group(int count);
	~Group();	

	void readGroupFile(const string& filepath);
	void printGroup();

	void addStudent();

	void removeByInitials(const string& lastname, const string& name, const string& surname);
	void removeByPhone(const string& phone);

	int findPhone(const string& phone);
	int findInitials(const string& lastname, const string& name, const string& surname);

	friend std::istream& operator>>(std::istream& in, Student& new_student);
	friend std::ostream& operator<<(std::ostream& out, const Student& new_student);

	
};


std::string getFilePath();

#endif
