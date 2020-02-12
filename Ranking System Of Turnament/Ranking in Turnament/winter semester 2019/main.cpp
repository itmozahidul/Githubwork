#include <iostream>
#include<iomanip>
#include<string>
#define M 100

using namespace std;
struct Team {
    string name;
    unsigned int points,done_matches;

};
void ranking(Team* , int);
void display (Team teams[], unsigned int no_teams){
    cout<<"teams: ";
    for(unsigned int i=1;i<=no_teams; i++){
        cout<<endl<<"teams"<< i<<":"<<endl;
        cin>>teams[i-1].name;
        cout<<endl;
        teams[i-1].points=0;
        teams[i-1].done_matches=0;
       }
 ranking(teams,no_teams);
}

  int choose (Team teams[], unsigned int no_teams){
   int p;
   static int callno=0;
   callno=callno+1;
    if(callno%2==0){
         cout<<"choose the seceond team in the match?"<<endl;
    }else{
         cout<<"choose the first team in the match?"<<endl;;
    }

for(unsigned int i=0;i<no_teams; i++){
     cout<<i+1<<"\t"<<teams[i].name<<endl;

    }

cout<<"choose team by number :";
cin>>p;
cout<<"................."<<endl;
  return p-1;

   }

   void rearrange(Team teams[],int n)
{   Team temp;
    int chk=1;

    while(chk){
            chk=0;
        for(int i=0;i<n-1;i++){
        if(teams[i].points<teams[i+1].points)
        {   temp.points=teams[i].points;
            temp.done_matches=teams[i].done_matches;
            temp.name=teams[i].name;

            teams[i].points=teams[i+1].points;
            teams[i].done_matches=teams[i+1].done_matches;
            teams[i].name=teams[i+1].name;

            teams[i+1].points=temp.points;
            teams[i+1].done_matches=temp.done_matches;
            teams[i+1].name=temp.name;
            chk=1;
        }
    }

    }

}

void addscore(Team teams[], unsigned int no_teams,int a, int point){
 teams[a].points=teams[a].points+point;
    teams[a].done_matches=teams[a].done_matches+1;




   }

void addResultOfMatch(Team teams[], unsigned int no_teams)
{
    int team1no,team1point,team2no,team2point,ignr;
    team1no=choose(teams,no_teams);
    team2no=choose(teams,no_teams);
    if(team1no==team2no){cout<<"sorry teams need to be different";}else{
    cout<<"input as [points of "<<teams[team1no].name<<"] : [points of "<<teams[team2no].name<<"]?";
    cin >> team1point;cout<<":";cin >> team2point;

    cout<<endl;
    addscore(teams,no_teams,team1no,team1point);
    addscore(teams,no_teams,team2no,team2point);
    rearrange(teams,no_teams);
                                                                        }
}

void ranking(Team teams[], int no_teams)
{
    cout<<"ranking"<<endl<<"======="<<endl<<"points \t done matches  \t  name"<<endl;

 for(int i=0;i<no_teams;i++){
        cout<<teams[i].points<<"\t"<<teams[i].done_matches<<"\t"<<teams[i].name<<endl;
        }

}
void resett(Team teams[], int no_teams){

for( int i=1;i<=no_teams; i++){

        teams[i-1].points=0;
        teams[i-1].done_matches=0;
       }
       ranking(teams,no_teams);
}

int main(){



Team t[M];
int i,loop=1,numb;
cout<<"nuber of teams :";
cin>>numb;
display(t,numb);
while(loop)
{
  cout<<"0 end"<<endl;
cout<<"1 add result of a match"<<endl;
cout<<"2 show ranking"<<endl;
cout<<"9 reset points"<<endl;
cout<<"your choice:";cin>>i;cout<<endl;
switch(i){
case 1:addResultOfMatch(t,numb);break;
case 2:ranking(t,numb);break;
case 9:resett(t,numb);break;
case 0:loop=0;break;
}
}
return 0;
}
