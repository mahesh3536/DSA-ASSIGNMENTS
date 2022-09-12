#include<stdio.h>
#include "dsa103.h"
int main(){
    char s1[100];
    printf("Enter the string:");
    scanf("%s",s1);
    char s2[100];
    cpy(s1,s2);
   
    printf("%s",s2);
}