#include "submarine.cpp"

class Ocean{
    public:
        Ocean(Submarine &sub, int temp, int water);
};

Ocean::Ocean(Submarine &sub, int temp, int water){
    sub.setTemp(temp);
    sub.setWaterflow(water);
}