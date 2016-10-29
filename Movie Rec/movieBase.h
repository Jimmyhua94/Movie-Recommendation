#pragma once

#ifndef movieBase_H_
#define movieBase_H_

#include <string>
#include <vector>
#include <map>
#include "movie.h"

using namespace std;

class movieBase{
	friend class ratingBase;
	friend class driver;
public:
	explicit movieBase();
	~movieBase();
	void readMovieInfo();
	string getTitle(int index);
	double getRating(int index);
	vector<int> getGenre(int index);
private:
	map<int, movie> movieInfo;
	vector<int> subGenre;
};

#endif