#include <stdio.h>
#include <stdlib.h>

double read3x3m(double M[3][3])
{

    printf("******inverse of 3x3 matrix**********\n");
    printf("[0,0]\n");
    scanf("%lf", &M[0][0]);
     printf("[0,1]\n");
     scanf("%lf", &M[0][1]);
      printf("[0,2]\n");
      scanf("%lf", &M[0][2]);
       printf("[1,0]\n");
       scanf("%lf", &M[1][0]);
        printf("[1,1]\n");
        scanf("%lf", &M[1][1]);
         printf("[1,2]\n");
         scanf("%lf", &M[1][2]);
          printf("[2,0]\n");
          scanf("%lf", &M[2][0]);
           printf("[2,1]\n");
           scanf("%lf", &M[2][1]);
            printf("[2,2]\n");
            scanf("%lf", &M[2][2]);
            return 0;}


  void prntm3(double M[3][3]){
        int i,j;


 for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%.2lf\t", M[i][j]);
        }
printf("\n"); }
}
  void prntm2(double M[2][2]){
        int i,j;

 for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%.2lf\t", M[i][j]);
        }
printf("\n\n"); }
}
double dtrmtm2(double M[2][2]){
double n;
n=((M[0][0]*M[1][1])-(M[1][0]*M[0][1]));
return n;
}
double dtrmtm3(double M[3][3]){
double n;

n=((M[0][0]*((M[1][1]*M[2][2])-(M[2][1]*M[1][2])))
  -(M[0][1]*((M[1][0]*M[2][2])-(M[2][0]*M[1][2])))
  +(M[0][2]*((M[1][0]*M[2][1])-(M[2][0]*M[1][1]))));
return n;
}
void prnt9ary(double M[9]){
 int i;
 for(i=0;i<9;i++){printf("%.2lf", M[i]);}
 printf("\n");

}
double chs2mf3m(double M[3][3],double M00[2][2],double M01[2][2],double M02[2][2],double M10[2][2],double M11[2][2],double M12[2][2],double M20[2][2],double M21[2][2],double M22[2][2], double N[9]){


M00[0][0]=M[1][1];M00[0][1]=M[1][2];M00[1][0]=M[2][1];M00[1][1]=M[2][2];
M01[0][0]=M[1][0];M01[0][1]=M[1][2];M01[1][0]=M[2][0];M01[1][1]=M[2][2];
M02[0][0]=M[1][0];M02[0][1]=M[1][1];M02[1][0]=M[2][0];M02[1][1]=M[2][1];
M10[0][0]=M[0][1];M10[0][1]=M[0][2];M10[1][0]=M[2][1];M10[1][1]=M[2][2];
M11[0][0]=M[0][0];M11[0][1]=M[0][2];M11[1][0]=M[2][0];M11[1][1]=M[2][2];
M12[0][0]=M[0][0];M12[0][1]=M[0][1];M12[1][0]=M[2][0];M12[1][1]=M[2][1];
M20[0][0]=M[0][1];M20[0][1]=M[0][2];M20[1][0]=M[1][1];M20[1][1]=M[1][2];
M21[0][0]=M[0][0];M21[0][1]=M[0][2];M21[1][0]=M[1][0];M21[1][1]=M[1][2];
M22[0][0]=M[0][0];M22[0][1]=M[0][1];M22[1][0]=M[1][0];M22[1][1]=M[1][1];

N[0]=dtrmtm2(M00);N[1]=(-1)*dtrmtm2(M01);N[2]=dtrmtm2(M02);N[3]=(-1)*dtrmtm2(M10);N[4]=dtrmtm2(M11);N[5]=(-1)*dtrmtm2(M12);N[6]=dtrmtm2(M20);N[7]=(-1)*dtrmtm2(M21);N[8]=dtrmtm2(M22);


return 0;}

void convrtarytom( double M[3][3], double N[9]){
 int i,j,k=0;
  for(i=0;i<3;i++){
        for(j=0;j<3;j++){
     M[i][j]=N[k];
     k++;

        }
}
 prntm3(M);
 }

void transposm3(double M[3][3],double T[3][3]){
T[0][0]=M[0][0];T[1][1]=M[1][1];T[2][2]=M[2][2];
T[0][1]=M[1][0];T[0][2]=M[2][0];T[1][0]=M[0][1];T[1][2]=M[2][1];T[2][0]=M[0][2];T[2][1]=M[1][2];
}

void scalermultiplicationtom(double s, double M[3][3]){
 int i,j;
 for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            M[i][j]=(M[i][j]*s);
        }
 }
}

int main(){

    double M[3][3],m[3][3],T[3][3],N[9],s;
    double M00[2][2],M01[2][2],M02[2][2],M10[2][2],M11[2][2],M12[2][2],M20[2][2],M21[2][2],M22[2][2];

    read3x3m(M);
    printf("your matrix\n");
    prntm3(M);

if(dtrmtm3(M)==0){printf("it doesnt have any inverse");}else{
   s=(1/dtrmtm3(M));
   printf("determinant is= %.2lf", dtrmtm3(M));

   printf("\n");
    chs2mf3m(M,M00,M01,M02,M10,M11,M12,M20,M21,M22,N);
    printf("your array is\t");
    prnt9ary(N);
    printf("sub matrixwith determinant\n");
    prntm2(M00);
     printf("determinant=%.2lf", dtrmtm2(M00) );

     printf("\n");
     prntm2(M01);
     printf("determinant=%.2lf", dtrmtm2(M01));

     printf("\n");
     prntm2(M02);
     printf("determinant=%.2lf", dtrmtm2(M02));

     printf("\n");
     prntm2(M10);
     printf("determinant=%.2lf",dtrmtm2(M10));

     printf("\n");
     prntm2(M11);
     printf("determinant=%.2lf", dtrmtm2(M11));

     printf("\n");
     prntm2(M12);
     printf("determinant=%.2lf", dtrmtm2(M12));

     printf("\n");
     prntm2(M20);
     printf("determinant=%.2lf", dtrmtm2(M20));

     printf("\n");
     prntm2(M21);
     printf("determinant=%.2lf", dtrmtm2(M21));

     printf("\n");
     prntm2(M22);
     printf("determinant=%.2lf", dtrmtm2(M22));

     printf("\n");
     printf("cofactor matrix\n");
    convrtarytom(m,N);
    transposm3(m,T);
    printf("Adjoint of the matrix\n");
    prntm3(T);
    printf("inverse matrix\n");
    scalermultiplicationtom(s,T);
    prntm3(T);}
    return 0;
}
