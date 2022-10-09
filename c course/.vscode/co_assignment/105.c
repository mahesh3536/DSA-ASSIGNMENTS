#include<stdio.h>
#include "105.h"
int main(){
    char s1[100];
    char s2[100];
    printf("Enter the binary string 1:");
    scanf("%s",s1);
    printf("Enter the binary string 2:");
    scanf("%s",s2);
    char s3[100];
    printf("the result is : %s",addition_signed_binary_numbers_U21CS023(s1,s2,s3));
}