#include "contact.h"
#include<string.h>

found_t compare_name(char *ename, char var[]){
    int result=1;
    for(int i=0;i<strlen(var);i++){
        if(var[i]==ename[i] || var[i]==(ename[i]+32) || var[i]==(ename[i]-32)){
            continue;
        }
        else{
            return NOT_FOUND;
        }
    }
    return FOUND;
}

found_t search_result(char ename[]){
    FILE *fptr;
    fptr=fopen("csv_file/data.csv","r");
    fgets(buffer,1024,fptr);
    int flag=0;
    
    
    while(fgets(buffer,1024,fptr)){
        char *var=strtok(buffer,",");
        if(compare_name(var,ename)==1){
            printf("\t\t\t\t%20s |",var);
            var=strtok(NULL,",");
            printf("%18s |",var);
            var=strtok(NULL,",");
            printf("%18s |",var);
            var=strtok(NULL,",");
            printf("%32s\n",var);
            flag=1;
        }
    }
    fclose(fptr);
    if(flag==1){
        return FOUND;
    }
    return NOT_FOUND;
}