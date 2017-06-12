#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "parser.h"

int main(int argc, char* argv[]){
    
    test_addElement();
    test_printElement();
    if(argv <= 2){
        printf("veuillez saisir un text");
    } else {
        list my_list;
        build_dict(&my_list, argv[1]);
        for(int i ==2; i<argc, i++){
         parser(&my_list,argv[i]);
     }
    }
   
    return EXIT_SUCCESS;
}
