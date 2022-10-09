char* reverse(char* s1){
    int len=0;
    for(int i=0;s1[i]!='\0';i++) len++;
    for(int i=0;i<len/2;i++){
        char temp=s1[i];
        s1[i]=s1[len-i-1];
        s1[len-i-1]=temp;
    }
    return s1;
}