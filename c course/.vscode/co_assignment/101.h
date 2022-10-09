float decimal(char s[],int len){
    int p;
    int flag =0;
    for(int i=0;i<len;i++){
        
        if(s[i]=='.'){
            p=i;
            flag=1;
            break;
        }
    }
    
    if(flag){
   
    float num=0;
    int pow =1;
    for(int j=p-1;j>=0;j--){
       num = num + ((int)s[j] - 48) * pow;
       pow = pow*2;
    }
    float pow1 = 0.5;
    for(int j=p+1;j<len;j++){
        num = num + ((int)s[j] -48.0)*pow1;
        pow1 = pow1/2.0;
    }
    return num;}
    else{
        int pow=1;
        float num=0.0;
        for(int j=len-1;j>=0;j--){
            num = num + ((int)s[j] -48) * pow;
            pow = pow * 2;
        }
        return num;
    }
}