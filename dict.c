#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "list.h"

static int get_word(FILE* my_file, char* my_word);

void build_dict(list* ma_list, const char* path_dict){
	
	FILE* fichier = fopen(path_dict, "r+");
	char* word = NULL;
	
	element_value my_elemt_value = {
		.word = NULL,
		.occurence = 0
	};
	
	if(fichier != NULL && ma_list != NULL)
	{
		while (get_word(fichier, word)== 0)
		{
			strncpy(my_elemt_value.word, word, strlen(word));
			addElement(ma_list, my_elemt_value);
		}
	}
	
} 


int get_word(FILE* my_file, char* my_word1)
{
	
	char lettre = 0;
	
	char * my_word = malloc(sizeof(char));
	
	int i = 1;
	lettre = fgetc(my_file);


		while(lettre != 0x20)
		{
			my_word = (char *) realloc(my_word, sizeof(char)*i);
			memcpy(my_word, &lettre, sizeof(char));
			//my_word = &lettre;
			i++;
			printf("\n%c %s\n", lettre, my_word);

			lettre = fgetc(my_file);
			printf("%x\n",(unsigned int)lettre );
			
		}
		printf("blq");
		if(lettre == EOF)
		{
			return 1;
		} else 
		{
			my_word1 = my_word;
			return 0;
		}
	
}
