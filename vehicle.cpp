#include <iostream>
using namespace std;

class Vehicle{
    private:
        int speed;
        int energy;
        int temp;
        int humidity;
        int altitude;
        int oxygen;
        int airdensity;
        int depth;
        int waterflow;
        int km;
        int state;
        int arrived;
        int subgoal;
        //0: default 1: arrival 2: mode change 
        //3:no energy 4:no oxygen 5:car stop 6:subgoal
    public:
        Vehicle();
        void setSpeed(int speed);
        void setEnergy(int energy);
        void setTemp(int temp);
        void setHumidity(int humid);
        void setAltitude(int altitude);
        void setOxygen(int oxy);
        void setAirdensity(int air);
        void setDepth(int depth);
        void setWaterflow(int water);
        void setKm(int km);
        void setSubgoal(int km);

    //car
        void car();
        void car_print();
        void solarCharge();
        int car_check();

    //airplane
        void airplane();
        void airplane_print();
        int airplane_check();
    //submarine
        void submarine();
        void submarine_print();
        int submarine_check();

        int getKm();
        int getHumidity();
        int getSpeed();
        int getEnergy();
        int getTemp();
        int getAltitude();
        int getOxygen();
        int getAirdensity();
        int getDepth();
        int getWaterflow();
        int getSubgoal();
        int checkstate();
        void checklist();

};

Vehicle::Vehicle(){
    setEnergy(1000);
    setOxygen(100);
    this->state=0;
    this->arrived=0;
};


void Vehicle::checklist(){
    if(this->temp<40&&this->temp>0) this->energy-=5;
    else if(this->temp>=40) this->energy-=10;
    else this->energy-=8;

    if(this->humidity<50) this->energy -=5;
    else this->energy -=8;
}

void Vehicle::setSpeed(int speed){
    this->speed = speed;
}
void Vehicle::setEnergy(int energy){
    this->energy = energy;
}
void Vehicle::setTemp(int t){
    this->temp = t;
}
void Vehicle::setAltitude(int alt){
    this->altitude = alt;
}
void Vehicle::setOxygen(int oxy){
    this->oxygen = oxy;
}
void Vehicle::setAirdensity(int air){
    this->airdensity = air;
}
void Vehicle::setDepth(int depth){
    this->depth = depth;
}
void Vehicle::setWaterflow(int water){
    this->waterflow = water;
}
void Vehicle::setHumidity(int h){
    this->humidity = h;
}
void Vehicle::setKm(int km){
    this->km = km;
}
void Vehicle::setSubgoal(int km){
    this->subgoal = km;
}

int Vehicle::getSubgoal(){
    return this->subgoal;
}
int Vehicle::getKm(){
    return this->km;
}
int Vehicle::getSpeed(){
    return this->speed;
}
int Vehicle::getEnergy(){
    return this->energy;
}
int Vehicle::getTemp(){
    return this->temp;
}

int Vehicle::getAltitude(){
    return this->altitude;
}
int Vehicle::getOxygen(){
    return this->oxygen;
}
int Vehicle::getAirdensity(){
    return this->airdensity;
}
int Vehicle::getDepth(){
    return this->depth;
}
int Vehicle::getWaterflow(){
    return this->waterflow;
}

int Vehicle::getHumidity(){
    return this->humidity;
}
int Vehicle::checkstate(){
    if(this->arrived) return 1;
    else if(this->oxygen<=0) return 3;
    else if(this->energy<=0) return 4;
    else if(this->subgoal<=this->km) return 6;
    else return 0;
}




// class Car : public Vehicle{
//     private:
//     public:
//         Car();
//         Car(Vehicle v);
//         void print();
//         void solarCharge();

// };
// Car::Car(Vehicle v):Vehicle(v){
//     setSpeed(80);
//     solarCharge();
// }
void Vehicle::car(){
    setSpeed(80);
    setOxygen(100);
    solarCharge();
}

void Vehicle::car_print(){
    cout<<"Current Status: Car"<<endl;
    cout<<"Distance: "<<getKm()<<" km"<<endl;
    cout<<"Speed: "<<getSpeed()<<" km/hr"<<endl;
    cout<<"Energy: "<<getEnergy()<<endl;
    cout<<"Temperature: "<<getTemp()<<" C"<<endl;
    cout<<"Humidity: "<<getHumidity()<<endl;
}
void Vehicle::solarCharge(){
    int humid = getHumidity();
    if(humid>=50) return;
    int energy = getEnergy();
    energy+=200;
    if(energy>1000) setEnergy(1000);
    else setEnergy(energy);
}
int Vehicle::car_check(){
    checklist();
    int km = getKm();
    km+=50;
    setKm(km);
    int p = checkstate();
    return p;
}






// class Airplane : public Vehicle{
//     public:
//         Airplane();
//         void check();
// };


void Vehicle::airplane(){
    setSpeed(900);
}
void Vehicle::airplane_print(){
    cout<<"Current Status: Airplane"<<endl;
    cout<<"Distance: "<<getKm()<<" km"<<endl;
    cout<<"Speed: "<<getSpeed()<<" km/hr"<<endl;
    cout<<"Energy: "<<getEnergy()<<endl;
    cout<<"Oxygen Level: "<<getOxygen()<<endl;
    cout<<"Temperature: "<<getTemp()<<" C"<<endl;
    cout<<"Humidity: "<<getHumidity()<<endl;
    cout<<"Altitude: "<<getAltitude()<<" m"<<endl;
    cout<<"Air Density: "<<getAirdensity()<<endl;
}

int Vehicle::airplane_check(){
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

    int km = getKm();
    km+=1000;
    setKm(km);
    int p = checkstate();
    return p;
}

// class Submarine : public Vehicle{
//     public:
//         Submarine();
//         void check();
//         void light(); 
//         //TODO light reduce 30 every 10km
// };

void Vehicle::submarine(){
    setSpeed(20);
}
void Vehicle::submarine_print(){
    cout<<"Current Status: Submarine"<<endl;
    cout<<"Distance: "<<getKm()<<" km"<<endl;
    cout<<"Speed: "<<getSpeed()<<" km/hr"<<endl;
    cout<<"Energy: "<<getEnergy()<<endl;
    cout<<"Oxygen Level: "<<getOxygen()<<endl;
    cout<<"Temperature: "<<getTemp()<<" C"<<endl;
    cout<<"Depth: "<<getDepth()<<" m"<<endl;
    cout<<"Water Flow: "<<getWaterflow()<<endl;
}
int Vehicle::submarine_check(){
    checklist();
    int depth = getDepth();
    int oxy = getOxygen();
    oxy -= depth/10;
    oxy -= 30; // for light
    setOxygen(oxy);

    int energy = getEnergy();
    energy-=30;
    setEnergy(energy);

    int water = getWaterflow();
    int speed = getSpeed();
    if(water>=70) speed-=10;
    else if(water>=50) speed-=5;
    else if(water>=30) speed-=3;
    setSpeed(speed);

    int km = getKm();
    km+=10;
    setKm(km);
    int p = checkstate();
    return p;
}

// class Road{
//     public:
//         Road(Vehicle &v, int temp, int humid);
// };

// Road::Road(Vehicle &v, int temp, int hum){
//     v.setTemp(temp);
//     v.setHumidity(hum);
//     v.setOxygen(100);
// }
// class Sky{
//     public:
//         Sky(Vehicle &airplane, int temp, int hum, int air);
// };

// Sky::Sky(Vehicle &airplane, int temp, int hum, int air ){
//     airplane.setTemp(temp);
//     airplane.setAirdensity(air);
//     airplane.setHumidity(hum);
// }
// class Ocean{
//     public:
//         Ocean(Submarine &sub, int temp, int water);
// };

// Ocean::Ocean(Submarine &sub, int temp, int water){
//     sub.setTemp(temp);
//     sub.setWaterflow(water);
// }