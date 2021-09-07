using namespace std;
#include <string>
#include <vector>

class Vaccine{
public:
 
int covishieldDosesTotal;
int cowinDosesTotal;
int pincode;
 
Vaccine()
{
   cowinDosesTotal = 0;
   covishieldDosesTotal = 0;
}

void addVaccine( vector<Vaccine> &vaccinefile );

void searchForAvailablilty( vector<Vaccine> &vaccinefile );
};