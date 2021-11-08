// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"

//_________________________________________Define the data structure of a node that will put into hash table_______________________________

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//____________________________________________________________Global Values__________________________________________________________________

// Number of buckets in hash table
const unsigned int N = 26;

//Number of word in dictionary
int word_count = 0;

// Hash table
node *table[N];

//____________________________________________________________Check Function__________________________________________________________________

// Returns true if word is in dictionary, else false
bool check(const char *word)                                            //input is the words from text file
{
    // put the word into hash function to obtain hash index
    int hashIndex = hash(word); 
    
    //accept link list at that index in the table
    //cursor is current dictionary's word that have to be checked with text's word
    node *cursor = table[hashIndex];
    
    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word,word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    
    return false;
}

//____________________________________________________________Hash Function__________________________________________________________________

//// HASH FUNCTION => Put each word of loaded dictionary into hash table with hash funciton 
unsigned int hash(const char *word)
{
    // initialize the sum which is summing every ascii number of each char of the word
    int sum = 0;
    
    //sum the ascii value of the word  ==> eg -> cat = c(99) + a(97) + t(116) = 312
    for(int i = 0; i < strlen(word) ; i++)
    {
        sum += tolower(word[i]);
    }
    
    //return the index of the word where it should be placed in the hash table //known as hash index
    return (sum % N);      // ==> 312 % 26 = 0 
}

//____________________________________________________________Load Function_______________________________________________________________

//// LOAD FUNCTION => Loads dictionary into memory, returning true if successful, else false 
bool load(const char *dictionary)                                                   //input is words from dic file
{
    //_____________________ [1] Open Dictionary___________________________ // 
    
    FILE *dict = fopen(dictionary,"r");
    if (dict == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return 1;
    }

    char scanWord[LENGTH + 1];
    
    // ________[2] Read Each Word From File and [3] add these word into hash table //
    
    while(fscanf(dict,"%s",scanWord) != EOF)
    {
        //fscanf(dict,"%s",scanWord);
        
        //create memory for new word
        node *new_word = malloc(sizeof(node));
        if(new_word == NULL)
        {
            return false;
        }
        
        //copy dictionary's word into new word
        strcpy(new_word->word,scanWord);
        
        //set the new word's next word to NULL
        new_word->next = NULL;
        
        //hash index which show the new word where to go in the hash table
        int hashIndex = hash(scanWord);
        
        //check if there is collision / when the new word is added to the hash table and if there is already taken word 
        if(table[hashIndex] == NULL)
        {
            table[hashIndex] = new_word;
        }
        else
        {
            new_word->next = table[hashIndex];
            table[hashIndex] = new_word;
        }
        
        //count the number of word added into hash table
        word_count++;
        
    }

    //close dictionary
    fclose(dict);
    return true;
    //when every word is loaded into hash table
 
}


//____________________________________________________________Size Function__________________________________________________________________

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    
    return word_count;
}

//_____________________________________________________________Unload Function____________________________________________________________

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // loop all table 
    for(int i = 0; i < N ; i++)
    {
        node *cursor = table[i];
        node *tmp = table[i];
        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}


