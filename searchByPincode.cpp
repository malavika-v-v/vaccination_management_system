#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Vaccine.h"
#include "Person.h"

//included classes .h files
 
using namespace std;
 
struct Date2
{

   int day;
   int month;
   int year;
 
 
   void showDate2()
   {

       cout<<day<<"/"<<month<<"/"<<year;
       
       


   }
 
   void enterDate2()
   {

       int dateFlag = 0;
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
       if( year < 2021 )
       {
           cout<< "Invalid date!";
       }
       else
       {
           dateFlag = 1;
           cout<< "Date successfully entered!";
       }
                  
          
       }
 


   }
 
   int getDatesDifference2( Date2 date2 )
   {


       //fn finds difference in days date2 - date1(aka calling date) by: finding no of days from year 0000 for each date and subtracting them;
 
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
 
       //add leap year days to dayscount.
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
       return (daysBeforeDate2 - daysBeforeDate1) ;
 

   }
 
};




/* class pstore
{

     Vaccine V[10];//use dynamic memory alloc
     //or use list instead of array
     //


}; */

void addVaccine( vector<Vaccine> &vaccinefile )
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

 
       for(int i=0; i<vaccinefile.size(); i++)
       {
           Vaccine vaccineObject;
           vaccineObject = vaccinefile[i];//tested in test.cpp

            
           if( vaccineObject.pincode == inputPincode )       
           {
               vaccineObject.cowinDosesTotal += inputCowinDoses;
               vaccineObject.covishieldDosesTotal += inputCovishieldDoses;

               vaccinefile[i] = vaccineObject;//tested in test.cpp
 
               flagFoundPin = 1;
 
               break;
           }
 
        }
 
 
       if( !flagFoundPin )
       {
           Vaccine vaccineObjectNew;
 
           vaccineObjectNew.pincode = inputPincode;

            //cout<<"\n newobj Cowindosestotal: "<<vaccineObjectNew.cowinDosesTotal; //debug
            //cout<<"\nnewobj covishield total: "<<vaccineObjectNew.covishieldDosesTotal; //debug
           
           vaccineObjectNew.covishieldDosesTotal = inputCovishieldDoses;
           vaccineObjectNew.cowinDosesTotal = inputCowinDoses;

           vaccinefile.push_back(vaccineObjectNew);
 
 
        }
 
    
 
 
  
  
}




void searchForAvailablilty( vector<Vaccine> &vaccinefile )
{ 
   int inputPincode;
 
   int flagFoundPin = 0;
 
   cout<< "\nEnter pincode: ";
   cin>> inputPincode;
 
 


   
  
       
 
       for(int i = 0; i < vaccinefile.size(); i++ )
       {
           Vaccine vaccineObject;
           vaccineObject = vaccinefile[i];

            
           if( vaccineObject.pincode == inputPincode )       
           {
                cout << "\nDoses available at pincode " << inputPincode <<":-\n";
                cout << "\nCovishield: " << vaccineObject.covishieldDosesTotal <<":-\n";
                cout << "\nCowin: " << vaccineObject.cowinDosesTotal <<":-\n";
              
               flagFoundPin = 1;
 
               break;
           }
 
        }
 
       if( !flagFoundPin )
       {
           cout<< "\nNo vaccines available at this Pincode!\n";
       }
 
    
 
  
 
}





void registerForVaccine( vector<Vaccine> &vaccinefile, vector<Person> &personfile)
{
 

    int inputPincode;

    int inputDoseNumber = 0 ;

    long inputMobileNumber;

    string inputName;

    Date2 inputDate;

    //Vaccine Vtemp;//change name

    int flagMobileFound = 0;
    //int flagSameName = 0;

    int datesDifferenceInDays;
 
    cout << "\nEnter pincode: ";
    cin >> inputPincode;

    

    cout << "\nEnter mobile number: "; //check mobile no exist then name same then if dose2 appropriate vaccine dose available (not zero) at same pincode 
    cin >> inputMobileNumber;

    cin.clear();
    cin.ignore( 1000, '\n' );

    cout << "\nEnter Name: ";//should check case insensitive?
    getline( cin, inputName );

    //cout<<"core dump?0";

   

    while( inputDoseNumber == 0 )
    {
        cout << "\nEnter dose number ( 1 or 2 ) : ";
        cin >> inputDoseNumber;

        /* cin.clear();
        cin.ignore(1000,'\n'); *///debug remove core dump?

        //cout<<"core dump?0.5";

        if( inputDoseNumber < 1 || inputDoseNumber > 2 )
        cout << "Invalid dose number!";
        else
        {
            break;
        }
        

    }


        for(int i = 0; i < personfile.size(); i++ )
       {
           Person personObject;
           personObject = personfile[i];

            
           if( personObject.mobileNumber == inputMobileNumber )       
           {
               if(personObject.personName==inputName)
               {
                   switch (inputDoseNumber)
                   {
                        case 1 : cout << "\nAlready registered for Dose 1 " <<personObject.vaccineName << " !\n";
                            break;

                        case 2 : if( personObject.dose2 == "true" )//not checking other since dose1 must be true
                                {
                                    cout << "\nAlready registered for Dose 2 " << personObject.vaccineName << " !\n";
                                }
                                else
                                {
                                    struct Date2 inputDate;
                                    struct Date2 fileDate;

                                    cout << "Enter date for dose 2 vaccination:-\n";
                                    inputDate.enterDate2();

                                    fileDate.day = personObject.dateDose1.day;
                                    fileDate.month = personObject.dateDose1.month;
                                    fileDate.year = personObject.dateDose1.year;

                                    

                                    datesDifferenceInDays = fileDate.getDatesDifference2( inputDate );


                                    if( ( datesDifferenceInDays < 60 ) && ( datesDifferenceInDays >= 0 ) )
                                    {
                                        cout << "\nWait for " << 60 - datesDifferenceInDays << " more days before registering!\n";
                                    }
                                    else
                                    if( datesDifferenceInDays < 0 )
                                    {
                                        cout << "\nInvalid date!\n";//put in loop till dates diff positive? but 60 days check tells to 'wait'
                                    }
                                    else
                                    {
                                        int pinflag=0;



                                            for(int j = 0; i < vaccinefile.size(); i++ )
                                            {
                                                Vaccine vaccineObject;
                                                vaccineObject = vaccinefile[j];

            
                                                if( vaccineObject.pincode == inputPincode )       
                                                {
                                                    if( vaccineObject.covishieldDosesTotal > 0 )
                                                    {
                                                        vaccineObject.covishieldDosesTotal -= 1;
                                                        cout << "\nVaccine dose decremented!\n";//debug
                                                        personObject.dose2 = "true";
                                                        personObject.dateDose2.day = inputDate.day;
                                                        personObject.dateDose2.month = inputDate.month;
                                                        personObject.dateDose2.year = inputDate.year;

                                                        vaccinefile[j] = vaccineObject;
                                                        personfile [i] = personObject;

                                
                                                    }
                                                    else
                                                    if( vaccineObject.cowinDosesTotal >0)
                                                    {
                                                            vaccineObject.cowinDosesTotal -=1;
                                                            cout << "\nVaccine dose decremented!\n";//debug
                                                            personObject.dose2 = "true";
                                                            personObject.dateDose2.day = inputDate.day;
                                                            personObject.dateDose2.month = inputDate.month;
                                                            personObject.dateDose2.year = inputDate.year;

                                                            vaccinefile[j] = vaccineObject;
                                                            personfile [i] = personObject;
                                                    }
                                                    else
                                                    {
                                                        cout << "\nNo vaccines available at this pincode!(depleted)\n";
                                                    }  



              
                                                    pinflag = 1;
 
                                                    break;
                                                }
 
                                            }

                                        if(!pinflag)
                                        {
                                            cout << "\nNo vaccines available at this pincode!\n";//could be none added or all depleted
                                        }


                                        /* if( Vtemp.checkPincodeExistAndDecreaseAppropriateDose( inputPincode, vaccineName ) )
                                        {
                                            cout << "\nVaccine dose decremented!\n";//debug

                                            dose2 = "true";

                                            dateDose2 = inputDate;

                                            personFile.seekp( personFile.tellp() - sizeof(*this) );
                                            personFile.write( (char*)this, sizeof(*this) );
                                            

                                        } */


                                        



                                    }



                                }
                            break;
                   
                        default:cout << "\nCode shouldn't reach here!\n";
                            break;
                    }//switch end



                }
                else //not same name
               {

                   cout << "\nThis mobile number is already registered to another user!";
                    //flagSameName = 0;

               }

                flagMobileFound = 1;
 
               break;
            }
    
 
        }

        if( !flagMobileFound ) //possibly change to more refined form with functions
       {
           Person personObject;
 
           cout<< "\nNew mobile number!\n";//debug

            switch ( inputDoseNumber )
                    {
                        case 2 : cout << "\nMust register for dose 1 first!\n";
                            break;

                        case 1 :
                                {
                                    cout << "Enter date for dose 1 vaccination:-\n";
                                inputDate.enterDate2();                    

                                int pinflag1=0;



                                for(int j = 0; j < vaccinefile.size(); j++ )
                                    {
                                        Vaccine vaccineObject;
                                        vaccineObject = vaccinefile[j];

            
                                        if( vaccineObject.pincode == inputPincode )       
                                        {
                                                if( vaccineObject.covishieldDosesTotal > 0 )
                                                    {
                                                        vaccineObject.covishieldDosesTotal -= 1;
                                                        cout << "\nVaccine dose decremented!\n";//debug
                                                        personObject.dose1 = "true";
                                                        personObject.dose2 = "false";

                                                        personObject.dateDose1.day = inputDate.day;
                                                        personObject.dateDose1.month = inputDate.month;
                                                        personObject.dateDose1.year = inputDate.year;

                                                        personObject.vaccineName = "Covishield";

                                                        personObject.mobileNumber = inputMobileNumber;

                                                        personObject.personName = inputName;

                                                        vaccinefile[j] = vaccineObject;
                                                        personfile.push_back(personObject);

                                
                                                    }
                                                else
                                                if( vaccineObject.cowinDosesTotal >0)
                                                    {
                                                        vaccineObject.cowinDosesTotal -= 1;
                                                        cout << "\nVaccine dose decremented!\n";//debug
                                                        personObject.dose1 = "true";
                                                        personObject.dose2 = "false";

                                                        personObject.dateDose1.day = inputDate.day;
                                                        personObject.dateDose1.month = inputDate.month;
                                                        personObject.dateDose1.year = inputDate.year;

                                                        personObject.vaccineName = "Cowin";

                                                        personObject.mobileNumber = inputMobileNumber;

                                                        personObject.personName = inputName;

                                                        vaccinefile[j] = vaccineObject;
                                                        personfile.push_back(personObject);
                                                    }
                                                else
                                                    {
                                                        cout << "\nNo vaccines available at this pincode!(depleted)\n";
                                                    }  



              
                                                    pinflag1 = 1;
 
                                                    break;
                                        }
 
                                    }

                                    if(!pinflag1)
                                    {
                                            cout << "\nNo vaccines available at this pincode!\n";//could be none added or all depleted
                                    }

                                    break;
                                }    
                            
                    
                        default : cout << "\nCode shouldn't reach here!\n";
                            break;
                    }
 
        }
 

   
 
}






void showVaccinationStatus( vector<Person> &personfile )
{


    long inputMobileNumber;
    int flagFoundPin = 0;

    cout << "\nEnter mobile number: ";
    cin >> inputMobileNumber;  

    for(int i = 0; i < personfile.size(); i++ )
    {
        Person personObject;
        personObject = personfile[i];


        if( personObject.mobileNumber == inputMobileNumber )      
        {
            

            cout << "\nName : " << personObject.personName;
            cout << "\nMobile number : " << personObject.mobileNumber;
            if(personObject.dose1 == "true" && personObject.dose2 == "false" )
            {
               cout << "\nDose 1 date: "; 

               Date2 tempd;
               tempd.day = personObject.dateDose1.day;
               tempd.month = personObject.dateDose1.month;
               tempd.year = personObject.dateDose1.year;

        	    tempd.showDate2();

        	cout << "\n";
            }
            else if (personObject.dose1 == "true" && personObject.dose2 == "true")
            {
                cout << "\nDose 2 date: "; 

        	    cout<<personObject.dateDose2.day;
               cout<<"/"<<personObject.dateDose2.month;
               cout<<"/"<<personObject.dateDose2.year;

        	cout << "\n";
            }
            else // not needed?
            {
                cout << "Dose one not taken." << endl;
            }
            
            flagFoundPin = 1;
            break;
        }
    }
    if( !flagFoundPin )
    {
    cout<< "\nNo person registered with this mobile number!\n";
    }

}
 
 
 


void exit( vector<Vaccine> &vaccinefile, vector<Person> &personfile )//add person later
{

    ofstream fout2;//incase file didnt exist aka first time running pgm
    fout2.open("vaccine_detail.txt", ios::out | ios::binary );

///
    if( !fout2 )
    {
        cout << "No Vaccine file!";
    }
    else
    {

        for(int i = 0; i < vaccinefile.size(); i++ )
        {
           Vaccine vaccineObject;
           vaccineObject = vaccinefile[i];

            fout2<<to_string(vaccineObject.pincode)<<"\n";
            fout2<<to_string(vaccineObject.covishieldDosesTotal)<<"\n";
            fout2<<to_string(vaccineObject.cowinDosesTotal)<<"\n";
            fout2<<"."<<"\n";
        }


       
    }

///


    fout2.close();


    ofstream fout3;//incase file didnt exist aka first time running pgm
    fout3.open("person_detail.txt", ios::out | ios::binary );

///
    if( !fout3 )
    {
        cout << "No Person file!";
    }
    else
    {

        for(int i = 0; i < personfile.size(); i++ )//
        {
           Person personObject;
           personObject = personfile[i];

            fout3<<to_string(personObject.mobileNumber)<<"\n";
            fout3<<personObject.personName<<"\n";
            fout3<<personObject.dose1<<"\n";
            fout3<<personObject.dose2<<"\n";
            fout3<<to_string(personObject.dateDose1.day)<<"\n";
            fout3<<to_string(personObject.dateDose1.month)<<"\n";
            fout3<<to_string(personObject.dateDose1.year)<<"\n";
            fout3<<to_string(personObject.dateDose2.day)<<"\n";
            fout3<<to_string(personObject.dateDose2.month)<<"\n";
            fout3<<to_string(personObject.dateDose2.year)<<"\n";
            fout3<<personObject.vaccineName<<"\n";
            fout3<<"."<<"\n";
        }


       
    }

///


    fout3.close();




    cout<<"\nThank you for using the vaccination portal!\n\n";
    
}









void showVaccinePortalMenu()
{

    fstream fout1;//incase file didnt exist aka first time running pgm
    fout1.open("vaccine_detail.txt", ios::app | ios::binary );
    fout1.close();

    fstream fout2;
    fout2.open("person_detail.txt", ios::app | ios::binary );
    fout2.close();


    //reading vaccine objects from file into vector

    vector <Vaccine> vaccinefile;//holds vaccine objects from file
    

    string vaccineFileInputLine;
    vector <string> vaccineObject;//used to temporarily store current object members

    ifstream vfin;
    vfin.open( "vaccine_detail.txt", ios::in | ios::binary );//remove binary? since storing as strings?

    if( !vfin )
    {
        cout << "No Vaccine file!";
    }
    else
    {

        while( getline( vfin, vaccineFileInputLine ) )
        {
            if( vfin.eof() )
            {
                break;
            }
            else
            {
                if( vaccineFileInputLine != "." )
                {
                    vaccineObject.push_back( vaccineFileInputLine );
                }
                else
                { //store in order since we know order of storing(fixed) -> pincode, then covishieldtotal, then cowin

                    Vaccine Vinput; //used to store current object from file(values read and assigned line by line)

                    Vinput.pincode = stoi( vaccineObject[0] );
                    Vinput.covishieldDosesTotal = stoi( vaccineObject[1] );
                    Vinput.cowinDosesTotal = stoi( vaccineObject[2] );

                    vaccinefile.push_back(Vinput);

                    vaccineObject.clear();
                }



            }

        }

    }

    vfin.close();



    //reading person objects from file into vector 

    vector <Person> personfile;//holds person objects from file
    

    string personFileInputLine;
    vector <string> personObject;//used to temporarily store current object members

    ifstream pfin;
    pfin.open( "person_detail.txt", ios::in | ios::binary );//remove binary? since storing as strings?

    if( !pfin )
    {
        cout << "No Person file!";
    }
    else
    {

        while( getline( pfin, personFileInputLine ) )
        {
            if( pfin.eof() )
            {
                break;
            }
            else
            {
                if( personFileInputLine != "." )
                {
                    personObject.push_back( personFileInputLine );
                }
                else
                { //store in order since we know order of storing(fixed) -> pincode, then covishieldtotal, then cowin

                    Person Pinput; //used to store current object from file(values read and assigned line by line)

                    Pinput.mobileNumber = stol( personObject[0] );
                    Pinput.personName = personObject[1];
                    Pinput.dose1 = personObject[2]; //IMPORTANT : if bool not work might have to use string instead(changed)
                    Pinput.dose2 = personObject[3];
                    Pinput.dateDose1.day = stoi( personObject[4]);//maybe just change date to string and do parsing and handling locally(18/8/2021)
                    Pinput.dateDose1.month = stoi( personObject[5]);
                    Pinput.dateDose1.year = stoi( personObject[6]);
                    Pinput.dateDose2.day = stoi( personObject[7]);
                    Pinput.dateDose2.month = stoi( personObject[8]);
                    Pinput.dateDose2.year = stoi( personObject[9]);
                    Pinput.vaccineName = personObject[10];

                    personfile.push_back(Pinput);

                    personObject.clear();
                }



            }

        }

    }

    pfin.close();






    


    

   int option, flag = 1;

   //make array?

   Person Pinput;
 
   while( flag == 1 )
   {
       //Vinput.clearVaccineObject(); //needed?

       cout<< "\n\nVaccination Portal Menu:-";
       cout<< "\n1.Add Vaccine";
       cout<< "\n2.Register Vaccine";
       cout<< "\n3.View Vaccination Status";
       cout<< "\n4.Search Vaccine availability";
       cout<< "\n5.Exit";
       cout<< "\n6.all person";
       cout<< "\n7.all vaccine";
       cout<< "\nEnter options: ";
       cin>> option;
 
       switch ( option )
       {
       case 1 :   
                   addVaccine( vaccinefile) ;
                   break;
 
       case 2 :    
                   registerForVaccine( vaccinefile, personfile );  
                   break;
 
       case 3 :
                    showVaccinationStatus( personfile );
                   break;
 
       case 4 :
                   searchForAvailablilty( vaccinefile );
                   break;
 
       case 5 :    flag=0;
                    exit( vaccinefile , personfile);//add person later
                   break;

        case 6 :    
                    //showallp( personfile );//debug
                   break;

        case 7 :    
                    //showallv( vaccinefile );//debug
                   break;
  
       default :   cout<<"Invalid option!";
                   break;
 
       }
 
   }
 
}
 
int main()
{
    cout<<"vector!";
    showVaccinePortalMenu();
}
 
