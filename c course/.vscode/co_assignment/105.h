
int len(char* s1){
    int len=0;
    for(int i=0;s1[i]!='\0';i++){
        len++;
    }
    return len;
}
void comple(char s[]){
    for(int i=0;i<len(s);i++){
        if(s[i]=='0'){
            s[i]='1';
        }
        else{
            s[i]='0';
        }
    }
    int r=0;
    int l=len(s);
    int p=s[l-1];
    s[l-1] =(s[l-1]+r+'1'-'0'-'0')%2 +48;
    r=(p+r+'1'-'0'-'0')/2;
    if(r!=0){
        for(int i=l-2;i>=0;i--){
            int p=s[i];
            s[i]=(s[i]+r-'0')%2 +48;
            r=(p+r-'0')/2;
        }
    }
    printf("%s",s);
}
char* addition_signed_binary_numbers_U21CS023(char* s1,char* s2,char* s3){
    int l1=len(s1);
    int l2=len(s2);
    int max = l1>l2 ? l1 : l2;
    l1--;
    l2--;
   
    if(s1[0]==s2[0]){
         s3[max+1]='\0';
         int r=0;
        while(max){
            if(l1>=1){
                r = r+s1[l1]-'0';
            }
            if(l2>=1){
                r = r + s2[l2]-'0';
            }
            s3[max] = '0' + (r & 1);
            r = r/2;
            l1--;
            l2--;
            max--;
        }
        s3[0]=s1[0];
        return s3;
    }
    else {
        s3[max]='\0';
        int r = 0;
        for(int i=max-1;i>=0;i--){
            s3[i]=(s1[i]+s2[i]+r-'0'-'0')%2 +48;
            r = (s1[i]+s2[i]+r-'0'-'0')/2;
        }
        return s3;
    }
    
}