#pragma once

#ifndef user_H_
#define user_H_

#include <map>
#include <vector>

using namespace std;

class user {
	friend class userBase;
	friend class ratingBase;
	friend class driver;
public:
	explicit user();
	~user();
private:
	int uId;
	map<int, double> movieRating;
	map<int, double> genreRating;
	vector<int> topMovies;
	map<int, double> pref;

};

#endif