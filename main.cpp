#include "vehicle.cpp"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
void road(string s, Vehicle gogo){
    int i =0;
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
    Vehicle gogo;
    while(getline(ss, token, ',')){
        tasks.push_back(token);
    }
    for( int i=0; i<tasks.size(); i++){
        int len = tasks[i].length();
        string parsed_task = tasks[i].substr(1,len-2);
        char d  =parsed_task.at(0);
        cout<<d;
        switch(d){
            case 'R' : road(parsed_task, gogo);
            case 'S' : sky(parsed_task);
            case 'O' : ocean(parsed_task);
            default: unexpected(parsed_task);
            }
    }
    

}