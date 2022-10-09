#include<stdio.h>
#include<string.h>
#include "101.h"
int main(){
    char str[100];
    scanf("%s",str);
    int len=strlen(str);
    
    printf("%f",decimal(str,len));
}