#pragma once

#ifndef movie_H_
#define movie_H_

#include <string>
#include <vector>

using namespace std;

class movie{
	friend class movieBase;
	friend class ratingBase;
	friend class driver;
public:
	explicit movie();
	~movie();
private:
	int index;
	string title;
	int year;
	vector<int> genre;
	double avg;
	int count;
};

#endif