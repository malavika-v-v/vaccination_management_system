#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct date
{
    int day;
    int month;
    int year;


    //start enter date fn

    void enterDate()
    {
        int dateFlag = 0;
                                                        //string inputDate;cin.clear();cin.ignore(100,'\n');

        while( dateFlag == 0 )
        {
            
        cout<< "\nEnter date of vaccination:-\n ";       //or use getline for string and then parse with .find and .substr and .erase?
        cout<< "Enter day in dd format: ";
        cin>> day;
        cout<< "Enter month in mm format: ";
        cin>> month;
        cout<< "Enter year in yy format: ";
        cin>> year;

        if( day > 31 || day < 18 )
        {
            cout<< "Invalid date!";
        }
        else
        if( month > 12 || month < 8 )
        {
            cout<< "Invalid date!";
        }
        else
        if( year != 2021 )
        {
            cout<< "Invalid date!";
        }
        else
        {
            dateFlag = 1;
            cout<< "Date successfully entered!";
        }
                    
            
        }

    } //end of enter date fn


    int checkIfDatesDifferenceIs60( date date1, date date2) 
    {

        //fn finds difference in days by: finding no of days from year 0000 for each date and subtracting them;

        int daysBeforeDate1=0;
        int daysBeforeDate2=0;

        int leapYearsBeforeDate1;
        int leapYearsBeforeDate2;

        const int monthDays[ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        int index;

    //finding date1 days:-

        //convert years and days and add to daycount
        daysBeforeDate1 += ( date1.year * 365 ) + date1.day;

        //add leap year days to dayscount
        if( date1.month <= 2 )
        {
            leapYearsBeforeDate1 = ( (date1.year - 1) / 4 ) - ( (date1.year - 1) / 100 ) + ( (date1.year - 1) / 400 );
        }
        else
        {
            leapYearsBeforeDate1 = ( date1.year / 4 ) - ( date1.year / 100 ) + ( date1.year / 400 );
        }

        daysBeforeDate1 += leapYearsBeforeDate1;

        //convert and add months to dayscount
        for( index = 0 ; index < ( date1.month - 1 ) ; index++ )
        {
            daysBeforeDate1 += monthDays[index];
        }


    //finding date1 days:-

        //convert years and days and add to daycount
        daysBeforeDate2 += ( date2.year * 365 ) + date2.day;

        //add leap year days to dayscount
        if( date2.month <= 2 )
        {
            leapYearsBeforeDate2 = ( (date2.year - 1) / 4 ) - ( (date2.year - 1) / 100 ) + ( (date2.year - 1) / 400 );
        }
        else
        {
            leapYearsBeforeDate2 = ( date2.year / 4 ) - ( date2.year / 100 ) + ( date2.year / 400 );
        }

        daysBeforeDate2 += leapYearsBeforeDate2;

        //convert and add months to dayscount
        for( index = 0 ; index < ( date2.month - 1 ) ; index++ )
        {
            daysBeforeDate2 += monthDays[index];
        }


        //debug display days
        cout<< "date1 days: "<< daysBeforeDate1;//
        cout<< "date2 days: "<< daysBeforeDate2;//


        //check 60 difference btw days
        if( abs( daysBeforeDate2 - daysBeforeDate1 ) >= 60 )
            return 1;
        else
            return 0;

    }




};


class vaccine
{
public:

int covishieldDosesTotal;
int cowinDosesTotal;
int pincode;

vaccine()
{
	cowinDosesTotal = 0;
	covishieldDosesTotal = 0;
}

void addVaccine()
{


	if( pincode )
	{
		int option;

		cout<< "Choose vaccine type:-\n";
		cout<< "1.Covishield\n";
		cout<< "1.Cowin\n";
		cin>> option;

		switch( option )
		{
			case 1 : 
				break;
        	case 2 : 
				break;
			default : cout<< "Invalid!\n";
		}
		
			
	}
	
}


};



class person
{

long mobileNumber;
string personName;
bool dose1;
bool dose2;
date dateDose1;
date dateDose2;
string vaccineName;



};





//global fn

void searchForAvailablilty()

{

    string pincode;

    int flagFoundPin = 0;



    cout<< "\nEnter pincode: ";

    getline( cin, pincode );



    ifstream in( "students.txt", ios::binary );

    vaccine vfile;



    if( !in ) 

    {

        cout<< "\nFile not found!\n";

    }
    else
    {

        in>>student;//

        while( !in.eof() )

        {

            if( vfile.checkpincodeanddisplay( pincode ) )       //or check student.mPhonemunber==pincode here itself and exit and display according to flag

            {

                flagFoundPin = 1;

                break;

            }



            in>>student;//

        }



        if( !flagFoundPin )

        {

            cout<< "\nNo vaccines available at this Pincode!\n";

        }



    }


    in.close();


}







//global fn
void registerForVaccine()
{



string pincode;

int flagFoundPin = 0;

cout<< "\nEnter pincode of vaccine to update(enter mobile no): ";
getline( cin, pincode );                               //maybe instead of all this make function(pincode)
                                                    //that searches for pincode and returns 1 if found for code reuse in other fns

fstream fchange;

fchange.open( "students.txt", ios::in | ios::binary );

if( !fchange )
{
cout<< "\nError file not found!\n";
}
else
{
        Student student;

        fchange>>student;

        while( !fchange.eof() )
        {
            if( student.mPhoneNumber == pincode )       //or check student.mPhonemunber==pincode here itself and exit and display according to flag
            {                                    
                flagFoundPin = 1;

                if( xtemp == 0 )   //in reg fn check both totals
                {
                    cout<< "\nAll vaccines depleted at this pincode!//mid is 0\n"; 
                }         
                else
                if( xtemp > 0 )
                {
                    int position;

                    cout<< endl<< xtemp<< " Vaccine available and booked!"; // in reg fn display "respective" vaccine is avaialble and set person vaccine name accordingly

                    fchange.close();//

                    fstream fchange;//

                    fchange.open("students.txt",ios::ate|ios::binary);//

                    position = fchange.tellp();

                    fchange.seekp( sizeof(Student), ios::beg );//

                    fchange<<student;//
                    

                    cout<< "\nVaccine count updated to "<< xtemp<< endl;


                }



                break;


            }

            fchange>>student; //load next object
        }

        if( !flagFoundPin )
        {
            cout<< "No Pincode found(pgm meaning) (or No vaccines available at this pincode! for actual project)\n";
        }  



        fchange.close();

}


}












void menu()
{
	int option, flag = 1;

	while( flag == 1 )
	{
		cout<< "\n\nVaccination Portal Menu:-";
		cout<< "\n1.Add Vaccine";
		cout<< "\n2.Register Vaccine";
		cout<< "\n3.View Vaccination Status";
		cout<< "\n4.Search Vaccine availability";
		cout<< "\n5.Exit";
		cout<< "\nEnter options: ";
		cin>> option;

		switch ( option )
		{
		case 1 :
			break;
		case 2 :
			break;
		case 3 :
			break;
		case 4 :
			break;
		case 5 : flag=0;
			break;
	
		default :
			break;
		}


	}

	

}

int main()
{

	menu();

}