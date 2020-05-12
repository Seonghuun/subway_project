#include "Ticket.h"

void Ticket::makeSJTicket(const char * dpr, const char * dst, bool spc)
{
	this->dept_name = dpr;
	this->dest_name = dst;
	this->special = spc;
}

void Ticket::makeSPTicket(bool spc)
{
	this->special = spc;
}


