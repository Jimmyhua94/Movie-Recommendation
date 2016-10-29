#include <iostream>
#include "driver.h"

using namespace std;

int main() {
	driver movies = driver();
	movies.topRated(1, 10);
	return 0;
}