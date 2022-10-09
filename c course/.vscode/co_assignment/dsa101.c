#include<stdio.h>
#include "dsa101.h"
int main(){
    char s1[100];
    printf("Enter the string:");
    scanf("%s",s1);
    printf("The length of the string %s is : %d",s1,len(s1));
}