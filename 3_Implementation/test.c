#include<stdio.h>
#include "contact.h"
#include "unity.h"

void setUp(){}

void tearDown(){}

void test_addcontact(void){
    TEST_ASSERT_EQUAL(1,add_contact("Sobin","7814174948","ludhiana","sobin@gmail.com"));
    TEST_ASSERT_EQUAL(0,add_contact("Sobin","8874598234","ludhiana"," ");
}
                    
void test_search_contact(void){
    TEST_ASSERT_EQUAL(1,search_contact("Annamma"));
    TEST_ASSERT_EQUAL(0,search_contact("Vishwas"));
}
                      
void test_edit_delete_contact(void){
    TEST_ASSERT_EQUAL(1,edit_delete_contact("Annamma"));
    TEST_ASSERT_EQUAL(0,edit_delete_contact("mammad"));
}

void test_search_result(void){
    TEST_ASSERT_EQUAL(1,search_result("annamma"));
    TEST_ASSERT_EQUAL(0,search_result("Vishwas"));
}

void test_compare_name(void){
    TEST_ASSERT_EQUAL(1,compare_name("sobin","Sobin"));
    TEST_ASSERT_EQUAL(0,compare_name("sobin","rajan"));
}

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_addcontact);
    RUN_TEST(test_search_contact);
    RUN_TEST(test_edit_delete_contact);
    RUN_TEST(test_search_result);
    RUN_TEST(test_compare_name);

    return UNITY_END();
}
