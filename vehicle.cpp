

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

        int getHumidity();
        int getSpeed();
        int getEnergy();
        int getTemp();
        int getAltitude();
        int getOxygen();
        int getAirdensity();
        int getDepth();
        int getWaterflow();

        void checklist();

};

Vehicle::Vehicle(){
    setEnergy(1000);
    setOxygen(100);

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

class Road{
    public:
        Road(Car &car, int temp, int humid);
};

Road::Road(Car &car, int temp, int hum){
    car.setTemp(temp);
    car.setHumidity(hum);
    car.setOxygen(100);
}
class Sky{
    public:
        Sky(Airplane &airplane, int temp, int hum, int air);
};

Sky::Sky(Airplane &airplane, int temp, int hum, int air ){
    airplane.setTemp(temp);
    airplane.setAirdensity(air);
    airplane.setHumidity(hum);
}
class Ocean{
    public:
        Ocean(Submarine &sub, int temp, int water);
};

Ocean::Ocean(Submarine &sub, int temp, int water){
    sub.setTemp(temp);
    sub.setWaterflow(water);
}