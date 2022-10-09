char* concat(char* s1,char* s2){
    int len=0;
    int j=0;
    for(int i=0;s1[i]!='\0';i++) len++;
    for( ;s2[j]!='\0';j++){
        s1[len+j]=s2[j];
    }
    s1[len+j]='\0';
    return s1;
}