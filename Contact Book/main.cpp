#include <iostream>

using namespace std;

 enum tpn{home,work,fax,mobile,other};

    struct contact {

    string name;
    string number;
    tpn type;
    };
    int cn=100,acn=0;
    contact pblist[100];

    bool addcdata(){
        contact data,tem;

        char t;
        bool ans,correct=false;
        int n=0;
    cout<<"enter the contact info"<<endl;
    cout<<"name :";
    cin.ignore(1);
   getline(cin,data.name); cout<<endl;

    cout<<"number :";
    cin>>data.number; cout<<endl;
    while(correct!=true){
            correct=true;
     cout<<"type of number(f for fax,h for home,m for mobile,w for work,o for other) :";
    cin>>t; cout<<endl;

     switch(t){
        case 'f':data.type=fax;break;
        case 'h':data.type=home;break;
        case 'm':data.type=mobile;break;
        case 'w':data.type=work;break;
        case 'o':data.type=other;break;
        default :cout<<"not correct type"<<endl;correct=false;break;
        }}
    if(acn<cn){
        n=acn;
        pblist[n].name=data.name;
        pblist[n].number=data.number;
        pblist[n].type=data.type;
        if(n!=0){


                 while(n!=0)
               {
                 if(data.name[0]<pblist[n-1].name[0])
                    {n--;
                     tem.name=pblist[n].name;
                     tem.number=pblist[n].number;
                     tem.type=pblist[n].type;
                     pblist[n].name= pblist[n+1].name;
                     pblist[n].number= pblist[n+1].number;
                     pblist[n].type= pblist[n+1].type;
                     pblist[n+1].name=tem.name;
                     pblist[n+1].number=tem.number;
                     pblist[n+1].type=tem.type;

                    }
                 else{break;}
               }


        }



       acn++;
       ans=true;
    }else{
    ans=false;
    cout<<"no place in the contact book!!!";}

   return ans; }

   bool deletcdata(){
   string x;
   int n=0;
   bool ans=false;
   if(acn!=0){
   cout<<"please enter a name to delet:";
   cin.ignore(1);
   getline(cin,x);
   while(n!=acn)
   {
       if(x==pblist[n].name){

        while(n!=(acn-1)){
            pblist[n].name=pblist[n+1].name;
        pblist[n].number= pblist[n+1].number;
         pblist[n].type=pblist[n+1].type;
         n++;
        }
        acn--;
        ans=true;
       break;}

       n++;

   }}else{cout<<"empty list!"<<endl;}

  return ans; }
  ostream& operator<<(ostream& out,tpn x)
  {
    switch(x){
        case fax:out<<"(fax)";break;
        case home:out<<"(home)";break;
        case mobile:out<<"(mobile)";break;
        case work:out<<"(work)";break;
        case other:out<<"(other)";break;
        default :cout<<"    ";break;
        }
 return out; }

  void printcdata(){
  int n=0;
  while(n!=acn){

    cout<<pblist[n].name<<"    "<<pblist[n].number<<"       "<<pblist[n].type<<endl;
  n++;}
  }


int main()
{
  int c;
  bool a=true;
  while(a){
cout<<"choose an option and enter the number "<<endl;
cout<<"1. add contact data on the list"<<endl;
cout<<"2. print the contact list"<<endl;
cout<<"3. delet an contact from the list"<<endl;
cout<<"4. to erease all data from the list"<<endl;
cout<<"5. to end the programm"<<endl;
cin>>c;
switch(c){
case 1: if(addcdata()){cout<<"data added"<<endl;}else{cout<<"data failed to add"<<endl;};break;
case 2: printcdata();break;
case 3: if(deletcdata()){cout<<"data deleted"<<endl;}else{cout<<"data failed to deleted"<<endl;};break;
case 4: acn=0;break;
case 5: a=false;break;
default:cout<<"choose the right option"<<endl;
}
cout<<"*"<<acn<<" contact entries***"<<endl;
}




    return 0;
}
