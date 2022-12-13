#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>

using namespace std;

class Employee
{
private:
	string surname;
	int age;
	int experience;
	int salary;
public:
	Employee(const string &surname, int age, int experience, int salary);
    Employee();
	virtual ~Employee();
	virtual void show();
	virtual int calculateSalary(int value);
	int ageEmployment();

	int getAge();
	
	int getExperience();
	
	int getSalary();
};
#endif