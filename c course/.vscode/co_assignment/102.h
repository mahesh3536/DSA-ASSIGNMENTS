char* convertingtobinary (int  num, char* arr) {
int a = num , d =0;
int i = 31;
arr[32] = '\0';
while(i+1) {
if(a > 1) d++;
arr[i] ='0'+(a & 1);
a = a >> 1;
i--;
}
return arr;
}