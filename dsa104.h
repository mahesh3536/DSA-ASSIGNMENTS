int cmp(char* s1,char* s2){
    int i=0;
    while(s1[i]!='\0' && s2[i]!='\0'){
        if(s1[i]!=s2[i]){
           if(s1[i]>s2[i]) return 1;
           else return -1;
        }
        else {
            i++;
        }
    }
    return 0;
}
