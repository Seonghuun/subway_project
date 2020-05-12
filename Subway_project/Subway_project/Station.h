#pragma once
class Station
{
private:
	int id;
	const char* name;
	double dist;
public:
	
	Station(int a, const char* b, double c);	
	void showStation();
	double getDistance();
	const char* getName();	
};

