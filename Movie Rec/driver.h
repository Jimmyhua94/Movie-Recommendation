#pragma once

#ifndef driver_H_
#define driver_H_

#include <vector>
#include "movieBase.h"
#include "userBase.h"
#include "ratingBase.h"

using namespace std;

class driver {
public:
	explicit driver();
	~driver();
	void topRated(int user, int k);
private:
	movieBase movieDriver;
	userBase userDriver;
	ratingBase ratings;
};

#endif