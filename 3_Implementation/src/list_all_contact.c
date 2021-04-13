#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "contact.h"

/**
 * @brief Print all the contact details
 * 
 * @return error_t return if it has any error or not
 */
error_t list_all_contact(){
    system("clear");
    FILE *fptr;
    printf("\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Contact List~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\t\t\t                Name |             Phone |          Location |                      Email ID\n");
    printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        for(int i=97;i<=122;i++){
            fptr=fopen("csv_file/data.csv","r");
            if(!fptr){                                          //This for loop will print the whole contact list in alphabetical order
                return FAIL;
            }
            fgets(buffer,1024,fptr);
            while(fgets(buffer,1024,fptr)){
                if(buffer[0]==i || buffer[0]==i-32){
                    print_list(buffer);
                }
            }
            
        }
        printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    fclose(fptr);
    return SUCCESS;
}