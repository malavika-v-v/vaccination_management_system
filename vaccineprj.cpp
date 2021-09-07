#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <termios.h>
#include "Person.h"
#include "Date.h"

using namespace std;

//getch fn from net
char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    //printf("%c\n", buf);  //include for display input immediately
    return buf;
}

void printloadanim()//prints stars as a quick animation
{
    for( int column=2; column<100; column++ )//length
    {
        for( int row=2; row<14; row++)//height
        {    
            cout << "\033["<<row<<";"<<column<<"f";
            cout << "*";     
        }
        usleep( 1000 );
    }
    cout << "\x1B[2J\x1B[H";//clrscr
}

void exit( vector<Vaccine> &vaccinefile, vector<Person> &personfile )
{
    ofstream fout2;//truncating file for writing contents of vector
    fout2.open( "vaccine_detail.txt", ios::out | ios::binary );

    if( !fout2 )
    {
        cout << "No Vaccine file!";
    }
    else
    {
        for( int vindex = 0; vindex < vaccinefile.size(); vindex++ )
        {
           Vaccine vaccineObject;
           vaccineObject = vaccinefile[vindex];

            fout2 << to_string(vaccineObject.pincode) << "\n";
            fout2 << to_string(vaccineObject.covishieldDosesTotal) << "\n";
            fout2 << to_string(vaccineObject.cowinDosesTotal) << "\n";
            fout2 << "." << "\n";
        }
    }
    fout2.close();

    ofstream fout3;//truncating file for writing contents of vector
    fout3.open( "person_detail.txt", ios::out | ios::binary );

    if( !fout3 )
    {
        cout << "No Person file!";
    }
    else
    {
        for( int pindex = 0; pindex < personfile.size(); pindex++ )//
        {
            Person personObject;
            personObject = personfile[pindex];

            fout3 << to_string(personObject.mobileNumber) << "\n";
            fout3 << personObject.personName << "\n";
            fout3 << personObject.dose1 << "\n";
            fout3 << personObject.dose2 << "\n";
            fout3 << personObject.dateDose1 << "\n";
            fout3 << personObject.dateDose2 << "\n";
            fout3 << personObject.vaccineName << "\n";
            fout3 << "." << "\n";
        }
    }
    fout3.close();

    cout << "\x1B[2J\x1B[H";//clrscr
    cout << "_____________________________________________________________________________________________" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                        \033[32mThank you for using the vaccination portal!\033[0m                         |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|____________________________________________________________________________________________|" << endl<<endl;  
}

void showVaccinePortalMenu()
{
    fstream fout1;//incase files didnt exist aka first time running pgm
    fout1.open( "vaccine_detail.txt", ios::app | ios::binary );
    fout1.close();

    fstream fout2;
    fout2.open( "person_detail.txt", ios::app | ios::binary );
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


   int option, flagExit = 1;
    Vaccine vaccineCallObject;
    Person personCallObject;
   while( flagExit == 1 )
   {
    cout << "\x1B[2J\x1B[H";//clrscr
    cout << "_____________________________________________________________________________________________" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                  \033[1m\033[34mVACCINATION PORTAL\033[0m                                        |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                  \033[36m1. Add Vaccine\033[0m                                            |" << endl; 
    cout << "|                                  \033[36m2. Register Vaccine\033[0m                                       |" << endl;
    cout << "|                                  \033[36m3. View Vaccination Status\033[0m                                |" << endl;
    cout << "|                                  \033[36m4. Search Vaccine Availability\033[0m                            |" << endl;
    cout << "|                                  \033[36m5. Exit\033[0m                                                   |" << endl;
    cout << "|                                                                                            |" << endl;
    cout << "|                                  \033[35mEnter option:\033[0m \033[s                                            |" << endl;
    cout << "|____________________________________________________________________________________________|" << endl;
    cout<<"\033[u";
       cin>> option;

        printloadanim();

       switch ( option )
       {
       case 1 : vaccineCallObject.addVaccine( vaccinefile) ;
                cout << "\nPress any key to continue : ";
                getch();
                break;
       case 2 : personCallObject.registerForVaccine( vaccinefile, personfile );
                cout << "\nPress any key to continue : ";
                getch();  
                break;
       case 3 : personCallObject.showVaccinationStatus( personfile );
                cout << "\nPress any key to continue : ";
                getch();
                break;
       case 4 : vaccineCallObject.searchForAvailablilty( vaccinefile );
                cout << "\nPress any key to continue : ";
                getch();
                break;
       case 5 : flagExit = 0;
                exit( vaccinefile , personfile);
                break;
       default : cout<<"Invalid option!";
                 break;
       }
    }
}
 
int main()
{
    showVaccinePortalMenu();
}
 