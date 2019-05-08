#include "airplane.cpp"

class Sky{
    public:
        Sky(Airplane &airplane, int temp, int hum, int air);
};

Sky::Sky(Airplane &airplane, int temp, int hum, int air ){
    airplane.setTemp(temp);
    airplane.setAirdensity(air);
    airplane.setHumidity(hum);
}