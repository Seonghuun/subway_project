#include "Route.h"
#include <cmath>

Route::Route(double dept, double dest, int am)
{
	this->dept_dist = dept;
	this->dest_dist = dest;
	this->amount = am;
}

double Route::getTotalDist()
{
	double total;
	total = this->dest_dist - this->dept_dist;
	return abs(total);
}

int Route::getFare()
{
	int fare = 1350;
	double payup = this->getTotalDist();
	if (this->getTotalDist() <= 10){
		fare += 0;
	}else if (this->getTotalDist() <= 50) {
		payup = ceil((payup - 10) / 5);
		fare += payup * 100;
	}
	else if (this->getTotalDist() > 50) {
		fare += 800;
		payup = ceil((payup - 50) / 8);
		fare += payup * 100;

	}
	return fare * this->amount ;
}

