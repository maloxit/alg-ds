#pragma once
#include "DataStructureConsole.h"
#include "../HashTableLin/HashTableLin.h"
#include "../BTree/BTree.h"

struct STRCTS
{
  HashTable_t* hTable;
  BTree_t* bTree;
};

void* WrapperGet();

void WrapperFree(void* dataStructure);

OUT_CODE WrapperFind(void** dataStructure_p, int key, int* val_p);

OUT_CODE WrapperAdd(void** dataStructure_p, int key, int val);

OUT_CODE WrapperRemove(void** dataStructure_p, int key, int* val_p);