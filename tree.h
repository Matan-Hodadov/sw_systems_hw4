#pragma once

#define NUM_LETTERS ((int)26)
#define WORD 30


typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
    char letter;
    char word[WORD];
    long unsigned int count;  
    struct node* children[NUM_LETTERS]; 
} node;

node* create_node(char letter); 

void add_child_to_node(node *pnode, char letter); 

void remove_child_of_node(node *pnode, char letter);

void dealocate_children(node *pnode); 

void insert_word(node *root_node, char *word);

int getword(char w[]);

void print_words_in_order(node *pnode);

void print_words_in_reversed_order(node *pnode);


