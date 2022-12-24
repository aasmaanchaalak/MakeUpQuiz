#include <stdio.h>

void basicFizzBuzz(int x){
    if (x%3==0 || x%5==0){
        printf("fizz\n");
    }
    if (x%11==0 || x%13==0){
        printf("buzz\n");
    }
    if (x%33==0 || x%39==0 || x%55==0 || x%65==0){
        printf("fizzbuzz\n");
    }
    if (x%3!=0 && x%5!=0 && x%11!=0 && x%13!=0){
        printf("%d", x);
    }
}

int main(){
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    basicFizzBuzz(x);
}