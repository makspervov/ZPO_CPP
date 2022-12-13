#include "TeamLeader.h"

using namespace std;
int TeamLeader::calculateBonus(int value) {
    return value * (1 + getSalary() + getExperience());
}

void TeamLeader::show() {
    cout << "I am TeamLead with " << getExperience() <<" years of experience." << endl;
}

TeamLeader::TeamLeader(const string &surname, int age, int experience, int salary) : Employee(surname, age, experience, salary) {
    cout << " This is parameterized constructor - TeamLead" << endl;

}