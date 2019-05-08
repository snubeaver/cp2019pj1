/*
[ Car ]
    Speed
    Energy
    Temperature
    Humidity
    Solar panel recharge
Car mode has 4 factors (speed, energy, temperature, humidity) and 
public function (solar panel recharge). 
All of the attributes are defined private, 
so you have to make get/set functions to deal with the situation.
 When in car mode, the solar charging system is activated to charge energy. 

*/
#include "vehicle.cpp"

class Car : public Vehicle{
    private:
    public:
        Car();
        void solarCharge();

};
Car::Car():Vehicle(){
    setSpeed(80);
    solarCharge();
}
void Car::solarCharge(){
    int humid = getHumidity();
    if(humid>=50) return;
    int energy = getEnergy();
    energy+=200;
    if(energy>1000) setEnergy(1000);
    else setEnergy(energy);
}