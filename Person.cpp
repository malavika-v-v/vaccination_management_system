#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Person.h"
#include "Vaccine.h"

//using namespace std; //dont use, bad practise?


void Person::enterDate1()
{

       int dateFlag = 0;
       int day, month, year;
                                                       //string inputDate;cin.clear();cin.ignore(100,'\n');
 
       while( dateFlag == 0 )
       {
          
       //or use getline for string and then parse with .find and .substr and .erase?
       cout<< "Enter day in dd format: ";
       cin>> day;
       cout<< "Enter month in mm format: ";
       cin>> month;
       cout<< "Enter year in yy format: ";
       cin>> year;
 
       if( year < 2021 )
       {
           cout<< "Invalid date!";
       }
       else
       if( day < 1 || day > 31)
       {
           cout<< "Invalid date!";
       }
       else
       if( month < 1 || month > 12)
       {
           cout<< "Invalid date!";
       }
       else//day > 31 redundant //not checking leap yr
       if( (month == 1 && day > 31) || (month == 2 && day > 28) || (month == 3 && day > 31) || (month == 4 && day > 30) || (month == 5 && day > 31) || (month == 6 && day > 30) || (month == 7 && day > 31) || (month == 8 && day > 31) || (month == 9 && day > 30) || (month == 10 && day > 31) || (month == 11 && day > 30) || (month == 12 && day > 31) )
       {
           cout<< "Invalid date!";
       }
       else
       {
           dateFlag = 1;
           cout<< "Date successfully entered!";
       }
                           
       }

       dateDose1 = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

}

void Person::enterDate2()
{

       int dateFlag = 0;
       int day, month, year;
                                                       //string inputDate;cin.clear();cin.ignore(100,'\n');
 
       while( dateFlag == 0 )
       {
          
       //or use getline for string and then parse with .find and .substr and .erase?
       cout<< "Enter day in dd format: ";
       cin>> day;
       cout<< "Enter month in mm format: ";
       cin>> month;
       cout<< "Enter year in yy format: ";
       cin>> year;
 
       if( year < 2021 )
       {
           cout<< "Invalid date!";
       }
       else
       if( day < 1 || day > 31)
       {
           cout<< "Invalid date!";
       }
       else
       if( month < 1 || month > 12)
       {
           cout<< "Invalid date!";
       }
       else//day > 31 redundant //not checking leap yr
       if( (month == 1 && day > 31) || (month == 2 && day > 28) || (month == 3 && day > 31) || (month == 4 && day > 30) || (month == 5 && day > 31) || (month == 6 && day > 30) || (month == 7 && day > 31) || (month == 8 && day > 31) || (month == 9 && day > 30) || (month == 10 && day > 31) || (month == 11 && day > 30) || (month == 12 && day > 31) )
       {
           cout<< "Invalid date!";
       }
       else
       {
           dateFlag = 1;
           cout<< "Date successfully entered!";
       }
                           
       }

       dateDose2 = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

}


int Person::getDatesDifference(string date1, string date2)
{
    int day1,day2,month1,month2,year1,year2;
      
    // Vector of string to save tokens
    vector <string> tokens;
      
    // stringstream class check1
    stringstream check1(date1);
      
    string part;
      
    // Tokenizing w.r.t. space '/'
    while(getline(check1, part, '/'))
    {
        tokens.push_back(part);
    }


    day1    = stoi( tokens[0] );
    month1  = stoi( tokens[1] );
    year1   = stoi( tokens[2] );

    stringstream check2(date2);

    while(getline(check2, part, '/'))
    {
        tokens.push_back(part);
    }

    day2    = stoi( tokens[3] );
    month2  = stoi( tokens[4] );
    year2   = stoi( tokens[5] );



    //fn finds difference in days date2 - date1(aka calling date) by: finding no of days from year 0000 for each date and subtracting them;
 
       int daysBeforeDate1=0;
       int daysBeforeDate2=0;
 
       int leapYearsBeforeDate1;
       int leapYearsBeforeDate2;
 
       const int monthDays[ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 
       int index;
 
   //finding date1 days:-
 
       //convert years and days and add to daycount
       daysBeforeDate1 += ( year1 * 365 ) + day1;
 
       //add leap year days to dayscount
       if( month1 <= 2 )
       {
           leapYearsBeforeDate1 = ( (year1 - 1) / 4 ) - ( (year1 - 1) / 100 ) + ( (year1 - 1) / 400 );
       }
       else
       {
           leapYearsBeforeDate1 = ( year1 / 4 ) - ( year1 / 100 ) + ( year1 / 400 );
       }
 
       daysBeforeDate1 += leapYearsBeforeDate1;
 
       //convert and add months to dayscount
       for( index = 0 ; index < ( month1 - 1 ) ; index++ )
       {
           daysBeforeDate1 += monthDays[index];
       }
 
 
   //finding date2 days:-
 
       //convert years and days and add to daycount
       daysBeforeDate2 += ( year2 * 365 ) + day2;
 
       //add leap year days to dayscount
       if( month2 <= 2 )
       {
           leapYearsBeforeDate2 = ( (year2 - 1) / 4 ) - ( (year2 - 1) / 100 ) + ( (year2 - 1) / 400 );
       }
       else
       {
           leapYearsBeforeDate2 = ( year2 / 4 ) - ( year2 / 100 ) + ( year2 / 400 );
       }
 
       daysBeforeDate2 += leapYearsBeforeDate2;
 
       //convert and add months to dayscount
       for( index = 0 ; index < ( month2 - 1 ) ; index++ )
       {
           daysBeforeDate2 += monthDays[index];
       }
 
 
       //debug display days
       //cout<< "date1 days: "<< daysBeforeDate1;//
       //cout<< "date2 days: "<< daysBeforeDate2;//
 
 
       //check 60 difference btw days
       return (daysBeforeDate2 - daysBeforeDate1) ;


}

//int main (void) { return 0; }