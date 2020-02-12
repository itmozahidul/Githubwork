/*************************************************
Aufgabe Nr./Task No.: H1
Nachname/Last,Family Name: Islam
Vorname/First,Given Name: Mozahidul
Matrikelnummer/Matriculation number: 3022958
Uni-Email: mozahidul.islam@stud.uni-due.de
Studiengang/Course of Studies: ISE CE
*************************************************/







#include<iostream>
 using namespace std;

 struct polynumber{
        double pc;/**polynomial coefficients**/
        int degree;
        polynumber *next;
 };

void output(polynumber*);

polynumber* listofgetpolynumber(polynumber* head ,int d){
polynumber *newelement,*last;
newelement = new polynumber;
 if(newelement==NULL){
        cout<<"no memory"<<endl;
 }else{
     cin>>newelement->pc;
     newelement->degree=d;
     cout<<endl;
     if (head == NULL)
   {
      newelement->next = NULL;
      head = newelement;
   }
   else
   {
      last = head;
      while (last->next != NULL)
         {last = last->next;}
      newelement->next = NULL;
      last->next = newelement;
   }

 }

return head;}

 int degreecounter(polynumber* p){
int i=0;
do{
    if(p->next==NULL){break;}
    i++;
    p=p->next;
}while(p->next!=NULL);

return i;}


polynumber* inputcoefficient(){
      int d,i;
      polynumber *head=NULL;

      cout<<"enter the degree of polynomial:";
    cin>>d;
      for(i=d;i>=0;i--){
     cout<<"coefficient a_"<<i<<":";
     head=listofgetpolynumber(head,i);

     }
return head;}

polynumber* polyplus(polynumber *a,polynumber *b,polynumber *head){
int i,j,k;
polynumber *c,*last1,*last2,*temp1,*temp2,*head1=NULL,*head2=NULL;
if(degreecounter(a)>=degreecounter(b)){i=degreecounter(a);}else{i=degreecounter(b);}
last1=a;
while(last1!=NULL)
{ temp1=new polynumber;
    temp1->pc=last1->pc;
    temp1->degree=last1->degree;
    temp1->next=head1;
    head1=temp1;
    last1=last1->next;
}
last2=b;
while(last2!=NULL)
{ temp2=new polynumber;
    temp2->pc=last2->pc;
    temp2->degree=last2->degree;
    temp2->next=head2;
    head2=temp2;
    last2=last2->next;
}

for(j=0;j<=i;j++){c=new polynumber;
                  c->pc=head1->pc+head2->pc;cout<<"before check head2pc"<<head2->pc<<"  cpc"<<c->pc<<endl;
                  c->degree=head1->degree;
                  c->next=head;
                  head=c;
                  if(head1->next==NULL){for(k=j+1;k<=i;k++){c=new polynumber;head2=head2->next;c->pc=head2->pc;c->degree=head2->degree;c->next=head;head=c;}break;}
                  if(head2->next==NULL){for(k=j+1;k<=i;k++){c=new polynumber;head1=head1->next;c->pc=head1->pc;c->degree=head1->degree;c->next=head;head=c;}break;}
                  head1=head1->next;
                  head2=head2->next;

                 }

                 output(head);


 output(head);
return head;}


void output(polynumber* p){
int i,d;

d=degreecounter(p);
for(i=d;i>=0;i--){
        if(p->pc!=0){if(i==0){cout<<p->pc;}else{
    cout<<p->pc<<"x"<<"^"<<i;}}
    p=p->n/*************************************************
Aufgabe Nr./Task No.: H1
Nachname/Last,Family Name: Islam
Vorname/First,Given Name: Mozahidul
Matrikelnummer/Matriculation number: 3022958
Uni-Email: mozahidul.islam@stud.uni-due.de
Studiengang/Course of Studies: ISE CE
*************************************************/







#include<iostream>
 using namespace std;

 struct polynumber{
        double pc;/**polynomial coefficients**/
        int degree;
        polynumber *next;
 };

void output(polynumber*);

polynumber* listofgetpolynumber(polynumber* head ,int d){
polynumber *newelement,*last;
newelement = new polynumber;
 if(newelement==NULL){
        cout<<"no memory"<<endl;
 }else{
     cin>>newelement->pc;
     newelement->degree=d;
     cout<<endl;
     if (head == NULL)
   {
      newelement->next = NULL;
      head = newelement;
   }
   else
   {
      last = head;
      while (last->next != NULL)
         {last = last->next;}
      newelement->next = NULL;
      last->next = newelement;
   }

 }

return head;}

 int degreecounter(polynumber* p){
int i=0;
do{
    if(p->next==NULL){break;}
    i++;
    p=p->next;
}while(p->next!=NULL);

return i;}


polynumber* inputcoefficient(){
      int d,i;
      polynumber *head=NULL;

      cout<<"enter the degree of polynomial:";
    cin>>d;
      for(i=d;i>=0;i--){
     cout<<"coefficient a_"<<i<<":";
     head=listofgetpolynumber(head,i);

     }
return head;}

polynumber* polyplus(polynumber *a,polynumber *b,polynumber *head){
int i,j,k;
polynumber *c,*last1,*last2,*temp1,*temp2,*head1=NULL,*head2=NULL;
if(degreecounter(a)>=degreecounter(b)){i=degreecounter(a);}else{i=degreecounter(b);}
last1=a;
while(last1!=NULL)
{ temp1=new polynumber;
    temp1->pc=last1->pc;
    temp1->degree=last1->degree;
    temp1->next=head1;
    head1=temp1;
    last1=last1->next;
}
last2=b;
while(last2!=NULL)
{ temp2=new polynumber;
    temp2->pc=last2->pc;
    temp2->degree=last2->degree;
    temp2->next=head2;
    head2=temp2;
    last2=last2->next;
}

for(j=0;j<=i;j++){c=new polynumber;
                  c->pc=head1->pc+head2->pc;cout<<"before check head2pc"<<head2->pc<<"  cpc"<<c->pc<<endl;
                  c->degree=head1->degree;
                  c->next=head;
                  head=c;
                  if(head1->next==NULL){for(k=j+1;k<=i;k++){c=new polynumber;head2=head2->next;c->pc=head2->pc;c->degree=head2->degree;c->next=head;head=c;}break;}
                  if(head2->next==NULL){for(k=j+1;k<=i;k++){c=new polynumber;head1=head1->next;c->pc=head1->pc;c->degree=head1->degree;c->next=head;head=c;}break;}
                  head1=head1->next;
                  head2=head2->next;

                 }

                 output(head);


 output(head);
return head;}


void output(polynumber* p){
int i,d;

d=degreecounter(p);
for(i=d;i>=0;i--){
        if(p->pc!=0){if(i==0){cout<<p->pc;}else{
    cout<<p->pc<<"x"<<"^"<<i;}}
    p=p->next;
if(i==0){cout<<".";}else{
if(p->pc>0){cout<<"+";}else{cout<<"";}}

}
cout<<endl;
}
void interval(double &a,double &b,double &h){
cout<<"left interval borders a for the table of values: ";
cin>>a;
cout<<endl;
cout<<"right interval borders b for the table of values: ";
cin>>b;
cout<<endl;
cout<<"step width h for the table of values: ";
cin>>h;
cout<<endl;
}

double power(double x,int n)
{ double sum=1;
  int i;
for(i=0;i<n;i++){
sum=sum*x;}

return sum;}

double addingseries(polynumber* a,double x){
double sum=0;
int i,j;j=degreecounter(a);
for(i=0;i<=j;i++)
    {
     sum=sum+((a->pc)*(power(x,a->degree)));

    a=a->next;
    }

return sum;}


void printwithinterval(polynumber* a,double c,double b,double h)
{
double i;
for(i=c;i<=b;i=i+h)
    {
    cout<<i<<"     "<<addingseries(a,i)<<endl;/*************************************************
Aufgabe Nr./Task No.: H1
Nachname/Last,Family Name: Islam
Vorname/First,Given Name: Mozahidul
Matrikelnummer/Matriculation number: 3022958
Uni-Email: mozahidul.islam@stud.uni-due.de
Studiengang/Course of Studies: ISE CE
*************************************************/







#include<iostream>
 using namespace std;

 struct polynumber{
        double pc;/**polynomial coefficients**/
        int degree;
        polynumber *next;
 };

void output(polynumber*);

polynumber* listofgetpolynumber(polynumber* head ,int d){
polynumber *newelement,*last;
newelement = new polynumber;
 if(newelement==NULL){
        cout<<"no memory"<<endl;
 }else{
     cin>>newelement->pc;
     newelement->degree=d;
     cout<<endl;
     if (head == NULL)
   {
      newelement->next = NULL;
      head = newelement;
   }
   else
   {
      last = head;
      while (last->next != NULL)
         {last = last->next;}
      newelement->next = NULL;
      last->next = newelement;
   }

 }

return head;}

 int degreecounter(polynumber* p){
int i=0;
do{
    if(p->next==NULL){break;}
    i++;
    p=p->next;
}while(p->next!=NULL);

return i;}


polynumber* inputcoefficient(){
      int d,i;
      polynumber *head=NULL;

      cout<<"enter the degree of polynomial:";
    cin>>d;
      for(i=d;i>=0;i--){
     cout<<"coefficient a_"<<i<<":";
     head=listofgetpolynumber(head,i);

     }
return head;}

polynumber* polyplus(polynumber *a,polynumber *b,polynumber *head){
int i,j,k;
polynumber *c,*last1,*last2,*temp1,*temp2,*head1=NULL,*head2=NULL;
if(degreecounter(a)>=degreecounter(b)){i=degreecounter(a);}else{i=degreecounter(b);}
last1=a;
while(last1!=NULL)
{ temp1=new polynumber;
    temp1->pc=last1->pc;
    temp1->degree=last1->degree;
    temp1->next=head1;
    head1=temp1;
    last1=last1->next;
}
last2=b;
while(last2!=NULL)
{ temp2=new polynumber;
    temp2->pc=last2->pc;
    temp2->degree=last2->degree;
    temp2->next=head2;
    head2=temp2;
    last2=last2->next;
}

for(j=0;j<=i;j++){c=new polynumber;
                  c->pc=head1->pc+head2->pc;cout<<"before check head2pc"<<head2->pc<<"  cpc"<<c->pc<<endl;
                  c->degree=head1->degree;
                  c->next=head;
                  head=c;
                  if(head1->next==NULL){for(k=j+1;k<=i;k++){c=new polynumber;head2=head2->next;c->pc=head2->pc;c->degree=head2->degree;c->next=head;head=c;}break;}
                  if(head2->next==NULL){for(k=j+1;k<=i;k++){c=new polynumber;head1=head1->next;c->pc=head1->pc;c->degree=head1->degree;c->next=head;head=c;}break;}
                  head1=head1->next;
                  head2=head2->next;

                 }

                 output(head);


 output(head);
return head;}


void output(polynumber* p){
int i,d;

d=degreecounter(p);
for(i=d;i>=0;i--){
        if(p->pc!=0){if(i==0){cout<<p->pc;}else{
    cout<<p->pc<<"x"<<"^"<<i;}}
    p=p->next;
if(i==0){cout<<".";}else{
if(p->pc>0){cout<<"+";}else{cout<<"";}}

}
cout<<endl;
}
void interval(double &a,double &b,double &h){
cout<<"left interval borders a for the table of values: ";
cin>>a;
cout<<endl;
cout<<"right interval borders b for the table of values: ";
cin>>b;
cout<<endl;
cout<<"step width h for the table of values: ";
cin>>h;
cout<<endl;
}

double power(double x,int n)
{ double sum=1;
  int i;
for(i=0;i<n;i++){
sum=sum*x;}

return sum;}

double addingseries(polynumber* a,double x){
double sum=0;
int i,j;j=degreecounter(a);
for(i=0;i<=j;i++)
    {
     sum=sum+((a->pc)*(power(x,a->degree)));

    a=a->next;
    }

return sum;}


void printwithinterval(polynumber* a,double c,double b,double h)
{
double i;
for(i=c;i<=b;i=i+h)
    {
    cout<<i<<"     "<<addingseries(a,i)<<endl;/*************************************************
Aufgabe Nr./Task No.: H1
Nachname/Last,Family Name: Islam
Vorname/First,Given Name: Mozahidul
Matrikelnummer/Matriculation number: 3022958
Uni-Email: mozahidul.islam@stud.uni-due.de
Studiengang/Course of Studies: ISE CE
*************************************************/







#include<iostream>
 using namespace std;

 struct polynumber{
        double pc;/**polynomial coefficients**/
        int degree;
        polynumber *next;
 };

void output(polynumber*);

polynumber* listofgetpolynumber(polynumber* head ,int d){
polynumber *newelement,*last;
newelement = new polynumber;
 if(newelement==NULL){
        cout<<"no memory"<<endl;
 }else{
     cin>>newelement->pc;
     newelement->degree=d;
     cout<<endl;
     if (head == NULL)
   {
      newelement->next = NULL;
      head = newelement;
   }
   else
   {
      last = head;
      while (last->next != NULL)
         {last = last->next;}
      newelement->next = NULL;
      last->next = newelement;
   }

 }

return head;}

 int degreecounter(polynumber* p){
int i=0;
do{
    if(p->next==NULL){break;}
    i++;
    p=p->next;
}while(p->next!=NULL);

return i;}


polynumber* inputcoefficient(){
      int d,i;
      polynumber *head=NULL;

      cout<<"enter the degree of polynomial:";
    cin>>d;
      for(i=d;i>=0;i--){
     cout<<"coefficient a_"<<i<<":";
     head=listofgetpolynumber(head,i);

     }
return head;}

polynumber* polyplus(polynumber *a,polynumber *b,polynumber *head){
int i,j,k;
polynumber *c,*last1,*last2,*temp1,*temp2,*head1=NULL,*head2=NULL;
if(degreecounter(a)>=degreecounter(b)){i=degreecounter(a);}else{i=degreecounter(b);}
last1=a;
while(last1!=NULL)
{ temp1=new polynumber;
    temp1->pc=last1->pc;
    temp1->degree=last1->degree;
    temp1->next=head1;
    head1=temp1;
    last1=last1->next;
}
last2=b;
while(last2!=NULL)
{ temp2=new polynumber;
    temp2->pc=last2->pc;
    temp2->degree=last2->degree;
    temp2->next=head2;
    head2=temp2;
    last2=last2->next;
}

for(j=0;j<=i;j++){c=new polynumber;
                  c->pc=head1->pc+head2->pc;
                  c->degree=head1->degree;
                  c->next=head;
                  head=c;
                  if(head1->next==NULL){for(k=j+1;k<=i;k++){c=new polynumber;head2=head2->next;c->pc=head2->pc;c->degree=head2->degree;c->next=head;head=c;}break;}
                  if(head2->next==NULL){for(k=j+1;k<=i;k++){c=new polynumber;head1=head1->next;c->pc=head1->pc;c->degree=head1->degree;c->next=head;head=c;}break;}
                  head1=head1->next;
                  head2=head2->next;

                 }

                 output(head);


 output(head);
return head;}


void output(polynumber* p){
int i,d;

d=degreecounter(p);
for(i=d;i>=0;i--){
        if(p->pc!=0){if(i==0){cout<<p->pc;}else{
    cout<<p->pc<<"x"<<"^"<<i;}}
    p=p->next;
if(i==0){cout<<".";}else{
if(p->pc>0){cout<<"+";}else{cout<<"";}}

}
cout<<endl;
}
void interval(double &a,double &b,double &h){
cout<<"left interval borders a for the table of values: ";
cin>>a;
cout<<endl;
cout<<"right interval borders b for the table of values: ";
cin>>b;
cout<<endl;
cout<<"step width h for the table of values: ";
cin>>h;
cout<<endl;
}

double power(double x,int n)
{ double sum=1;
  int i;
for(i=0;i<n;i++){
sum=sum*x;}

return sum;}

double addingseries(polynumber* a,double x){
double sum=0;
int i,j;j=degreecounter(a);
for(i=0;i<=j;i++)
    {
     sum=sum+((a->pc)*(power(x,a->degree)));

    a=a->next;
    }

return sum;}


void printwithinterval(polynumber* a,double c,double b,double h)
{
double i;
for(i=c;i<=b;i=i+h)
    {
    cout<<i<<"     "<<addingseries(a,i)<<endl;
    }
}


 int main(){
     polynumber *poly1,*poly2,*sum=NULL;
     double a,b,h;
     poly1=inputcoefficient();
     cout<<endl;
     poly2=inputcoefficient();
     cout<<endl;
     sum=polyplus(poly1,poly2,sum);
     cout<<endl;
cout<<"p(x)=";
output(poly1);
cout<<"q(x)=";
output(poly2);
cout<<"s(x)=";
output(sum);
     cout<<endl;
 interval(a,b,h);
 cout<<" x     p(x)"<<endl;
printwithinterval(poly1,a,b,h);
 cout<<" x     q(x)"<<endl;
printwithinterval(poly2,a,b,h);
 cout<<" x     s(x)"<<endl;
printwithinterval(sum,a,b,h);

delete poly1;
delete poly2;
delete sum;

return 0; }

    }
}


 int main(){
     polynumber *poly1,*poly2,*sum=NULL;
     double a,b,h;
     poly1=inputcoefficient();
     cout<<endl;
     poly2=inputcoefficient();
     cout<<endl;
     sum=polyplus(poly1,poly2,sum);
     cout<<endl;
cout<<"p(x)=";
output(poly1);
cout<<"q(x)=";
output(poly2);
cout<<"s(x)=";
output(sum);
     cout<<endl;
 interval(a,b,h);
 cout<<" x     p(x)"<<endl;
printwithinterval(poly1,a,b,h);
 cout<<" x     q(x)"<<endl;
printwithinterval(poly2,a,b,h);
 cout<<" x     s(x)"<<endl;
printwithinterval(sum,a,b,h);

delete poly1;
delete poly2;
delete sum;

return 0; }

    }
}


 int main(){
     polynumber *poly1,*poly2,*sum=NULL;
     double a,b,h;
     poly1=inputcoefficient();
     cout<<endl;
     poly2=inputcoefficient();
     cout<<endl;
     sum=polyplus(poly1,poly2,sum);
     cout<<endl;
cout<<"p(x)=";
output(poly1);
cout<<"q(x)=";
output(poly2);
cout<<"s(x)=";
output(sum);
     cout<<endl;
 interval(a,b,h);
 cout<<" x     p(x)"<<endl;
printwithinterval(poly1,a,b,h);
 cout<<" x     q(x)"<<endl;
printwithinterval(poly2,a,b,h);
 cout<<" x     s(x)"<<endl;
printwithinterval(sum,a,b,h);

delete poly1;
delete poly2;
delete sum;

return 0; }
ext;
if(i==0){cout<<".";}else{
if(p->pc>0){cout<<"+";}else{cout<<"";}}

}
cout<<endl;
}
void interval(double &a,double &b,double &h){
cout<<"left interval borders a for the table of values: ";
cin>>a;
cout<<endl;
cout<<"right interval borders b for the table of values: ";
cin>>b;
cout<<endl;
cout<<"step width h for the table of values: ";
cin>>h;
cout<<endl;
}

double power(double x,int n)
{ double sum=1;
  int i;
for(i=0;i<n;i++){
sum=sum*x;}

return sum;}

double addingseries(polynumber* a,double x){
double sum=0;
int i,j;j=degreecounter(a);
for(i=0;i<=j;i++)
    {
     sum=sum+((a->pc)*(power(x,a->degree)));

    a=a->next;
    }

return sum;}


void printwithinterval(polynumber* a,double c,double b,double h)
{
double i;
for(i=c;i<=b;i=i+h)
    {
    cout<<i<<"     "<<addingseries(a,i)<<endl;
    }
}


 int main(){
     polynumber *poly1,*poly2,*sum=NULL;
     double a,b,h;
     poly1=inputcoefficient();
     cout<<endl;
     poly2=inputcoefficient();
     cout<<endl;
     sum=polyplus(poly1,poly2,sum);
     cout<<endl;
cout<<"p(x)=";
output(poly1);
cout<<"q(x)=";
output(poly2);
cout<<"s(x)=";
output(sum);
     cout<<endl;
 interval(a,b,h);
 cout<<" x     p(x)"<<endl;
printwithinterval(poly1,a,b,h);
 cout<<" x     q(x)"<<endl;
printwithinterval(poly2,a,b,h);
 cout<<" x     s(x)"<<endl;
printwithinterval(sum,a,b,h);

delete poly1;
delete poly2;
delete sum;

return 0; }
