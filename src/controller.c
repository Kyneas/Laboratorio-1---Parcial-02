#include "controller.h"

static int GuardarListaEnArchivo (LinkedList* pArrayBookList, FILE* pArchivo);
static int CrearArchivoGuardarloYCerrarlo (LinkedList* pArrayBookList, char* path);

int controller_loadTextFile (LinkedList* pArrayList, char* mensaje, int (*pFuncParseo) (FILE* , LinkedList* )) {
	int rtn = -1;
	FILE* pFile;
	char path[128];

	if (pArrayList != NULL) {

		PedirCadena(path, sizeof(path), mensaje, "\nError.");
		pFile = fopen (path, "r");

		if (pFile) {
			rtn = pFuncParseo(pFile, pArrayList);
			fclose(pFile);
		}
	}

	return rtn;
}

int controller_sortBooksByAuthor (LinkedList* pArrayBookList) {
	int rtn = -3;

	if (pArrayBookList != NULL) {
		rtn = -2;

		if (!ll_isEmpty(pArrayBookList)) {
			printf("\nOrdenando lista...");
			rtn = ll_sort(pArrayBookList, book_compareByAuthor, 1);
		}
	}

	return rtn;
}

int controller_ListBooks (LinkedList* pArrayBookList, LinkedList* pArrayEditorialList) {
	int rtn = -3;

	if (pArrayBookList != NULL && pArrayEditorialList != NULL) {

		rtn = book_showAll(pArrayBookList, pArrayEditorialList);

	}
	return rtn;
}

int controller_saveNewList (LinkedList* pArrayBookList, LinkedList* (*pFunCNuevaLista)(LinkedList*, int (*fn)(void*)), int (*pFunCriterio)(void*), char * path) {
	int rtn = -5;
	LinkedList* pNewList;

	if (pArrayBookList != NULL && path != NULL) {
		rtn = -4;
		if (!ll_isEmpty(pArrayBookList)) {

			rtn = -3;
			pNewList = pFunCNuevaLista (pArrayBookList, pFunCriterio);
			if (pNewList != NULL) {

				rtn = CrearArchivoGuardarloYCerrarlo(pNewList, path);
				ll_deleteLinkedList(pNewList);
			}
		}
	}
	return rtn;
}

int controller_applyDiscounts (LinkedList* pArrayBookList, int (*pFuncion)(LinkedList*, int (*fn)(void*)), int (*pCriterio)(void*), char * path) {
	int rtn = -3;

	if (pArrayBookList != NULL && path != NULL) {
		rtn = -2;

		if (!ll_isEmpty(pArrayBookList)) {

			pFuncion(pArrayBookList, pCriterio);

			rtn = CrearArchivoGuardarloYCerrarlo(pArrayBookList,"descuentos.csv");

		}
	}
	return rtn;
}

static int CrearArchivoGuardarloYCerrarlo (LinkedList* pArrayBookList, char* path) {
	int rtn = -2;
	FILE* pArchivo;

	if (pArrayBookList != NULL) {
		pArchivo = fopen (path, "w");
		if (pArchivo != NULL) {

			rtn = GuardarListaEnArchivo(pArrayBookList, pArchivo);
			fclose(pArchivo);
		}
	}
	return rtn;
}

static int GuardarListaEnArchivo (LinkedList* pArrayBookList, FILE* pArchivo) {
	int rtn = -1;
	int len;
	eLibro* pLibro;
	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;

	len = ll_len(pArrayBookList);

	fprintf(pArchivo, "id,titulo,autor,precio,idEditorial\n");

	for (int i = 0 ; i < len ; i++){
		pLibro = (eLibro* )ll_get(pArrayBookList, i);

		book_getAll(pLibro, &id, titulo, autor, &precio, &idEditorial);

		fprintf(pArchivo, "%d,%s,%s,%.2f,%d\n",id,titulo,autor,precio,idEditorial);

		rtn = 0;
	}
	return rtn;
}

void BorrarLinkedListYLibros (LinkedList* pArray) {
	int len;
	eLibro* pLibro;

	if (pArray != NULL) {

		len = ll_len(pArray);

		for (int i = 0 ; i < len ; i++) {
			pLibro = ll_get(pArray, i);
			book_delete(pLibro);
		}

		ll_deleteLinkedList(pArray);

	}
}

void BorrarLinkedListYEditoriales (LinkedList* pArray) {
	int len;
	eEditorial* pEditorial;

	if (pArray != NULL) {

		len = ll_len(pArray);

		for (int i = 0 ; i < len ; i++) {
			pEditorial = ll_get(pArray, i);
			editorial_delete(pEditorial);
		}
		ll_deleteLinkedList(pArray);
	}
}
