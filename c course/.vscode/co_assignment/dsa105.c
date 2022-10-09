#include<stdio.h>
#include "dsa105.h"
int main(){
    char s1[100];
    char ch;
     printf("Enter the character:");
    scanf("%c",&ch);
    printf("Enter the string:");
    scanf("%s",s1);
    printf("The first occurance of %c is : %d",ch,occur(s1,ch));
}