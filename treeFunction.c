#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "tree.h"

node* create_node(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        letter = letter + 32;
    }
    else if(letter < 'a' || letter > 'z')
    {
        return NULL;
    }

    node *pnode = (node*)calloc(1,sizeof(node));
    for(int i = 0; i<NUM_LETTERS;i++)
    {
        pnode->children[i] = NULL;
    }
    pnode->count = 0;
    pnode->letter = letter;

    return pnode;
}

void add_child_to_node(node *pnode, char letter)
{
    int child_index = letter - 'a';
    node *pchild = *(n->children[child_index]);
    if(pchild == NULL)
    {
        n->children[child_index] = create_node(letter);
    }
}

void remove_child_of_node(node *pnode, char letter)
{
    int child_index = letter - 'a';
    node *pchild = *(n->children[child_index]);
    dealocate_children(pchild);

}

void dealocate_children(node *pnode)
{
    if(n == NULL)
    {
        return;
    }
    for(int i = 0; i<NUM_LETTERS;i++)
    {
        if(n->children[i] != NULL)
        {
            dealocate_children(n->children[i]);
        }
    }
    free(pnode);
}

void read_word(node *root_node, char *word)
{
    node *temp = root_node; 
    char letter;
    node *pchild;
    for(int i = 0; i < (int)strlen(word); i++)
    {
        letter = *(word + i);
        pchild  = temp->children[i-'a'];
        if(pchild == NULL)
        {
            add_child_to_node(temp, letter);
        }
        temp = temp->children[i-'a'];
        if((int)strlen(word) == i)
        {
            temp->count = temp->count + 1;
        }
    }
}