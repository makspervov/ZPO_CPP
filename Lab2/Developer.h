#ifndef DEVELOPER_H_INCLUDED
#define DEVELOPER_H_INCLUDED

#include "Employee.h"

class Developer: public Employee
{
public:
	float calculateBonus(int value);
	void show() override;

	Developer(const string &surname, int age, int expirience, int salary);
};
#endif