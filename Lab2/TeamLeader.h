#ifndef TASK_2_2_TEAMLEADER_H
#define TASK_2_2_TEAMLEADER_H

#include "Employee.h"

class TeamLeader: public Employee {
public:
    TeamLeader(const string &surname, int age, int experience, int salary);

    int calculateBonus(int value);
    void show() override;
};

#endif
