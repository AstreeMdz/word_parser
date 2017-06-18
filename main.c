#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "dict.h"
#include "parser.h"


int main(int argc, char* argv[]){
    
    //test_addElement();
    //test_printElement();
    char buffer_txt[100];
    FILE * dicto = NULL;
    FILE * texte = NULL;
        
    list my_list = NULL;
    
   
    /* Construction du dictionnaire en liste chaînée */
    dicto = fopen(argv[1], "r+");
    
    if(dicto != NULL)
    {
        build_dict(&my_list, dicto);
        fclose(dicto);
    } else {
        printf("le dictionnaire ne peut_être ouvert ou n existe pas \n");
        return EXIT_FAILURE;
    }
    
    /* Comptage des occurences */
    if(argc <= 2)
    {
        printf("saisissez le fichier de text\n");
        fflush(stdout);
        fgets(buffer_txt, 100, stdin);
        parser_string(&my_list, buffer_txt);
    } else 
    {
        for (int i = 2; i<argc; i++)
        {
            texte = fopen(argv[i], "r+");
            parser_file(&my_list, texte);
            fclose(texte);
        }
    }


    printElementOccurence(my_list);
        
   
   
    return EXIT_SUCCESS;
}
