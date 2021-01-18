#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 30 


int main(int argc, char ** argv)
{
    node *root_node=create_node('a');
    node *pnode=root_node;
    char word[WORD];
    while(getword(word) != -1 )
    {
       insert_word(pnode, word);
    }
    insert_word(pnode, word);//because when we do get word on the last word it returns -1
    if (argc == 2 && strlen(argv[1])==1 && argv[1][0]=='r') 
    {
        print_words_in_reversed_order(pnode);
    }
    else 
    {
        print_words_in_order(pnode);
    }
    dealocate_children(pnode);
}


   
