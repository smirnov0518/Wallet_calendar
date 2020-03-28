#include<iostream>
#include<string>
#include "windows.h"
#include <stdio.h>
#include <windows.h>
#include <fstream>
using namespace std;
#define GREEN SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define RED SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
#define ORANGE SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define WHITE SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
bool show_calend(int &,int&, int&,int&, int&);
void controling_dates(int &, int&, int&, int&, int&);


int main() {

	
	SYSTEMTIME stime;
	FILETIME ltime;
	FILETIME ftTimeStamp;
	
	int days = 0, year = 1986, mon = 6, week_day = 0, today = 0;

	GetSystemTimeAsFileTime(&ftTimeStamp);
	FileTimeToLocalFileTime(&ftTimeStamp, &ltime);
	FileTimeToSystemTime(&ltime, &stime);
	year = stime.wYear;
	mon = stime.wMonth;
	week_day = stime.wDayOfWeek;
	controling_dates(today, days, year, mon, week_day);

	for (;;) {
		if (mon == stime.wMonth)today = stime.wDay;
		else today = 0;
		if (show_calend(today, days, year, mon, week_day)) {
			mon++;
			controling_dates(today, days, year, mon, week_day);
		}
		else {
			week_day = 7 - ((days - (week_day)) % 7);
			mon--;
			controling_dates(today, days, year, mon, week_day);
			week_day = 7 - ((days - (week_day)) % 7);
		}
	}

	system("pause");
	return 0;
}



bool show_calend(int &today,int &days, int &year,int &mon, int &week_day)
{
	system("cls");
	bool chek = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\t\t    Year  " << year << "  Mounth "<<mon << endl << endl;
	cout << "Mon\tTue\tWed\tThu\tFri\tSut\tSun" << endl << endl;

	for (int i = 0; i < week_day; i++) {
		cout << " \t";
	}
	for (int i = 1; i <= days; i++) {
		if (week_day % 7 == 0) {
			cout << endl << endl;
			week_day = 0;
		}
		if (i == today)RED
		cout << i << "\t";
		week_day++;
		WHITE
	}
	cout << endl;
	cin >> chek;
	return chek;
}

void controling_dates(int &today, int &days, int &year, int &mon, int &week_day)
{

	if (mon == 13) {
		mon = 1;
		year++;
	}
	if (mon == 0) {
		mon = 12;
		year--;
	}
	if (mon == 1 || mon == 3 || mon == 5 || mon == 7 ||mon==8|| mon == 10 || mon == 12)days = 31;
	else if ((year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0)) && mon == 2) {
		days = 29;
	}
	else if (mon == 2)days = 28;
	else days = 30;
}
