//Garrett Vernon 12/10/2020
#include "exceptions.h"
OverOrigWeight::OverOrigWeight(std::string v)
{
    tValue=v;
    message += "BeCareful you are adding ";
    message += tValue;
    message += " more seed then the orignal inventory";
}

const char* OverOrigWeight::what() const noexcept
{
    return message.c_str();
}

NotEnoughSeed::NotEnoughSeed(std::string v)
{
    tValue = v;
    message += "Cannot complete request. You lack ";
    message += tValue;
    message += " pounds of seed in the current lot number please try again";
}
const char* NotEnoughSeed::what() const noexcept
{
   return message.c_str();
}