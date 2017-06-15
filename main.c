#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "dict.h"
#include "parser.h"

int main(int argc, char* argv[]){
    
    //test_addElement();
    //test_printElement();
    if(argc < 2){
        printf("veuillez saisir un text %d",argc);
    } else {
        list my_list;
        build_dict(&my_list, argv[1]);
        printElement(my_list);
        //~ for(int i ==2; i<argc, i++){
         //~ parser(&my_list,&argv[i]);
     //~ }
    }
   
    return EXIT_SUCCESS;
}
