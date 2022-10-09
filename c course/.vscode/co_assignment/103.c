#include<stdio.h>
#include "103.h"
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    printf("Factorial of number %d is %d",n,factorial(n));
}