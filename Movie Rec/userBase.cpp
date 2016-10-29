#include <fstream>
#include <sstream>
#include "userBase.h"

userBase::userBase()
{
	readUser();
}

userBase::~userBase()
{
}

void userBase::readUser()
{
	string line;
	ifstream data("data/u.user");
	users.push_back(user());
	if (data.is_open()) {
		while (getline(data, line, '|')) {
			user person;
			person.uId = stoi(line);
			data.ignore(numeric_limits<streamsize>::max(), '\n');
			users.push_back(person);
		}
	}
}

user userBase::getUser(int person)
{
	return users[person];
}
