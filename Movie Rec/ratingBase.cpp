#include <fstream>
#include <sstream>
#include "userBase.h"
#include "movieBase.h"
#include "ratingBase.h"

ratingBase::ratingBase(map<int, movie>* movieInfo, vector<user>* users)
{
	ratingBase::movieInfo = movieInfo;
	ratingBase::users = users;
	readRating();
	setAvgRating();
}

ratingBase::ratingBase()
{
}

ratingBase::~ratingBase()
{
}

void ratingBase::readRating()
{
	string line;
	ifstream data("data/u.data");
	if (data.is_open()) {
		while (getline(data, line)) {
			string element[3];
			stringstream ss;
			ss.str(line);
			getline(ss, element[0], '\t');
			getline(ss, element[1], '\t');
			getline(ss, element[2], '\t');
			movieInfo->at(stoi(element[1])).avg += stoi(element[2]);
			movieInfo->at(stoi(element[1])).count++;
			users->at(stoi(element[0])).movieRating[stoi(element[1])] = stoi(element[2]);
		}
	}
}

void ratingBase::setAvgRating()
{
	for (map<int, movie>::iterator it = movieInfo->begin(); it != movieInfo->end(); it++) {
		it->second.avg /= it->second.count;
	}
}

void ratingBase::genreRatingAvg(int person)
{
	vector<vector<double>> genres(6, vector<double>(3, 0));
	for (map<int, double>::iterator it = users->at(person).movieRating.begin(); it != users->at(person).movieRating.end(); it++) {
		for (int i = 0; i < movieInfo->at(it->first).genre.size(); i++) {
			genres[movieInfo->at(it->first).genre[i]-1][0] += it->second;
			genres[movieInfo->at(it->first).genre[i]-1][1] += movieInfo->at(it->first).avg;
			genres[movieInfo->at(it->first).genre[i]-1][2]++;
		}
	}
	for (int i = 0; i < 6; i++){
		users->at(person).genreRating[i+1] = genres[i][0] / genres[i][2];
		users->at(person).pref[i+1] = users->at(person).genreRating[i+1] / (genres[i][1] / genres[i][2]);
	}
}