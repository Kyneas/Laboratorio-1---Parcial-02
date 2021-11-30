#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include "libro.h"
#include "parser.h"

//int controller_loadBooks(LinkedList* pArrayBookList);
//int controller_loadEditorials (LinkedList* pArrayEditorialList);
int controller_loadTextFile (LinkedList* pArrayList, char* mensaje, int (*pFuncParseo) (FILE* , LinkedList* ));
int controller_sortBooksByAuthor (LinkedList* pArrayBookList);
int controller_ListBooks (LinkedList* pArrayBookList, LinkedList* pArrayEditorialList);
int controller_saveNewList (LinkedList* pArrayBookList, LinkedList* (*fn)(LinkedList*, int (*fn)(void*)), int (*pFunCriterio)(void*), char * path);
//int controller_filterEditorialMinotauro (LinkedList* pArrayBookList);
//int controller_applyDiscounts (LinkedList* pArrayBookList);
int controller_applyDiscounts (LinkedList* pArrayBookList, int (*pFuncion)(LinkedList*, int (*fn)(void*)), int (*pCriterio)(void*), char * path);

void BorrarLinkedListYLibros (LinkedList* pArray);
void BorrarLinkedListYEditoriales (LinkedList* pArray);

#endif
