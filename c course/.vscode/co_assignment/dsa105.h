int occur(char* s1,char ch){
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i]==ch) {
            return i;
        }
    }
    return -1;
}