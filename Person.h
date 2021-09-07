using namespace std;
#include <string>
#include <vector>
#include "Vaccine.h"

class Person{
public:

long mobileNumber;
string personName;
string dose1;
string dose2;
string dateDose1;
string dateDose2;
std::string vaccineName;

Person()
{
    dose1 = "false";
    dose2 = "false";
}

void showVaccinationStatus( vector<Person> &personfile );

void registerForVaccine( vector<Vaccine> &vaccinefile, vector<Person> &personfile); 
};
 