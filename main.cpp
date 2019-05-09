#include "vehicle.cpp"
#include <iostream>
#include <sstream>
#include <vector>
void road_full(Vehicle *gogo, int km);
void road_50(Vehicle *gogo, int km);
void sky_s(Vehicle *gogo, int km);
void sky_f(Vehicle *gogo, int km);
void ocean_f(Vehicle *gogo, int km);
void ocean_s(Vehicle *gogo, int km);
using namespace std;





void road_full(Vehicle *gogo, int km){
    int mode =0;
    int dist = km - gogo->getKm();
    while (mode==0){
        mode = gogo->car_check();
    }
    if(mode==1) cout<<"!FINISHED : Arrived"<<endl;
    else if(mode==3) cout<<"!FINISHED : Oxygen failure"<<endl;
    else if(mode==4) cout<<"!FINISHED : Energy failure"<<endl;
    else if(mode==6) cout<<"Successfully moved to next "<<dist<<" km"<<endl;
    else;
    gogo->car_print();
        
    if(mode ==0) {
        cout<<"Next Move? (1,2)"<<endl;
        cout<<"CP-2012-11933>";
        int t =1;
        cin>>t;
        if(t==1){
            road_50(gogo, km);
        }
        else{
            road_full(gogo, km);
        }
    }else if(mode ==6){
        return;
    }
    else cout<<"-------------------------"<<endl;
}
void road_50(Vehicle *gogo, int km){
    int mode =gogo->car_check();
    if(mode==1) cout<<"!FINISHED : Arrived"<<endl;
    else if(mode==3) cout<<"!FINISHED : Oxygen failure"<<endl;
    else if(mode==4) cout<<"!FINISHED : Energy failure"<<endl;
    else cout<<"Successfully moved to next 50 km"<<endl;
    gogo->car_print();
    
    if(mode ==0) {
        cout<<"Next Move? (1,2)"<<endl;
        cout<<"CP-2012-11933>";
        int t =1;
        cin>>t;
        if(t==1){
            road_50(gogo, km);
        }
        else{
            road_full(gogo, km);
        }
    }else if(mode ==6){
        return;
    }
    else cout<<"-------------------------"<<endl;
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
    gogo->setSubgoal(km);
    gogo->car();

    cout<<"Current Status: Car"<<endl;
    cout<<"Distance: "<<gogo->getKm()<<" km"<<endl;
    cout<<"Speed: "<<gogo->getSpeed()<<" km/hr"<<endl;
    cout<<"Temperature: "<<gogo->getTemp()<<" C"<<endl;
    cout<<"Humidity: "<<gogo->getHumidity()<<endl;
    cout<<"Next Move? (1,2)"<<endl;
    cout<<"CP-2012-11933>";
    int mode=1;
    cin>>mode;
    if(mode==1) road_50(gogo, km);
    else road_full(gogo, km);
}

void sky_f(Vehicle *gogo, int km){
    int mode =0;
    int dist =gogo->getSubgoal() - gogo->getKm();
    while (mode==0){
        mode = gogo->airplane_check();
    }
    if(mode==1) cout<<"!FINISHED : Arrived"<<endl;
    else if(mode==3) cout<<"!FINISHED : Oxygen failure"<<endl;
    else if(mode==4) cout<<"!FINISHED : Energy failure"<<endl;
    else if(mode==6) cout<<"Successfully moved to next "<<dist<<" km"<<endl;
    else;
    gogo->airplane_print();
        
    if(mode ==0) {
        cout<<"Next Move? (1,2)"<<endl;
        cout<<"CP-2012-11933>";
        int t =1;
        cin>>t;
        if(t==1){
            sky_s(gogo, km);
        }
        else{
            sky_f(gogo, km);
        }
    }else if(mode ==6){
        return;
    }
    else cout<<"-------------------------"<<endl;
}
void sky_s(Vehicle *gogo, int km){
    int mode =gogo->airplane_check();
    if(mode==1) cout<<"!FINISHED : Arrived"<<endl;
    else if(mode==3) cout<<"!FINISHED : Oxygen failure"<<endl;
    else if(mode==4) cout<<"!FINISHED : Energy failure"<<endl;
    else cout<<"Successfully moved to next 1000 km"<<endl;
    gogo->airplane_print();
    
    if(mode ==0) {
        cout<<"Next Move? (1,2)"<<endl;
        cout<<"CP-2012-11933>";
        int t =1;
        cin>>t;
        if(t==1){
            sky_s(gogo, km);
        }
        else{
            sky_f(gogo, km);
        }
    }else if(mode ==6){
        return;
    }
    else cout<<"-------------------------"<<endl;
}
void sky(string s, Vehicle *gogo){
    int i =1;
    string km_s="";
    string t_s="";
    string h_s="";
    string a_s="";
    while(s.at(i)!='T'){
        km_s+=s.at(i++);
    };
    i++;
    while(s.at(i)!='H'){
        t_s+=s.at(i++);
    };
    i++;
    while(s.at(i)!='A'){
        h_s+=s.at(i++);
    };
    i++;
    while(s.at(i)!='D'){
        a_s+=s.at(i++);
    };
    string d_s = s.substr(i+1,s.length());

    int km= stoi(km_s);
    int t= stoi(t_s);
    int h= stoi(h_s);
    int a= stoi(a_s);
    int d= stoi(d_s);
    gogo->setTemp(t);
    gogo->setHumidity(h);
    int temp_km = gogo->getSubgoal();
    gogo->setSubgoal(km+temp_km);
    // cout<<">>>>"<<gogo->getSubgoal();
    gogo->setAltitude(a);
    gogo->setAirdensity(d);
    gogo->airplane();
    cout<<"Next Move? (1,2)"<<endl;
    cout<<"CP-2012-11933>";
    int mode=1;
    cin>>mode;
    if(mode==1) sky_s(gogo, km);
    else sky_f(gogo, km);
}


void ocean_f(Vehicle *gogo, int km){
    int mode =0;
    int dist =gogo->getSubgoal() - gogo->getKm();
    while (mode==0){
        mode = gogo->submarine_check();
    }
    if(mode==1) cout<<"!FINISHED : Arrived"<<endl;
    else if(mode==3) cout<<"!FINISHED : Oxygen failure"<<endl;
    else if(mode==4) cout<<"!FINISHED : Energy failure"<<endl;
    else if(mode==6) cout<<"Successfully moved to next "<<dist<<" km"<<endl;
    else;
    gogo->submarine_print();
        
    if(mode ==0) {
        cout<<"Next Move? (1,2)"<<endl;
        cout<<"CP-2012-11933>";
        int t =1;
        cin>>t;
        if(t==1){
            ocean_s(gogo, km);
        }
        else{
            ocean_f(gogo, km);
        }
    }else if(mode ==6){
        return;
    }
    else cout<<"-------------------------"<<endl;
}
void ocean_s(Vehicle *gogo, int km){
    int mode =gogo->submarine_check();
    if(mode==1) cout<<"!FINISHED : Arrived"<<endl;
    else if(mode==3) cout<<"!FINISHED : Oxygen failure"<<endl;
    else if(mode==4) cout<<"!FINISHED : Energy failure"<<endl;
    else cout<<"Successfully moved to next 1000 km"<<endl;
    gogo->submarine_print();
    
    if(mode ==0) {
        cout<<"Next Move? (1,2)"<<endl;
        cout<<"CP-2012-11933>";
        int t =1;
        cin>>t;
        if(t==1){
            ocean_s(gogo, km);
        }
        else{
            ocean_f(gogo, km);
        }
    }else if(mode ==6){
        return;
    }
    else cout<<"-------------------------"<<endl;
}
void ocean(string s, Vehicle *gogo){
    int i =1;
    string km_s="";
    string t_s="";
    string d_s=""; //[O80T0D100W100]
    while(s.at(i)!='T'){
        km_s+=s.at(i++);
    };
    i++;
    while(s.at(i)!='D'){
        t_s+=s.at(i++);
    };
    i++;
    while(s.at(i)!='W'){
        d_s+=s.at(i++);
    };
    string w_s = s.substr(i+1,s.length());

    int km= stoi(km_s);
    int t= stoi(t_s);
    int d= stoi(d_s);
    int w= stoi(w_s);
    gogo->setTemp(t);
    gogo->setDepth(d);
    gogo->setWaterflow(w);
    int temp_km = gogo->getSubgoal();
    gogo->setSubgoal(km+temp_km);
    // cout<<">>>>"<<gogo->getSubgoal();
    
    gogo->submarine();
    cout<<"Next Move? (1,2)"<<endl;
    cout<<"CP-2012-11933>";
    int mode=1;
    cin>>mode;
    if(mode==1) ocean_s(gogo, km);
    else ocean_f(gogo, km);

}
void unexpected(string s){
}

int main(void){
    cout<<"PJ1.권일재.2012-11933"<<endl;
    cout<<"Choose the number of the test case (1~10) : ";
    int testnum;
    cin>>testnum;
    // while (testnum!=0){
        
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
                case 'R' : road(parsed_task, gogo); break;
                case 'S' : sky(parsed_task, gogo);break;
                case 'O' : ocean(parsed_task, gogo);break;
                default: unexpected(parsed_task);
                }

        }
    // }
    return 0;

}