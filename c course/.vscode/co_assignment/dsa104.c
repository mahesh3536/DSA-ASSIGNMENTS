#include<stdio.h>
#include "dsa104.h"
int main(){
    char s1[100];
    char s2[100];
    printf("Enter the string 1 :");
    scanf("%s",s1);
    printf("Enter the string 2 :");
    scanf("%s",s2);
   printf("%d",cmp(s1,s2));
}