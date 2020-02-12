#include <iostream>
using namespace std;

enum time_zone{
ACT,CET,CST,EST,GMT,MSK,PST
};
enum status{arrival,departure};

class LocalTime{
private:
    int minutes;
    time_zone timezone;
public:
    LocalTime()
    {
        minutes=-1;
        timezone=CET;
    }
    LocalTime(int hour,int minute,time_zone t=CET)
    {
       set_time(hour,minute);
       timezone=t;
    }
    void set_time(int h,int m)
    {
        minutes=(h*60)+m;
    }
    int get_hour()
    {
        return minutes/60;
    }
    int get_minute()
    {
        return minutes%60;
    }
    bool is_valid()
    {
        if(minutes<0)
        {
            return false;
        }else
        {
            return true;
        }
    }

};

ostream &operator<<(ostream &out,LocalTime &localtime)
{  if(localtime.is_valid())
{   if(((localtime.get_hour())/10)==0)
{
     out<<"0"<<localtime.get_hour();
}else{out<<localtime.get_hour();}

    out<<":";
    if(((localtime.get_minute())/10)==0)
{
     out<<"0"<<localtime.get_minute();
}else{out<<localtime.get_minute();}
out<<"   ";}
else{out<<"        ";}

    return out;
}
class Flight{

private:
    status arraivalOrdeparture;
    string code;
    string destination;
    string gate;
    string checkIn;
    string comment;
    LocalTime expected;
public:
    Flight(status a,string b,string c,string d,string e);
    ~Flight();
    string get_code();

    string get_destination();

    string get_gate();

    string get_checkIn();

    string get_comment();

    LocalTime get_scheduled();

    void set_expected(LocalTime a);

    void set_comment(string a);

    bool is_arraival();

       bool is_departure();

    void print(LocalTime t);
};
Flight::Flight(status a,string b,string c,string d,string e="")
    {
        arraivalOrdeparture=a;
        code=b;
        destination=c;
        gate=d;
        checkIn=e;comment="";
    }
Flight::~Flight()
    {cout<<code;}
string Flight::get_code()
    {
      return code;
    }
     string Flight::get_destination()
    {
      return destination;
    }

void Flight::print(LocalTime t)
{
    cout<<code<<"\t"<<destination<<"\t\t\t"<<t<<"\t"<<expected<<"\t"<<gate<<"\t"<<checkIn<<" \t"<<comment;

}
string Flight::get_gate()
    {
      return gate;
    }
string Flight::get_checkIn()
    {
      return checkIn;
    }
string Flight::get_comment()
    {
      return comment;
    }
LocalTime Flight::get_scheduled()
    {
      return expected;
    }
void Flight::set_expected(LocalTime a)
    {
        expected=a;
    }
void Flight::set_comment(string a)
    {
        comment=a;
    }
bool Flight::is_arraival()
    {
      if(arraivalOrdeparture==arrival)
        {
            return true;
        }else
        {
            return false;
        }
    }
bool Flight::is_departure()
    {
      if(arraivalOrdeparture==departure)
        {
            return true;
        }else
        {
            return false;
        }
    }
class Airport{
private:
    string name;
    Flight* slot[24][60];

public:
     Airport(string a)
     {name=a;
     int i,j;
      for(i=0;i<24;i++)
             {
                 for(j=0;j<60;j++)
                 {

                          slot[i][j]=nullptr;

                  }
             }
     }
     ~Airport(){
      int i,j;
      for(i=0;i<24;i++)
             {
                 for(j=0;j<60;j++)
                 {
                     if(slot[i][j]!=nullptr)
                       {
                          delete slot[i][j];cout<<" deleted"<<endl;
                       }
                  }
             }

     }



     void schedule(LocalTime a,Flight* b)
     {
         slot[a.get_hour()][a.get_minute()]=b;
     }
     void comment(LocalTime a,string b)
     {
         slot[a.get_hour()][a.get_minute()]->set_comment(b);
     }
     void delay(LocalTime a,LocalTime b)
     {
         slot[a.get_hour()][a.get_minute()]->set_expected(b);
     }
     void print(status a)
     {    int i,j;
     LocalTime t;
         if(a==arrival)
         {
             cout<<name<<" Airport Arrivals"<<endl;
             cout<<"=================================="<<endl;
             cout<<"Flight\tFrom\t\t\t\tScheduled\tExpected\tgate\tCheck-In\tComment"<<endl;

             for(i=0;i<24;i++)
             {
                 for(j=0;j<60;j++)
                 {
                     if(slot[i][j]!=nullptr && slot[i][j]->is_arraival())
                     {   t.set_time(i,j);
                         slot[i][j]->print(t);cout<<endl;

                     }
                 }
             }

         }else
            {
             cout<<name<<" Airport Departures"<<endl;
             cout<<"=================================="<<endl;
             cout<<"Flight\tFrom\t\t\t\tScheduled\tExpected\tgate\tCheck-In\tComment"<<endl;

             for(i=0;i<24;i++)
             {
                 for(j=0;j<60;j++)
                 {
                     if(slot[i][j]!=nullptr && slot[i][j]->is_departure())
                     {   t.set_time(i,j);
                         slot[i][j]->print(t);cout<<endl;

                     }
                 }
             }

            }

     }
};

int main()
{
    Airport DusseldorfAirport("Duesseldorf");
    Flight* Af1=new Flight(arrival,"LH 2010","Munich    ","A04");
    Flight* Af2=new Flight(arrival,"EW 9347","Manchester","B04");

    Flight* Df1=new Flight(departure,"AF 1307","Paris          ","B51","192-194");
    Flight* Df2=new Flight(departure,"SU 2637","Moscow         ","C31","252-255");
    Flight* Df3=new Flight(departure,"EW 9466","London-Heathrow","B35","151-170");
    Flight* Df4=new Flight(departure,"LH 2011","Munich         ","A40","115-120");
    Flight* Df5=new Flight(departure,"XQ 959", "Izmir          ","C45","240-242");

    LocalTime t1(12,40);
    LocalTime t2(14,50);
    LocalTime t3(9,10);
    LocalTime t4(10,40);
    LocalTime t5(11,15);
    LocalTime t6(13,25);
    LocalTime t7(14,55);

    LocalTime e1(13,5);
    LocalTime e2(15,20);

   DusseldorfAirport.schedule(t1,Af1);
   DusseldorfAirport.schedule(t2,Af2);

   DusseldorfAirport.schedule(t3,Df1);
   DusseldorfAirport.schedule(t4,Df2);
   DusseldorfAirport.schedule(t5,Df3);
   DusseldorfAirport.schedule(t6,Df4);
   DusseldorfAirport.schedule(t7,Df5);

   DusseldorfAirport.delay(t1,e1);
   DusseldorfAirport.delay(t7,e2);

   DusseldorfAirport.comment(t3,"departed");
   DusseldorfAirport.comment(t4,"boarding");
   DusseldorfAirport.comment(t6,"Code Sharing");



   DusseldorfAirport.print(arrival);

   DusseldorfAirport.print(departure);

return 0;
}





