#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <termios.h>
#include "Person.h"
#include "Date.h"

void Person::showVaccinationStatus( vector<Person> &personfile )
{
    long inputMobileNumber;
    int flagFoundNumber = 0;

    cout << "VACCINATION STATUS:-\n";
    cout << "\nEnter mobile number: ";
    cin >> inputMobileNumber;  

    for( int index = 0; index < personfile.size(); index++ )
    {
        Person personObject;
        personObject = personfile[index];

        if( personObject.mobileNumber == inputMobileNumber )      
        {
            cout << "\nName : " << personObject.personName;
            cout << "\nMobile number : " << personObject.mobileNumber;
            cout << "\nVaccine : " << personObject.vaccineName;
            if( personObject.dose1 == "true" && personObject.dose2 == "false" )
            {
                cout << "\nDose 1 date: "; 
                cout << personObject.dateDose1;
        	    cout << "\n";
            }
            else if ( personObject.dose1 == "true" && personObject.dose2 == "true")
            {
                cout << "\nDose 2 date: "; 
                cout << personObject.dateDose2;
        	    cout << "\n";
            }
            else
            {
                cout << "Dose one not taken." << endl;
            }
            flagFoundNumber = 1;
            break;
        }
    }
    if( !flagFoundNumber )
    {
    cout<< "\nNo person registered with this mobile number!\n";
    }
}

void Person::registerForVaccine( vector<Vaccine> &vaccinefile, vector<Person> &personfile)
{
    int inputPincode;
    int inputDoseNumber = 0 ;
    int inputVaccine = 0;
    long inputMobileNumber;
    char dose2Choice;
    string inputName;
    int datesDifferenceInDays;
    int flagPinFound=0, flagMobileFound = 0, flagpinfoundbutdepleted = 0, flagSameName = 0, flagmobilefounddose2done = 0, flagcontinuedose1 = 0;
    int vaccineavailableandtype = 0;
    int vindex = 0, pindex = 0;
    
    cout << "VACCINE REGISTRATION:-\n";
    cout << "\nEnter pincode: ";
    cin >> inputPincode;

    for( vindex = 0; vindex < vaccinefile.size(); vindex++ )
    {
        Vaccine vobject;//can we declare at start of fn?
        vobject = vaccinefile[vindex];

        if( vobject.pincode == inputPincode )
        {
            flagPinFound = 1;
            if( vobject.covishieldDosesTotal < 1 && vobject.cowinDosesTotal < 1 )
            {
                flagpinfoundbutdepleted = 1;
                flagPinFound = 0;
            }
            break;//vindex current vaccinefile vector postion
            //also breaking since pincode is unique
        }
    }
    if( !flagPinFound )
    {
        if( flagpinfoundbutdepleted )
        cout << "\nNo vaccines available at this pincode!(depleted)\n";
        else
        cout << "\nNo vaccines available at this pincode!(never added)\n";
    }
    else
    {
        cout << "\nEnter mobile number: ";
        cin >> inputMobileNumber;

        cin.clear();
        cin.ignore( 1000, '\n' );

        cout << "\nEnter Name: ";//Case sensitive
        getline( cin, inputName );
        for( pindex = 0; pindex < personfile.size(); pindex++ )
        {
            Person pobject;//can we declare at start of fn?
            pobject = personfile[pindex];
            if( pobject.mobileNumber == inputMobileNumber )
            {
                if( pobject.personName == inputName )
                {
                    flagSameName = 1;
                }
                if( pobject.dose2 == "true")
                {
                    flagmobilefounddose2done = 1;
                }
                flagMobileFound = 1;
                break;//pindex current personfile vector postion
                //also breaking since mobile number is unique
            }
        }
        if( !flagMobileFound )
        {
            Person pobject2;
            Vaccine vobject2;
            Date dobject2;
            vobject2 = vaccinefile[vindex];

            while( inputVaccine != 4 )
            {
                cout << "\nNew User!\n";//new mobile number
                cout << "Dose 1 Vaccine selection:-\n";
                cout << "1.Covishield\n";
                cout << "2.Cowin\n";
                cout << "3.Quit registration\n";
                cout << "Enter option: \n";
                cin >> inputVaccine;

                if( inputVaccine == 1 )
                {
                    if(vobject2.covishieldDosesTotal > 0)
                    {
                        vobject2.covishieldDosesTotal -= 1;
                        pobject2.vaccineName = "Covishield";
                        flagcontinuedose1 = 1;
                        break;
                    }
                    else
                    {
                        cout << "\nNo Covishield vaccines available at this pincode!(depleted)\n";
                    }
                }
                else
                if( inputVaccine == 2 )
                {
                    if(vobject2.cowinDosesTotal > 0)
                    {
                        vobject2.cowinDosesTotal -= 1;
                        pobject2.vaccineName = "Cowin";
                        flagcontinuedose1 = 1;
                        break;
                    }
                    else
                    {
                        cout << "\nNo Cowin vaccines available at this pincode!(depleted)\n";
                    }
                }
                else
                if( inputVaccine == 3 )
                {
                    flagcontinuedose1 = 0;
                    cout << "\nExiting registration!\n";
                    break;
                }
                else
                {
                    cout << "Invalid option!\n";
                }
            }
            if(flagcontinuedose1)
            {
                cout << "\nEnter date for dose 1 vaccination:-\n";
                pobject2.dateDose1 = dobject2.enterDate();
                pobject2.dose1 = "true";
                pobject2.dose2 = "false";
                pobject2.mobileNumber = inputMobileNumber;
                pobject2.personName = inputName;
                vaccinefile[vindex] = vobject2;
                personfile.push_back(pobject2);
                cout << "\nVaccine Dose1 registration complete!\n";
            }
        }
        else
        {
            if( !flagSameName )
            {
                cout << "\nThis mobile number is already registered to another user!\n";
            }
            else//mobile found
            {
                cout<<"\nPreviously registered User!\n";
                if( flagmobilefounddose2done )
                {
                    cout << "\nAlready fully vaccinated!\n";
                }
                else
                {
                    Person pobject1;
                    pobject1 = personfile[pindex];
                    Vaccine vobject1;
                    vobject1 = vaccinefile[vindex];
                    Date dobject;

                    if( pobject1.vaccineName == "Covishield" && vobject1.covishieldDosesTotal > 0 )
                    {
                        vaccineavailableandtype = 1;   
                    }
                    else
                    if( pobject1.vaccineName == "Cowin" && vobject1.cowinDosesTotal > 0 )
                    {
                        vaccineavailableandtype = 2;
                    }
                    else
                    {
                        vaccineavailableandtype = 0;
                    }
                    if( vaccineavailableandtype == 0 )
                    {
                        cout << "\nSame vaccine as Dose 1 not available at this pincode!\n";
                    }
                    else
                    {
                        cout << "Dose 2 available!\n";
                        cout << "Continue registration? (Yes = 'y' / No = Any other key)\n";
                        cout << "Enter choice: ";
                        cin >> dose2Choice;

                        if(dose2Choice == 'y')
                        {
                            cout << "\nEnter date for dose 2 vaccination:-\n";
                            pobject1.dateDose2 = dobject.enterDate();
                            datesDifferenceInDays = dobject.getDatesDifference( pobject1.dateDose1, pobject1.dateDose2 );

                            if( ( datesDifferenceInDays < 60 ) && ( datesDifferenceInDays >= 0 ) )
                            {
                                cout << "\nWait for " << 60 - datesDifferenceInDays << " more days before registering!\n";
                            }
                            else
                            if( datesDifferenceInDays < 0 )
                            {
                                cout << "\nInvalid date!\n";
                            }
                            else
                            {
                                if( vaccineavailableandtype == 1 )
                                vobject1.covishieldDosesTotal -= 1;
                                else
                                if( vaccineavailableandtype == 2 )
                                vobject1.cowinDosesTotal -= 1;

                                cout << "\nVaccine Dose2 registration complete!\n";
                                pobject1.dose2 = "true";
                                vaccinefile[vindex] = vobject1;
                                personfile[pindex] = pobject1;
                            }
                        }
                        else
                        {
                            cout << "\nExiting registration!\n";
                        }
                    }
                }
            }
        }
    } 
}

