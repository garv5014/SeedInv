//Garrett Vernon 12/10/2020
#include "seed.h"
using namespace std;


// Seed class definitions

Seed::Seed (string name, string n, double current , double org, double perBag) : lotNum(n,current,org,perBag)
{
    seedName=name;
}

string Seed::getSeedName() const
{
    return seedName;
}

void Seed::displaySeedName() const
{
    cout << seedName << " ";
    lotNum.displayLotInfo();
}

bool Seed::operator <(const Seed& s) {
       return (this-> seedName < s.seedName);
}

bool Seed::operator > (const Seed& s) {
    return (this-> seedName > s.seedName);
}

const LotNumber& Seed::getLotNum() const
{
    return lotNum;
}

    Seed& Seed::operator= (const Seed& right)
{
    if(this==&right)
    {
        return *this;
    }else
    {
        seedName=right.seedName;
        lotNum=right.lotNum;   
    }
    return *this;
}

std::vector<Seed*> Seed::makeInventory()
{
    std::vector<Seed*> L;
    std::fstream inventory;
    inventory.open("inv.txt", ios::out| ios::in);
    if (inventory.fail()) cout << "file failed" <<endl;
    if (inventory.bad()) cout << "file is bad" << endl;
    assert(inventory.is_open());
    string seedName;
    string lotNum;
    double perbag;
    double origWeight;
    double currentWeight;

    while(inventory) // loop over the text file X amount of times
    {
        inventory >> seedName >> lotNum >>currentWeight >> origWeight >> perbag;
        L.push_back(new Seed(seedName, lotNum, currentWeight ,origWeight, perbag));
    }
    inventory.close();
    return L;
}
// LotNumberClass definitions. 
LotNumber::LotNumber(string n, double current , double org, double perBag)
{
    num=n;
    weightPerBag=perBag;
    origWeight=org;
    currentWeight=current;
    if(current > 0){
    exhaust=false;
    }
}

string LotNumber::getNum() const
{
    return num;
}

double LotNumber::getWeightPerBag() const
{
    return weightPerBag;
}
double LotNumber::getOrigWeight() const
{
    return origWeight;
}
double LotNumber::getCurrentWeight() const
{
    return currentWeight;
}

bool LotNumber::isExhausted() const
{
    return exhaust;
}



//need to add if statements to prevent adding more weight then the total in the inventory.
void LotNumber::adjustCurrentWieght(double newWeight)
{
    double leftOver;// to be used as a potential value for an exception later.
    if(currentWeight+newWeight<0)
    {
        exhaust=true;
        leftOver=currentWeight+newWeight;
        std::stringstream val; 
        val << leftOver;
        throw NotEnoughSeed(val.str());
    }else if (currentWeight+newWeight>origWeight)
    {
        leftOver=currentWeight+newWeight-origWeight;
        std::stringstream val; 
        val << leftOver;
        throw OverOrigWeight(val.str());
    }else{currentWeight+=newWeight;}
    
}

// displays the seed name then lotnumber, the current weight of the lot number the total
// weight in inventory and the weight of each bag.
void LotNumber::displayLotInfo() const
{
    cout<< num << " " << currentWeight << " " << origWeight << " " << weightPerBag << endl;
}

LotNumber& LotNumber::operator= (const LotNumber &right)
{
    if(this==&right)
    {
        return *this;
    }else
    {
        num=right.num;
        weightPerBag=right.weightPerBag;
        origWeight=right.origWeight;
        currentWeight=right.currentWeight;
        exhaust=right.exhaust;
    }
    return *this;
}
