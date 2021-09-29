//Garrett Vernon 12/10/2020
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <iostream>
#include <sstream>

class WeightException : public std::exception
{
    protected:
    //Holds the string of the value that was computed
    std::string tValue;
    public:
    const std::string& getExcess() const;
};

//This class is thrown When The user trys to input more seed then the original weight.
class OverOrigWeight : public WeightException 
{
    private:
    //Holds the error message the is created in the constructor
    std::string message;
    public:
    OverOrigWeight(std::string v);
    const char* what() const noexcept override;
};

//This class is thrown When Not Enough seed is in the inventory error occurs.
class NotEnoughSeed : public WeightException
{
    private:
    //Holds the error message the is created in the constructor
    std::string message;
    public:
    NotEnoughSeed(std::string v);
    const char* what() const noexcept override;
}; 
#endif