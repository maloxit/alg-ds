#include "DataStructureLibWrapper.h"
#include "../HashTableLin/HashTableLin.h"
#include "../BTree/BTree.h"
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

static struct STRCTS structs;

void* WrapperGet()
{
  structs.hTable = HashTableGet(1046527, 1);
  structs.bTree = BTreeGet(5);
  return (void*)(&structs);
}

void WrapperFree(void* dataStructure)
{
  HashTableFree(structs.hTable);
  BTreeFree(structs.bTree);
}

OUT_CODE WrapperFind(void** dataStructure_p, int key, int* val_p)
{
  int rH, rB;
  int* tmp;
  char buff[30];
  sprintf(buff, "%i", key);
  rH = HashTableFind(structs.hTable, buff, (void**)&tmp);
  rB = BTreeFind(structs.bTree, key, val_p);
  if (rH == rB)
  {
    return OC_YES;
  }
  else
  {
    return OC_NO;
  }
}

OUT_CODE WrapperAdd(void** dataStructure_p, int key, int val)
{
  int rH, rB;
  int* tmp = (int*)malloc(sizeof(int));
  char buff[30];
  sprintf(buff, "%i", key);
  *tmp = val;
  rH = HashTableAdd(structs.hTable, buff, (void*)tmp);
  if (rH == -1)
  {
    free(tmp);
  }
  rB = BTreeAdd(structs.bTree, key, val);
  if (rH == rB)
  {
    return OC_YES;
  }
  else
  {
    return OC_NO;
  }
}

OUT_CODE WrapperRemove(void** dataStructure_p, int key, int* val_p)
{
  int rH, rB;
  int* tmp;
  char buff[30];
  sprintf(buff, "%i", key);
  rH = HashTableRemove(structs.hTable, buff, (void**)&tmp);
  if (rH == 1)
  {
    free(tmp);
  }
  rB = BTreeRemove(structs.bTree, key, val_p);
  if (rH == rB)
  {
    return OC_YES;
  }
  else
  {
    return OC_NO;
  }
}
