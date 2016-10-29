#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "movieBase.h"

movieBase::movieBase()
{
	subGenre = vector<int>(18,0);
	subGenre[0] = 1;
	subGenre[1] = 1;
	subGenre[2] = 3;
	subGenre[3] = 3;
	subGenre[4] = 3;
	subGenre[5] = 2;
	subGenre[6] = 6;
	subGenre[7] = 4;
	subGenre[8] = 5;
	subGenre[9] = 2;
	subGenre[10] = 2;
	subGenre[11] = 3;
	subGenre[12] = 2;
	subGenre[13] = 4;
	subGenre[14] = 5;
	subGenre[15] = 1;
	subGenre[16] = 6;
	subGenre[17] = 1;
	readMovieInfo();
}

movieBase::~movieBase()
{
}

void movieBase::readMovieInfo()
{
	string line;
	ifstream data("data/u.item");
	if (data.is_open()) {
		while (getline(data, line)) {
			stringstream ss;
			ss.str(line);
			string element;
			movie mov;
			getline(ss, element, '|');
			mov.index = stoi(element);
			getline(ss, element, '|');
			mov.title = element;
			ss.ignore(7, '\n');
			getline(ss, element, '|');
			mov.year = stoi(element);
			ss.ignore(numeric_limits<streamsize>::max(), '|');
			ss.ignore(numeric_limits<streamsize>::max(), '|');
			ss.ignore(numeric_limits<streamsize>::max(), '|');
			int i = 0;
			while (getline(ss, element, '|')) {
				if (element == "1") {
					mov.genre.push_back(subGenre[i]);
				}
				i++;
			}
			movieInfo[mov.index] = mov;
		}
	}
}

string movieBase::getTitle(int index)
{
	return movieInfo.at(index).title;
}

double movieBase::getRating(int index)
{
	return movieInfo.at(index).avg;
}

vector<int> movieBase::getGenre(int index)
{
	return movieInfo.at(index).genre;
}
