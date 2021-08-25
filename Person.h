
using namespace std;
#include <string>

class Person
{
//change to private later and add fns for retrieving and changing private data?
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

void enterDate1();

void enterDate2();

int getDatesDifference(string date1, string date2);
 
};
 