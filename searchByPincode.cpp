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

   void showDate()
   {
       cout<<day<<"/"<<month<<"/"<<year;
   }
 
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
 
 
   int getDatesDifference( date date2 )
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
       daysBeforeDate1 += ( year * 365 ) + day;
 
       //add leap year days to dayscount
       if( month <= 2 )
       {
           leapYearsBeforeDate1 = ( (year - 1) / 4 ) - ( (year - 1) / 100 ) + ( (year - 1) / 400 );
       }
       else
       {
           leapYearsBeforeDate1 = ( year / 4 ) - ( year / 100 ) + ( year / 400 );
       }
 
       daysBeforeDate1 += leapYearsBeforeDate1;
 
       //convert and add months to dayscount
       for( index = 0 ; index < ( month - 1 ) ; index++ )
       {
           daysBeforeDate1 += monthDays[index];
       }
 
 
   //finding date2 days:-
 
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
       return abs(daysBeforeDate2 - daysBeforeDate1) ;
 
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

void clearVaccineObject()
{
   cowinDosesTotal = 0;
   covishieldDosesTotal = 0;
}
 
void showVaccineDetails()
{
   cout<< "Doses available at pincode "<< pincode<< ":-\n";
   cout<< "Covishield: "<<covishieldDosesTotal;
   cout<< "\nCowin: "<<cowinDosesTotal;
   cout<<"\n";
}


int checkPincodeExist(int inputPin)//rewrite since pincode search not used in this manner  
{

    int checkFlagFoundPin = 0;

    ifstream checkin;
    checkin.open( "vaccine_detail.txt", ios::in | ios::binary );

    if( !checkin )
   {
 
       cout<< "\nFile not found!\n";
 
   }
   else
   {
 
       checkin.read(( char* )this, sizeof( *this ) );
 
       while( !checkin.eof() )
 
       {
 
           if( pincode == inputPin )       
 
           {
 
               checkFlagFoundPin = 1;
 
               break;
 
           }
 
           checkin.read(( char* )this, sizeof( *this ) );
 
       }
  
 
   }
 
 
   checkin.close();


    if( !checkFlagFoundPin ) 
    {
        return 0;       //not found return 0
    }
    else
    {
        return 1;       //found return 1
    }

} 


void addVaccine()
{
 
   int inputPincode;
 
   int flagFoundPin = 0, vaccineType=0, vaccineNameFlag=0, inputCovishieldDoses=0, inputCowinDoses = 0;
 
   cout<< "\nEnter pincode: ";
   cin>> inputPincode;
 
 
   while( vaccineNameFlag == 0 )
   {
       cout<< "Choose vaccine name:-\n"; //at a time enter only one type?
       cout<< "1.Covishield\n";
       cout<< "2.Cowin\n";
       cout<< "3.Both\n";
       cout<< "Enter option: ";
       cin>> vaccineType;
 
       switch ( vaccineType )
       {
       case 1 :    //maybe use while loop to check for negative input
                   cout<< "Enter covishield doses: ";
                   cin>> inputCovishieldDoses; //inputCowinDoses already inintialised 0
 
                   vaccineNameFlag=1;
           break;
 
       case 2 :    //maybe use while loop to check for negative input
                   cout<< "Enter cowin doses: ";
                   cin>> inputCowinDoses; //inputCovishieldDoses already inintialised 0
 
                   vaccineNameFlag=1;
           break;
 
       case 3 :    //maybe use while loop to check for negative input
                   cout<< "Enter covishield doses: ";
                   cin>> inputCovishieldDoses;
                   cout<< "Enter cowin doses: ";
                   cin>> inputCowinDoses;
 
                   vaccineNameFlag=1;
           break;
 
       default:    cout<< "Invalid vaccine option!\n\n";
           break;
       }
 
      
 
   }
 
 
 
   fstream file;
   file.open( "vaccine_detail.txt", ios::in | ios::out | ios::ate | ios::binary );
  
 
   if( !file )
 
   {
 
       cout<< "\nFile not found!\n";
 
   }
   else
   {
       file.seekg(0);
       file.read(( char* )this, sizeof( *this ) );
 
       while( !file.eof() )
       {
 
           if( pincode == inputPincode )       
 
           {

               cowinDosesTotal += inputCowinDoses;
               covishieldDosesTotal += inputCovishieldDoses;

               file.seekp(file.tellp() - sizeof( *this ));
 
               file.write(( char* )this, sizeof( *this ));
 
               flagFoundPin = 1;
 
               break;
 
           }
 
           file.read(( char* )this, sizeof( *this ) );
 
       }
 
 
 
       if( !flagFoundPin )
       {
           file.close();
 
           pincode = inputPincode;

            cout<<"\nCowindosestotal: "<<cowinDosesTotal; //debug
            cout<<"\ncovishield total: "<<covishieldDosesTotal; //debug
           
           covishieldDosesTotal = inputCovishieldDoses;
           cowinDosesTotal = inputCowinDoses;
 
           file.open("vaccine_detail.txt",ios::out | ios::app | ios::binary);
           file.write(( char* )this, sizeof( *this ));
 
 
 
       }
 
 
 
   }
 
 
   file.close();
 
 
 
  
}
 

 
void searchForAvailablilty()
 
{
 
   int inputPincode;
 
   int flagFoundPin = 0;
 
   cout<< "\nEnter pincode: ";
   cin>> inputPincode;
 
 
   ifstream in;
   in.open( "vaccine_detail.txt", ios::in | ios::binary );
 
 
 
   if( !in )
 
   {
 
       cout<< "\nFile not found!\n";
 
   }
   else
   {
 
       in.read(( char* )this, sizeof( *this ) );
 
       while( !in.eof() )
 
       {
 
           if( pincode == inputPincode )       
 
           {
               showVaccineDetails();
 
               flagFoundPin = 1;
 
               break;
 
           }
 
           in.read(( char* )this, sizeof( *this ) );
 
       }
 
 
 
       if( !flagFoundPin )
 
       {
 
           cout<< "\nNo vaccines available at this Pincode!\n";
 
       }
 
 
 
   }
 
 
   in.close();
 
 
}
 
 
};
 
 
 
class person
{
 
public:

long mobileNumber;
string personName;
bool dose1;
bool dose2;
date dateDose1;
date dateDose2;
string vaccineName;

person()
{
    dose1 = false;
    dose2 = false;
}
 
 void showPersonDetails()//rearrange order of display?
{
   cout << "Name: " << personName << ":-\n";
   cout << "\nMobile: " << mobileNumber;
   cout << "\nVaccine name: " << vaccineName;

   if( dose1 == true && dose2 == false )
   {
        cout << "\nDose 1 date: "; 
        dateDose1.showDate();
        cout << "\n";

   }
   else
   if( dose1 == true && dose2 == true )
   {
        cout << "\nDose 2 date: "; 
        dateDose2.showDate();
        cout << "\n";
   }

}


 void showVaccinationStatus()
 {

    long inputMobileNumber;

    int flagFoundPin = 0;

    cout<< "Enter mobile number: ";
    cin>> inputMobileNumber;

    ifstream in;
    in.open( "patient_detail.txt", ios::in | ios::binary );

    if( !in )
    {
        cout<<"\nFile not found!\n";
    }
    else
    {
        in.read( (char*)this, sizeof(*this) );

        while( !in.eof() )
        {
            if( mobileNumber == inputMobileNumber )
            {
                showPersonDetails();

                flagFoundPin = 1;

                break;
            }

            in.read( (char*)this, sizeof(*this) );

        }

        if( !flagFoundPin )
       {
 
           cout<< "\nNo person registered with this mobile number!\n";
 
       }


    }

    in.close();

 }


 
void registerForVaccine()
{
 

    int inputPincode;
    int inputDoseNumber;
    int inputMobileNumber;
    string inputName;

    vaccine Vtemp;//change name
 
    cout << "\nEnter pincode: ";
    cin >> inputPincode;

    cout << "\nEnter mobile number: "; //check mobile no exist then name same then if dose2 appropriate vaccine dose available (not zero) at same pincode 
    cin >> inputMobileNumber;

    cin.clear();
    cin.ignore( 1000, '\n' );

    cout << "\nEnter Name: ";//should check case insensitive?
    getline( cin, inputName );

    while( inputDoseNumber == 0 )
    {
        cout << "\nEnter dose number ( 1 or 2 ) : ";
        cin >> inputDoseNumber;

        if( inputDoseNumber < 1 || inputDoseNumber > 2 )
        cout<<"Invalid dose number!";
        else
        break;

    }


    if( Vtemp.checkPincodeExist( inputPincode ) ) //will check for pincode again later to update if optimise either store or write expaned code here instead of fn 
    {




    }
    else
    {
        cout<<"No vaccines available at this pincode!";
    }



                                            
 
 
     
 
    
 
 
}
 
 
 
 
 
 
 
};
 
 
 
 
 
 
 
 
 

 
 
 
 
 
void menu()
{

    fstream fout;
    fout.open("vaccine_detail.txt", ios::app | ios::binary );
    fout.close();

   int option, flag = 1;

   vaccine Vinput;

   person Pinput;
 
   while( flag == 1 )
   {
       Vinput.clearVaccineObject();

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
                   Vinput.addVaccine();
                   break;
 
       case 2 :  
                  
                   break;
 
       case 3 :

                   break;
 
       case 4 :
                   Vinput.searchForAvailablilty();
                   break;
 
       case 5 :    flag=0;
                    cout<<"\nThank you for using the vaccination portal!\n\n";
                   break;
  
       default :   cout<<"Invalid option!";
                   break;
 
       }
 
 
   }
 
  
 
}
 
int main()
{
 
   menu();
 
}
 

