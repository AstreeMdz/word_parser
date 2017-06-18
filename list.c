#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"


int addElement(list* a_list, element_value a_element_value){
    
    element* new_element = (element*) malloc(sizeof(element));
    new_element->value = a_element_value;
    new_element->next = NULL;
    
    if(*a_list == NULL){
        *a_list = new_element;
    } else {
        new_element->next = *a_list;
        *a_list = new_element;
    }
    return 0;
}


void printElement(list a_list){
      
       
    while(a_list != NULL){
        printf("%s\n", a_list->value.word);
        a_list = a_list->next;
    }
    
}

void printElementOccurence(list a_list){
      
       
    while(a_list != NULL){
        printf("%s :", a_list->value.word);
        printf(" %d\n", a_list->value.occurence);
        a_list = a_list->next;
    }
    
}

int CheckElement(list a_list){
      
    if(a_list != NULL){
        if(strncmp(a_list->value.word, "?", sizeof("?"))==0){
            a_list = a_list->next;
            if(strncmp(a_list->value.word, "vous", sizeof("vous"))==0){
                a_list = a_list->next;
                if(strncmp(a_list->value.word, "allez", sizeof("?"))==0){
                    a_list = a_list->next;
                    if(strncmp(a_list->value.word, "comment", sizeof("commenr"))==0){
                        return 0;
                    }
                }
                
            }
        } 
    }

    return 1;
}

int count_element_list(list a_list){
    
     int total = 0;

    if(a_list == NULL){
        total = 0;
     } else {
         total = 1;
        while(a_list->next != NULL){
            a_list = a_list->next;
            total ++;
        }
    }

    return total;
}

int count_element_list_recursif(list a_list){
    
    if(a_list == NULL){
        return 0;
     } 

    return 1 + count_element_list_recursif(a_list->next);

}


int test_addElement(void){
    
    list my_list = NULL;
    element my_element ={
        .value.word ="bonjour",
        .next = NULL
    }; 

//test retour fonction
    if(addElement(&my_list, my_element.value) == 1){
        printf("[%s][%d] KO\n", __FUNCTION__, __LINE__);
    } else {
        printf("[%s][%d] OK\n", __FUNCTION__, __LINE__);
    }
//test la liste fait 1 element
    
    if(count_element_list(my_list) != 1){
        printf("[%s][%d] KO\n", __FUNCTION__, __LINE__);
    } else {
        printf("[%s][%d] OK\n", __FUNCTION__, __LINE__);
    }
//test cet element est bonjour
    if(strncmp(my_list->value.word, "bonjour", sizeof("bonjour")) != 0){
        printf("[%s][%d] KO\n", __FUNCTION__, __LINE__);
    } else {
        printf("[%s][%d] OK\n", __FUNCTION__, __LINE__);
    }
    
//******test ajout de deux éléments*****//
    element my_element1 ={
        .value.word ="hello",
        .next = NULL
    }; 
    element my_element2 ={
        .value.word ="gutentag",
        .next = NULL
    }; 
//test retour fonction
    if(addElement(&my_list, my_element1.value) == 1){
        printf("[%s][%d] KO\n", __FUNCTION__, __LINE__);
    } else {
        printf("[%s][%d] OK\n", __FUNCTION__, __LINE__);
    }
    
    if(addElement(&my_list, my_element2.value) == 1){
        printf("[%s][%d] KO\n", __FUNCTION__, __LINE__);
    } else {
        printf("[%s][%d] OK\n", __FUNCTION__, __LINE__);
    }
//test la liste a trois élements

    if(count_element_list_recursif(my_list) != 3){
        printf("[%s][%d] KO\n", __FUNCTION__, __LINE__);
    } else {
        printf("[%s][%d] OK\n", __FUNCTION__, __LINE__);
    }
    
    return 0;
}

int test_printElement(void){
    
    list my_list = NULL;
    element my_element ={
        .value.word ="bonjour",
        .next = NULL
    }; 
    element my_element1 ={
        .value.word ="comment",
        .next = NULL
    }; 
    element my_element2 ={
        .value.word ="allez",
        .next = NULL
    }; 
    element my_element3 ={
        .value.word ="vous",
        .next = NULL
    }; 
    element my_element4 ={
        .value.word ="?",
        .next = NULL
    }; 
    addElement(&my_list, my_element.value);
    addElement(&my_list, my_element1.value);
    addElement(&my_list, my_element2.value);
    addElement(&my_list, my_element3.value);
    addElement(&my_list, my_element4.value);
    printElement(my_list);
    if(CheckElement(my_list) == 1){
        printf("[%s][%d] KO\n", __FUNCTION__, __LINE__);
    } else {
        printf("[%s][%d] OK\n", __FUNCTION__, __LINE__);
    }
    return 0;
}
