#include "Show_calend.h"

void show_calenda()
{
	SYSTEMTIME stime;
	FILETIME ltime;
	FILETIME ftTimeStamp;

	GetSystemTimeAsFileTime(&ftTimeStamp);
	FileTimeToLocalFileTime(&ftTimeStamp, &ltime);
	FileTimeToSystemTime(&ltime, &stime);
	int today = stime.wDay;
	int year = stime.wYear;
	int mon = stime.wMonth;
	int week_day = stime.wDayOfWeek;
	int days = 31;


	
}
