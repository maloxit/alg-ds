#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#else

#include <stdlib.h>

#endif // _DEBUG
#include "DataStructureConsole.h"
#include "DataStructureLibWrapper.h"
#include <stdio.h>
#pragma warning(disable:4996)
#include <string.h>

static _dsGet* DsGet;

static _dsFree* DsFree;

static _dsFind* DsFind;

static _dsAdd* DsAdd;

static _dsRemove* DsRemove;

void SetDataStructure(_dsGet* dsGet, _dsFree* dsFree, _dsFind* dsFind, _dsAdd* dsAdd, _dsRemove* dsRemove)
{
  DsGet = dsGet;
  DsFree = dsFree;
  DsFind = dsFind;
  DsAdd = dsAdd;
  DsRemove = dsRemove;
}

static void* DataStructureGet(void)
{
  return (void*)DsGet();
}

static void DataStructureFree(void* dataStructure)
{
  DsFree(dataStructure);
}

typedef OUT_CODE CommandFunc_t(void** dataStructure_p, int key);

static OUT_CODE cmdAdd(void** dataStructure_p, int key)
{
  int output;
  output = DsAdd(dataStructure_p, key, key);
  switch (output)
  {
  case OC_YES:
    return OC_YES;
    break;
  case OC_NO:
    return OC_NO;
    break;
  default:
    return OC_ERROR;
    break;
  }
}

static OUT_CODE cmdFind(void** dataStructure_p, int key)
{
  int tmp;
  int output;
  output = DsFind(dataStructure_p, key, &tmp);
  switch (output)
  {
  case OC_YES:
    return OC_YES;
    break;
  case OC_NO:
    return OC_NO;
    break;
  default:
    return OC_ERROR;
    break;
  }
}

static OUT_CODE cmdRemove(void** dataStructure_p, int key)
{
  int tmp;
  int output;
  output = DsRemove(dataStructure_p, key, &tmp);
  switch (output)
  {
  case OC_YES:
    return OC_YES;
    break;
  case OC_NO:
    return OC_NO;
    break;
  default:
    return OC_ERROR;
    break;
  }
}

#define COMMAND_COUNT 3

static struct
{
  char str[2];
  CommandFunc_t* func;
}commands[] =
{
  {"a", cmdAdd},
  {"f", cmdFind},
  {"r", cmdRemove},
};

static OUT_CODE ExecuteCommand(int commandID, void** dataStructure_p, int key)
{
  return commands[commandID].func(dataStructure_p, key);
}

int StartConsole(void)
{
  int commandID;
  int key;
  int index = 0;
  OUT_CODE oCode;
  struct STRCTS* dataStructure;
  dataStructure = DataStructureGet();
  do
  {
    commandID = rand() % 3;
    key = rand() % 10000000;
    oCode = ExecuteCommand(commandID, &dataStructure, key);
    
    if (oCode == OC_NO)
    {
      printf("%i:\n\t%s %i\n\n", index, commands[commandID].str, key);
    }
    index++;
  } while (index < 10000000);
  DataStructureFree(dataStructure);
  return 0;
}