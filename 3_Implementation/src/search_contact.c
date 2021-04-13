#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "contact.h"

found_t search_contact(char *ename){
    FILE *f;
    f=fopen("csv_file/data.csv","r");
    fgets(buffer,1024,f);
    while(fgets(buffer,1024,f)){
        char *evar=strtok(buffer,",");
        if(compare_name(evar,ename)==1){
            return FOUND;
        }
    }
    fclose(f);
    return NOT_FOUND;
}