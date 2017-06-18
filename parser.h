#ifndef PARSER_H
#define PARSER_H

#include "list.h"

void parser_file(list* my_list, FILE * my_file);
void parser_string(list* my_list, char * my_string);

#endif /*PARSER_H */
