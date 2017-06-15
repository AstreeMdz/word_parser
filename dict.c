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
			printf("hello1 %lu\n", strlen(word));
			strncpy(my_elemt_value.word, word, strlen(word));
			printf("hello2\n");
			addElement(ma_list, my_elemt_value);
		}
		printf("hello3");
	}
	
} 


int get_word(FILE* my_file, char* my_word)
{
	
	char lettre = 0;
	
	my_word = malloc(sizeof(char));
	
	int i = 1;
	lettre = fgetc(my_file);


		while(lettre != ' ' && lettre != EOF && lettre != '\n')
		{
			printf("0\n");
			my_word = (char *) realloc(my_word, sizeof(char));
			memcpy(my_word, &lettre, sizeof(char));
			//my_word = &lettre;
			i++;
			lettre = fgetc(my_file);
			printf("\n1 %c + %s\n",lettre, my_word);
			if(lettre == ' '){
				printf("sd");
			} else {
				printf("sfd");
			}
		}
		printf("dhs");

		if(lettre == EOF)
		{
			return 1;
		} else 
		{
			return 0;
		}
	
}
