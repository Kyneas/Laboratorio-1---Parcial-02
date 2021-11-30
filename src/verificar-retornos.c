#include "verificar-retornos.h"

void retornos_loadFile (int estado, int* retorno) {
	if (estado == 0) {
		printf("\nLista cargada con exito.");
	}else {
		printf("\nError al cargar la lista.");
	}
	*retorno = estado;
}

void retornos_sortBooks (int estado) {
	if (estado == 0) {
		printf("\nLista ordenada con exito.");
	} else if (estado == -1) {
		printf("\nError, al ordenar.");
	} else if (estado == -2){
		printf("\nError, es necesario cargar mas elementos para realizar el ordenamiento.");
	} else {
		printf ("\nError, lista nula.");
	}

}

void retornos_listBooks(int estado) {
	if (estado == -1) {
		printf("\nError, al mostrar");
	} else if (estado == -2){
		printf("\nError, no hay libros/editoriales cargados/as.");
	} else if (estado == -3){
		printf("\nError, lista nula.");
	}
}

void retorno_saveNewList (int estado) {
	if (estado == 0) {
		printf ("\nArchivo filtrado y guardado con exito.");
	} else if (estado == -1) {
		printf ("\nLa lista filtrada no contiene elementos.");
	} else if (estado == -2) {
		printf ("\nError al crear el archivo.");
	} else if (estado == -3) {
		printf ("\nError al crear la nueva lista.");
	}else if (estado == -4){
		printf ("\nNo se genero la lista filtrada ya que la lista original no contiene elementos.");
	} else {
		printf ("\nError, lista/path nula/o.");
	}
}

void retorno_apllyDiscount (int estado) {
	if (estado == 0) {
		printf ("\nArchivo filtrado y guardado con exito.");
	} else if (estado == -1) {
		printf ("\nError al crear el archivo.");
	} else if (estado == -2) {
		printf ("\nNo se genero la lista con descuentos ya que no hay elementos.");
	} else {
		printf ("\nError, lista/path nula/o.");
	}
}
