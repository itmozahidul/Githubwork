/*************************************************
Aufgabe Nr./Task No.: H2
Nachname/Last,Family Name: Islam
Vorname/First,Given Name: Mozahidul
Matrikelnummer/Matriculation number: 3022958
Uni-Email: mozahidul.islam@stud.uni-due.de
Studiengang/Course of Studies: ISE CE
*************************************************/











#include<iostream>
#include<fstream>

using namespace std;
#define M 50



struct info{
double tem;
int date;
int month;

};



void read( string file_name, double store[M][M]){

char c,tempc;
int gate=0,gate2=1,arry2,day=0,month=0;
double sign_of_result=1,result,counter2,sum,sum2,num2[5];
ifstream i;

i.open(file_name.c_str());


if(!i.is_open())
    {cout<<"error";}
else
    {
     cout << "input file " <<file_name<< " opened" << endl;
      while (! i.eof())
      {
                c=i.get();

                if(c==';'){gate=1;}
                if(c=='\n')
                {
                    gate=0;
                gate2=1;

                store[month][day]=result*sign_of_result;
                sign_of_result=sign_of_result*sign_of_result;

                day++;c=i.get();

                if(c=='0')
                {   c=i.get();
                    if(c=='1')
                    {day=0;
                    month++;}
                }

                }
                if(gate==1)
                    {  if(c!='-')
                        {if(c!=';'){
                        if(c=='.'){gate2=0;}

                        if(gate2==1)
                            {
                            tempc=c;
                            double C=tempc-'0';
                            sum=((sum*10)+((C*10)/10));

                            }
                        if(gate2==0)
                            {if(c!='.'){
                                tempc=c;
                                double C2=tempc-'0';
                            counter2=(counter2/10);
                            num2[arry2]=(C2*(counter2));
                             sum2=sum2+num2[arry2];
                             result=sum+sum2;
                            }}

                    }
                    }else
                    {
                    sign_of_result=-1;
                    }
                    }
                    if(gate==0){

                      sum=0;
                      counter2=1;
                      arry2=0;
                      sum2=0;
                    }
    }}

}

info mini(double a[M][M]){
int i,j,k,m,stop;
info minimum;

for(k=0;k<12;k++){
    for(m=0;m<31;m++)
        {
        for(i=0;i<12;i++)
           {
           for(j=0;j<31;j++)
              {
              if(a[k][m]<a[i][j])
                {
                 stop=0;
                }
              if(a[k][m]>a[i][j])
                {
                     stop=1;break;
                }
              }if(stop==1)
                 {break;}

           } if(stop==0)
               {
                minimum.date=m;minimum.month=k;minimum.tem=a[k][m];
                break;
                }
        } if(stop==0)
            {
             break;
            }

    }
return minimum;}



double avarage(double a[M][M]){
int k,m;
double sum=0,counter=0,avg;
for(k=0;k<12;k++){
    for(m=0;m<31;m++)
        {
            sum=sum+a[k][m];
            if(a[k][m]!=0){counter++;}


        }
                 }
   avg=(sum/counter);

return avg;}



info maxi(double a[M][M]){
int i,j,k,m,stop;
info minimum;

for(k=0;k<12;k++){
    for(m=0;m<31;m++)
        {
        for(i=0;i<12;i++)
           {
           for(j=0;j<31;j++)
              {
              if(a[k][m]>a[i][j])
                {
                 stop=0;
                }
              if(a[k][m]<a[i][j])
                {
                     stop=1;break;
                }
              }if(stop==1)
                 {break;}

           } if(stop==0)
               {
                minimum.date=m;minimum.month=k;minimum.tem=a[k][m];
                break;
                }
        } if(stop==0)
            {
             break;
            }

    }
return minimum;}

void open_html_file(string name, double x[M][M]){

int i,j,k=0,e=0,y=0,gate=0;
char c,html_name[M],year[M];
char html_ending[]="html";
while(name[e]!='\0')
{
    c=name[e];
    if(c=='-'){gate=1;html_name[e]=c;}
    if(c=='.'){gate=2;html_name[e]=c;}
    if(gate==1 && c!='-'){year[y]=c;y++;html_name[e]=c;}

   if(gate==2 && c!='.'){html_name[e]=html_ending[k];k++;}
   if(gate==0){html_name[e]=c;}
   e++;
}
year[y]='\0';

info minimum,maximum;
ofstream h;
h.open(html_name);
cout<<"opening...."<<endl;

minimum=mini(x);
maximum=maxi(x);
   h<<"<!DOCTYPE html>"<<endl;
h<<"<html>"<<endl;
h<<"<head>"<<endl;h<<""<<endl;
h<<"<title>Mean Temperatures "<<year<<"</title>"<<endl;
h<<"<style>"<<endl;
h<<"table {"<<endl;
 h<<"width: 100%;"<<endl;
h<<"}"<<endl;
h<<"th, td {"<<endl;
 h<<"border: 1px solid black;"<<endl;
  h<<"text-align: center;"<<endl;
h<<"}"<<endl;
h<<"tr:nth-child(even) {"<<endl;
 h<<"background-color: #f2f2f2;"<<endl;
h<<"}"<<endl;
h<<"</style>"<<endl;
h<<"</head>"<<endl;
h<<"<body>"<<endl;
h<<"<h1>Mean Temperatures"<<year<<"(Unit Degree Celsius)</h1>"<<endl;
h<<"<table>"<<endl;
h<<"<tr><th> </th><th>JAN</th><th>FEB</th><th>MAR</th><th>APR</th><th>MAY</th><th>JUN</th><th>JUL</th><th>AUG</th><th>SEPT</th><th>OCT</th><th>NOV</th><th>DEC</th></tr>"<<endl;

for(i=0;i<31;i++){h<<"<tr><td>"<<i+1<<"</td>";
    for(j=0;j<12;j++){

h<<"<td>";
 if(x[j][i]!=0){h<<x[j][i];}
h<<"</td>";

    }
    h<<"</tr>";
}

h<<"</table>"<<endl;
h<<"<p>Minimum Temperature: "<<minimum.tem<<" ("<<minimum.date+1 <<"."<<minimum.month+1<<".)</p>"<<endl;
h<<"<p>Maximum Temperature: "<<maximum.tem<<" ("<<maximum.date+1 <<"."<<maximum.month+1<<".)</p>"<<endl;

h<<"<p>Average Temperature: "<<avarage(x)<<"</p>"<<endl;
h<<"</body>"<<endl;
h<<"</html>"<<endl;


}

int main(){
string name="C:\\Users\\PC\\Downloads\\duisburg-2017.csv";
double x[M][M];


read(name,x);
cout<<"reading...."<<endl<<"opening html file..."<<endl;
open_html_file(name,x);
cout<<"finished";
return 0;}


