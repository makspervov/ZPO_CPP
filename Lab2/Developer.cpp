#include "Developer.h"

float Developer::calculateBonus(int value) {
    return ( value + 0.2 * value * (getSalary() + getExperience()));
}

Developer::Developer(const std::string &surname, int age, int experience, int salary) : Employee(surname, age, experience, salary) {
    cout << " This is parameterized constructor - Developer" << std::endl;

}

void Developer::show() {
    cout << "I am Developer with " << getExperience() <<" years of experience." << std::endl;
}