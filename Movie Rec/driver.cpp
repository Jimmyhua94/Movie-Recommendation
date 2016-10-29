#include <algorithm>
#include "movieBase.h"
#include "userBase.h"
#include "ratingBase.h"
#include "driver.h"

using namespace std;

driver::driver()
{
	ratings = ratingBase(&(movieDriver.movieInfo), &(userDriver.users));
}

driver::~driver()
{
}

struct topMovie {
	size_t movieId;
	string movieName;
	double topRate;

	topMovie(size_t mov, string mName, double topR)
		: movieId(mov), movieName(mName), topRate(topR)
	{ }
};

ostream& operator<<(ostream& OUT, const topMovie r) {
	OUT << "Preference: " << r.topRate << "\tMovie ID: " <<  r.movieId << "\tMovie Name: " << r.movieName;
	return OUT;
}

bool compTopRatings(const topMovie& r1,
	const topMovie& r2) {
	return r1.topRate > r2.topRate;
}

void driver::topRated(int user, int k)
{
	ratings.genreRatingAvg(user);
	vector<topMovie> topMovies;
	for (map<int, movie>::iterator it = movieDriver.movieInfo.begin(); it != movieDriver.movieInfo.end(); it++) {
		double factor = 0;
		for (int i = 0; i < it->second.genre.size(); i++) {
			factor += userDriver.users[user].pref[it->second.genre[i]];
		}
		factor /= it->second.genre.size();
		factor *= it->second.avg;
		topMovies.push_back(topMovie(it->second.index, it->second.title, factor));
	}
	sort(topMovies.begin(), topMovies.end(), compTopRatings);
	for (int i = 0; i<k && i < topMovies.size(); i++) {
		cout << topMovies[i] << endl;
	}
}



