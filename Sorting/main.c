#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct contact{
                 char firstname[30];
                 char lastname[30];
                 char adress[30];
                 int houseno;
                 int zip;
                 char city[40];
    };
int main(){
    int b,z;
 struct contact phonebook[7]={{"shakil","khan","duisburg str",13,47225,"koeln"},
                             {"nahid","ahamed","annastr",83,47225,"duisburg"},
                             {"sabur","rahman","krefeld str",91,47233,"dusseldorf"},
                             {"ashek","islam","dusseldorf str",38,47226,"rheinhausen"},
                             {"topon","kor","richard str",19,47223,"duisburg"}};
   struct contact sortedphonebook[7];


    printf("your contact details:\n");
     for(b=0;b<5;b++){

    printf("  %s\n", phonebook[b].firstname);
    printf("  %s\n", phonebook[b].lastname);
    printf("  %s\n", phonebook[b].adress);
    printf("  %d\n", phonebook[b].houseno);
    printf("  %d\n", phonebook[b].zip);
    printf("  %s\n", phonebook[b].city);
printf(" \n");
      };
while(1){z=0;
  for(b=0;b<4;b++){


   if(phonebook[b].lastname[0]>phonebook[b+1].lastname[0]){
     strcpy(sortedphonebook[b].firstname,phonebook[b].firstname);
     strcpy(sortedphonebook[b].lastname,phonebook[b].lastname);
     strcpy(sortedphonebook[b].adress,phonebook[b].adress);
   sortedphonebook[b].houseno=phonebook[b].houseno;
     sortedphonebook[b].zip=phonebook[b].zip;
     strcpy(sortedphonebook[b].city,phonebook[b].city);

     strcpy(phonebook[b].firstname,phonebook[b+1].firstname);
     strcpy(phonebook[b].lastname,phonebook[b+1].lastname);
     strcpy(phonebook[b].adress,phonebook[b+1].adress);
    phonebook[b].houseno=phonebook[b+1].houseno;
     phonebook[b].zip=phonebook[b+1].zip;
     strcpy(phonebook[b].city,phonebook[b+1].city);

     strcpy(phonebook[b+1].firstname,sortedphonebook[b].firstname);
     strcpy(phonebook[b+1].lastname,sortedphonebook[b].lastname);
     strcpy(phonebook[b+1].adress,sortedphonebook[b].adress);
     phonebook[b+1].houseno=sortedphonebook[b].houseno;
     phonebook[b+1].zip=sortedphonebook[b].zip;
     strcpy(phonebook[b+1].city,sortedphonebook[b].city);
z=1;


 };

};if(z==0){break;}};

 printf("your new sorted contacts:\n");
     for(b=0;b<5;b++){

    printf("  %s\n", phonebook[b].firstname);
    printf("  %s\n", phonebook[b].lastname);
    printf("  %s\n", phonebook[b].adress);
    printf("  %d\n", phonebook[b].houseno);
    printf("  %d\n", phonebook[b].zip);
    printf("  %s\n", phonebook[b].city);
printf(" \n");
     };
    return 0;
}
