#include <stdio.h>
 
void Binary(int n, int i)
{
 
    
    int k;
    for (k = i - 1; k >= 0; k--) {
 
        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }
}
 
typedef union {
 
    float f;
    struct
    {
 
       
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
 
    } ieee754;
    
} floating_point;
 

void printieee754(floating_point f)
{
 
    
    printf("%d | ", f.ieee754.sign);
    Binary(f.ieee754.exponent, 8);
    printf(" | ");
    Binary(f.ieee754.mantissa, 23);
    printf("\n");
}
 

int main()
{
 
    
    floating_point val;
    float temp ;
    printf("Enter floating point number : ");
    scanf("%f",&temp);
    val.f = temp ;
    printf("IEEE754 of %f is : \n" ,temp);
    printieee754(val);
    return 0;
}