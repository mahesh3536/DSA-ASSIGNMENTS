char* replace(char* s1){
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i]=='a' || s1[i]=='e' || s1[i]=='o' || s1[i]=='u'|| s1[i]=='i' || s1[i]=='A' || s1[i]=='E' || s1[i]=='O' || s1[i]=='U' || s1[i]=='I'){
            s1[i]='*';
        }
        else s1[i]='#';
    }
    return s1;
}