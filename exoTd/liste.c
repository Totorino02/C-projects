#include <stdio.h>
#include "liste.h"

/// constructipon de liste vide
list * construct(){
    //list *newList = malloc(sizeof(list));
    return NULL;
}

/// initialisation de la liste avec un élément
/*list construct(int x, list *newList){
    newList->data = x;
    newList->suivant = NULL;

    return newList;
}*/

int length(list *l){
    int cpt = 0;
    while(l != NULL){
        cpt++;
        l = l->suivant;
    }
    return cpt;
}

Bool isEmpty(list *l){
    if(length(l) == 0){
        return true;
    }
    return false;
}

void free_list(list *newList){
    free(newList);
}

list * copy_list (list *oldList){
    list *newList = malloc(sizeof(list));
    list *current = newList;

    while(oldList !=NULL){
        current->data = oldList->data;
        current = current->suivant;
        oldList = oldList->suivant;
    }
    return newList;
}



