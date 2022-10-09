#include<stdio.h>
#include "dsa108.h"
int main(){
    char s1[100];
    printf("Enter the string : ");
    scanf("%s",s1);
    printf("The resultant string is : %s",replace(s1));
}