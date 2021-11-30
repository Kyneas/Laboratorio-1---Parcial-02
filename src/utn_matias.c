#include "utn_matias.h"

/// @fn int EsNumeroEnteroValido(char[], int, int*)
/// @brief Valida que el string ingresada sea un numero valido
///
/// @param buffer String con los datos a verificar
/// @param longitud Largo del string con los datos a verificar
/// @param numero Direccion de memoria donde se guardara el numero en caso de ser valido
/// @return 1 si es numero, 0 en caso de error
static int EsNumeroEnteroValido(char buffer[], int longitud, int* numero);

static int myGets(char * cadena, int longitud);

/// @fn int validarNombre(char*, int)
/// @brief Valida que el string ingresado sea un nombre correcto,  y de serlo se asegura de devolverlo
/// 	   con las iniciales en mayuscula
///
/// @param cadena Nombre a verificar
/// @param limite sizeof del nombre
/// @return -1 en caso de error, 0 en caso de ser un nombre
static int validarNombre(char* cadena, int limite);

void PedirCadena(char vector[], int largoVector, char mensaje[],
		char mensajeError[]) {
	char buffer[1000];

	printf("%s", mensaje);

	while (!myGets(buffer, sizeof(buffer)) || strlen(buffer) > largoVector - 1) {
		printf("%s", mensajeError);
	}

	strncpy(vector, buffer, largoVector - 1);
}

int StringIsFloat(char buffer[]) {
	int esNumero = 1;
	int largo = strlen(buffer);
	int contadorPuntos = 0;

	for (int i = 0; i < largo && buffer[i] != '\0'; i++) {
		if(buffer[i] == '.')
		{
			contadorPuntos++;

			if(contadorPuntos > 1 || largo == 1)
			{
				esNumero = 0;
				break;
			}
			continue;
		}

		if(i == 0 && (buffer[i] == '+' || buffer[i] == '-') && largo > 1)
		{
			if(buffer[1] == '.' && largo == 2)
			{
				esNumero = 0;
				break;
			}
			continue;
		}

		if (!isdigit(buffer[i]))
		{
			esNumero = 0;
			break;
		}
	}

	return esNumero;
}

int StringIsNumber(char buffer[]) {
	int esNumero = 1;
	int largo = strlen(buffer);

	for (int i = 0; i < largo && buffer[i] != '\0'; i++) {
		if((buffer[0] == '+' || buffer[0] == '-') && largo > 1){
			continue;
		}
		if (isdigit(buffer[i]) == 0) {
			esNumero = 0;
			break;
		}
	}

	return esNumero;
}

static int EsNumeroEnteroValido(char buffer[], int longitud, int* numero) {

	int esNumero = 1;
	int largo = strnlen(buffer,longitud);

	for (int i = 0; i < longitud && buffer[i] != '\0'; i++) {

		if((buffer[0] == '+' || buffer[0] == '-') && largo > 1){
			continue;
		}
		if (isdigit(buffer[i]) == 0) {
			esNumero = 0;
			break;
		}
	}

	if (esNumero) {
		*numero = atoi (buffer);

	}

	return esNumero;
}

static int myGets(char * cadena, int longitud){
	int retorno = 0;
	char buffer[4096];
	int largo = sizeof(buffer);

	if(cadena != NULL && longitud > 0){
		fflush(stdin);

		if(fgets(buffer, largo, stdin) != NULL){

			if(buffer[strnlen(buffer, largo) - 1] == '\n'){
				buffer[strnlen(buffer, largo) - 1] = '\0';
			}

			if(strnlen(buffer, largo) <= longitud){
				strncpy(cadena, buffer, longitud);
				retorno = 1;
			}
		}
	}

	return retorno;
}

int EsNombreInvalido (char nombre[]) {
	int noEsNombre = 0;
	int largo = strlen(nombre);

	for (int i = 0 ; i < largo ; i++) {
		if (nombre[i] == ' ') {
			continue;
		}

		if (!isalpha(nombre[i])) {
			noEsNombre = 1;
			break;
		}
	}

	return noEsNombre;
}

int PedirEnteroEnRangoV3(char mensaje[], char mensajeError[], int min, int max, int* numero, int reintentos) {

	char numeroIngresado[20];
	int rtn = -1;
	int longitud = sizeof (numeroIngresado);
	int entero;

	if (mensaje != NULL && mensajeError != NULL && numero != NULL && min < max && reintentos > -1) {

		printf(mensaje);

		do {

			if (myGets(numeroIngresado, longitud) &&
				EsNumeroEnteroValido(numeroIngresado, longitud, &entero) &&
				(entero >= min && entero <= max)) {

				*numero = entero;
				rtn = 0;
				break;
			}

			printf(mensajeError);

			reintentos--;

		} while (reintentos >= 0);

	}

	return rtn;
}

int PedirEnteroV3(char mensaje[], char mensajeError[], int* numero, int reintentos) {

	char numeroIngresado[20];
	int rtn = -1;
	int longitud = sizeof (numeroIngresado);
	int entero;

	if (mensaje != NULL && mensajeError != NULL && numero != NULL && reintentos > -1) {

		printf(mensaje);

		do {

			if (myGets(numeroIngresado, longitud) &&
				EsNumeroEnteroValido(numeroIngresado, longitud, &entero)) {

				*numero = entero;
				rtn = 0;
				break;
			}

			printf(mensajeError);

			reintentos--;

		} while (reintentos >= 0);

	}

	return rtn;
}

int PedirEnteroChar (char mensaje[], char mensajeError[], char numero[], int reintentos) {

	int rtn = -1;
	char numeroIngresado[11];

	if (numero != NULL && mensajeError != NULL && numero != NULL && reintentos > -1) {

		printf(mensaje);

		do {

			if (myGets(numeroIngresado, sizeof(numeroIngresado)) && StringIsNumber(numeroIngresado)) {

				rtn = 0;

				strcpy(numero, numeroIngresado);

				break;

			}

			printf(mensajeError);

			reintentos--;

		}while (reintentos >= 0);

	}

	return rtn;
}

int utn_getNombre(char* pNombre, char* pMensaje, char* pMensajeError, int limite, int reintentos)
{
	int retorno = -1;
	char buffer[limite];

	if(pNombre != NULL && pMensaje != NULL && pMensajeError != NULL && limite > 0 && reintentos > 0)
	{
		do
		{
			printf("%s", pMensaje);

			if(myGets(buffer, sizeof(buffer)) && validarNombre(buffer, sizeof(buffer)) == 1)
			{
				strncpy(pNombre, buffer, limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", pMensajeError);
				reintentos--;
			}
		}while(reintentos);
	}
	return retorno;
}

static int validarNombre(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{

			if ((cadena[i] != ' ') && ((cadena[i] < 'A' || cadena[i] > 'z') || (cadena[i] < 'a' && cadena[i] > 'Z')) )
			{
				retorno = 0;
				break;
			}
			else
			{

				if((i == 0 || cadena[i - 1] == ' '))
				{
					if(cadena[i] >= 'A' && cadena[i] <= 'Z')
					{
						continue;
					}
					else if (cadena[i] >= 'a' && cadena[i] <= 'z')
					{
						cadena[i]=toupper(cadena[i]);
					}
				}
				else if((i != 0 || cadena[i - 1] != ' '))
				{
					if((cadena[i] >= 'a' && cadena[i] <= 'z') && cadena[i-1] != ' ')
					{
						continue;
					}
					else if(cadena[i] >= 'A' && cadena[i] <= 'Z')
					{
						cadena[i]=tolower(cadena[i]);
					}
				}
			}
		}
	}
	return retorno;
}
