/**
 * @file contact.h
 * @author Sobin Rajan (sobinrajan@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdio.h>
#ifndef __CONTACT_H__
#define __CONTACT_H__

/**
 * @brief yes_or_no variable to check whether you want to continue or not
 *        buffer string to store the files values
 * 
 */
char yes_or_no;
char buffer[1024];

/**
 * @brief error_t enum to check any failures and success
 *        SUCCESS means the function is working fine
 *        FAIL means that there is some error in parameters or your contact is not there in file
 * 
 */
typedef enum error_t{
    SUCCESS=1,
    FAIL=0,
}error_t;

/**
 * @brief found_t enum is basically used to find the names in csv file
 *        FOOUND means the name is in the list
 *        NOT_FOUND means the name is not in the list
 * 
 */
typedef enum found_t{
    FOUND=1,
    NOT_FOUND=0,
}found_t;

/**
 * @brief Add contact to csv file
 * 
 * @param name contains the name you want to add
 * @param phone contains the phone number you want to add
 * @param location contains the location you want to add
 * @param email contains the email address you want to add
 * @return error_t to check whether this parameters contain any NULL value
 */
error_t add_contact(char name[],char phone[],char location[],char email[]);

/**
 * @brief Print all the contact details
 * 
 * @return error_t return if it has any error or not
 */
error_t list_all_contact();

/**
 * @brief Print the search result
 * 
 * @param ename contain the name or fraction of the name you want to find
 * @return found_t checks whether we find the contact in list or not.
 */
found_t search_result(char ename[]);

/**
 * @brief Helper function to list_all_contact to print the list
 * 
 * @param buffer contains line of the file having details in comma seperated format
 */
void print_list(char buffer[]);

/**
 * @brief Delete the contact from the file
 * 
 * @param ename contain the name you want to delete
 * @return error_t checks if the list contains that name or not
 */
error_t edit_delete_contact(char ename[]);

/**
 * @brief search for the name in list
 * 
 * @param name contain the name you want to search in list
 * @return found_t return if it found the name or not
 */
found_t search_contact(char *name);

/**
 * @brief Compare the name you want to search with the names in the contact list
 * 
 * @param ename contains the name of the person you want to compare with the contact list
 * @param var contain the name from the contact list.
 * @return found_t return if the name is in the list or not.
 */
found_t compare_name(char *ename, char var[]);

#endif