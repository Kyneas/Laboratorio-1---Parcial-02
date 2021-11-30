/*
Desarrollar en ANSI C:
Un programa que realice lo siguiente:

1. Leer un archivo con los datos de libros, guard�ndolos en un linkedList de entidades
eLibro.
ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de
comandos.

2. Leer un archivo con los datos de editoriales, guard�ndolos en un linkedList de entidades
eEditorial.
ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de
comandos.

3. Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio de
ordenamiento �Autor� de manera ascendente.

4. Imprimir por pantalla todos los datos de los libros.
ACLARACI�N: Se deber� imprimir la descripci�n de la editorial.

5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deber� utilizar la
funci�n ll_filter* del LinkedList. Guardar el listado en un archivo csv.

Detalle de la funci�n �ll_filter()�
Prototipo de la funci�n:
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
La funci�n �ll_filter� recibir� una lista y una funci�n criterio �fn�. Se deber� iterar todos los elementos
de la lista y pasarlos a la funci�n �fn�. La funci�n �fn� devolver� 1 si ese �tem se debe agregar a la
lista resultado o 0 si no debe agregarse. La funci�n �ll_filter� generar� la nueva lista resultado,
agregar� a la misma los �tems correspondientes y la devolver�.

Datos:
eLibro:
� id
� titulo
� autor
� precio
� idEditorial
eEditorial:
� idEditorial
� nombre

Las editoriales con las que trabajaremos son las siguientes. Deber�n generar un archivo csv con
estos datos.
1 - PLANETA
2 - SIGLO XXI EDITORES
3 - PEARSON
4 - MINOTAURO
5 - SALAMANDRA
6 - PENGUIN BOOKS

										Parte 2

Desarrollar la funci�n ll_map en la biblioteca linkedList, la cual recibir� la lista y una funci�n.
La funci�n ll_map ejecutar� la funci�n recibida como par�metro por cada �tem de la lista, de
este modo se realizar�n descuentos a los precios seg�n se detalla:
* PLANETA: 20% (si el monto es mayor o igual a $300)
* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
Agregar la siguiente opcion al men� de usuarios:
6. Generar el archivo de salida �mapeado.csv� luego de aplicar la funci�n map.

NOTAS:
Nota 0: El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y respetar las
reglas de estilo de la c�tedra.
Nota 1: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Nota 2: Se deber�n utilizar las bibliotecas LinkedList, Libro y Editorial (desarrollando las funciones setter y getter
necesarias).
Nota 3: Los datos (editoriales y libros) deber�n estar en listas separadas, realizando las relaciones
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
