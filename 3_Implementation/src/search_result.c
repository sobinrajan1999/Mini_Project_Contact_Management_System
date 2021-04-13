#include "contact.h"
#include<string.h>

/**
 * @brief Compare the name you want to search with the names in the contact list
 * 
 * @param ename contains the name of the person you want to compare with the contact list
 * @param var contain the name from the contact list.
 * @return found_t return if the name is in the list or not.
 */
found_t compare_name(char *ename, char var[]){
    int result=1;
    for(int i=0;i<strlen(var);i++){
        if(var[i]==ename[i] || var[i]==(ename[i]+32) || var[i]==(ename[i]-32)){             //if a char is equal (not case sensitive)
            continue;                                                                       //continue;
        }
        else{                                                                               //else return NOT_FOUND
            return NOT_FOUND;
        }
    }
    return FOUND;                                                                           //if the whole string matches then return FOUND
}

/**
 * @brief Print the search result
 * 
 * @param ename contain the name or fraction of the name you want to find
 * @return found_t checks whether we find the contact in list or not.
 */
found_t search_result(char ename[]){
    FILE *fptr;
    fptr=fopen("csv_file/data.csv","r");
    fgets(buffer,1024,fptr);
    int flag=0;
    
    
    while(fgets(buffer,1024,fptr)){                         //This while loop will print all contact detail that have that name
        char *var=strtok(buffer,",");
        if(compare_name(var,ename)==1){                     //Comparing the name with contact list
            printf("\t\t\t\t%20s |",var);
            var=strtok(NULL,",");
            printf("%18s |",var);                           //Strings are displaying in specific format for GUI.
            var=strtok(NULL,",");
            printf("%18s |",var);
            var=strtok(NULL,",");
            printf("%32s\n",var);
            flag=1;
        }
    }
    fclose(fptr);
    if(flag==1){
        return FOUND;                                      //if we found that name in contact list return FOUND
    }
    return NOT_FOUND;                                       //else return NOT_FOUND;
}