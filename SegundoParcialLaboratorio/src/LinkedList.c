#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/**
 * \brief :
 * \param :
 * \return:
**/
LinkedList* ll_newLinkedList(void){

    LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList*));

    if(this != NULL){

        this->pFirstNode = NULL;
        this->size = 0;
    }

    return this;
}

int ll_len(LinkedList* this){

    int retorno = -1;

    if(this != NULL){

        retorno = this->size;
    }
    return retorno;
}


/**
 * \brief :
 * \param :
 * \return:
**/
static Node* getNode(LinkedList* this, int nodeIndex){

    Node* auxNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){

        auxNode = this->pFirstNode;

        for(int i = 0; i < nodeIndex; i++){

            auxNode = auxNode->pNextNode;
        }
    }
    return auxNode;
}


/**
 * \brief :
 * \param :
 * \return:
**/
static int addNode(LinkedList* this, int nodeIndex,void* pElement){

   int retorno = -1;

   Node* auxNode = (Node*)malloc(sizeof(Node*));
   Node* auxPrevNode = NULL;

    if(auxNode != NULL && this != NULL && nodeIndex >= 0 && pElement != NULL && nodeIndex <= ll_len(this)){

    	auxNode->pElement = pElement;

        if(nodeIndex == 0){

            auxNode->pNextNode = this->pFirstNode;
            this->pFirstNode = auxNode;
            this->size++;
            retorno = 0;

        }else{

           auxPrevNode = getNode(this, nodeIndex-1);

           if(auxPrevNode != NULL){

               auxNode->pNextNode = auxPrevNode->pNextNode;
               auxPrevNode->pNextNode = auxNode;
               this->size++;
               retorno = 0;
           }
        }
    }
    return retorno;
}


/**
 * \brief :
 * \param :
 * \return:
**/
int ll_add(LinkedList* this, void* pElement){

    int retorno=-1;

    if(this != NULL && pElement != NULL){

        if(addNode(this, ll_len(this), pElement) == 0){

            retorno=0;

        }
    }
    return retorno;
}


/**
 * \brief :
 * \param :
 * \return:
**/
void* ll_get(LinkedList* this, int index){

    Node* auxNode = NULL;
    void* pRetorno = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){

       auxNode = getNode(this, index); //Validar.

       if(auxNode != NULL){

    	   pRetorno = auxNode->pElement;
       }
    }
    return pRetorno;
}


/**
 * \brief :
 * \param :
 * \return:
**/
int ll_set(LinkedList* this, int index, void* pElement){

    int retorno = -1;
    Node* auxNode = NULL;

    if(this != NULL && pElement != NULL && index >= 0 && index < ll_len(this)){

        auxNode = getNode(this, index);
        auxNode->pElement = pElement;
        retorno = 0;
    }

    return retorno;
}


/**
 * \brief :
 * \param :
 * \return:
**/
int ll_remove(LinkedList* this, int index){

    int retorno = -1;
    Node* auxNode = NULL;
    Node* auxPrevNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){

        auxNode = getNode(this, index);

        if(index==0){

            this->pFirstNode = auxNode->pNextNode;
            this->size--;


        }else{

            auxPrevNode = getNode(this, index-1);
            auxPrevNode->pNextNode = auxNode->pNextNode;
            this->size--;

        }
        free(auxNode);
        retorno = 0;

    }
    return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int ll_clear(LinkedList* this) {

    int retorno = -1;
    int longitudLinkedList = ll_len(this);

    if (this != NULL && longitudLinkedList > 0) {

        for (int i = 0; i < longitudLinkedList; i++) {

            if(ll_remove(this, 0)){

				retorno = 0;
            }
        }
    }
    return retorno;
}


/**
 * \brief :
 * \param :
 * \return:
**/
int ll_deleteLinkedList(LinkedList* this) {

    int retorno = -1;

    if (this != NULL) {

        if(ll_clear(this) == 0){

			free(this);
			retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int ll_indexOf(LinkedList* this, void* pElement) {

    int retorno = -1;
    int longitudLinkedlist = ll_len(this);
    Node* auxNode;

    if (this != NULL && pElement != NULL && longitudLinkedlist > 0) {

        for (int i = 0; i < longitudLinkedlist; i++) {

            auxNode = getNode(this, i);

            if (auxNode != NULL && auxNode->pElement == pElement) {

                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/**
 * \brief :
 * \param :
 * \return:
**/
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){

    int returnAux =-1;
    int estaOrdenado;
    int longitudThis;
    void* pAuxElement = NULL;
    void* pAuxElementDos = NULL;
    int retornoPFunc;

    if(this != NULL && pFunc!= NULL && (order == 0 || order == 1) ){

    	longitudThis = ll_len(this);

    	do{

    		estaOrdenado = 1;
    		longitudThis--;

    		for(int i = 0; i < longitudThis; i++){

    			pAuxElement = ll_get(this, i);
    			pAuxElementDos = ll_get(this, i+1);
    			retornoPFunc = pFunc(pAuxElement, pAuxElementDos);

    			if((retornoPFunc > 0 && order == 1) || (retornoPFunc < 0 && order == 0)){

    				if(ll_set(this, i, pAuxElementDos) == 0 && ll_set(this, i+1, pAuxElement) == 0){

						estaOrdenado = 0;
    				}
    			}
    		}
    	}while(estaOrdenado == 0);

    	returnAux = 0;
    }
    return returnAux;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int ll_isEmpty(LinkedList* this){

    int retorno = -1;

    if(this!=NULL){

        if(ll_len(this) > 0){

            retorno = 0; //ocupado

        }else{

            retorno = 1; //vacio
        }
    }
    return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int ll_push(LinkedList* this, int index, void* pElement){

    int retorno = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this) && pElement != NULL){

        if(addNode(this, index, pElement) == 0){

			retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
void* ll_pop(LinkedList* this, int index){

    void* retorno = NULL;
    void * auxPElement = NULL;

    if(this!=NULL && index>=0 && index<ll_len(this)){

    	auxPElement = ll_get(this, index);

        if(auxPElement!=NULL){

            retorno = auxPElement;
            ll_remove(this, index);
        }
    }
    return retorno;

}

/**
 * \brief :
 * \param :
 * \return:
**/
int ll_contains(LinkedList* this, void* pElement){

    int retorno=-1;//null

    if(this!=NULL && pElement!=NULL){

        if(ll_indexOf(this,pElement) != -1){

            retorno = 1; //si contiene

        }else{

            retorno = 0; //no contiene
        }
    }
    return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int ll_containsAll(LinkedList* this, LinkedList* this2){

    int retorno=-1;
    int longitudThis2;

    if(this!=NULL && this2!=NULL){  //ver si hay que validar que una list2 sea menor que list

    	longitudThis2 = ll_len(this2);

        if(longitudThis2 == 0){

            retorno = 0;
        }else{

            for(int i = 0; i < longitudThis2; i++){

                if(ll_contains(this, ll_get(this2, i)) == 0){

                    retorno=0;//no contiene
                    break;

                }else{

                    retorno = 1;//contiene
                }
            }
        }
    }
    return retorno;
}

/**
 * \brief :
 * \param :
 * \return:
**/
LinkedList* ll_subList(LinkedList* this, int from, int to) {

    LinkedList* subList = NULL;
    void* pAuxElemento;

    if(this != NULL && to > from && to <= ll_len(this) && from >= 0 && from < ll_len(this)){
        subList = ll_newLinkedList();

        if(subList != NULL){

            for(int i = from ; i < to ; i++){

            	pAuxElemento = ll_get(this,i);

                if(pAuxElemento != NULL){

                    ll_add(subList, pAuxElemento);
                }
            }
        }
    }
    return subList;
}

/**
 * \brief :
 * \param :
 * \return:
**/
LinkedList* ll_clone(LinkedList* this) {

    LinkedList* cloneList = NULL;

    if(this != NULL) {

        cloneList = ll_subList(this, 0, ll_len(this));
    }
    return cloneList;
}

/**
 * \brief :
 * \param :
 * \return:
**/
int ll_count(LinkedList* this, int (*fn)(void* element)){

	int acumulador = 0;
    void* pAuxElemento;
    int longitudThis;

    if(this!=NULL){

    	longitudThis = ll_len(this);

        for(int i = 0; i < longitudThis; i++){

        	pAuxElemento = ll_get(this, i);

        	if(pAuxElemento != NULL){

        		acumulador += fn(pAuxElemento);
        	}
        }
    }
	return acumulador;
}

