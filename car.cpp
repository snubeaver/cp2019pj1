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
        Vehicle obj;
        Car(Vehicle v):obj(v);
        void print();
        void solarCharge();

};
Car::Car(Vehicle v):Vehicle(v){
    v->setSpeed(80);
    v->solarCharge();
}

void Vehicle::car_print(){
    cout<<"Current Status: Car"<<endl;
    cout<<"Distance: "<<getKm()<<" km"<<endl;
    cout<<"Speed: "<<getSpeed()<<" km/hr"<<endl;
    cout<<"Temperature: "<<getTemp()<<" C"<<endl;
    cout<<"Humidity: "<<getHumidity()<<endl;
}

