#include <iostream>

using namespace std;

class Time
{
private:
    int minuteOfday;
public:
    Time(){minuteOfday=0;}
    Time(unsigned int t){
        if(t>1440){t=0;}else{minuteOfday=t;}
                        }
    Time(int,int);
   void set_time(int hour,int minute)
    {
       if(hour>=24 || minute>=60)
       {
           cout<<"wrong time input"<<endl;
           minuteOfday=0;
       }
       else
       {
           minuteOfday=(hour*60)+minute;
       }
    }
    int get_hour()
    {
        return minuteOfday/60;
    }
    int get_minute()
    {
        return minuteOfday%60;
    }
   Time operator+(int x)
   {
      Time t;
      if((minuteOfday+x)<1440)
      {
          t.minuteOfday=minuteOfday+x;
      }
      else
      {
          t.minuteOfday=((minuteOfday+x)-1440);
      }

  return t; }

};

Time::Time(int hour,int minute)
{
    set_time(hour,minute);

}
istream& operator>>(istream &in, Time &t)
{ int x,y;
    in>>x;
    in.ignore(1,':');
    in>>y;
   t.set_time(x,y);
return in;}
ostream& operator<<(ostream &out,Time &t)
{

    if(t.get_hour()==0)
              {
                  out<<"00";
              }
              else
              {
                  if(t.get_hour()/10==0)
                  {
                      out<<"0"<<t.get_hour();
                  }
                  else
                  {
                      out<<t.get_hour();
                  }
              }
               if(t.get_minute()==0)
              {
                  out<<":00";
              }
              else
              {
                  if(t.get_minute()/10==0)
                  {
                      out<<":0"<<t.get_minute();
                  }
                  else
                  {
                      out<<":"<<t.get_minute();
                  }
              }
return out;}

class Train
{
private:
    string no;
    string to;
    string over;
public:
    Train(){};
    Train(string,string,string);
    ~Train();
    string get_no();
    string get_to();
    string get_over();
};
Train::Train(string a, string b, string c):no(a),to(b),over(c){}
string Train::get_to()
{
    return to;
}
Train::~Train()
{
    cout<<no<<" to "<<to;
}
string Train::get_no()
{
    return no;
}
string Train::get_over()
{
    return over;
}
class Station
{
private:
    const string station;
    const unsigned int platforms=15;
    Train* schedule[1440][15];
public:
    Station(){};
    Station(string s):station(s)
    {   int i,j;

        for(i=0;i<1440;i++)
        {
            for(j=0;j<=15;j++)
            {
                schedule[i][j]=nullptr;
            }
        }
    }
    ~Station()
    {
        int i,j;

        for(i=0;i<1440;i++)
        {
            for(j=1;j<=15;j++)
            {   if(schedule[i][j]!=nullptr)
            {
              Time t(i);
              cout<<t;
              cout<<"  platform"<<j<<":  train  ";
              delete schedule[i][j];
                schedule[i][j]=nullptr;
                cout<<" deleted"<<endl;
            }

            }
        }
        cout<<"schedeul for DUISBURG MAIN TRAIN STATION has been completly deleted"<<endl;
    }
void addDeparture(Time t,int p,Train* tr)
{ int x;


x=((t.get_hour()*60)+t.get_minute());
if(schedule[x][p]==nullptr)
{
   schedule[x][p]=tr;
}
else
{
    cout<<"it is not possible"<<endl;
}


}
void showDeparture(Time from ,int till)
{
    int i,j;
    Time temp;
    temp=from+till;

    cout<<"DUISBURG MAIN TRAIN STATION"<<endl;
              cout<<"Departures "<<from<<"-"<<temp<<endl;
              cout<<"==========================================="<<endl;
              cout<<"Time   Ttrain               over                          to            platform"<<endl;
    if( ((from.get_hour()*60)+from.get_minute())<=(temp.get_hour()*60+temp.get_minute()))
    {
        for (i=((from.get_hour()*60)+from.get_minute());i<=((temp.get_hour()*60)+temp.get_minute());i++)
    {
       for(j=0;j<=15;j++)
       {
          if(schedule[i][j]!=nullptr)
          {
              Time t(i);
              cout<<t<<"  "<<schedule[i][j]->get_no()<<"    "<<schedule[i][j]->get_over()<<"    "<<schedule[i][j]->get_to()<<"       "<<j<<endl;
          }
       }
    }
    }else
    {
        for (i=((from.get_hour()*60)+from.get_minute());i<1440;i++)
        {
             for(j=0;j<=15;j++)
       {
          if(schedule[i][j]!=nullptr)
          {
              Time t(i);
              cout<<t<<"  "<<schedule[i][j]->get_no()<<"    "<<schedule[i][j]->get_over()<<"    "<<schedule[i][j]->get_to()<<"       "<<j<<endl;
          }
       }
        }
        for (i=0;i<=((temp.get_hour()*60)+temp.get_minute());i++)
        {
             for(j=0;j<=15;j++)
       {
          if(schedule[i][j]!=nullptr)
          {
              Time t(i);
              cout<<t<<"  "<<schedule[i][j]->get_no()<<"    "<<schedule[i][j]->get_over()<<"    "<<schedule[i][j]->get_to()<<"       "<<j<<endl;
          }
       }
        }
    }

}
};

int main()
{
    Station s("duisburg");
    int i;
    for(i=7;i<1440;i=i+20)
    {
      Time t(i);
      Train* tr=new Train("s1","Dortmund Hbf","Muelheim(Ruhr)Styrum - Muelheim(Ruhr) - Essen.");
      s.addDeparture(t,9,tr);
    }
    for(i=15;i<1440;i=i+20)
    {
      Time t(i);
      Train* tr_1=new Train("s1","solingen Hbf","Duisburg-Schlenk - Duesseldorf Flughafen.");
      s.addDeparture(t,5,tr_1);
    }
      for(i=35;i<1440;i=i+60)
    {
      Time t(i);
      Train* tr_2=new Train("s2","Dortmund Hbf","Oberhausen - Gelsenkirchen - Wanne-Eickel.");
      s.addDeparture(t,2,tr_2);
    }
       for(i=22;i<1440;i=i+60)
    {
      Time t(i);
      Train* tr_3=new Train("RE1","Aachen Hbf","Duesseldorf Flughafen - Duesseldorf - Koeln.");
      s.addDeparture(t,4,tr_3);
    }
        for(i=24;i<1440;i=i+60)
    {
      Time t(i);
      Train* tr_4=new Train("RE2","Muenstar","Muelheim(Ruhr) - Essen - Gelsenkirchen.");
      s.addDeparture(t,10,tr_4);
    }
    int n,m=1;
    while(m!=0){
    cout<<"0 end"<<endl<<"1 schedule train"<<endl<<"2 show schedule"<<endl;

    Time ti;int till;string a,b,c;cout<<">>";cin >>n;
    switch(n)
    {
    case 0:  m=0;break;
    case 1:{cout<<"time of departure(hh:mm) : ";cin>>ti;cout<<endl;
           cout<<"platform? ";cin>>till;cout<<endl;
           cout<<"train? ";cin>>a;cout<<endl;
           cout<<"to? ";cin>>b;cout<<endl;
           cout<<"over? ";cin.ignore(1);getline(cin,c);cout<<endl;
           Train* train=new Train(a,b,c);
           s.addDeparture(ti,till,train);break;}

    case 2:{ cout<<"show separture starting at:";cin>>ti;cout<<endl;
           cout<<"for how many next minutes?";cin>>till;cout<<endl;
           s.showDeparture(ti,till);break;
           }


     default: cout<<"wrong input"<<endl;break;
    }
    }

    return 0;
}
