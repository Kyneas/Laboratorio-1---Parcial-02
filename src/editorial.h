#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include "utn_matias.h"

typedef struct {

	int idEditorial;
	char nombre[128];

}eEditorial;

void editorial_delete(eEditorial* this);

eEditorial* editorial_new();
eEditorial* editorial_newParametros (char* idStr, char* nameStr);

int editorial_setId (eEditorial* this, int id);
int editorial_setName (eEditorial* this, char* name);

int editorial_getId (eEditorial* this, int* id);
int editorial_getName (eEditorial* this, char* name);

int editorial_findDescriptionById (LinkedList* pArrayEditorialList, int id, char* name);

#endif
