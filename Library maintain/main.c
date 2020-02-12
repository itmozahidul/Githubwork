#include<stdio.h>
#include<stdlib.h>
#define M 50
typedef struct date {
 int day;
 int month;
 int year;
}date;

typedef struct person{
char firstname[M];
char lastname[M];
date birthday;
}person;

typedef struct book{
char title[M];
int price;
int seriealno;
int pageno;
person author;
}book;

book library[M];


void insertingsort(book Book[M],int n){
int i,j;
book temp;printf("n=%i", n);
for(i=0;i<n-1;i++){
    for(j=i+1;j>0;j--){
        if(Book[j].seriealno<Book[j-1].seriealno){
           temp=Book[j-1];
           Book[j-1]=Book[j];
           Book[j]=temp;
        }
        else{
                break;
        }
    }
}
}


date inputbirthday(){
date temp;
printf("day:");
scanf("%d", &temp.day);
printf("year:");
scanf("%d", &temp.year);
printf("month:");
scanf("%d", &temp.month);
return temp;
}


void selectingsort(person *Author,int n){
int i,j,min;
person temp;
for(i=0;i<n;i++){min=i;
    for(j=i+1;j<n;j++){

        if(Author[min].birthday.year>Author[j].birthday.year){
            min=j;
        }
    }
    temp=Author[min];
    Author[min]=Author[i];
    Author[i]=temp;


}
}


person inputauthor(){

person Author;
printf("firstname:");
scanf("%s", Author.firstname);

printf("lastname:");
scanf("%s", Author.lastname);

Author.birthday=inputbirthday();

return Author;}


void addauthor(person *Author, int n,int old_n){

int i;
for(i=old_n;i<n;i++){
printf("%d.Authors information::\n", i+1);
Author[i]=inputauthor();
}

selectingsort(Author,n);
}


void printbook(book Book[M],int n,int check){
   if(check==0||n==0){printf("list is empty.\nPlease enter some data first then try.\n");}
else{

   int i;
for(i=0;i<n;i++){
printf("Name of the no.%d. book:%s\n", i+1, Book[i].title);
printf("Serial number:%d\n", Book[i].seriealno);
printf("Price:%d$\n", Book[i].price);
printf("Pages number:%d\n", Book[i].pageno);
printf("Authors name:%s\t", Book[i].author.firstname);
printf("%s\n", Book[i].author.lastname);
printf("Date of birth :%d.", Book[i].author.birthday.day);
printf("%d.", Book[i].author.birthday.month);
printf("%d\n", Book[i].author.birthday.year);

}
}}


void printauthor(person Author[M],int n,int check){
   if(check==0||n==0){printf("empty!\n");}else{
   int i;

for(i=0;i<n;i++){

printf("%dst Authors name:%s\t", i+1, Author[i].firstname);
printf("%s\n", Author[i].lastname);
printf("Date of birth :%d.", Author[i].birthday.day);
printf("%d.", Author[i].birthday.month);
printf("%d\n", Author[i].birthday.year);
}
}}


int stringlnth(char x[M]){
int i=0;
while(x[i]!='\0'){
           i++;
           }
return i;}



int comparestring(char x[M],char y[M]){
    int j,r=1;
    if(stringlnth(x)!=stringlnth(y)){r=0;}
    else{

for(j=0;j<stringlnth(y);j++){
        if(x[j]!=y[j]){
                      r=0;
                      break;
                      }

               }
               }
return r;}

void copystring(char x[M],char y[M]){
int i;
for(i=0;i<M;i++){
    x[i]=y[i];
}
}


book inputbook(person *Aauthor, int n){
book Book;
char lstnam[M];
printf("enter the name of book:");
scanf("%s", Book.title);
printf("enter the serial no of book:");
scanf("%d", &Book.seriealno);
printf("enter the price of book:");
scanf("%d", &Book.price);
printf("enter the page no of book:");
scanf("%d", &Book.pageno);
printf("enter the last name of Author of the book to check if it already exist\n");
scanf("%s", lstnam);
int p,pp,x,writer[n],count=0,choos;
for(p=0;p<n;p++){
    if(comparestring(Aauthor[p].lastname,lstnam)==1){
            writer[count]=p;
            count++; }}
            if(count!=0){
                    if(count==1){printf("we have found one and writer's info is initialized.\n");
        Book.author.birthday.day=Aauthor[(writer[count-1])].birthday.day;
        Book.author.birthday.month=Aauthor[(writer[count-1])].birthday.month;
        Book.author.birthday.year=Aauthor[(writer[count-1])].birthday.year;
        copystring(Book.author.firstname,Aauthor[(writer[count-1])].firstname);
        copystring(Book.author.lastname,Aauthor[(writer[count-1])].lastname);
                    }else{
   printf("Existed writer's names are:\n");
   for(pp=0;pp<count;pp++) {printf("%d.%s\t%s\n", pp+1, Aauthor[(writer[pp])].firstname, Aauthor[(writer[pp])].lastname);}
   printf("which writer was it?\n pls enter a number and press enter.\n");
     scanf("%d", &choos);
        Book.author.birthday.day=Aauthor[(writer[choos])].birthday.day;
        Book.author.birthday.month=Aauthor[(writer[choos])].birthday.month;
        Book.author.birthday.year=Aauthor[(writer[choos])].birthday.year;
        copystring(Book.author.firstname,Aauthor[(writer[choos])].firstname);
        copystring(Book.author.lastname,Aauthor[(writer[choos])].lastname);
            }}else{   printf("Nothing is found.\npls enter writer's info:");
    Book.author=inputauthor();}
return Book;}


void addbook(book *Book,int *n,int old_n,person *Author, int m){

int i;
for(i=old_n;i<*n;i++){
        printf("no.%d book's info::\n", i+1);
Book[i]=inputbook(Author,m);
if(i<*n-1){
printf("enter 1 to add more book or 0 if not.\n");
int gate;
scanf("%d", &gate);
if(gate==0){*n=i+1;printf("n=%i", *n);break;}}
else{printf("no more space.\n choose number 2 to add more space.\n");*n=i+1;}
}
insertingsort(Book,*n);

}

void searchbook(book Book[M],char key,int n,int checklibrary){
if(checklibrary==0||n==0){printf("list is empty.\nPlease enter some data first then try.\n");}
else{
int law=0,mid;
do{
mid=(law+n)/2;
if(Book[mid].seriealno<key){law=mid+1;}
else{n=mid-1;}
}while(law<=n&&Book[mid].seriealno!=key);
printf("%d", mid);
printf("name of the author:%s", library[mid].author.firstname);
printf("\t%s\n", library[mid].author.lastname);
printf("Date of birth:%d.", library[mid].author.birthday.day);
printf("%d.", library[mid].author.birthday.month);
printf("%d\n", library[mid].author.birthday.year);
printf("serial number:%d\n", library[mid].seriealno);
printf("Title of the Book:%s\n", library[mid].title);
printf("Page's numbers:%d\n", library[mid].pageno);
printf("Preice:%d$", library[mid].price);

}}

int searchauthor(person Author[M],char key[M],int n){

int r=0,q;
for(q=0;q<n;q++){
        if(comparestring(Author[q].lastname,key)==1){r=q+1;
       break;
    }
      }

return r;
}

void delauthor(person *Aauthor, int *n,int *m,char lstnam[M]){
    int i,s,p,t,u,v;
for(v=0;v<*n;v++){

i=searchauthor(Aauthor,lstnam,*n);
if(i!=0)
{


          for(s=i-1;s<*n-1;s++){

        Aauthor[s]=Aauthor[s+1];

      }*n=*n-1;
      }
      }




  for(t=0;t<*m;t++){p=comparestring(library[t].author.lastname,lstnam);
                   if(p!=0)
                            {
                            for(u=t;u<*m-1;u++){
                                               library[u]=library[u+1];}*m=*m-1;t=0;
                            }
                 }

    if(i==0&&p==0){printf("no record found here to delet.\n");}
}

int main(){
int n,old_n=0,m,old_m=0,close,check=0,checklibrary=0,serial,switchnum,check_del_author,check_del_library,h=0,j=0;
char del[M];
printf("Enter a length number for an Author Array and a length number for library array.\n");
printf("for Authors:");
scanf("%d", &n);

check_del_author=n;
printf("for the library:");
scanf("%d", &m);
check_del_library=m;
person *Aauthor=(person*)calloc(n,sizeof(person*));
if(Aauthor==NULL){printf("no memory.\n");}else{

while(close!=0){

printf("Choose a number to work:\n");
printf("1.To add author's information.\n");
printf("2.To add book.\n");

printf("3.To print list of books.\n");
printf("4.To find a book\n");
printf("5.To delet data releted to an author.\n");
printf("6.To print authors.\n");
printf("7.To exit.\n");

scanf("%i", &switchnum);

switch(switchnum){
case 1: check=1;
       if(h==0){

       addauthor(Aauthor,n,old_n);

       h++;}
       else{
           if(n<check_del_author){old_n=n;n=check_del_author;addauthor(Aauthor,n,old_n);}
           else{
       printf("no space in array you need to extract array length.");int o;
       printf("enter the new length of arry:");
       scanf("%d", &o);old_n=n;n=o;check_del_author=n;
       addauthor(Aauthor,n,old_n);}}
       break;
case 2:
       checklibrary=1;
       if(j==0){
        addbook(library,&m,old_m,Aauthor,n);
        j++;
        }
        else{
            if(m<check_del_library){old_m=m,m=check_del_library;addbook(library,&m,old_m,Aauthor,n);}
            else{
        printf("no space in array you need to extract array length.");
        printf("enter the new length of array:");
        old_m=m;
       scanf("%d", &m);
       check_del_library=m;
       addbook(library,&m,old_m,Aauthor,n);}}

        break;
case 3:printbook(library,m,checklibrary);
        break;
case 4:
       printf("enter a sereial number to find a book\n");
       scanf("%d", &serial);
       searchbook(library,serial,m,checklibrary);
       break;
case 5:printf("write the name of the Author to delet: ");
       scanf("%s", del);
       delauthor(Aauthor,&n,&m,del);
       break;
 case 6: printauthor(Aauthor,n,check);
         break;
 case 7: close=0;
         break;
 default:printf("wrong input!!!\n");
         break;}}
}
free(Aauthor);
return 0;}
