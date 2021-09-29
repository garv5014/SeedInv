//Garrett Vernon 12/10/2020
#include "seed.h"
#include "doctest.h"
TEST_CASE("constructors")
{
    Seed s("Alfalfa-Yellow-Don", "19-1-21",500,3000,50);
    CHECK(s.getSeedName()=="Alfalfa-Yellow-Don");
    CHECK(s.getLotNum().getCurrentWeight()== 500);
    CHECK(s.getLotNum().getNum()== "19-1-21");
    CHECK(s.getLotNum().getOrigWeight()== 3000);
    CHECK(s.getLotNum().getWeightPerBag()== 50);
}
TEST_CASE("adjust weight")
{
    SUBCASE("Weight Change")
    {
        Seed s("Alfalfa-Yellow-Don", "19-1-21",500,3000,50);
        CHECK(s.getLotNum().getCurrentWeight() == 500);
        s.adjustCurrentWieght(-50);
        CHECK(s.getLotNum().getCurrentWeight() == 450);
    }
    SUBCASE("Exhuast")
    {
        Seed s("Alfalfa-Yellow-Don", "19-1-21",500,3000,50);
        CHECK(s.getLotNum().isExhausted()==false);
        CHECK(s.getLotNum().getCurrentWeight() == 500);
        s.adjustCurrentWieght(-500);
        CHECK(s.getLotNum().getCurrentWeight() == 0);
        CHECK(s.getLotNum().isExhausted()==false);
    }
}
