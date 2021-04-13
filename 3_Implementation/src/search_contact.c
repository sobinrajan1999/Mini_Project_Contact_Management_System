#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "contact.h"

/**
 * @brief search for the name in list
 * 
 * @param name contain the name you want to search in list
 * @return found_t return if it found the name or not
 */
found_t search_contact(char *ename){
    FILE *f;
    f=fopen("csv_file/data.csv","r");
    fgets(buffer,1024,f);
    while(fgets(buffer,1024,f)){
        char *evar=strtok(buffer,",");
        if(compare_name(evar,ename)==1){                        //if both the strings are same then it will return FOUND.
            return FOUND;
        }
    }
    fclose(f);
    return NOT_FOUND;                                           //if they are not equal then ti will return NOT_FOUND;
}