#pragma once

#ifndef ratingBase_H_
#define ratingBase_H_

#include <iostream>
#include <map>

using namespace std;

class ratingBase {
public:
	explicit ratingBase(map<int, movie>* movieInfo, vector<user>* users);
	explicit ratingBase();
	~ratingBase();
	void readRating();
	void setAvgRating();
	void genreRatingAvg(int person);
private:
	map<int, movie>* movieInfo;
	vector<user>* users;
};

#endif