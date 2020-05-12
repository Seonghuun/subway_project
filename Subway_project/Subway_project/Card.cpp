#include "Card.h"

Card::Card()
{
}

Card::Card(int no, int bal)
{
	this->card_no = no;
	this->balance = bal;
}

int Card::getCard_NO()
{
	return this->card_no;
}

int Card::getBalance()
{
	return this->balance;
}

void Card::recharge(int rcAmount)
{
	this->balance += rcAmount;
}
