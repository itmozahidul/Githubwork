#include <stdio.h>
#include <stdlib.h>

double abslt(double x)
{ double r;
    if(x<0){r=x*(-1);}
    else{r=x;}
    return r;
}

double power( double x, double y)
{ int i;
double r=1;
   for(i=1;i<=y;i++)
   {
    r=r*x;
   }
    return r;
}

double factorial( double x)
{
  double i;
i=abslt(x);
double r=1;
while(i>0)
{
 r=r*i;
 i--;
}
if(x<0){return r*(-1);}
else{return r;}
}

double arctan(double x, double y)
{
    double n=0;
    double dmntr,nmntr,r,R=0;
    while(1)
    {nmntr=(power(-1,n))*(power(x,((2*n)+1)));
    dmntr=(2*n)+1;
    r=nmntr/dmntr;
    R=R+r;
    n++;

   if(abslt(r)<y){break;
   } }


return R;}

double pi(double y)
{   double n=1;
    double dmntr,nmntr,r,R=0;
    while(1)
    {nmntr=n*(power(2,n))*(power((factorial(n)),2));
    dmntr=factorial(2*n);
    r=nmntr/dmntr;
    R=R+r;
    n++;

   if(abslt(r)<y){break;} }


return R-3;}


double arccos(double x, double y)
{
    double n=0;
    double dmntr,nmntr,r,R=0;
    while(1)
    {nmntr=factorial(2*n)*(power(x,((2*n)+1)));
    dmntr=((2*n)+1)*(power((factorial(n)),2))*power(4,n);
    r=nmntr/dmntr;
    R=R+r;
    n++;

   if(abslt(r)<y){break;} }


return (3.1416/2)-R;}

main(){ int n;

double x, y, r;
printf("Choose a series you would like to calculte\n");
printf("1. Arctan(x)\n2. pi\n3. arccos(x)\n ");
scanf("%d", &n);

switch(n){
 case 1:while(1){
        printf("enter the value of x \n");
        scanf("%lf", &x);

        if(x>1||x<-1){printf("invalid input!!!\n input interval [1,-1]\n");}else{break;}}
        printf("enter the value of approximation \n");
        scanf("%lf", &y);
        r=arctan(x, y);



        break;
 case 2:
        printf("enter the value of approximation \n");
        scanf("%f", &y);
        r=pi(y);

        break;
 case 3:while(1){
       printf("enter the value of x \n");
       scanf("%lf", &x);
        if(x>1||x<-1){printf("invalid input!!!\n input interval [1,-1]\n");}else{break;}}

        printf("enter the value of approximation \n");
        scanf("%lf", &y);

        r=arccos(x,y);

        break;
 }

printf("%.5lf",r);

return 0;}
