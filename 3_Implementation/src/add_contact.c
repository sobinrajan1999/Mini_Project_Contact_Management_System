#include<stdio.h>
#include "contact.h"
#include<stdlib.h>

/**
 * @brief Add contact to csv file
 * 
 * @param name contains the name you want to add
 * @param phone contains the phone number you want to add
 * @param location contains the location you want to add
 * @param email contains the email address you want to add
 * @return error_t to check whether this parameters contain any NULL value
 */
error_t add_contact(char name[], char phone[], char location[], char email[]){
    FILE *fptr;
        fptr=fopen("csv_file/data.csv","a");
//         if(name==NULL || phone==NULL || location==NULL, email==NULL){            //return FAIL if any varibale contain NULL value
//             return FAIL;
//         }
        fprintf(fptr,"%s,%s,%s,%s\n",name,phone,location,email);      //add the details to file
        fclose(fptr);
        return SUCCESS;                           //return SUCCESS if everything works fine
}
