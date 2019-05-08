/*
    Speed
    Energy
    Temperature
    Depth
    Light(Always on)
    Oxygen rate
    Water flow

Submarine mod has 6 factors 
(speed, energy, temperature, depth, oxygen rate, water flow) 
and public function(light). 
All of the factors are defined private, 
so you have to make get/set functions to deal with the situation.

*/
#include "vehicle.cpp"

class Submarine : public Vehicle{
    public:
        Submarine();
        void check();
        void light(); 
        //TODO light reduce 30 every 10km
};

Submarine::Submarine():Vehicle(){
    setSpeed(20);
}
void Submarine::check(){
    checklist();
    int depth = getDepth();
    int oxy = getOxygen();
    oxy -= depth/10;
    oxy -= 30; // for light
    setOxygen(oxy);

    int water = getWaterflow();
    int speed = getSpeed();
    if(water>=70) speed-=10;
    else if(water>=50) speed-=5;
    else if(water>=30) speed-=3;
    setSpeed(speed);
}