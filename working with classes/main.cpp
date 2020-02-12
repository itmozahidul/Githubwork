
/*************************************************
Aufgabe Nr./Task No.: H3
Nachname/Last,Family Name: Islam
Vorname/First,Given Name: Mozahidul
Matrikelnummer/Matriculation number: 3022958
Uni-Email: mozahidul.islam@stud.uni-due.de
Studiengang/Course of Studies: ISE CE
*************************************************/




#include <iostream>
#include<string>
using namespace std;

class Duration{
private:
    int sec;
    Duration(int);
public:
    Duration (){
    sec=0;};
    Duration(int,int);
   friend ostream&operator<<(ostream&,Duration&);
   friend int operator<=(Duration&,Duration&);
   friend Duration operator+(Duration&,Duration&);
};

Duration::Duration(int t):sec(t){};
Duration::Duration(int m,int s)
{

    sec=((60*m)+s);
}
ostream& operator<<(ostream& out,Duration& s){
    if(((s.sec/60)/10)==0)
        {out<<"0";}
    out<<(s.sec/60);
    out<<":";
    if(((s.sec%60)/10)==0)
    {out<<"0";}
    cout<<(s.sec%60);
return out;}
int operator<=(Duration &a,Duration &b)
{

int i;
if(a.sec<=b.sec)
     {i=1;}
else
    {i=0;}
 return i;
}

Duration operator+(Duration& a,Duration& b)
{   Duration sum;
    sum.sec=a.sec+b.sec;
    return sum;
}


const static Duration zero(0,0);
static Duration standard(1,30);





class Correspondent
{

private:
    string name,
          country;
     const static int maxCorrespondents=200;
     static int numberOfcorrespondents;
     static Correspondent *correspondent[maxCorrespondents];
public:
    Correspondent();
    Correspondent(string a,string b)
    {
    name=b;
    country=a;
    }

friend ostream& operator<<(ostream& out,Correspondent& c)
    {
      out<<"("<<c.country<<")-"<<c.name<<endl;
      return out;
    }

static Correspondent* get_correspondent(string );

static void new_correspondent(string a,string b)
    {
    Correspondent *p=new Correspondent(a,b);
    correspondent[numberOfcorrespondents]=p;
    numberOfcorrespondents++;
    if(numberOfcorrespondents>=maxCorrespondents)
    {
    cout<<"there is no place anymore";
    }
    }
};
Correspondent* Correspondent::get_correspondent(string a)
    {  Correspondent *h;
       int i=0;h=nullptr;
       while(correspondent[i]!=nullptr)
        {
         if(correspondent[i]->country==a)
           {
            h=correspondent[i];break;
           }
         i++;
        }
       return h;
    }
int Correspondent:: numberOfcorrespondents=0;
Correspondent* Correspondent:: correspondent[maxCorrespondents]={nullptr};
Correspondent::Correspondent() {   }

class Item
{
private:
    Duration duration;
    string topic;
    Correspondent *correspondent;
public:
    Item ();
    Item(Duration,string,Correspondent*);
    ~Item(){};
    Duration& get_duration();
    string& get_topic();
    Correspondent get_correspondent();
    void set_duration(Duration);
    void set_topic(string);
    void set_correspondent(Correspondent*);
    void input();

friend ostream& operator<<(ostream& outt,Item& i)
{
 outt<<i.duration;
 if(i.duration<=standard){}else{outt<<"+";}
 outt<<"     "<<i.topic;

 if(i.correspondent!=nullptr)
    {
     outt<<*i.correspondent;
    }
 return outt;
}
};
Item::Item()
{   Duration d(0,0);
    duration=d;
    topic="";
    correspondent=nullptr;
}
Item::Item(Duration d,string s,Correspondent *c)
{
    duration=d;
    topic=s;
    correspondent=c;
}
Duration& Item::get_duration()
{
    return duration;
}
string& Item::get_topic()
{
    return topic;
}
Correspondent Item::get_correspondent()
{
    return *correspondent;
}
void Item::set_duration(Duration d)
{
    duration=d;
}
void Item::set_topic(string a)
{
    topic=a;
}
void Item::set_correspondent(Correspondent *c)
{
    correspondent=c;
}
void Item::input()
{  int m,s;
string ct,t,dot;
   cout<<"Topic:"; getline(cin,t);

cout<<"duration in format mm:ss  ";
    cin>>m;cin.ignore(1,':');cin>>s;
   cout<<"country:";cin.ignore(1,'\n'); getline(cin,ct);
   Correspondent *l;
   l=Correspondent::get_correspondent(ct);
   set_correspondent(l);

   Duration d(m,s);
   set_duration(d);
   set_topic(t);


}
class News
{
private:
    static const int n=3;
    Item first;
    Item news[n];
    Item weather;
    Item* lastMinute;
public:
    News();
    void print();

};
News::News()
{
  cout<<"input first news item"<<endl;
  first.input();
  cout<<"input further news items"<<endl;
  for(int i=0;i<n;i++)
  {
    news[i].input();
  }
    weather.set_topic("weather forecast");
    Duration d(2,0);
    weather.set_duration(d);
    lastMinute=new Item;
    lastMinute->set_topic("end of the year is close");
    lastMinute->set_duration(standard);
}
void News::print()
{

  cout<<"THE NEWS"<<endl;
  cout<<first;
  for(int i=0;i<n;i++)
  {
      cout<<news[i];
      first.get_duration()=first.get_duration()+news[i].get_duration();
  }
  first.get_duration()=first.get_duration()+lastMinute->get_duration();
  first.get_duration()=first.get_duration()+weather.get_duration();
  cout<<*lastMinute<<endl<<weather<<endl<<endl<<"total news duration: "<<first.get_duration();

}


int main()
{Duration d1(2,10),d2(2,00),d3;
d3=d2+d1;
string a,b,c;

cout<<"name of the correspondent for France : ";
getline(cin,a);
Correspondent::new_correspondent("France",a);
cout<<"name of the correspondent for Germany : ";
getline(cin,b);
Correspondent::new_correspondent("Germany",b);
cout<<"name of the correspondent for Great Britain : ";
getline(cin,c);
Correspondent::new_correspondent("Great Britain",c);

News evening;
evening.print();

    return 0;
}
