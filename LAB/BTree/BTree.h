#pragma once
#include "../HashTableLin/HashTableLin.h"
#include "../BTree/BTree.h"

typedef struct _BTree_t BTree_t;

BTree_t* BTreeGet(int t);

void BTreeFree(BTree_t* tree);

int BTreeFind(BTree_t* tree, int key, int* value);

int BTreeAdd(BTree_t* tree, int key, int value);

int BTreeRemove(BTree_t* tree, int key, int* value);
