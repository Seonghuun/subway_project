#pragma once
#include "Route.h"
#include "Station.h"
#include "Identification.h"
#include "Card.h"
#include "Ticket.h"
#include <vector>

using namespace std;
class App
{
private:
	vector<Station> stationList;
	vector<Identification> idList;
	vector<Card> cardList;
	Ticket* ticketList;
	Card myCard;
	int totalCost;
	
public:
	
	void run();
	void setStationList();
	void showStationList();
	void setIdList();
	bool readId();
	void setCardList();
	bool readCard();
	bool checkPayment();
	void setTicketList(int a, const char * dpr, const char * dst, bool spc);
	void releaseSPTicket();
	
	
	
};

