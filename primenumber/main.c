#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, i, f = 0;
    printf("give a number:");
    scanf("%d", &t);
    for (i=2; i<t/2; i++){
        if (t%i==0){
            f=1;
        }

    }
    if(f==0){
        printf("prime number");
    }
    else{
        printf("not prime");
    }
    return 0;
}
