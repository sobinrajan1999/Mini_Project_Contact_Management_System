#include "contact.h"
#include<string.h>
#include<stdio.h>


void print_list(char buffer[]){
    char *evar=strtok(buffer,",");
    printf("\t\t\t\t%20s |",evar);
    evar=strtok(NULL,",");
    printf("%18s |",evar);
    evar=strtok(NULL,",");
    printf("%18s |",evar);
    evar=strtok(NULL,",");
    printf("%32s\n",evar);
    
}