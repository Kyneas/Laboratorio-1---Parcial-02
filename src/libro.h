#ifndef LIBRO_H_
#define LIBRO_H_

#include <stdio.h>
#include "editorial.h"

typedef struct {

	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;

} eLibro;

int book_dataIsOK (char * id, char* autor, char* precio, char* idEditorial);

int book_show (eLibro* pLibro, LinkedList* pArrayEditorialList);
int book_showAll (LinkedList* pArrayBookList, LinkedList* pArrayEditorialList);

int book_applyDiscount (void* book);
int book_compareByAuthor (void* element1, void* element2);
int book_editorialIsMinotauro (void* book);
/// @fn void book_delete(eLibro*)
/// @brief Borra el puntero a un eLibro
///
/// @param this eLibro a borrar
void book_delete(eLibro* this);
/// @fn eLibro book_new*()
/// @brief Contructor por defecto de un eLibro
///
/// @return Puntero a eLibro o nulo si no lo pudo conseguir
eLibro* book_new ();
/// @fn eLibro book_newParametros*(char*, char*, char*, char*, char*)
/// @brief Constuctor parametrizado de eLibro
///
/// @param idStr Cadena con los datos del id
/// @param titleStr Cadena con los datos del titulo
/// @param authorStr Cadena con los datos del autor
/// @param priceStr Cadena con los datos del precio
/// @param editorialStr Cadena con los datos de editorial
/// @return Puntero a eLibro o nulo si no lo pudo conseguir
eLibro* book_newParametros (char* idStr, char* titleStr, char* authorStr, char* priceStr, char* editorialStr);

int book_setId (eLibro* this, int id);
int book_setTitle (eLibro* this, char* title);
int book_setAuthor (eLibro* this, char* author);
int book_setPrice (eLibro* this, float price);
int book_setEditorial (eLibro* this, int editorial);
int book_setAll (eLibro* this, int id, char* title, char* author, float price, int editorial);

int book_getId(eLibro* this,int* id);
int book_getTitle(eLibro* this,char* title);
int book_getAuthor(eLibro* this,char* author);
int book_getPrice(eLibro* this,float* price);
int book_getIdEditorial(eLibro* this,int* idEditorial);
int book_getAll (eLibro* this,int* id,char* title,char* author,float* price,int* idEditorial);

#endif
