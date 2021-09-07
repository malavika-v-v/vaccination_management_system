#include <iostream>
#include <fstream>
#include <vector>
#include "Vaccine.h"

void Vaccine::addVaccine( vector<Vaccine> &vaccinefile )
{
   int inputPincode;
   int flagFoundPin = 0, vaccineType=0, vaccineNameFlag=0, inputCovishieldDoses=0, inputCowinDoses = 0;
 
    cout << "ADDING VACCINE:-\n";
    cout << "Enter pincode: ";
    cin>> inputPincode;

   while( vaccineNameFlag == 0 )
   {
       cout << "Choose vaccine name:-\n";
       cout << "1.Covishield\n";
       cout << "2.Cowin\n";
       cout << "3.Both\n";
       cout << "Enter option: ";
        cin>> vaccineType;
 
       switch ( vaccineType )
       {
       case 1 :    
                   cout<< "Enter covishield doses: ";
                   cin>> inputCovishieldDoses;//not negative
 
                   vaccineNameFlag=1;
           break;
 
       case 2 :    
                   cout<< "Enter cowin doses: ";
                   cin>> inputCowinDoses; 
 
                   vaccineNameFlag=1;
           break;
 
       case 3 :    
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
           vaccineObject = vaccinefile[i];

           if( vaccineObject.pincode == inputPincode )       
           {
               vaccineObject.cowinDosesTotal += inputCowinDoses;
               vaccineObject.covishieldDosesTotal += inputCovishieldDoses;

               vaccinefile[i] = vaccineObject;
 
               flagFoundPin = 1;
 
               break;
           }
        }
       if( !flagFoundPin )
       {
           Vaccine vaccineObjectNew;
           vaccineObjectNew.pincode = inputPincode;
           vaccineObjectNew.covishieldDosesTotal = inputCovishieldDoses;
           vaccineObjectNew.cowinDosesTotal = inputCowinDoses;
           vaccinefile.push_back(vaccineObjectNew);
        }
}

void Vaccine::searchForAvailablilty( vector<Vaccine> &vaccinefile )
{ 
   int inputPincode;
   int flagFoundPin = 0;
    
    cout << "VACCINE AVAILABILITY:-\n";
    cout<< "\nEnter pincode: ";
    cin>> inputPincode;
 
       for(int i = 0; i < vaccinefile.size(); i++ )
       {
           Vaccine vaccineObject;
           vaccineObject = vaccinefile[i];

           if( vaccineObject.pincode == inputPincode )       
           {
                cout << "\nDoses available at pincode " << inputPincode <<":-\n";
                cout << "\nCovishield: " << vaccineObject.covishieldDosesTotal <<"\n";
                cout << "\nCowin: " << vaccineObject.cowinDosesTotal <<"\n";   
               flagFoundPin = 1;
               break;
           }
        }
       if( !flagFoundPin )
       {
           cout<< "\nNo vaccines available at this Pincode!\n";
       }
}