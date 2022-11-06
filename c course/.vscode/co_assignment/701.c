#include<stdio.h>
void addBinary(char nums1[8],char nums2[8]){
    int count = 0;
    int carry = 0;
    for(int i=7;i>=0;i--){
        int count = nums1[i]-'0' + nums2[i]-'0'+carry;
        nums1[i] = count%2 + '0';
        carry = count/2;
    }
}
char* complementTwo(char nums[8]){
    static char arr[8];
    for(int i=0;i<8;i++){
        arr[i] = nums[i]=='0' ? '1' : '0';
    }
    char temp[8];
    for(int i =0;i<7;i++){
        temp[i] = '0';
    }
    temp[7]='1';
    addBinary(arr,temp);
    return arr;
}
void ashr(char ac[8],char qr[8]){
    
    for(int i=7;i>=1;i--){
        qr[i]=qr[i-1];
    }
    qr[0] = ac[7];
    for(int i=7;i>=1;i--){
        ac[i] = ac[i-1];
    }
}
int main(){
    char qr[8];
    char br[8];
    printf("Enter first Binary string qr : ");
    scanf("%s",qr);
    printf("Enter second Binary string br : ");
    scanf("%s",br);
    char ac[8];
    for(int i = 0;i<8;i++){
        ac[i]='0';
    }
    char* brComplement = complementTwo(br);
    int sc = 8;
    char q = '0';
    while(sc--){
        char qn = qr[7];
        if(qn=='1' && q=='0'){
            addBinary(ac,brComplement);
        }
        else if(qn=='0' && q=='1'){
            addBinary(ac,br);
        }
        q=qr[7];
        ashr(ac,qr);
    }
    for(int i =0;i<=7;i++) {
        printf("%c",ac[i]);
    }
    for(int i = 0;i<=7;i++){
        printf("%c",qr[i]);
    }
}