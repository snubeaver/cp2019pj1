#include "vehicle.cpp"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
void road_50(Vehicle *gogo, int km){
    gogo->car_check();
    
}
void road(string s, Vehicle *gogo){
    int i =1;
    string km_s="";
    string t_s="";
    while(s.at(i)!='T'){
        km_s+=s.at(i++);
    };
    i++;
    while(s.at(i)!='H'){
        t_s+=s.at(i++);
    };
    string h_s = s.substr(i+1,s.length());
    int km= stoi(km_s);
    int t= stoi(t_s);
    int h= stoi(h_s);
    gogo->setTemp(t);
    gogo->setHumidity(h);
    gogo->setKm(0);
    gogo->car();
    gogo->car_print();
    cout<<"Next Move? (1,2)"<<endl;
    cout<<"CP-2012-11933>";
    int mode=1;
    cin>>mode;
    if(mode==1) road_50(gogo, km);
}


void sky(string s){

}
void ocean(string s){

}
void unexpected(string s){
}

int main(void){
    cout<<"PJ1.권일재.2012-11933"<<endl;
    cout<<"Choose the number of the test case (1~10) : ";
    int testnum;
    cin>>testnum;
    if(testnum ==0) return 0;
    
    string tc= "[R500T20H20],[S3000T10H5A2000D30],[O80T0D100W100]";
    stringstream ss(tc);
    string token;
    vector<string> tasks;
    Vehicle* gogo = new Vehicle();

    while(getline(ss, token, ',')){
        tasks.push_back(token);
    }
    for( int i=0; i<tasks.size(); i++){
        int len = tasks[i].length();
        string parsed_task = tasks[i].substr(1,len-2);
        char d  =parsed_task.at(0);
        switch(d){
            case 'R' : road(parsed_task, gogo);
            case 'S' : sky(parsed_task);
            case 'O' : ocean(parsed_task);
            default: unexpected(parsed_task);
            }
    }
    

}