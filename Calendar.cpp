#include <iostream>
#include <string>

using namespace std;

int firstDay( int year, int month, int day ) //function that calculates which day of the week, the first day of the month falls into, for specific month in year
{                                                  //(http://www.cplusplus.com/forum/general/174165/)
  int x, y, z;
  x = (14 - month) / 12;
  y = year - x;
  z = month + (12 * x) - 2;
  return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * z) / 12)) % 7;
}

void printYear(int year)//function that displays yearly calendar
{
  int newWeek=0;
  string months[]={"JANUARY", "FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER", "OCTOBER","NOVEMBER","DECEMBER"};//array of months
  int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};//make array of days in each month

  if ((year%4==0 and year%100!=0) or (year%400==0))//add extra day to Feb. if leap year
  {
    monthDays[1]=29;
  }
  cout<<endl;
  for (int month=0;month<12;month++)//print the following for each month:
  {
    cout<<"    "<<months[month]<<"  "<<year<<endl;
    cout<<endl;
    cout<<"    S    M   Tu    W   Th    F    S"<<endl;

    for (newWeek=0;newWeek<firstDay(year,month+1,1);newWeek++)//until first-day-of-month-position reached, fill preceding positions with blank spaces
    {
        cout<<"     ";
    }

    for(int day=1;day<=monthDays[month];day++)//print each day of month under corrct day of week
    {
      printf("%5d",day);
      if (++newWeek>6)//start new week line when 7 days are reached for one week
      {
        cout<<endl;
        newWeek=0;
      }
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
  }
}

void printMonth(int year, int month)
{
  int newWeek;
  string months[]={"JANUARY", "FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER", "OCTOBER","NOVEMBER","DECEMBER"};//array of months
  int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};//make array of days in each month

  if ((year%4==0 and year%100!=0) or (year%400==0))//add extra day to Feb. if leap year
  {
    monthDays[1]=29;
  }
  cout<<endl;
  cout<<"    "<<months[month-1]<<" "<<year<<endl;//month that user inputs
  cout<<endl;
  cout<<"    S    M   Tu    W   Th    F    S"<<endl;
  for (newWeek=0;newWeek<firstDay(year, month,1);newWeek++)//until first-day-of-month-position reached, fill preceding positions with blank spaces
  {
    cout<<"     ";
  }
  for (int i=1;i<=monthDays[month-1];i++)//print each day of month under corrct day of week
  {
    printf("%5d",i);
    if (++newWeek>6)//start new week line when 7 days are reached for one week
    {
      cout<<endl;
      newWeek=0;
    }
  }
  cout<<endl;
  cout<<endl;
  cout<<endl;
}

int main() {
  int year, month, choice;
  cout<<"Do you want the yearly calendar(1) or  the monthly calendar(2)?(1/2):";//ask what calendar they want
  cin>>choice;

  if (choice==1)//get parameters and call yearly calendar function
  {
    cout<<"Enter the year:";
    cin>>year;
    printYear(year);
  }
  else//get parameters and call monthly calendar function
  {
    cout<<"Enter the year:";
    cin>>year;
    cout<<"Enter the month(1-12):";
    cin>>month;
    printMonth(year,month);
  }
}
