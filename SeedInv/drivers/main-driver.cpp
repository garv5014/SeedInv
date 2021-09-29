//Garrett Vernon 12/10/2020

#include "seed.h"
#include <vector>
#include <fstream>
#include <cassert>
#include <algorithm>
using std::vector;
using namespace std;

//displays the menue of the program
void displayMenue();

// displays the vector L of seed pointers in inventory format
void displayInv(const vector<Seed*> &L);

int main() 
{
    vector<Seed*> seedList;
    std::fstream inventory;
    seedList=Seed::makeInventory();
    cout <<"Inventory has been retrieved" << endl << "Now Printing the inventory" << endl;
    displayInv(seedList);
    char choice='n'; 
    int invNum;
    while (true) 
    {
        displayMenue();
        cout << "Please enter a command." << endl;
        cin >> choice;
        switch (choice)
        {
            case 'c': //Changes the weight of an item
            {
                int adjust;
                cout << "Enter the inventory number." << endl;
                cin >> invNum;
                cout << "Enter how much you want to adjust the weight by" << endl;
                cin >> adjust;
                try
                {
                    seedList[invNum-1]->adjustCurrentWieght(adjust);
                }catch(const std::exception& e)
                {
                    std::cout<< e.what() << std::endl;
                    displayInv(seedList);
                    continue;
                }
                    displayInv(seedList);
                break;
            } 
            case '+': // Adds an item to the inventory
            {
                string seedName;
                string lotNum;
                double perbag;
                double origWeight;
                double currentWeight;
                cout << "please enter the new seed you want to add to the list in order of seed name, lot number,"
                << "current weight in inventory, original weight in inventory, and finally pounds per bag."<< endl;
                cout << "Remember for the seeds name to use dashes instead of spaces. such as Alfalfa-Yellow-Don"<< endl;
                cin >> seedName >> lotNum >> currentWeight >> origWeight >> perbag;
                seedList.push_back(new Seed(seedName, lotNum, currentWeight ,origWeight, perbag));
                sort(seedList.begin(),seedList.end(), [](Seed* SL, Seed* SR){return  *SL < *SR;} ); //sort point
                displayInv(seedList);
                break;
            }
            case '-': // Takes an item out of the inventory vector according to the its number in inventory.
            {
                cout << "please enter the inventory number on the item you want removed" << endl;
                int remove=0;
                cin >> remove;
                seedList.erase(seedList.begin()+(remove-1));
                displayInv(seedList);
                break;
            }
            case 'E': // Exits the program and updates the text file to the changed inventory.
            {
                inventory.open("inv.txt", ios::out);
                for(std::size_t i =0; i< seedList.size()-1; i++)
                {
                    inventory << seedList[i]->getSeedName() << " " <<  seedList[i]->getLotNum().getNum() << " " <<  seedList[i]->getLotNum().getCurrentWeight() << " " << seedList[i]->getLotNum().getOrigWeight() << " " << seedList[i]->getLotNum().getWeightPerBag() << endl;
                }
                inventory.close();
                return false;
            }
            default:
                break;
        }
    }
    return 0;
}

void displayMenue()
{
    cout << endl;
    cout << "Instructions" << endl;
    cout << "c) change the weight of an item in the inventory" << endl;
    cout << "+) add an item to inventory" << endl;
    cout << "-) remove and item from inventory " << endl; 
    cout << "E) exit the program (stores inventory)"<< endl;
}

void displayInv(const vector<Seed*> &L)
{
    cout << "The data is in order of species name then lot number the current weight in inventory then the orignal weight and finally the pounds per  bag" << endl;
    for (std::size_t i = 0; i < L.size()-1; i++) // loops over the vector displaying the list
        {
            cout << i+1 << ")" << " ";
            L[i]->displaySeedName();
        }
}