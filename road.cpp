#include "car.cpp"
class Road{
    public:
        Road(Car &car, int temp, int humid);
};

Road::Road(Car &car, int temp, int hum){
    car.setTemp(temp);
    car.setHumidity(hum);
    car.setOxygen(100);
}