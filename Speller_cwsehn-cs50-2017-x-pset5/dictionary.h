/**
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>


        typedef struct node
        {
            bool is_word;
            struct node *ap[27];
        }
        node;
        
        node *root;
        
        

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define LETTERS 27

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word);

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);
/**
 * mallocs new nodes for trie
 */
node* createNode(node *parent, int index);

/**
 *  called from unload to recursively free memory
 */
bool freeme(node *bound);

#endif // DICTIONARY_H

