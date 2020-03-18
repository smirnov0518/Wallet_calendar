#include<iostream>
#include<string>
#include "windows.h"
using namespace std;
#define GREEN SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define RED SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
#define ORANGE SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define WHITE SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
void show_calend(int, int, int);



int main() {
	int days = 0, year = 1986, mon = 6, week_day = 0;

	week_day = (year % 100);

	
		show_calend(30, 2020, 3);


	system("pause");
	return 0;
}



void show_calend(int days, int year, int week_day)
{
	system("cls");
	bool chek = 0;
	int posision = week_day;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\t\t    Year  " << year << "  August" << endl << endl;
	cout << "Mon\tTue\tWed\tThu\tFri\tSut\tSun" << endl << endl;

	for (int i = 0; i < week_day; i++) {
		cout << " \t";
	}
	for (int i = 1; i <= days; i++) {
		if (week_day % 7 == 0) {
			cout << endl << endl;
			week_day = 0;
		}
		if (i == 5 || i == 13 || i == 27)GREEN;
		if (i == 11 || i == 20)ORANGE
			if(i==12||i==28)RED
			cout << i << "\t";
		
		week_day++;
		
		WHITE
	}
	cout << endl;

	cin >> chek;
	if (chek)show_calend(days, year, week_day);
	else show_calend(days, year,7-( (days-(posision)) % 7));

}
