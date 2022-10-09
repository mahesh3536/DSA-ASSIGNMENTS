#include<stdio.h>
#include "dsa106.h"
int main(){
    char str[100];
    char find[100];
    printf("Enter the string : ");
    scanf("%s",str);
    printf("Enter the string which we have to find : ");
    scanf("%s",find);
    printf("%s is sub string of %s : %d",str,find,substring(str,find));
}