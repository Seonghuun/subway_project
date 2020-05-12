#include "App.h"
#include <iostream>
using namespace std;


void App::run()
{
	this->setStationList();
	this->setIdList();
	this->setCardList();
	while (1)
	{	
		cout << "\n\t--------------------------------------";
		cout << '\n' << "\t원하시는 서비스를 선택해주세요." << '\n' << '\n';
		cout << "\t1. 1회용 교통 카드 발급" << '\n';
		cout << "\t2. 우대권 발급" << '\n';
		cout << "\t3. 교통 카드 충전" << '\n';
		int service;
		cout << "\n\t-> "; cin >> service;
		switch (service)
		{
		case 1:
		{
			cout << '\n' << "\t1회용 교통카드 발급을 선택하셨습니다." << '\n';
			cout << '\n' << "\t출발역과 도착역을 선택해주세요." << '\n';
			
			
			this->showStationList();
			int depart, destin;
			
			cout << "\n\t-> "; cin >> depart >> destin;
			
			cout << '\n' << "\t구매매수를 선택해주세요" << '\n';
			int amount;
			cout << "\n\t-> "; cin >> amount;
			double dept_dist = this->stationList[depart].getDistance(); double dest_dist = this->stationList[destin].getDistance();
			Route rt(dept_dist, dest_dist, amount);
			
			this->totalCost = rt.getFare() + 500* amount; //보증금 추가
			cout << '\n' << "\t운임 : " << this->totalCost - 500 * amount<< "원 보증금 :  " << 500 *amount <<"원  합계금액 : " << this->totalCost  << "원" << '\n';
			cout << '\n' << "\t합계금액을 넣어주세요" << '\n';
			bool ckP = this->checkPayment();
			if (ckP == true) {
				this->setTicketList(amount, this->stationList[depart].getName(), this->stationList[destin].getName(), 0);
			}
			break;
		}

		case 2:
		{
			cout << '\n' << "\t우대권 발급을 선택하셨습니다." << '\n';
			cout << '\n' << "\t발급대상 확인을 위해 신분증을 리더기에 올려주세요(주민번호 앞자리 입력으로 대체)" << '\n';
			bool checkId = this->readId();
			if (checkId == true) {
				cout << '\n' << "\t신원이 확인되었습니다. 보증금을 넣어주세요" << '\n' << "\t보증금 : 500원" << '\n';
				this->totalCost = 500;
				bool ckP = this->checkPayment();
				if (ckP == true) {
					this->releaseSPTicket();
				}
			}
			else {
				cout << '\n' << "\t우대권 발급대상이 아닙니다.";
			}
			break;
		}
		case 3:
		{
			cout << '\n' << "\t교통카드 충전을 선택하셨습니다." << '\n';
			cout << '\n' << "\t교통카드를 리더기에 올려주세요(카드 일련번호 입력으로 대체)" << '\n';
			bool ex = this->readCard();
			if (ex == true) {
				cout << '\n' << "\t고객님의 교통카드 잔액입니다" << '\n' << "\t교통카드 잔액 : " << this->myCard.getBalance() << '\n';
				cout << '\n' << "\t충전할 금액을 입력해주세요" << '\n';
				cout << "\n\t-> "; cin >> this->totalCost;
				cout << '\n' << "\t입력한 금액은 " << this->totalCost << "원입니다" << '\n' << "\t금액을 넣어주세요" << '\n';

				bool ckP = this->checkPayment();
				if (ckP == true) {
					this->myCard.recharge(this->totalCost);
					cout << '\n' << "\t충전후 금액 : " << this->myCard.getBalance() << "원" << '\n' << "\t충전이 완료되었습니다" << '\n';
				}
				break;

			}
		}
		}
	}
}


void App::setStationList()
{
	Station s_1(1, "북한산우이", 0), s_2(2, "솔밭공원", 0.8), s_3(3, "4.19민주묘지", 1.5), s_4(4, "가오리", 2.4),
			s_5(5, "화계", 3.2), s_6(6, "삼양", 4.0), s_7(7, "삼양사거리", 4.7), s_8(8, "솔샘", 5.5), s_9(9, "북한산보국문", 6.7),
			s_10(10, "정릉", 7.9), s_11(11, "성신여대입구", 9.1), s_12(12, "보문", 10.0), s_13(13, "신설동", 11.0), s_0(0, "차량사업소", 0);
	this->stationList.push_back(s_0);
	this->stationList.push_back(s_1); this->stationList.push_back(s_2); this->stationList.push_back(s_3); this->stationList.push_back(s_4); 
	this->stationList.push_back(s_5); this->stationList.push_back(s_6); this->stationList.push_back(s_7); this->stationList.push_back(s_8); 
	this->stationList.push_back(s_9); this->stationList.push_back(s_10); this->stationList.push_back(s_11); this->stationList.push_back(s_12); 
	this->stationList.push_back(s_13);
}

void App::showStationList()
{

	for (int i = 1; i < this->stationList.size(); i++) {
		this->stationList[i].showStation();
	}
}

void App::setIdList()
{
	Identification id_1(540101, "김철수", 0), id_2(510314, "박명자", 0), id_3(750515, "김민수", 1);
	this->idList.push_back(id_1); this->idList.push_back(id_2); this->idList.push_back(id_3);
}

bool App::readId()
{
	int id;
	cout << "\n\t-> "; cin >> id;
	for (int i = 0; i < this->idList.size(); i++) {
		if (this->idList[i].getID_No() == id) {
			return true;
		}
		else {
			
		}
	}
}

void App::setCardList()
{
	Card cd_1(1234, 10000), cd_2(4321, 15000), cd_3(5678, 23500);
	this->cardList.push_back(cd_1); this->cardList.push_back(cd_2); this->cardList.push_back(cd_3);
}

bool App::readCard()
{
	int cd;
	cout << "\n\t-> "; cin >> cd;
	bool flag = false; int idx;
	for (int i = 0; i < this->cardList.size(); i++) {
		if (this->cardList[i].getCard_NO() == cd) {
			flag = true;
			idx = i;
			
		}
	}
	if (flag == true) {
		this->myCard = this->cardList[idx];
		return true;
	}
	else {
		cout << "\t등록되지 않은 카드입니다" << '\n';
		return false;
	}
	
}

bool App::checkPayment()
{
	
	int deposit, change;
	cout << "\n\t-> "; cin >> deposit;
	if (deposit >= this->totalCost) {
		
		change = deposit - totalCost;
		cout << '\n'<<"\t거스름돈 : " << change <<"원"<< '\n';
		return true;
	}
	else {
		cout << "\t금액이 부족합니다" << '\n';

	}
}

void App::setTicketList(int a, const char * dpr, const char * dst, bool spc)
{
	ticketList= new Ticket[a];
	for (int k = 0; k < a; k++) {
		ticketList[k].makeSJTicket(dpr, dst, spc);
	}
	cout << '\n'  << "\t1회용 교통카드 " << a << "장이 발급되었습니다" << '\n';
}

void App::releaseSPTicket()
{
	Ticket tick;
	tick.makeSPTicket(1);
	cout << '\n' << "\t우대권이 발급되었습니다" <<'\n';
}




