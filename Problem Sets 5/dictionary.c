// Implements a dictionary's functionality

#include <stdbool.h>
#define LENGTH 45
#include "dictionary.h"
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;
// Hash value
unsigned int hash_value;
// word count
unsigned int word_count;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);
    // access linked list
    node *nextNode = table[hash_value];
    while (nextNode != NULL)
    {
        if (strcasecmp(word, nextNode->word) == 0)
        {
            return true;
        }

        nextNode = nextNode->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return (hash % N);

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *praiseFile = fopen(dictionary, "r");

    if (praiseFile == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(praiseFile, "%s", word) != EOF)
    {

        node *list = malloc(sizeof(node));

        if (list == NULL)
        {
            return false;
        }

        strcpy(list->word, word);

        hash_value = hash(word);

        list->next = table[hash_value];

        table[hash_value] = list;

        word_count++;
    }

    fclose(praiseFile);
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    if (word_count > 0)
    {
        return word_count;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *eachBucket = table[i];
        while (eachBucket)
        {

            node *temp = eachBucket;
            eachBucket = eachBucket->next;
            free(temp);

        }
        if (i == N - 1 && eachBucket == NULL)
        {
            return true;
        }
    }
    return false;
}
