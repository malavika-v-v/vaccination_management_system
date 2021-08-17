#include <iostream>
using namespace std;

class vaccine
{
public:

int covishieldDosesTotal;
int cowinDosesTotal;
int pincode;

vaccine()
{

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

		switch(option)
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



};


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
		cout<< "\nEnter option: ";
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