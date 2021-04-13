#include "contact.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



/**
 * @brief Delete the contact from the file
 * 
 * @param ename contain the name you want to delete
 * @return error_t checks if the list contains that name or not
 */
error_t edit_delete_contact(char *ename){
    fflush(stdin);
    FILE *fptr;
    FILE *fptr2;
    found_t flag=search_contact(ename);
    if(flag==1){
        fptr=fopen("csv_file/data.csv","r");
        fptr2=fopen("csv_file/temp","w");                  //create a duplicate file in write mode
        fgets(buffer,1024,fptr);
        fprintf(fptr2,"%s",buffer);
        while(fgets(buffer,1024,fptr)){
            char *var=strtok(buffer,",");
            if(compare_name(var,ename)==0){                //compare the name with the contact list
                char *ephone=strtok(NULL,",");            
                char *elocation=strtok(NULL,",");
                char *eemail=strtok(NULL,",");
                fprintf(fptr2,"%s,%s,%s,%s",var,ephone,elocation,eemail);         //copy everything to duplicate file
            }                                                                     //except the contact you want to delete
        }
        fflush(stdin);
        fclose(fptr);
        fclose(fptr2);
        remove("csv_file/data.csv");                                            //remove the original file
        rename("csv_file/temp","csv_file/data.csv");                            //rename the file to original file

        return SUCCESS;
    }
    return FAIL;
}