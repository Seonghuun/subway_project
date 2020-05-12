#pragma once
class Card
{
private:
	int card_no;
	int balance;
public:
	Card();
	Card(int no, int bal);
	int getCard_NO();
	int getBalance();
	void recharge(int rcAmount);
};

