 #include<iostream>
 #include<fstream>
 #include<string.h>

 using namespace std;

 class Add_Vaccine
 {
    public:
        int pincode;
        int cowinDosesTotal, covishieldDosesTotal, total_vaccine_number;

    public:
        Add_Vaccine()
        {
            pincode = 0;
            cowinDosesTotal = 0;
            covishieldDosesTotal = 0;
            total_vaccine_number = 0;
        }

        void get_Vaccine_Data()
        {
            cout << "Enter pincode : ";
            cin >> pincode;
            cout << "Number of new Cowin vaccine : ";
            cin >> cowinDosesTotal;
            cout << "Number of new Covishield vaccine : ";
            cin >> covishieldDosesTotal;
            total_vaccine_number = cowinDosesTotal + covishieldDosesTotal;
        }

        void show_Vaccine_Data()
        {
            cout << "\n" << pincode << " " << cowinDosesTotal << " " << covishieldDosesTotal << " " << total_vaccine_number << endl;
        }

        int store_Vaccine_Data()
        {
            if(pincode == 0)
            {
                cout << "invalid detail." << endl;
                return(0);
            }
            else
            {
                ofstream vaccine_file;
                vaccine_file.open("vaccine_data.txt", ios::app|ios::binary);
                vaccine_file.write((char*)this, sizeof(*this));
                vaccine_file.close();
                return(1);
            }
        }

        void view_All_Vaccine_Data()
        {
            ifstream vaccine_file;
            vaccine_file.open("vaccine_data.txt", ios::in|ios::binary);
            if(!vaccine_file)
            {
                cout << "File not found." << endl;
            }
            else
            {
                vaccine_file.read((char*)this, sizeof(*this));
                while (!vaccine_file.eof())
                {
                    show_Vaccine_Data();
                    vaccine_file.read((char*)this, sizeof(*this));
                }
            }
            vaccine_file.close();
        }

        void search_Vaccine_Data(char *pincode)
        {

        }

 };

 int main()
 {
     Add_Vaccine v1, v2;
     //v1.view_All_Vaccine_Data();
     v1.get_Vaccine_Data();
     v1.show_Vaccine_Data();
     v1.store_Vaccine_Data();
     v2.show_Vaccine_Data();
     v2.store_Vaccine_Data();
 }