// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 80000;
int counter = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashValue = hash(word);
    node *checker = table[hashValue];
    while(checker != NULL)
    {
        if(strcasecmp(word,checker->word) == 0)
        {
            return true;
        }
        checker = checker->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for(int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if(dictionary == NULL)
    {
        return false;
    }

    char wordCheck[LENGTH+1];

    while(fscanf(dict ,"%s", wordCheck) != EOF)
    {
        node *dictWord = malloc(sizeof(node));
        
        if(dictWord == NULL)
        {
            return false;
        }

        strcpy(dictWord->word, wordCheck);
        int hashValue = hash(wordCheck);
        dictWord->next = table[hashValue];
        table[hashValue] = dictWord;
        counter++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
       // TODO
    for (int i = 0; i < N; i++)
    {
        node *unloader = table[i];

        while (unloader != NULL)
        {
            node *temp = unloader;
            unloader = unloader->next;
            free(temp);
        }

        if (unloader == NULL && i == N - 1)
        {
            return true;
        }
    }
return false;
}