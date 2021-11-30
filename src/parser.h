#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include "libro.h"

int parser_BookFile(FILE* pFile , LinkedList* pArrayBookList);
int parser_EditorialFile (FILE* pFile , LinkedList* pArrayEditorialList);

#endif
