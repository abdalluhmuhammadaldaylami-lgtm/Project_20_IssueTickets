#include <iostream>
#include"clsQueueLine.h"
using namespace std;

int main()
{
	clsQueueLine PayBillsQueue("A0", 10);
	clsQueueLine SubscriptionQueue("B0", 5);

	cout << " pay Bills Queue Info:\n";
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();

	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintAllTikets();
	PayBillsQueue.ServNextClint();
	PayBillsQueue.PrintInfo();

	cout << " Subscription Queue Info:\n";
	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();
	SubscriptionQueue.IssueTicket();

	SubscriptionQueue.PrintInfo();


	SubscriptionQueue.PrintAllTikets();
	SubscriptionQueue.ServNextClint();

}
