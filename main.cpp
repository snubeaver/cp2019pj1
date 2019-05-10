#include "vehicle.cpp"
#include <sstream>
#include <vector>
void road_full(Vehicle *gogo, int km);
void road_50(Vehicle *gogo, int km);
void sky_s(Vehicle *gogo, int km);
void sky_f(Vehicle *gogo, int km);
void ocean_f(Vehicle *gogo, int km);
void ocean_s(Vehicle *gogo, int km);
string modes ="";
string energys ="";
string oxygens ="";
string speeds ="";
int startflag=0;
int endflag=0;
int broke=0;
int solarbroke=0;
string extra="";
int extra_i;

void ending(){
    cout<<"Blackbox:"<<endl;
    cout<<"Mode: "<<modes<<endl;
    cout<<"Energy Level: "<<energys<<endl;
    cout<<"Oxygen Level: "<<oxygens<<endl;
    cout<<"Speed: "<<speeds<<endl;
    cout<<"-------------------------"<<endl;
}


void road_full(Vehicle *gogo, int km){
    int mode =0;
    int dist = gogo->getSubgoal() - gogo->getKm();
    int count=0;
    while (mode==0){
        mode = gogo->car_check();
        count++;
        extra_i++;
    }
    cout<<"Successfully moved to next "<<count*50<<" km"<<endl;
    string extratemp = extra;
    extratemp[extra_i]='@';
        
    if(mode ==0) {
        gogo->car_print();
        cout<<extra<<endl;
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
    }
    else if(mode==6){
        gogo->car_print();
        cout<<extra<<endl;
     }
    else {
        cout<<"Final Status:"<<endl;
        cout<<"Distance: "<<gogo->getKm()<<endl;
        cout<<"Energy: "<<gogo->getEnergy()<<endl;
        cout<<"Oxygen Level: "<<gogo->getOxygen()<<endl;
        cout<<""<<endl;

        if(startflag){ 
            modes+=" > Car";
            energys+=" > "+to_string(gogo->getEnergy());
            oxygens+=" > "+to_string(gogo->getOxygen());
            speeds +=" > "+to_string(gogo->getSpeed());
        }else{
            modes+="Car";
            energys+=to_string(gogo->getEnergy());
            oxygens+=to_string(gogo->getOxygen());
            speeds +=to_string(gogo->getSpeed());
         }
        if(mode==6&&endflag==1) cout<<"!FINISHED : Arrived"<<endl;
        else if(mode==3) cout<<"!FINISHED : Oxygen failure"<<endl;
        else if(mode==4) cout<<"!FINISHED : Energy failure"<<endl; 
        else;
        ending();
    }
}
void road_50(Vehicle *gogo, int km){
    int mode =gogo->car_check();
    if(mode==0||mode==6){
        cout<<"Successfully moved to next 50 km"<<endl;
        extra_i++;
        }

    string extratemp = extra;
    extratemp[extra_i]='@';
    if(mode ==0) {
        gogo->car_print();
        cout<<extra<<endl;

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
    }
    else if(mode==6){
        gogo->car_print();
        cout<<extra<<endl;

    }else {
        cout<<"Final Status:"<<endl;
        cout<<"Distance: "<<gogo->getKm()<<endl;
        cout<<"Energy: "<<gogo->getEnergy()<<endl;
        cout<<"Oxygen Level: "<<gogo->getOxygen()<<endl;
        cout<<""<<endl;
        if(startflag){ 
            modes+=" > Car";
            energys+=" > "+to_string(gogo->getEnergy());
            oxygens+=" > "+to_string(gogo->getOxygen());
            speeds +=" > "+to_string(gogo->getSpeed());
        }else{
            modes+="Car";
            energys+=to_string(gogo->getEnergy());
            oxygens+=to_string(gogo->getOxygen());
            speeds +=to_string(gogo->getSpeed());
    }
        if(mode==6&&endflag==1) cout<<"!FINISHED : Arrived"<<endl;
        else if(mode==3) cout<<"!FINISHED : Oxygen failure"<<endl;
        else if(mode==4) cout<<"!FINISHED : Energy failure"<<endl; 
        else;
        ending();
    }
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
    if(solarbroke==1) gogo->car_b();
    else gogo->car();

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
    if(startflag){ 
        modes+=" > Car";
        energys+=" > "+to_string(gogo->getEnergy());
        oxygens+=" > "+to_string(gogo->getOxygen());
        speeds +=" > "+to_string(gogo->getSpeed());
    }else{
        modes+="Car";
        energys+=to_string(gogo->getEnergy());
        oxygens+=to_string(gogo->getOxygen());
        speeds +=to_string(gogo->getSpeed());
    }
}

void sky_f(Vehicle *gogo, int km){
    int mode =0;
    int dist =gogo->getSubgoal() - gogo->getKm();
    int count =0;
    while (mode==0){
        mode = gogo->airplane_check();
        count++;
    }
    cout<<"Successfully moved to next "<<count*1000<<" km"<<endl;
        
    if(mode ==0) {
        gogo->airplane_print();
        cout<<extra<<endl;

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
    }
    else if(mode==6){
        gogo->airplane_print();
        cout<<extra<<endl;

    }else {
        cout<<"Final Status:"<<endl;
        cout<<"Distance: "<<gogo->getKm()<<endl;
        cout<<"Energy: "<<gogo->getEnergy()<<endl;
        cout<<"Oxygen Level: "<<gogo->getOxygen()<<endl;
        cout<<""<<endl;
        modes+=" > Airplane";
        energys+=" > "+to_string(gogo->getEnergy());
        oxygens+=" > "+to_string(gogo->getOxygen());
        speeds +=" > "+to_string(gogo->getSpeed());

        if(mode==6&&endflag==1) cout<<"!FINISHED : Arrived"<<endl;
        else if(mode==3) cout<<"!FINISHED : Oxygen failure"<<endl;
        else if(mode==4) cout<<"!FINISHED : Energy failure"<<endl; 
        else;
        ending();
    }
}
void sky_s(Vehicle *gogo, int km){
    int mode =gogo->airplane_check();
    if(mode==0||mode==6) cout<<"Successfully moved to next 1000 km"<<endl;
    
    if(mode ==0) {
        gogo->airplane_print();
        cout<<extra<<endl;

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
    }
    else if(mode==6){
        gogo->airplane_print();
        cout<<extra<<endl;

    }else {
        cout<<"Final Status:"<<endl;
        cout<<"Distance: "<<gogo->getKm()<<endl;
        cout<<"Energy: "<<gogo->getEnergy()<<endl;
        cout<<"Oxygen Level: "<<gogo->getOxygen()<<endl;
        cout<<""<<endl;

        modes+=" > Airplane";
        energys+=" > "+to_string(gogo->getEnergy());
        oxygens+=" > "+to_string(gogo->getOxygen());
        speeds +=" > "+to_string(gogo->getSpeed());

        if(mode==6&&endflag==1) cout<<"!FINISHED : Arrived"<<endl;
        else if(mode==3) cout<<"!FINISHED : Oxygen failure"<<endl;
        else if(mode==4) cout<<"!FINISHED : Energy failure"<<endl; 
        else;
        ending();
    }
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

    modes+=" > Airplane";
    energys+=" > "+to_string(gogo->getEnergy());
    oxygens+=" > "+to_string(gogo->getOxygen());
    speeds +=" > "+to_string(gogo->getSpeed());
}


void ocean_f(Vehicle *gogo, int km){
    int mode =0;
    int dist =gogo->getSubgoal() - gogo->getKm();
    int count=0;
    while (mode==0){
        mode = gogo->submarine_check();
        count++;
    }
    cout<<"Successfully moved to next "<<count*10<<" km"<<endl;
    
    
    if(mode ==0) {
        gogo->submarine_print();
        cout<<extra<<endl;

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
    }
    else if(mode==6){
        gogo->submarine_print();
        cout<<extra<<endl;

    }else{ 
        cout<<"Final Status:"<<endl;
        cout<<"Distance: "<<gogo->getKm()<<endl;
        cout<<"Energy: "<<gogo->getEnergy()<<endl;
        cout<<"Oxygen Level: "<<gogo->getOxygen()<<endl;
        cout<<""<<endl;
        
        modes+=" > Submarine";
        energys+=" > "+to_string(gogo->getEnergy());
        oxygens+=" > "+to_string(gogo->getOxygen());
        speeds +=" > "+to_string(gogo->getSpeed());
        if(mode==6&&endflag==1){ cout<<"!FINISHED : Arrived"<<endl;}
        else if(mode==3){ cout<<"!FINISHED : Oxygen failure"<<endl;}
        else if(mode==4){ cout<<"!FINISHED : Energy failure"<<endl;}
        else ;
        ending();
    }
}
void ocean_s(Vehicle *gogo, int km){
    int mode =gogo->submarine_check();
    if(mode==0||mode==6) cout<<"Successfully moved to next 1000 km"<<endl;
    
    if(mode ==0) {
        gogo->submarine_print();
        cout<<extra<<endl;

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
    }
    else if(mode==6){
        gogo->submarine_print();
        cout<<extra<<endl;

    }else{ 
        cout<<"Final Status:"<<endl;
        cout<<"Distance: "<<gogo->getKm()<<endl;
        cout<<"Energy: "<<gogo->getEnergy()<<endl;
        cout<<"Oxygen Level: "<<gogo->getOxygen()<<endl;
        cout<<""<<endl;

        modes+=" > Submarine";
        energys+=" > "+to_string(gogo->getEnergy());
        oxygens+=" > "+to_string(gogo->getOxygen());
        speeds +=" > "+to_string(gogo->getSpeed());
        if(mode==6&&endflag==1){ cout<<"!FINISHED : Arrived"<<endl;}
        else if(mode==3){ cout<<"!FINISHED : Oxygen failure"<<endl;}
        else if(mode==4){ cout<<"!FINISHED : Energy failure"<<endl;}
        else ;
        ending();
    }
}
void ocean(string s, Vehicle *gogo){
    int i =1;
    string km_s="";
    string t_s="";
    string d_s="";
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
    modes+=" > Submarine";
    energys+=" > "+to_string(gogo->getEnergy());
    oxygens+=" > "+to_string(gogo->getOxygen());
    speeds +=" > "+to_string(gogo->getSpeed());
}
void unexpected(string s, Vehicle *gogo){
    if(s.at(0)=='X'){
        int prob = (int)(rand()%4) +1;
        if( prob ==1){
            broke =1;
            cout<<"Final Status:"<<endl;
            cout<<"Distance: "<<gogo->getKm()<<endl;
            cout<<"Energy: "<<gogo->getEnergy()<<endl;
            cout<<"Oxygen Level: "<<gogo->getOxygen()<<endl;
            cout<<""<<endl;
            cout<<"!FINISHED : Vehicle stop"<<endl;
            ending();
        }else{
            int energy = gogo->getEnergy();
            energy-=100;
            gogo->setEnergy(energy);
        }
    }
    else{
        if(rand()%(100/35)<1){
            broke =1;
            cout<<"Final Status:"<<endl;
            cout<<"Distance: "<<gogo->getKm()<<endl;
            cout<<"Energy: "<<gogo->getEnergy()<<endl;
            cout<<"Oxygen Level: "<<gogo->getOxygen()<<endl;
            cout<<""<<endl;
            cout<<"!FINISHED : Vehicle stop"<<endl;
            ending();
        }else{
            stringstream ss(modes);
            string last="";
            string token;
            while(getline(ss, token, '>')){
                last=token;
            }
            if(last.find("Car") != string::npos){
                solarbroke=1;
            }else{
                int oxy = gogo->getOxygen();
                oxy-=30;
                gogo->setOxygen(oxy);
            }
        }


    }
}

int main(void){
    cout<<"PJ1.권일재.2012-11933"<<endl;
    int testnum=-1;
    while (testnum!=0){
        cout<<"Choose the number of the test case (1~10) : ";
        cin>>testnum;
        if(testnum==0) break;
        string tc= "[R500T20H20],[S3000T10H5A2000D30],[X],[O80T0D100W100]";
        stringstream ss(tc);
        string token;
        vector<string> tasks;
        Vehicle* gogo = new Vehicle();
        modes ="";
        energys="";
        oxygens="";
        speeds="";
        broke=0;
        solarbroke=0;
        extra="";
        extra_i=0;

        while(getline(ss, token, ',')){
            tasks.push_back(token);
        }
        for( int i=0; i<tasks.size(); i++){
            int len = tasks[i].length();
            string parsed_task = tasks[i].substr(1,len-2);
            char d  =parsed_task.at(0);
            switch(d){
                case 'R' : {
                    int j=1;
                    string km_s="";
                    while(parsed_task.at(j)!='T'){
                        km_s+=parsed_task.at(j++);
                    };
                    for(int k=0; k<stoi(km_s)/50;k++){
                        extra+="=";
                    }
                    break;
                }
                case 'S' :{
                    int j=1;
                    string km_s="";
                    while(parsed_task.at(j)!='T'){
                        km_s+=parsed_task.at(j++);
                    };
                    for(int k=0; k<stoi(km_s)/1000;k++){
                        extra+="^";
                    }
                    break;
                }
                case 'O' : {
                    int j=1;
                    string km_s="";
                    while(parsed_task.at(j)!='T'){
                        km_s+=parsed_task.at(j++);
                    };
                    for(int k=0; k<stoi(km_s)/10;k++){
                        extra+="~";
                    }
                    break;
                }
                default: break;
                }
        }
        for( int i=0; i<tasks.size(); i++){
            if(i==1) startflag=1;
            int len = tasks[i].length();
            string parsed_task = tasks[i].substr(1,len-2);
            char d  =parsed_task.at(0);
            if(i==tasks.size()-1) endflag=1;
            switch(d){
                case 'R' : road(parsed_task, gogo); break;
                case 'S' : sky(parsed_task, gogo);break;
                case 'O' : ocean(parsed_task, gogo);break;
                default: unexpected(parsed_task, gogo);
                }
            if(broke) break;
        }

    }
    return 0;

}