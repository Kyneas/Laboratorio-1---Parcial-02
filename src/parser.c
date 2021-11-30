#include "parser.h"

int parser_BookFile(FILE* pFile , LinkedList* pArrayBookList)
{
	int rtn = -1;
	char id[12];
	char titulo[128];
	char autor[128];
	char precio[12];
	char idEditorial[12];
	eLibro* pLibro;

	if (pFile != NULL && pArrayBookList != NULL) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio,idEditorial);

		while (!feof(pFile)) {

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio,idEditorial);

			if (book_dataIsOK(id, autor, precio, idEditorial)) {

				pLibro = book_newParametros(id, titulo, autor, precio,idEditorial);

				if (pLibro != NULL) {
					if (ll_add(pArrayBookList, pLibro) == 0) {
					rtn = 0;
					}else {
						book_delete(pLibro);
					}
				}
			}
		}
	}
    return rtn;
}

int parser_EditorialFile (FILE* pFile , LinkedList* pArrayEditorialList) {
	int rtn = -1;
	char id[12];
	char nombre[128];
	eEditorial* pEditorial;

	if (pFile != NULL && pArrayEditorialList != NULL) {

		fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);

		while (!feof(pFile)){

			fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);

			if (StringIsNumber(id)) {

				pEditorial = editorial_newParametros(id, nombre);

				if (pEditorial != NULL) {
					if (ll_add(pArrayEditorialList, pEditorial) == 0) {
						rtn = 0;
					}
					else {
						editorial_delete(pEditorial);
					}
				}
			}
		}
	}
	return rtn;
}
