/*************************************************
Aufgabe Nr./Task No.: H4
Nachname/Last,Family Name: Islam
Vorname/First,Given Name: Mozahidul
Matrikelnummer/Matriculation number: 3022958
Uni-Email: mozahidul.islam@stud.uni-due.de
Studiengang/Course of Studies: ISE CE
*************************************************/







#include<iostream>
using namespace std;
#define M 14
int crn;
class Timepoint{
private:
    int dayOfYear=1;
    int Year;
    int time=0;
   const  static  int days[14];
public:
    Timepoint(int year=2025,int month=12,int day=31,int hour=23, int minit=59):
    dayOfYear((days[month-1])+day),Year(year),time((hour*60)+minit){};
    int get_dayOfYear(){
          return dayOfYear;
                       }
    void operator++(int){
         Timepoint timepoint;
         dayOfYear++;
         if(dayOfYear>365){dayOfYear=1;Year=Year+1;}
                        };
    friend ostream& operator>>(ostream&,Timepoint&);
    friend ostream& operator<<(ostream&, Timepoint&);
        };
const  int Timepoint:: days[M]={0,31,59,90,120,151,181,212,243,273,304,334,365};

     istream& operator>>(istream& in,Timepoint& t)
     {
     int y,m,d,h,mi;
     in>>d;in.ignore(1,'.');in>>m;in.ignore(1,'.');in>>y;in.ignore(1,'\t');in>>h;in.ignore(1,':');in>>mi;
     Timepoint T(y,m,d,h,mi);
     t=T;
     return in;
     }
     ostream& operator<<(ostream& out, Timepoint& t)
     {
     int m,d,i;
     for(i=0;i<13;i++){
        if(t.dayOfYear<=t.days[i])
            {
            m=i;d=((t.dayOfYear)-(t.days[i-1]));break;
            }
                      }
     out<<t.Year<<"-";if(m/10==0){out<<'0';}out<<m<<"-";if(d/10==0){out<<'0';}out<<d<<"  T:";if((t.time/60)/10==0){cout<<'0';}out<<t.time/60<<":";if((t.time%60)/10==0){cout<<'0';}out<<t.time%60;
     return out;
     }

     class License
     {
 private:
    int no;
    string issuer;
    Timepoint validUntill;
 public:
    License( Timepoint s=Timepoint(2025,12,31,23,59), string b="vehicles",int a=111){issuer=b;validUntill=s;no=a;};
    int get_no(){return no;};
    string get_issuer(){return issuer;};
    Timepoint get_validUntil(){return validUntill;};
    friend ostream& operator<<(ostream&,License&);
    } ;
    ostream& operator<<(ostream& out,License& l)
    {
    out<<l.issuer<<" "<<l.no<<", valid until "<<l.validUntill;
    return out;
    }

    class Driver
    {
private:
    string name;
    License license;
public:
    Driver(){};
    Driver(int j){
                  string a,b;
                  int c;
                  Timepoint d;
                  cout<<"name of the driver: ";  cin.ignore(1,'\n');  getline(cin,a);
                  cout<<"issuer of the license: ";cin>>b;
                  cout<<"number of the license: "; cin>>c;
                  cout<<"valid until: "; cin>>d;

                  name=a;
                  License l(d,b,c);
                  license=l;
                  }
     string get_name(){return name;};
     License get_license(){return license;};
     friend ostream& operator<<(ostream&, Driver&);
    };
    ostream& operator<<(ostream& out, Driver& d)
                       {
                        out<<d.name<<"("<<d.license<<")";
                        return out;
                        }

    class Vehicle
    {
private:
    string model;
    string plate;
    float price24h;
public:
    Vehicle(string a,string b,float c=9.99):model(a),plate(b),price24h(c){};
    string get_model(){return model;};
    string get_plate(){return plate;};
    double get_price(int a){return a*price24h;}
    void set_price24h(int a){price24h=a;};
    void virtual print()=0;
    };


    class Scooter:public Vehicle
    {
public:
    Scooter(string a,string b):Vehicle(a,b,9.99){};
    void print(){
                cout<<"Scooter "<<Vehicle::get_model()<<"("<<Vehicle::get_plate()<<")";
                }
    };


 class Car:public Vehicle
 {
 private:
    bool navigation;
 public:
    Car(string a,string b,float c=29.99,bool n=true):Vehicle(a,b,c),navigation(n){};
    bool virtual has_aircondition()=0;
    bool has_navigation(){return navigation;};
    void print(){
                 cout<<Vehicle::get_model()<<" (plate: "<<Vehicle::get_plate()<<"),";
                 if(has_aircondition())
                    {cout<<"air condition,";};
                 if(has_navigation())
                    {cout<<"navigation";};
                }

 };


 class Cabrio:public Car
 {
 private:
     bool aircondition;
 public:
        Cabrio(string a,string b,float c=99.90):Car(a,b,c,false){};
        bool has_aircondition(){return false;};
        void print(){
                    cout<<"Cabrio ";Car::print();
                    };
 };


 class Limousine:public Car
 {
private:
     bool aircondition;

 public:
        Limousine(string a,string b, float c=149.90,bool d=true):Car(a,b,c),aircondition(d){};
        bool has_aircondition(){return aircondition;};
        void print(){
                    cout<<"Limousine ";Car::print();
                    };
 };


 class Rental
 {
 private:
     const int no;
     Timepoint from;
     int days;
     Vehicle &vehicle;
     Driver driver;
     Driver* additionalDriver;
     class last_no{

         public:

             int get_rentalNo(){
                                     return crn++;
                                    }
                  };
          last_no ln;

 public:
    Rental(Vehicle &a,Timepoint st,Driver d1,int d=1,Driver* d2=nullptr):no(ln.get_rentalNo()),vehicle(a){
                                                                         from=st;
                                                                         days=d;
                                                                         driver=d1;
                                                                         additionalDriver=d2;
                                                                         };

    Timepoint get_from(){return from;};
    Timepoint get_untill(){
                           Timepoint x;int ds;
                           x=from;ds=days;
                           while(ds!=0)
                            {
                                x++;
                                ds--;
                            };
                          return x;
                          };
    int get_days(){return days;};
    void print(){
                 cout<<"VEHICLE RENTAL"<<endl;
                 cout<<"rental no:       "<<(no+1)<<endl;
                 cout<<"Vehicle:         ";vehicle.print();cout<<endl;
                 cout<<"from:            "<<from<<endl;Timepoint n;n=get_untill();
                 cout<<"until:           ";cout<<n;cout<<endl;
                 cout<<"driver:          "<<driver<<endl;
                 if(additionalDriver!=nullptr)
                                             {cout<<"additionaldriver:"<<*additionalDriver<<endl;}
                 cout<<"price for rental: "<<vehicle.get_price(days)<<endl;
               };
 };


 class Schedule
 {
 private:
     Vehicle* vehicle;
     Rental* years[2][366];
 public:
    Schedule(Vehicle* v):vehicle(v){int in,im;for(in=0;in<2;in++)
                                                {for(im=0;im<366;im++)
                                                     {years[in][im]=nullptr;}}};
    Vehicle* get_vehicle(){return vehicle;};
    bool isFree(Timepoint t,int d){
                                  int i,j=0;
                                  bool k=true;
                                  for(i=t.get_dayOfYear();i<=(d+(t.get_dayOfYear()));i++){
                                                                                         if(i>365){i=i-365;j=1;}
                                                                                         if(years[j][i]!=nullptr){k=false;}
                                                                                         if(j==1&&i==((d+(t.get_dayOfYear()))-365)){break;}
                                                                                       }
                                  return k;
                                  };
   void book(Timepoint startTime,Driver firstDriver,int numberOfDays=1,Driver* optionalDriver=nullptr)
             {
             Rental* r=new Rental(*vehicle,startTime,firstDriver,numberOfDays,optionalDriver);
             int i,j=0;
             for(i=startTime.get_dayOfYear();i<=(numberOfDays+(startTime.get_dayOfYear()));i++)
                {
                    if(i>365){i=i-365;j=1;}
                years[j][i]=r;
                if(j==1&&i==((numberOfDays+(startTime.get_dayOfYear()))-365)){break;}
                }

                cout<<"booked"<<endl;
             };

   void print()
             {int kl,ml,jump=0,firstBook=0;
              cout<<"SCHEDULE"<<endl;
              vehicle->print();cout<<endl;
               for(ml=0;ml<2;ml++){
              for(kl=jump;kl<366;kl++)
                  {if(years[ml][kl]!=nullptr)
                     {years[ml][kl]->print();
                      kl=kl+years[ml][kl]->get_days();
                      if(kl>365){jump=kl-365+1;}
                      firstBook=1;
                     }

                  }}
              if(firstBook==0)
                  {
                   cout<<"not booked yet!"<<endl;
                  }

              };

 };



    int main(){

       Vehicle *v1=new Scooter(" BMW C 650 GT","Du-BC 65");
       Vehicle *v2=new Cabrio("BMW i8 Roadstar","DU-BR 8");
       Vehicle *v3=new Limousine("Mercedes C 350 e","DU-MC 1",129);
       Vehicle *v4=new Limousine("Mercedes E 350 e","DU-ME 2",189,false);
 int i=1,lo;Timepoint h;
       Schedule *cars[5];
       for(lo=0;lo<5;lo++){cars[lo]=nullptr;}
       cars[0]=new Schedule(v1);
       cars[1]=new Schedule(v2);
       cars[2]=new Schedule(v3);
       cars[3]=new Schedule(v4);

 int g=0,k=0,l=0,lop;
 char ans;

 while(i!=0){
  cout<<"VEHICLE RENTAL EGENCY"<<endl;
       cout<<"0 end"<<endl;
       cout<<"1 new rental"<<endl;
       cout<<"2 print rentals"<<endl;
       cin>>g;
       switch(g){
    case 0:i=0;break;
    case 1:
           {cout<<"choose vehicle:"<<endl;
           for(lop=0;lop<4;lop++)
           {cout<<lop+1<<".";cars[lop]->get_vehicle()->print();cout<<endl;}
           cin>>k;
           cout<<"day of rental(dd.mm.yy hh:mm):";
                   Timepoint t;
                   cin>>t;
                   cout<<"number of days:";
                   int day;
                   cin>>day;
                   if(cars[k-1]->isFree(t,day)){
                   cout<<"input data vehicle renter and driver:"<<endl;
                   Driver d(1);
                   cout<<"additional driver (n/y):"; cin>>ans;
                  if(ans=='y')
                  {   cout<<"information of additional driver:"<<endl;
                      Driver *ad=new Driver(1);
                       cars[k-1]->book(t,d,day,ad);
                  }else{
                      cars[k-1]->book(t,d,day);
                       }                 }else{cout<<"this car model has been booked for this period of time"<<endl;}
                       }break;

    case 2:cout<<"choose vehicle:"<<endl;
           for(lop=0;lop<4;lop++)
           {cout<<lop+1<<".";cars[lop]->get_vehicle()->print();cout<<endl;}
           cin>>l;
            switch(l){
             case 1:cars[0]->print();break;
             case 2:cars[1]->print();break;
             case 3:cars[2]->print();break;
             case 4:cars[3]->print();break;}
             break;
       }
 }
    return 0;}
