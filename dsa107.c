#include<stdio.h>
#include "dsa107.h"
int main(){
    char s1[100];
    printf("Enter the string : ");
    scanf("%s",s1);
    printf("The reversed string is : %s",reverse(s1));
}