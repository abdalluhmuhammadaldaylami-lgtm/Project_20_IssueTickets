#pragma once
#include <iostream>
#include"clsDate.h"
#include<queue>
using namespace std;

class clsQueueLine
{
private:
	string _Perfix = "";
	int _TotalTikets = 0;
	int _AverageServeTime = 0;

	class clsTiket
	{
	private:
		short _Number=0;
		string _Perfix;
		string _TiketTime;
		int _AverageServeTime = 0;
		int _ExpectedServeTime = 0;
		int _WatingClints = 0;
		
	public:
		clsTiket(string perfix, short number, int watingClints, int AverageServeTime)
		{
			_Perfix = perfix;
			_Number = number;
			_WatingClints = watingClints;
			_AverageServeTime = AverageServeTime;
			_TiketTime = clsDate::GetSystemDateTimeString();
		}

		int Number()
		{
			return _Number;
		}

		string Perfex()
		{
			return _Perfix + to_string(_Number);
		}

		int watingClints()
		{
			return _WatingClints;
		}

		string TiketTime()
		{
			return _TiketTime;
		}
		 
		int ExpectedServeTime()
		{
			return _AverageServeTime *_WatingClints;
		}

		void print()
		{
			cout << "\n\t\t ________________________";
			cout << "\n\t\t\t  " << Perfex() << "\n";
			cout << "\n\t\t " << _TiketTime;
			cout << "\n\t\t Wating Clints :" << _WatingClints;
			cout << "\n\t\t Serve Time In :" << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t__________________________\n";
		}
	};

public:

	queue<clsTiket>QueueLine;

	clsQueueLine(string perfix, int AverageServeTime)
	{
		_TotalTikets = 0;
		_Perfix = perfix;
	    _AverageServeTime = AverageServeTime;
	}

	void IssueTicket()
	{
		_TotalTikets++;
		clsTiket Tiket(_Perfix, _TotalTikets, WatingClints(), _AverageServeTime);
		QueueLine.push(Tiket);
	}

	int WatingClints()
	{
		return QueueLine.size();
	}

	bool ServNextClint()
	{
		if (QueueLine.empty())
		{
			return false;
		}
		QueueLine.pop();
		return true;
	}

	int ServedClints()
	{
		return _TotalTikets - WatingClints();
	}

	void PrintInfo()
	{
		cout << "\t\t____________________________\n\n";
		cout << "\t\t\tQueue Line :\n";
		cout << "\t\t____________________________\n";
		cout << "\t\t\tPerfex :" << _Perfix << endl;
		cout << "\t\t\tTotal Tilets :" << _TotalTikets << endl;
		cout << "\t\t\tServed Clints :" << ServedClints() << endl;
		cout << "\t\t\tWating Clints :" << WatingClints() << endl;
		cout << "\t\t____________________________\n";
	}

	void PrintAllTikets() 
	{
		cout << "\n\n\t\t  --------Tickets--------\n";
		if (QueueLine.empty())
		{
			cout << "\n\n\t\t\t  --No Tickets--\n";
		}

		queue<clsTiket>tempqueu = QueueLine;
		while (!tempqueu.empty()) {

			tempqueu.front().print();
			tempqueu.pop();
		}
	}
};

