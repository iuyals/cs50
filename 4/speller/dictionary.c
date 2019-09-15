// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // TODO
        //to lower case first
        for(int i=0;i<strlen(word);++i){
            word[i]=tolower(word[i]);
        }
        int hashNumber=hash(word);
        int isHead=0;
        node* pWord=hashtable[hashNumber];
        node* preptr=NULL;
        isHead=(pWord==NULL?1:0);
        while(pWord != NULL){
            preptr=pWord;
            pWord=(pWord)->next;
        }
        pWord=malloc(sizeof(node));
        memcpy((pWord)->word,word,strlen(word)+1);
        pWord->next=NULL;
        if(preptr!=NULL){
            preptr->next=pWord;
        }
        hashtable[hashNumber]=(isHead?pWord:hashtable[hashNumber]);
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
int size(void)
{
    // TODO

    node* pWord;
    node* pNextWord;
    int counter;
    counter=0;
    for(int i=0;i<N;++i){
        pWord=hashtable[i];
        while(pWord!=NULL){
            counter++;
            pWord=pWord->next;
        }

    }
    return counter;
}

// Returns true if word is in dictionary else false
bool check(char *word)
{
    char loword[50];
    for(int i=0;i<strlen(word)+1;++i){
        loword[i]=tolower(word[i]);
    }
    // TODO
    int hashNumber=hash(loword);
    node* pWord=hashtable[hashNumber];
    while(pWord!=NULL){
        if( strcmp(pWord->word,loword)==0 ){
            return true;
        }
        pWord=pWord->next;
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node* pWord;
    node* pNextWord;
    for(int i=0;i<N;++i){
        pWord=hashtable[i];
        while(pWord!=NULL){
            pNextWord=pWord->next;
            free(pWord);
            pWord=pNextWord;
        }

    }
    return true;
}
