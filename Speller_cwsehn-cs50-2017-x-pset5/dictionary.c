/**
 * Implements a dictionary's functionality.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"

unsigned int SIZE = 0;
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    node *checker = root;
    int letter;
    
    for (int i = 0; i < (LENGTH + 1); i++)
    {
       if (word[i] == '\0')
       {
           if (checker->is_word == true)
           {
               return true;
           }
           else
           {
               return false;
           }
       }
       if (word[i] == '\'')
       {
           letter = (LETTERS - 1);
       }
       else
       {
            letter = (tolower(word[i]) - 'a');
       }
       checker = checker->ap[letter];
       
       
       if (checker == NULL)
       {
           return false;
       }

    }
    
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char* dictionary)
{
        node* createNode(node* parent, int index);
        node* parent = NULL;
        
        FILE *fp = fopen(dictionary, "r");
        if (fp == NULL)
        {
            printf("Could not open %s.\n", dictionary);
            return 1;
        }
        
        for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
        {
            //if c is alpha or '\'' convert c to an integer 0 - 26....
            if ( (c >= 'a' && c <= 'z' ) || (c == '\'') || (c == '\n'))
            {
                // reset node ptr at end of word....
                if ( c == '\n')
                {
                    // in this case 86 ...as in "you're out!"
                    c = 86;
                    if (parent != NULL)
                    {
                        parent->is_word = true;
                        parent = root;
                        size();
                    }
                }
               
                if (c >= 'a' && c <= 'z')
                {
                    c -= 'a';
                }
                if (c == '\'')
                {
                    c = (int)(LETTERS - 1);
                }
            }
            else
            {
                c = 86;
            }
            if (c < LETTERS)
            {
                parent = createNode(parent, c);
            }
        }
        if (fgetc(fp) == EOF)
        {
            fclose(fp);
            return true;
        }
    fclose(fp);
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    SIZE++;
    return (SIZE - 1);
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    node *unloader = root;
    bool freeme(node *bound);
    
    bool freed = freeme(unloader);
    
    if (freed)
    {
       return true; 
    }
    else
    {
        return false;
    }
}


    bool freeme(node* bound)
    {
        // 10 hours of work/hairpulling....10 lines of code :)
        int i;
        
        for (i = 0; i < LETTERS; i++)
        {
            if (bound->ap[i] != NULL)
            {
                freeme(bound->ap[i]);
            }
        }
        free(bound);
        
        return true;
        
    }


    node* createNode(node *parent, int index)
    {
        if (parent == NULL)
        {
           // malloc a root node.....
            parent = (node *)malloc(sizeof(node));
                if (parent == NULL)
                       {
                           fprintf(stderr, "Could not allocate memory...\n");
                           return parent;
                       }
            // initialize root node ...
            parent->is_word = false;
            for (int i = 0; i < LETTERS; i++)
            {
                parent->ap[i] = NULL;
            }
            root = parent;
        }
        
        if (parent->ap[index] == NULL)
        {
            parent->ap[index] = (node*)malloc(sizeof(node));
                    if (parent->ap[index] == NULL)
                           {
                               fprintf(stderr, "Could not allocate memory...\n");
                               return parent;
                           }
            
            parent->ap[index]->is_word = false;
            for (int i = 0; i < LETTERS; i++)
                {
                    parent->ap[index]->ap[i] = NULL;
                }
        }
        
        parent = parent->ap[index];
        
            return parent;
    }