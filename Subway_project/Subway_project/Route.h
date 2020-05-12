#pragma once
class Route
{
private:
	double dept_dist;
	double dest_dist;
	int amount;
public:
	Route(double a, double b, int am);
	double getTotalDist();
	int getFare();
};

