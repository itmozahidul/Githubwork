
#include <iostream>
#include<iomanip>

using namespace std;

struct fractionlist{                 /*task 1*/
    double n;
    fractionlist* next;

};
double continuedfraction(fractionlist* f,double k)       /*task 2*/
{   double d;
    f->next->n=k;
    d=f->n+(1/k);
    return d ;
}

fractionlist* deletcontinuedfraction(fractionlist* f)        /*task 3*/
{   fractionlist* vanish;
    cout<<"delete ";
    while(f!=NULL)
    { if(f->n!=0){cout<<f->n<<" ";}
      vanish=f->next;
     f=f->next;
    }

return vanish;}

double continuedfractionvalue(fractionlist* f)          /*task 4*/
{
     double v;
     if(f!=NULL)
    {
      v=f->n+(1/continuedfractionvalue(f->next));
    }
return v;}

fractionlist* addonthelist(fractionlist* head ,double k)/*this function helps to put value in the list*/
 { fractionlist* f;
 fractionlist* last;
     f= new fractionlist;
     if(f==NULL){cout<<"no memory";}
     else{
            f->n=k;

         if(head==NULL)
   {  f->next=head;
      head=f;

   }else
   {
       last=head;
      while(last->next!=NULL)
       {
           last=last->next;
       }
       f->next=NULL;
       last->next=f;


   }
     }


return head; }
void printfractionlist(fractionlist* temp)/*this function hepls to see my inputs*/
{   int umm;
    if(temp!=NULL)
    { umm=0;
 cout<<"the fraction list [";
    while(temp->next!=NULL)
    {   cout<<temp->n;
    if(temp->next->next!=NULL)
        {
            if(umm==1)
                {
                    cout<<",";
                }
                if(umm==0)
                {cout<<";";}
       }
        temp=temp->next;
        umm=1;
    }
    cout << "]" << endl;
}else
    {
        cout<<"empty"<<endl;
    }
}
fractionlist* makecontinuedfractionvalue()          /*task 5*/
{
    fractionlist* temp=NULL;
    double l,m=1,banana;
    cout<<"continued fraction , enter first value f_0:";
    cin>>banana;cout<<endl;

   temp=addonthelist(temp,banana);
    while(l>0)
    {   cout<<"enter next part denominator f_"<<m<<" (<=0 for end): ";
        cin>>l;

        temp=addonthelist(temp,l);
        m++;
    }


  return temp;
  }


int main()                                                      /*task 6*/
{   fractionlist *cf1=NULL,*cf2=NULL,*cf3=NULL,*busket1,*busket2;
    int stop=1;
    while(stop==1){double cf1baby[]={0,7,1,2,4,1},cf2baby[]={0,3,2,1,1};

    for(int lala=0;lala<6;lala++){busket1=new fractionlist;busket1->n=cf1baby[lala];busket1->next=cf1;cf1=busket1;}
    for(int lala=0;lala<5;lala++){busket2=new fractionlist;busket2->n=cf2baby[lala];busket2->next=cf2;cf2=busket2;}


     cout<<"cf1 = 123/100 = "<<setprecision(3)<<continuedfractionvalue(cf1)<<endl;
    cf1=deletcontinuedfraction(cf1);cout<<endl;
    cout<<"cf2 = 17/10 = "<<setprecision(3)<<continuedfractionvalue(cf2)<<endl;
     cf2=deletcontinuedfraction(cf2);cout<<endl;
    cf3= makecontinuedfractionvalue();
    printfractionlist(cf3);
    cout<<"value inputted continued fraction cf3 = "<<setprecision(16)<<continuedfractionvalue(cf3);cout<<endl;
    cf3=deletcontinuedfraction(cf3);


    cout<<endl;
    cout<<"to end the program enter 0 to continue 1";
    cin>>stop;
}
return 0;
}
