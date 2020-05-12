#pragma once
class Identification
{
private:
	int id_no;
	const char* name;
	bool disabled;
	
public:
	Identification(int id_n, const char* nam, bool dis);
	int getID_No();
	const char* getName();	
};

