#include "Station.h"
#include <iostream>
using namespace std;

Station::Station(int a, const char * b, double c)
{
	this->id = a;
	this->name = b;
	this->dist = c;
}

void Station::showStation()
{
	cout << "\t역번호 : " << this->id << " 역이름 : " << this->name << '\n';
}

double Station::getDistance()
{
	return this->dist;
	
}

const char * Station::getName()
{
	return this->name;
}



