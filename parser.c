#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "dict.h"

static void check_occurence(list liste, char* mot);

void parser_file(list* my_list,FILE * my_file){
	
	char * my_word = NULL;
		
		while((my_word=get_word_file(my_file)) != NULL)
		{
			check_occurence(*my_list, my_word);
			
		}

}

void parser_string(list* my_list, char * my_string)
{
	if(my_string == NULL)
	{
		exit(EXIT_FAILURE);
	}
	char * my_word = NULL;
		
		while((my_word=get_word_string(&my_string)) != NULL)
		{
			check_occurence(*my_list, my_word);
			//my_string = my_string + strlen(my_word);
			
		}

}


static void check_occurence(list liste, char* mot)
{
	
	if(mot!= NULL){
		
		while(liste !=NULL)
		{
			if(strncmp(liste->value.word, mot, strnlen(mot,sizeof(liste->value.word)))==0)
			{
				liste->value.occurence = liste->value.occurence+1;
			}
			liste = liste->next;
		}
		
	}

	}

