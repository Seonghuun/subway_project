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
		cout << '\n' << "\t���Ͻô� ���񽺸� �������ּ���." << '\n' << '\n';
		cout << "\t1. 1ȸ�� ���� ī�� �߱�" << '\n';
		cout << "\t2. ���� �߱�" << '\n';
		cout << "\t3. ���� ī�� ����" << '\n';
		int service;
		cout << "\n\t-> "; cin >> service;
		switch (service)
		{
		case 1:
		{
			cout << '\n' << "\t1ȸ�� ����ī�� �߱��� �����ϼ̽��ϴ�." << '\n';
			cout << '\n' << "\t��߿��� �������� �������ּ���." << '\n';
			
			
			this->showStationList();
			int depart, destin;
			
			cout << "\n\t-> "; cin >> depart >> destin;
			
			cout << '\n' << "\t���Ÿż��� �������ּ���" << '\n';
			int amount;
			cout << "\n\t-> "; cin >> amount;
			double dept_dist = this->stationList[depart].getDistance(); double dest_dist = this->stationList[destin].getDistance();
			Route rt(dept_dist, dest_dist, amount);
			
			this->totalCost = rt.getFare() + 500* amount; //������ �߰�
			cout << '\n' << "\t���� : " << this->totalCost - 500 * amount<< "�� ������ :  " << 500 *amount <<"��  �հ�ݾ� : " << this->totalCost  << "��" << '\n';
			cout << '\n' << "\t�հ�ݾ��� �־��ּ���" << '\n';
			bool ckP = this->checkPayment();
			if (ckP == true) {
				this->setTicketList(amount, this->stationList[depart].getName(), this->stationList[destin].getName(), 0);
			}
			break;
		}

		case 2:
		{
			cout << '\n' << "\t���� �߱��� �����ϼ̽��ϴ�." << '\n';
			cout << '\n' << "\t�߱޴�� Ȯ���� ���� �ź����� �����⿡ �÷��ּ���(�ֹι�ȣ ���ڸ� �Է����� ��ü)" << '\n';
			bool checkId = this->readId();
			if (checkId == true) {
				cout << '\n' << "\t�ſ��� Ȯ�εǾ����ϴ�. �������� �־��ּ���" << '\n' << "\t������ : 500��" << '\n';
				this->totalCost = 500;
				bool ckP = this->checkPayment();
				if (ckP == true) {
					this->releaseSPTicket();
				}
			}
			else {
				cout << '\n' << "\t���� �߱޴���� �ƴմϴ�.";
			}
			break;
		}
		case 3:
		{
			cout << '\n' << "\t����ī�� ������ �����ϼ̽��ϴ�." << '\n';
			cout << '\n' << "\t����ī�带 �����⿡ �÷��ּ���(ī�� �Ϸù�ȣ �Է����� ��ü)" << '\n';
			bool ex = this->readCard();
			if (ex == true) {
				cout << '\n' << "\t������ ����ī�� �ܾ��Դϴ�" << '\n' << "\t����ī�� �ܾ� : " << this->myCard.getBalance() << '\n';
				cout << '\n' << "\t������ �ݾ��� �Է����ּ���" << '\n';
				cout << "\n\t-> "; cin >> this->totalCost;
				cout << '\n' << "\t�Է��� �ݾ��� " << this->totalCost << "���Դϴ�" << '\n' << "\t�ݾ��� �־��ּ���" << '\n';

				bool ckP = this->checkPayment();
				if (ckP == true) {
					this->myCard.recharge(this->totalCost);
					cout << '\n' << "\t������ �ݾ� : " << this->myCard.getBalance() << "��" << '\n' << "\t������ �Ϸ�Ǿ����ϴ�" << '\n';
				}
				break;

			}
		}
		}
	}
}


void App::setStationList()
{
	Station s_1(1, "���ѻ����", 0), s_2(2, "�ֹ����", 0.8), s_3(3, "4.19���ֹ���", 1.5), s_4(4, "������", 2.4),
			s_5(5, "ȭ��", 3.2), s_6(6, "���", 4.0), s_7(7, "����Ÿ�", 4.7), s_8(8, "�ֻ�", 5.5), s_9(9, "���ѻ꺸����", 6.7),
			s_10(10, "����", 7.9), s_11(11, "���ſ����Ա�", 9.1), s_12(12, "����", 10.0), s_13(13, "�ż���", 11.0), s_0(0, "���������", 0);
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
	Identification id_1(540101, "��ö��", 0), id_2(510314, "�ڸ���", 0), id_3(750515, "��μ�", 1);
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
		cout << "\t��ϵ��� ���� ī���Դϴ�" << '\n';
		return false;
	}
	
}

bool App::checkPayment()
{
	
	int deposit, change;
	cout << "\n\t-> "; cin >> deposit;
	if (deposit >= this->totalCost) {
		
		change = deposit - totalCost;
		cout << '\n'<<"\t�Ž����� : " << change <<"��"<< '\n';
		return true;
	}
	else {
		cout << "\t�ݾ��� �����մϴ�" << '\n';

	}
}

void App::setTicketList(int a, const char * dpr, const char * dst, bool spc)
{
	ticketList= new Ticket[a];
	for (int k = 0; k < a; k++) {
		ticketList[k].makeSJTicket(dpr, dst, spc);
	}
	cout << '\n'  << "\t1ȸ�� ����ī�� " << a << "���� �߱޵Ǿ����ϴ�" << '\n';
}

void App::releaseSPTicket()
{
	Ticket tick;
	tick.makeSPTicket(1);
	cout << '\n' << "\t������ �߱޵Ǿ����ϴ�" <<'\n';
}




