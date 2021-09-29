//Garrett Vernon 12/10/2020
#ifndef SEED_H
#define SEED_H
#include <string>
#include <iostream>
#include <exception>
#include "exceptions.h"
#include <cassert>
#include <vector>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class LotNumber 
{
    private:
        string num;
        double weightPerBag;
        double origWeight;
        double currentWeight;
        bool exhaust=true;
    public:
    //Default constructor.
    LotNumber();

    // Explicit constructor.
    LotNumber(string num, double current, double origWeight, double perBag);

    // Copy constructor.
    LotNumber(const LotNumber &lotNum)
    {
        num=lotNum.num;
        weightPerBag=lotNum.weightPerBag;
        origWeight=lotNum.origWeight;
        currentWeight=lotNum.currentWeight;
        exhaust=lotNum.exhaust;
    }

    //Overloads the Equal operator.
    LotNumber& operator=(const LotNumber& right);

    // This will display the lot number, weight per bag, origweight, and the current weight.
    void displayLotInfo() const;

    // This function will take in a double (positive or negative) and add that to the current weight adjusting it
    // it will also check to see if the lot exhausts and change the exhuast variable.
    void adjustCurrentWieght(double newWeight);
    
    //getters for the lotNumber class.
    string getNum() const;
    double getWeightPerBag() const;
    double getOrigWeight() const;
    double getCurrentWeight() const;
    bool isExhausted() const;

    ~LotNumber()
    {}
};

class Seed
{
    private:
        string seedName;
        LotNumber lotNum;
    public:
        Seed () 
        {}
        //Explicit constructor.
        Seed(string name, string n, double current, double org, double perbag );
        
        // copy constructor.
        Seed(const Seed &s)
        {
            seedName=s.seedName;
            lotNum=s.lotNum;
        }

        // This function displays the seedName and calls lotNum.DisplayLotInfo();
        void displaySeedName() const;

        Seed& operator= (const Seed& right);

        //Overloads the relational operators
        bool operator < (const Seed& s);
        bool operator > (const Seed& s);

        //Getter for seedName and lotNum.
        string getSeedName() const;
        const LotNumber& getLotNum() const; 

        //changes the current weight of the lotNum class
        void adjustCurrentWieght(double newWeight)
        {
            lotNum.adjustCurrentWieght(newWeight);
        }

        // This static function opens a file called inventory reads out of the text file and 
        // populates a vector with Seed class pointers.
        static std::vector<Seed*> makeInventory();
        
        ~Seed()
        {}
};
#endif
