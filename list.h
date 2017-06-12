
typedef struct element_value{
    char* word;
    int occurence;
}element_value;

typedef struct element element;

struct element{
    element_value value;
    element* next;
};

typedef element* list;


int addElement(list* a_list, element_value a_element_value);
int count_element_list(list a_list);
int printElement(list a_list);







int test_addElement(void);
int test_printElement(void);
