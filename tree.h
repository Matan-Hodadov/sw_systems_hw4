#pragma once

#define NUM_LETTERS ((int)26)


typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
    char letter;
    long unsigned int count;  
    struct node* children[NUM_LETTERS]; 
} node;

node* create_node(char letter); 

void add_child_to_node(node *pnode, char letter); 

void remove_child_of_node(node *pnode, char letter);

void dealocate_children(node *pnode); 

void read_word(node *root_node, char *word);