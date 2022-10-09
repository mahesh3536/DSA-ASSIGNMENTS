int len(char* s1){
    int len=0;
    for(int i=0;s1[i]!='\0';i++){
        len++;
    }
    return len;
}
char* addition_unsigned_binary_numbers_U21CS023(char* s1,char* s2,char* s3){
    int l1=len(s1);
    int l2=len(s2);
    int max = l1>l2 ? l1 : l2;
    s3[max]='\0';
        int r = 0;
        for(int i=max-1;i>=0;i--){
            s3[i]=(s1[i]+s2[i]+r-'0'-'0')%2 +48;
            r = (s1[i]+s2[i]+r-'0'-'0')/2;
        }
        return s3;
}