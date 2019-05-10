#include <iostream>
using namespace std;

int main(){
    int i;
    for (i=0 ; i<30; i++){
        cout<<(int)(rand()%4) +1<<endl;
    }
}