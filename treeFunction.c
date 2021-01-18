#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "tree.h"
#define WORD 30

int getword(char w[])
{
    char c;
    int i;
    for(i=0;i<WORD;i++)  //maximun iteration is the max word length
    {
        if(scanf("%c", &c) != 1)
        {
            // *(w+i)='\0';
            return -1;
        }
       
       if(c==' '|| c=='\n' || c=='\t' || c=='\0' || c == EOF) //if the char isn't a letter from the word
        {
            *(w+i)='\0';  //end the word by putting \0
            return i;  //return the word's length 
        }
        else  //if this is the next word letter
        {
         *(w+i)=c;  //put it in the next place in the arr
        }
    }
    return i;
}

node* create_node(char letter)
{
    if (letter >= 'A' && letter <= 'Z')//check if its an upper letter
    {
        letter = letter + 32;
    }
    else if(letter < 'a' || letter > 'z')//check if its a letter
    {
        return NULL;
    }

    node *pnode = (node*)calloc(1,sizeof(node));
    for(int i = 0; i<NUM_LETTERS;i++)
    {
        pnode->children[i] = NULL;
    }
    pnode->count = 0;
    pnode->word[0]='\0';
    pnode->letter = letter;

    return pnode;
}

void add_child_to_node(node *pnode, char letter)
{
    int child_index = letter - 'a';
    node *pchild = pnode->children[child_index];
    if(pchild == NULL)
    {
        pnode->children[child_index] = create_node(letter);
    }
}

void remove_child_of_node(node *pnode, char letter)
{
    int child_index = letter - 'a';
    node *pchild = pnode->children[child_index];
    dealocate_children(pchild);
}

void dealocate_children(node *pnode)
{
    if(pnode == NULL)
    {
        return;
    }
    for(int i = 0; i<NUM_LETTERS;i++)
    {
        if(pnode->children[i] != NULL)
        {
            dealocate_children(pnode->children[i]);
        }
    }
    free(pnode);
}

void insert_word(node *root_node, char *pword)//insert the word into the TRIE
{
    node *temp = root_node; 
    char letter;
    node *pchild;
    for(int i = 0; i < (int)strlen(pword); i++)//for every letter in the word
    {
        letter = *(pword + i);
        pchild  = temp->children[letter-'a'];//pointer to the child with this letter
        if(pchild == NULL)
        {
            add_child_to_node(temp, letter);
        }
        temp = temp->children[letter-'a'];//temp pointing to the child with this letter
        if((int)strlen(pword)-1 == i)//if this letter is the last letter of the word 
        {
            temp->count = temp->count + 1;
            if(temp->word[0]=='\0')//check if this is the first time that this node is the end of the word
            {
                for(int i=0;i<(int)strlen(pword);i++)//copy yhe word to temp->word
                {
                    temp->word[i]=*(pword+i);
                }
            }
        }
    }
}


void print_words_in_order(node *pnode)
{
    if(pnode == NULL)
    {
        return;
    }
    if(pnode->word[0]!='\0')//if this node have a word
    {
        printf("%s %ld\n",pnode->word,pnode->count);//print the word and the number of instances
    }
    for(int i = 0; i<NUM_LETTERS;i++)
    {
        if(pnode->children[i] != NULL)
        {
            print_words_in_order(pnode->children[i]);
        }
    }
}

void print_words_in_reversed_order(node *pnode)
{
    if(pnode == NULL)
    {
        return;
    }
    if(pnode->word[0]!='\0')//if this node have a word
    {
        printf("%s %ld\n",pnode->word,pnode->count);//print the word and the number of instances
    }
    for(int i = NUM_LETTERS-1; i>=0;i--)
    {
        if(pnode->children[i] != NULL)
        {
            print_words_in_reversed_order(pnode->children[i]);
        }
    }
}

