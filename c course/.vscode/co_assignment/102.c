#include<stdio.h>
#include "102.h"
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    char s[100];
    printf("%s",convertingtobinary(n,s));
}