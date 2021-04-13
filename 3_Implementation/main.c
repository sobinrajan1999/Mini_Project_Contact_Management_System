#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "inc/contact.h"

char phone[11];
char name[50];
char location[50];
char email[50];

int main(){

main_menu:
    system("clear");

    printf("\n\t\t\t\t\t **** Contact Management System ****");

    printf("\n\n\n\t\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t\t\t\t\t[1] Add a new Contact\n\t\t\t\t\t\t[2] List all Contacts\n\t\t\t\t\t\t[3] Search for contact\n\t\t\t\t\t\t[4] Edit a Contact\n\t\t\t\t\t\t[5] Delete a Contact\n\t\t\t\t\t\t[0] Exit\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t");

    printf("\n\t\t\t\t\t\tEnter the choice:");

    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 0:
            exit(0);
        break;

    case 1:
    system("clear");
        printf("\n\n\t\t\t\t\t~~~~~~~~~~~ADD CONTACT~~~~~~~~~~~~~\n\n");
        // for(;;){
            fflush(stdin);
            printf("\t\t\t\t\t\tName: ");
            scanf("%49s",name);
            fflush(stdin);
            printf("\t\t\t\t\t\tPhone: ");
            scanf("%10s",phone);
            fflush(stdin);
            printf("\t\t\t\t\t\tLocation: ");
            scanf("%49s",location);
            fflush(stdin);
            printf("\t\t\t\t\t\tEmail ID: ");
            scanf("%49s",email);
            fflush(stdin);
            error_t add=add_contact(name,phone,location,email);
            printf("\n");
            // printf("\t\t\t\t\t\tDo want to add another contact[y/n]: ");
            // scanf("%c",&yes_or_no);
            // if(yes_or_no=='y'){
            //     continue;
            // }
            // else{
            //     break;
            // }
            // printf("\n\n");
        // }
        
        break;

    case 2:
        list_all_contact();
        break;

    case 3:
        printf("\n\n\t\t\t\tEnter the name of the person: ");
        fflush(stdin);
        scanf("%49s",name);
        system("clear");
        printf("\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Search Result~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("\t\t\t\t                Name |             Phone |          Location |                      Email ID\n");
        printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        found_t search=search_result(name);
        if(search==0){
        printf("\t\t\t\t\t\t\t\t\tSorry No Search Result\n");
        }
        printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        break;

    case 4:
        printf("\n\n\t\t\t\tEnter the name of the person you want to edit: ");
        fflush(stdin);
        scanf("%49s",name);
        error_t edit=edit_delete_contact(name);
        if(edit==1){
            system("clear");
            printf("\n\n\t\t\t\t\t~~~~~~~~~~~EDIT CONTACT~~~~~~~~~~~~~\n\n");
            fflush(stdin);
            printf("\t\t\t\t\t\tName: ");
            scanf("%49s",name);
            fflush(stdin);
            printf("\t\t\t\t\t\tPhone: ");
            scanf("%10s",phone);
            fflush(stdin);
            printf("\t\t\t\t\t\tLocation: ");
            scanf("%49s",location);
            fflush(stdin);
            printf("\t\t\t\t\t\tEmail ID: ");
            scanf("%49s",email);
            fflush(stdin);
            error_t add=add_contact(name,phone,location,email);
        }
        else{
            printf("\t\t\t\t\t\tSorry No contact found");
        }
        
        break;
        

    case 5:
        printf("\n\n\t\t\t\tEnter the name of the person you want to delete: ");
        fflush(stdin);
        scanf("%49s",name);
        error_t flag=edit_delete_contact(name);
        if(flag==1){
            printf("\t\t\t\t\t\tContact Deleted.");
        }
        else{
            printf("\t\t\t\t\t\tSorry No contact found");
        }
        break;

    default:
        printf("\t\t\t\t\t\tWrong Input!");
    }

    printf("\n\t\t\t\t\t\t\t\t [1]Main Menu \t\t\t [0]exit");
    printf("\n\n\t\t\t\t\t\t\t\t\tEnter your choice: ");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice){
        case 1:
            goto main_menu;
        case 0:
            break;
        default:
            printf("invalid statement!");
            break;

    }

}
