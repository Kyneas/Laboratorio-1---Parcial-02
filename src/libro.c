#include "libro.h"

static int recorrerLibrosYmostrarlos (int len, LinkedList* pArrayBookList,LinkedList* pArrayEditorialList);

void book_delete(eLibro* this) {
	if (this != NULL) {
		free(this);
	}
}

int book_dataIsOK (char * id, char* autor, char* precio, char* idEditorial) {
	int rtn = 0;

	if (id != NULL && autor != NULL && precio != NULL && idEditorial &&
		StringIsNumber(id) &&
		!EsNombreInvalido(autor) &&
		StringIsFloat(precio) &&
		StringIsNumber(idEditorial)) {

		rtn = 1;
	}

	return rtn;
}

int book_applyDiscount (void* book) {
	int rtn = -1;
	eLibro* pLibro;
	float precio;
	int editorial;

	if (book != NULL) {
		pLibro = (eLibro*) book;

		if (book_getPrice(pLibro, &precio) == 0 && book_getIdEditorial(pLibro, &editorial) == 0) {
			rtn = 0;

			if (editorial == 1 && precio >= 300) {
				precio *= 0.8;

				if (book_setPrice(pLibro, precio) == 0) {
					rtn = 1;
				}

			}else if (editorial == 2 && precio <= 200) {
				precio *= 0.9;

				if (book_setPrice(pLibro, precio) == 0) {
					rtn = 1;
				}
			}
		}
	}
	return rtn;
}

int book_editorialIsMinotauro (void* book) {
	int rtn = 0;
	eLibro* pLibro;
	int editorial;

	if (book != NULL) {
		pLibro = (eLibro*) book;

		if (book_getIdEditorial(pLibro, &editorial) == 0 && editorial == 4) {
			rtn = 1;
		}

	}
	return rtn;
}

int book_compareByAuthor (void* element1, void* element2) {
	int rtn = 0;
	eLibro* pLibro1;
	eLibro* pLibro2;
	char nombre1[128];
	char nombre2[128];

	if (element1 != NULL && element2 != NULL) {
		pLibro1 = (eLibro*) element1;
		pLibro2 = (eLibro*) element2;

		book_getAuthor(pLibro1, nombre1);
		book_getAuthor(pLibro2, nombre2);

		rtn = strcmp (nombre1,nombre2);

	}

	return rtn;
}

int book_show (eLibro* pLibro, LinkedList* pArrayEditorialList) {
	int rtn = -1;

	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int idEditorial;
	char editorial[128];

	if (pLibro != NULL &&
		book_getAll(pLibro, &id, titulo, autor, &precio, &idEditorial) == 0 &&
		editorial_findDescriptionById(pArrayEditorialList, idEditorial, editorial) == 0){

		printf ("%-6d %-35s %-25s %-8.2f %-35s\n", id, titulo, autor, precio, editorial);

		rtn = 0;

	}

	return rtn;
}

int book_showAll (LinkedList* pArrayBookList, LinkedList* pArrayEditorialList) {
	int rtn = -2;
	int lenLibros;
	int lenEditoriales;

	if (pArrayBookList != NULL && pArrayEditorialList != NULL) {
		lenLibros = ll_len(pArrayBookList);
		lenEditoriales = ll_len(pArrayEditorialList);

		if (lenLibros > 0 && lenEditoriales > 0) {
			rtn = recorrerLibrosYmostrarlos(lenLibros, pArrayBookList, pArrayEditorialList);
		}
	}


	return rtn;
}

static int recorrerLibrosYmostrarlos (int len, LinkedList* pArrayBookList,LinkedList* pArrayEditorialList) {
	int rtn = -1;
	eLibro* pLibro;

	for (int i = 0 ; i < len ; i++) {
		pLibro = ll_get(pArrayBookList, i);
		if (book_show(pLibro, pArrayEditorialList) == 0) {
			rtn = 0;
		}

	}

	return rtn;
}

eLibro* book_new () {
	eLibro* pLibro;

	pLibro = (eLibro*)calloc(sizeof(eLibro),1);

	return pLibro;
}

eLibro* book_newParametros (char* idStr, char* titleStr, char* authorStr, char* priceStr, char* editorialStr) {
	eLibro* pLibro;
	int id;
	float precio;
	int idEditorial;

	pLibro = book_new();

	if (pLibro != NULL && idStr != NULL && titleStr != NULL && authorStr != NULL && priceStr != NULL && editorialStr != NULL) {

		id = atoi(idStr);
		precio = atof(priceStr);
		idEditorial = atoi(editorialStr);

		book_setAll(pLibro, id, titleStr, authorStr, precio, idEditorial);
	}

	return pLibro;
}

int book_setAll (eLibro* this, int id, char* title, char* author, float price, int editorial) {
	int rtn = -1;

	if (this != NULL) {
		book_setId(this, id);
		book_setTitle(this, title);
		book_setAuthor(this, author);
		book_setPrice(this, price);
		book_setEditorial(this, editorial);

		rtn = 0;
	}

	return rtn;
}

int book_setId (eLibro* this, int id) {

	int rtn = -1;

	if (this != NULL) {
		this -> id = id;
		rtn = 0;
	}
	return rtn;
}

int book_setTitle (eLibro* this, char* title) {
	int rtn = -1;

	if (this != NULL) {
			strcpy(this -> titulo ,title);
			rtn = 0;
		}

	return rtn;
}

int book_setAuthor (eLibro* this, char* author) {
	int rtn = -1;

	if (this != NULL) {
			strcpy(this -> autor ,author);
			rtn = 0;
		}

	return rtn;
}

int book_setPrice (eLibro* this, float price) {
	int rtn = -1;

	if (this != NULL) {
			this -> precio = price;
			rtn = 0;
		}

	return rtn;
}

int book_setEditorial (eLibro* this, int editorial) {
	int rtn = -1;

	if (this != NULL) {
			this -> idEditorial = editorial;
			rtn = 0;
		}

	return rtn;
}

int book_getId(eLibro* this,int* id) {
	int rtn = -1;

	if (this != NULL && id != NULL) {
		*id = this -> id;
		rtn = 0;
	}

	return rtn;
}

int book_getTitle(eLibro* this,char* title) {
	int rtn = -1;

	if (this != NULL && title != NULL) {
		strcpy(title, this -> titulo);
		rtn = 0;
	}

	return rtn;
}

int book_getAuthor(eLibro* this,char* author) {
	int rtn = -1;

	if (this != NULL && author != NULL) {
		strcpy(author, this -> autor);
		rtn = 0;
	}

	return rtn;
}

int book_getPrice(eLibro* this,float* price) {
	int rtn = -1;

	if (this != NULL && price != NULL) {
		*price = this -> precio;
		rtn = 0;
	}

	return rtn;
}

int book_getIdEditorial(eLibro* this,int* idEditorial) {
	int rtn = -1;

	if (this != NULL && idEditorial != NULL) {
		*idEditorial = this -> idEditorial;
		rtn = 0;
	}

	return rtn;
}

int book_getAll (eLibro* this,int* id,char* title,char* author,float* price,int* idEditorial) {
	int rtn = -1;
	int auxID;
	char auxTitulo[128];
	char auxAutor[128];
	float auxPrecio;
	int auxIdEditorial;

	if (this != NULL &&
		book_getId(this, &auxID) == 0 && book_getTitle(this, auxTitulo) == 0 && book_getAuthor(this, auxAutor) == 0 &&
		book_getPrice(this, &auxPrecio) == 0 && book_getIdEditorial(this, &auxIdEditorial) == 0) {

		*id = auxID;
		strcpy(title, auxTitulo);
		strcpy(author, auxAutor);
		*price = auxPrecio;
		*idEditorial = auxIdEditorial;

		rtn = 0;
	}
	return rtn;
}
