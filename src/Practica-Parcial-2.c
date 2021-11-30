/*
Desarrollar en ANSI C:
Un programa que realice lo siguiente:

1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades
eLibro.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.

2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades
eEditorial.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.

3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de
ordenamiento “Autor” de manera ascendente.

4. Imprimir por pantalla todos los datos de los libros.
ACLARACIÓN: Se deberá imprimir la descripción de la editorial.

5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la
función ll_filter* del LinkedList. Guardar el listado en un archivo csv.

Detalle de la función “ll_filter()”
Prototipo de la función:
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
La función “ll_filter” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos
de la lista y pasarlos a la función “fn”. La función “fn” devolverá 1 si ese ítem se debe agregar a la
lista resultado o 0 si no debe agregarse. La función “ll_filter” generará la nueva lista resultado,
agregará a la misma los ítems correspondientes y la devolverá.

Datos:
eLibro:
• id
• titulo
• autor
• precio
• idEditorial
eEditorial:
• idEditorial
• nombre

Las editoriales con las que trabajaremos son las siguientes. Deberán generar un archivo csv con
estos datos.
1 - PLANETA
2 - SIGLO XXI EDITORES
3 - PEARSON
4 - MINOTAURO
5 - SALAMANDRA
6 - PENGUIN BOOKS

										Parte 2

Desarrollar la función ll_map en la biblioteca linkedList, la cual recibirá la lista y una función.
La función ll_map ejecutará la función recibida como parámetro por cada ítem de la lista, de
este modo se realizarán descuentos a los precios según se detalla:
* PLANETA: 20% (si el monto es mayor o igual a $300)
* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
Agregar la siguiente opcion al menú de usuarios:
6. Generar el archivo de salida “mapeado.csv” luego de aplicar la función map.

NOTAS:
Nota 0: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las
reglas de estilo de la cátedra.
Nota 1: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Nota 2: Se deberán utilizar las bibliotecas LinkedList, Libro y Editorial (desarrollando las funciones setter y getter
necesarias).
Nota 3: Los datos (editoriales y libros) deberán estar en listas separadas, realizando las relaciones
correspondientes entre las entidades.
Nota 4: Utilizar MVC (modelo vista controlador)
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "verificar-retornos.h"

int main(void) {
	setbuf(stdout, NULL);
	LinkedList* pArrayBookList;
	LinkedList* pArrayEditorialList;
	int opcion;
	int cargaLibros = -1;
	int cargaEditoriales = -1;

	pArrayBookList = ll_newLinkedList();
	pArrayEditorialList = ll_newLinkedList();

	do {

		if (PedirEnteroEnRangoV3("\n-----------------------------------------------------------"
					                 "\n1- Leer un archivo con los datos de libros."
					                 "\n2- Leer un archivo con los datos de editoriales."
					                 "\n3- Ordenar listado."
					                 "\n4- Mostrar libros"
					                 "\n5- Generar archivo con editorial MINOTAURO"
					                 "\n6- Aplicar descuento y guardar archivo"
					                 "\n7- Salir.", "\nError.", 1, 7, &opcion, 3) == -1) {
			printf("\nMuchos intentos fallidos, reintente luego.");
			break;
		}



		switch (opcion) {
//		case 1:
//			if (cargaLibros != 0) {
//				retornos_loadFile(controller_loadBooks(pArrayBookList), &cargaLibros);
//			}else {
//				printf ("\nEl archivo ya se encuentra cargado.");
//			}
//			break;
//		case 2:
//			if (cargaEditoriales != 0) {
//				retornos_loadFile(controller_loadEditorials(pArrayEditorialList), &cargaEditoriales);
//			}else {
//				printf ("\nEl archivo ya se encuentra cargado.");
//			}
//			break;
		case 1:
			if (cargaLibros != 0) {
				retornos_loadFile(controller_loadTextFile(pArrayBookList, "\nQue archivo de libros quiere cargar?", parser_BookFile), &cargaLibros);

			}else {
				printf ("\nEl archivo ya se encuentra cargado.");
			}
			break;
		case 2:
			if (cargaEditoriales != 0) {
				retornos_loadFile(controller_loadTextFile(pArrayEditorialList, "\nQue archivo de editoriales quiere cargar?", parser_EditorialFile), &cargaEditoriales);

			}else {
				printf ("\nEl archivo ya se encuentra cargado.");
			}
			break;
		case 3:
			retornos_sortBooks(controller_sortBooksByAuthor(pArrayBookList));
			break;
		case 4:
			retornos_listBooks(controller_ListBooks(pArrayBookList, pArrayEditorialList));
			break;
//		case 5:
//			retorno_saveNewList(controller_filterEditorialMinotauro(pArrayBookList));
//			break;
//		case 6:
//			retorno_saveNewList(controller_applyDiscounts(pArrayBookList));
//			break;
		case 5:
			retorno_saveNewList(controller_saveNewList(pArrayBookList, ll_filter, book_editorialIsMinotauro, "minotauro.csv"));
			break;

		case 6:
			retorno_apllyDiscount(controller_applyDiscounts(pArrayBookList, ll_map, book_applyDiscount, "descontados.csv"));
			break;

		}

	}while (opcion != 7);

	BorrarLinkedListYLibros(pArrayBookList);
	BorrarLinkedListYEditoriales(pArrayEditorialList);

	return EXIT_SUCCESS;
}
