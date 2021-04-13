#include "contact.h"
#include<string.h>
#include<stdio.h>

/**
 * @brief Helper function to list_all_contact to print the list
 * 
 * @param buffer contains line of the file having details in comma seperated format
 */
void print_list(char buffer[]){
    char *evar=strtok(buffer,",");                             //strtok function to tokenize the string on the basis of the delimiter ","
    printf("\t\t\t\t%20s |",evar);                              //Name
    evar=strtok(NULL,",");
    printf("%18s |",evar);                                      //Phone Number
    evar=strtok(NULL,",");
    printf("%18s |",evar);                                      //Location
    evar=strtok(NULL,",");
    printf("%32s\n",evar);                                      //Email ID
    
}