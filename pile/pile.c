#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


Pile* initStack(){
    return NULL;
}
Bool isEmptyStack(Pile *pile){
    if(pile == NULL)
        return true;
    return false;
}
int length(Pile *pile){
    int cpt = 0;
    while(pile != NULL){
        ++cpt;
        pile = pile->suivant;
    }
    return cpt;

}
Pile* push(int x, Pile *pile){
    Pile *newElem = malloc(sizeof(*newElem));
    newElem->data = x;
    if(isEmptyStack(pile)){
        return newElem;
    }
    newElem->suivant = pile;
    return newElem;
}
Pile* pop(Pile *pile){
    //int data;
    if(isEmptyStack(pile)){
        return 0;
    }
    //data = pile->data;
    pile = pile->suivant;
    return pile;
}

int top(Pile *pile){
    if(isEmptyStack(pile)){
        return -1;
    }
    return pile->data;
}

void show(Pile *pile){
    if(isEmptyStack(pile)){
        printf("NULL");
        return;
    }
    while(pile != NULL){
        printf("[ %d ]->", pile->data);
        pile = pile->suivant;
    }
    printf("NULL\n");
}
