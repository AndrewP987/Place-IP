//
// File: trie.h
// Starter trie module for an integer-keyed trie data type ADT
//
// @author Andrew
// // // // // // // // // // // // // // // // // // // // // // // //

#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>

/// public unsigned, integer key type for entries in the trie

typedef unsigned int ikey_t;

/// TODO define the data structure to represent the payload

typedef struct Entry_s
{
    ikey_t key; ///< unique identifier key
    char *from_value;
    char *to_value;
    char *country_code;
    char *country_name;
    char *province;
    char *city;
    unsigned char to_bytes[4];
    unsigned char from_bytes[4];
    //    unsigned int *from_value_in_bits;
    //    unsigned int *to_value_in_bits;
    int bit_pos;
} *Entry;

// typedef struct Entry_s * Entry;

/// Trie is a pointer to the Trie ADT

typedef struct Trie_s *Trie;
// typedef struct Trie_s Trie;

typedef struct Node_s *Node;

// constant values for bit processing available to application

extern const size_t BITSPERBYTE;  ///< number of bits in a byte
extern const size_t BITSPERWORD;  ///< number of bits in a word
extern const size_t BYTESPERWORD; ///< number of bytes in a word
extern const size_t RADIX;        ///< number of possible key values

// functions needed regarding node creation

// void inorder(Trie *trie, Node *node, FILE* stream, int count);
// void test_node(Node* node, Trie* trie);
// void test_root(Trie* trie);
void test_null_node(Trie trie);
void dcall(Trie trie);
/// Create a Trie instance and initialize its fields.
/// @param TODO ...
/// @return pointer to the Trie object instance or NULL on failure
/// @post Trie is NULL on failure or initialized with a NULL trie root

Trie ibt_create();

/// Destroy the trie and free all storage.
/// Uses Trie's Delete_value function to free app-specific (key and) value;
/// If the Trie's Delete_value function is NULL,
/// then call free() on the value in (key,value).
/// @param trie a pointer to a Trie instance
/// @pre trie is a valid Trie instance pointer
/// @post the storage associated with the Trie and all data has been freed

void ibt_destroy(Trie trie);

/// insert an entry into the Trie as long as the entry is not already present
/// @param trie a pointer to a Trie instance
/// @param TODO what needs to be copied into the trie node
/// @post the trie has grown to include a new entry IFF not already present

void ibt_insert(Node entry, Trie trie);

/// search for the key in the trie by finding
/// the closest entry that matches key in the Trie.
/// @param trie a pointer to a Trie instance
/// @param key the key to find
/// @return entry representing the found entry or a null entry for not found

Entry ibt_search(Trie trie, ikey_t key);
Entry ip_search(Trie trie, char *ip, Entry s, int bits[32]);

/// get the size of the trie or number of leaf elements
/// @param trie a pointer to a Trie instance
/// @return size of trie

size_t ibt_size(Trie trie);

/// get the node count of the trie: the number of internal nodes
/// @param trie a pointer to a Trie instance
/// @return the count of internal nodes

size_t ibt_node_count(Trie trie);

/// get height of the trie
/// @param trie a pointer to a Trie instance
/// @return height of trie

size_t ibt_height(Trie trie);

/// Perform an in-order traversal to show each (key, value) in the trie.
/// Uses Trie's Show_value function to show each leaf node's data,
/// and if the function is NULL, output each key and value in hexadecimal.
///
/// @param trie a pointer to a Trie instance
/// @param stream the stream destination of output

void ibt_show(Trie trie, FILE *stream);
void ibt_draw(Trie trie, FILE *stream);

#endif // TRIE_H
