#include "contacts.h"

Contacts::Contacts() {}

void Contacts::addContact(Contact c1) {
	this->phonebook.insert(c1);
}

void Contacts::removeContact(Contact c1) {
	this->phonebook.get<3>().erase(number);
}

void Contacts::findMemberByStreetName(string streetName) {
	cout << "\n\nShowing members of a street" << endl;
	for (auto it = this->phonebook.get<0>().begin(); it != this->phonebook.get<0>().end(); it++) {
		if (it->address == streetName) {
			cout << "###################" << endl;
			cout <<
				"Name:		" << it->name << endl <<
				"Lastname:	" << it->lastname << endl <<
				"Age:		" << it->age << endl <<
				"Street:	" << it->address << endl <<
				"Number:	" << it->phoneNumber << endl;
		}
	}
}