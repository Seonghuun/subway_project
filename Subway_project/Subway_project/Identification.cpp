#include "Identification.h"

Identification::Identification(int id_n, const char * nam, bool dis)
{
	this->id_no = id_n;
	this->name = nam;
	this->disabled = dis;
}

int Identification::getID_No()
{
	return this->id_no;
}

const char * Identification::getName()
{
	return this->name;
}