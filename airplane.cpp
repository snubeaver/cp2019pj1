/*
    Speed
    Energy
    Temperature
    Humidity
    Altitude
    Oxygen rate
    Air density
Airplane mode has 7 factors 
(speed, energy, temperature, humidity, altitude, oxygen rate, air density). 
All of the attributes are defined private, 
so you have to make get/set functions to deal with the situation.

*/
#include "vehicle.cpp"

class Airplane : public Vehicle{
    public:
        Airplane();
        void check();
};

Airplane::Airplane():Vehicle(){
    setSpeed(900);
}
void Airplane::check(){
    checklist();
    int air = getAirdensity();
    int speed = getSpeed();
    if(air>=70) speed-=500;
    else if(air>=50) speed -=300;
    else if(air>=30) speed -=200;
    setSpeed(speed);

    int altitude = getAltitude();
    int oxy = getOxygen();
    oxy-= altitude/100;
    setOxygen(oxy);
}