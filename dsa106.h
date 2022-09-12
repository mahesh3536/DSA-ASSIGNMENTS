int substring(char* s1,char* s2){
    int len1=0;
    int len2=0;
    int flag;
    for(int i=0;s1[i]!=0;i++) len1++;
    for(int i=0;s2[i]!=0;i++) len2++;
    for(int i=0;i<=len1-len2;i++){
        for(int j=i;j<i+len2;j++){
            flag=1;
            if(s1[j]!=s2[j-i]){
                flag=0;
                break;
            }

        }
        if(flag==1) break;

    }
    if(flag==1) return 1;
    else return 0;
}