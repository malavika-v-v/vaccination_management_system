#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Vaccine.h"
#include "Person.h"

//included classes .h files
 
using namespace std;



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

    //Date2 inputDate;

    //Vaccine Vtemp;//change name

    int flagMobileFound = 0;
    //int flagSameName = 0;

    int datesDifferenceInDays;
 
    cout << "\nEnter pincode: ";
    cin >> inputPincode;

    //cout<<"\npin:"<<inputPincode<<"\n";

    

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
                                    //struct Date2 inputDate;
                                    //struct Date2 fileDate;

                                    cout << "Enter date for dose 2 vaccination:-\n";
                                    personObject.enterDate2();


                                    

                                    datesDifferenceInDays = personObject.getDatesDifference( personObject.dateDose1, personObject.dateDose2 );


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



                                            for(int j = 0; j < vaccinefile.size(); j++ )
                                            {
                                                Vaccine vaccineObject;
                                                vaccineObject = vaccinefile[j];

                                                //cout<<"\nPin: "<<vaccineObject.pincode<<"\n";
            
                                                if( vaccineObject.pincode == inputPincode )       
                                                {
                                                    if( personObject.vaccineName == "Covishield" && vaccineObject.covishieldDosesTotal > 0 )
                                                    {
                                                        vaccineObject.covishieldDosesTotal -= 1;
                                                        cout << "\nVaccine dose decremented!\n";//debug
                                                        personObject.dose2 = "true";

                                                        vaccinefile[j] = vaccineObject;
                                                        personfile [i] = personObject;

                                
                                                    }
                                                    else
                                                    if( personObject.vaccineName == "Cowin" && vaccineObject.cowinDosesTotal >0)
                                                    {
                                                            vaccineObject.cowinDosesTotal -=1;
                                                            cout << "\nVaccine dose decremented!\n";//debug
                                                            personObject.dose2 = "true";

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
                                            cout << "\nNo vaccines available at this pincode!(abc)\n";//could be none added or all depleted
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
                                personObject.enterDate1();                    

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
            cout << "\nVaccine : " <<personObject.vaccineName;
            if(personObject.dose1 == "true" && personObject.dose2 == "false" )
            {
               cout << "\nDose 1 date: "; 
                cout<<personObject.dateDose1;

        	cout << "\n";
            }
            else if (personObject.dose1 == "true" && personObject.dose2 == "true")
            {
                cout << "\nDose 2 date: "; 
                cout<<personObject.dateDose2;

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
            fout3<<personObject.dateDose1<<"\n";
            fout3<<personObject.dateDose2<<"\n";
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
                    Pinput.dateDose1=personObject[4];
                    Pinput.dateDose2=personObject[5];
                    Pinput.vaccineName = personObject[6];

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

       cout<< "\n\nVaccination 32 Portal Menu:-";
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
  
       default :   cout<<"Invalid option!";
                   break;
 
       }
 
   }
 
}
 
int main()
{
    showVaccinePortalMenu();
}
 