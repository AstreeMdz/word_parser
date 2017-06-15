#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "list.h"

static char * get_word(FILE* my_file);

void build_dict(list* ma_list, const char* path_dict){
	
	FILE* fichier = fopen(path_dict, "r+");
	char* word = NULL;
	
	element_value my_elemt_value = {
		.word = NULL,
		.occurence = 0
	};
	
	if(fichier != NULL && ma_list != NULL)
	{
		while ((word = get_word(fichier)) != NULL)
		{
			strncpy(my_elemt_value.word, word, strlen(word));
			printf("sdjhf");
			free(word);
			addElement(ma_list, my_elemt_value);
		}
	}
	
} 


char * get_word(FILE* my_file)
{
	
	char lettre = 0;
	
	char * my_word = malloc(sizeof(char));
	
	int i = 1;
	lettre = fgetc(my_file);


		while(lettre != ' ' && lettre != EOF && lettre != '\n')
		{
			my_word = (char *) realloc(my_word, sizeof(char)*i);
			memcpy(my_word, &lettre, sizeof(char));
			i++;
			lettre = fgetc(my_file);

			printf("1%s \n", my_word);
		}
		printf("jsdh");
	return my_word;
	
}
