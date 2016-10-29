#pragma once

#ifndef userBase_H_
#define userBase_H_

#include <vector>
#include "user.h"

using namespace std;

class userBase {
	friend class ratingBase;
	friend class driver;
public:
	explicit userBase();
	~userBase();
	void readUser();
	user getUser(int person);
private:
	vector<user> users;
};

#endif