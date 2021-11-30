#include "editorial.h"


void editorial_delete(eEditorial* this) {
	if (this != NULL) {
		free(this);
	}
}

int editorial_findDescriptionById (LinkedList* pArrayEditorialList, int id, char* name) {
	int rtn = -1;
	int len;
	int auxId;
	eEditorial* pAuxEditorial;
	if (pArrayEditorialList != NULL && name != NULL) {
		len = ll_len(pArrayEditorialList);

		for (int i = 0 ; i < len ; i++) {

			pAuxEditorial = ll_get(pArrayEditorialList, i);

			if (pAuxEditorial != NULL && editorial_getId(pAuxEditorial, &auxId) == 0 && auxId == id && editorial_getName(pAuxEditorial, name) == 0) {
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

eEditorial* editorial_new() {
	eEditorial* pEditorial;

	pEditorial = (eEditorial*) calloc (sizeof(eEditorial),1);

	return pEditorial;
}

eEditorial* editorial_newParametros (char* idStr, char* nameStr) {
	eEditorial* pEditorial;
	int id;

	pEditorial = editorial_new();

	if (pEditorial != NULL && idStr != NULL && nameStr != NULL) {
		id = atoi(idStr);

		editorial_setId(pEditorial, id);
		editorial_setName(pEditorial, nameStr);
	}

	return pEditorial;
}

int editorial_setId (eEditorial* this, int id) {

	int rtn = -1;

	if (this != NULL) {
		this -> idEditorial = id;
		rtn = 0;
	}

	return rtn;
}

int editorial_setName (eEditorial* this, char* name) {

	int rtn = -1;

	if (this != NULL) {
		strcpy (this -> nombre, name);
		rtn = 0;
	}

	return rtn;
}

int editorial_getId (eEditorial* this, int* id) {
	int rtn = -1;

	if (this != NULL && id != NULL) {
		*id = this -> idEditorial;
		rtn = 0;
	}

	return rtn;
}

int editorial_getName (eEditorial* this, char* name) {
	int rtn = -1;

	if (this != NULL && name != NULL) {
		strcpy (name, this -> nombre);
		rtn = 0;
	}

	return rtn;
}
