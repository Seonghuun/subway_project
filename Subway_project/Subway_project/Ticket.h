#pragma once
class Ticket
{
private:
	const char* dept_name;
	const char* dest_name;
	bool special;
public:
	void makeSJTicket(const char* dpr, const char* dst, bool spc);
	void makeSPTicket(bool spc);
	
};

