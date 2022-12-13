#include "Employee.h"

using namespace std;
Employee::Employee(const string &surname1, int age1, int experience1, int salary1) {
    surname = surname1;
    age = age1;
    experience = experience1;
    salary = salary1;
    cout << "This is parameterized constructor - Employee" << endl;

}

Employee::Employee() {cout << "This is unparameterized constructor - Employee" << endl;}

string &Employee::getSurname() const{
    return surname;
} 

int Employee::getAge() const {
    return age;
}

int Employee::getExperience() const {
    return experience;
}

int Employee::getSalary() const {
    return salary;
}

Employee::~Employee() {
    cout<<"Destruktor w klasie Employee"<<endl;
}

void Employee::show() {
    cout << "I am Employee with " << getExperience() <<" years of experience." << endl;
}