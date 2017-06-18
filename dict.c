#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "list.h"
#include "dict.h"


void build_dict(list* ma_list, FILE* my_file){
	
	char* word = NULL;
	
	element_value my_elemt_value = {
		.word = NULL,
		.occurence = 0
	};
	
	if(ma_list != NULL)
	{
		while ((word = get_word_file(my_file)) != NULL)
		{
			my_elemt_value.word = word;
			addElement(ma_list, my_elemt_value);

		}
	}
	
} 

char * get_word_string(char** my_string)
{
	if(*my_string == NULL){
		exit(EXIT_FAILURE);
	}
	
	int i = 1;
	char * my_word = malloc(sizeof(char));
	char lettre = '0';

	while (**my_string == ' ' || **my_string == '\n'){
		(*my_string)++;
	}
	if(**my_string == '\0'){
		return NULL;
	}
	
	lettre = **my_string;
	*my_word = lettre;
	(*my_string)++;
	
	while(**my_string != ' ' && **my_string != '\n' && **my_string != '\0')
	{
		my_word = (char *) realloc(my_word, sizeof(char)*(i+1));
		
		lettre = **my_string;

		*(my_word + i) = lettre;
		(*my_string)++;
		i++;
	}

	if(*my_word != '\0' && i != 1) {
		my_word = (char *) realloc(my_word, sizeof(char)*(i+1));
		*(my_word + i) = '\0';
	}

	return my_word;
	
}


char * get_word_file(FILE* my_file)
{
	
	char lettre = 0;
	
	char * my_word = malloc(sizeof(char));
	my_word = NULL;
	int i = 0;
	
	do 
	{
		lettre = fgetc(my_file);
	}while(lettre == '\n' || lettre == ' ');

	while(lettre != ' ' && lettre != EOF && lettre != '\n')
	{
		my_word = (char *) realloc(my_word, sizeof(char)*(i+1));
		*(my_word + i)= lettre;
		i++;
		lettre = fgetc(my_file);
	}

	if(lettre != EOF && i != 0) {
		*(my_word + i)= '\0';
	}

	return my_word;
	
}
