#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef UTN_MATIAS_H_
#define UTN_MATIAS_H_

int StringIsNumber(char buffer[]);

int EsNombreInvalido (char nombre[]);

int PedirEnteroChar(char mensaje[], char mensajeError[], char numero[], int reintentos);

int PedirEnteroV3(char mensaje[], char mensajeError[], int* numero, int reintentos);

int PedirEnteroEnRangoV3(char mensaje[], char mensajeError[], int min, int max, int* numero, int reintentos);

int utn_getNombre(char* pNombre, char* pMensaje, char* pMensajeError, int limite, int reintentos);

void PedirCadena(char vector[], int largoVector, char mensaje[],
		char mensajeError[]);

int StringIsFloat(char buffer[]);

#endif
