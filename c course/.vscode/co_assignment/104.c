#include<stdio.h>
#include "104.h"
int main(){
    char s1[100];
    char s2[100];
    char result[100];
    printf("Enter the binary stirng 1 : ");
    scanf("%s",s1);
    printf("Enter the binary string 2 : ");
    scanf("%s",s2);
    printf("The addition is : %s",addition_unsigned_binary_numbers_U21CS023(s1,s2,result));
}