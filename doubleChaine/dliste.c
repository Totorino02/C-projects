#include <stdio.h>
#include <stdlib.h>
#include "dliste.h"

DList newList(void){
	return NULL;
}

Bool isEmpty(DList li){
	if(li == NULL)
		return true;
	return false;
}

int length(DList li){
	int cpt = 0;
	if(isEmpty(li))
		return cpt;
	Node node = li->begin;
	while(node != NULL){
        ++cpt;
        node = node->next;
	}
	return cpt;
}

int firstNode(DList li){
    if(isEmpty(li)){
        exit(1);
    }else{
        return li->begin->value;
    }
}

int lastNode(DList li){
    if(isEmpty(li)){
        exit(1);
    }else{
        return li->end->value;
    }
}

void show(DList li){
    Node node = li->begin;
    if(isEmpty(li)){
        printf("[]");
        return;
    }else{
        printf("NULL-> ");
        while(node != NULL){
            printf("[%d]-> ", node->value);
            node = node->next;
        }
        printf("NULL\n");
    }
}

DList addFront(DList li, int x){
    DListNode *node = malloc(sizeof(*node));
    if(node == NULL){
        fprintf(stderr, "Erreur lors de l'allocation de la memoire");
        exit(EXIT_FAILURE);
    }
    //on initialise les pointeurs back et next à null
    node->value = x;
    node->back = NULL;
    node->next = NULL;
    if(isEmpty(li)){
        li = malloc(sizeof(DList));
        li->begin = node;
        li->end = node;
        li->length = 1;
    }else{
        node->next = li->begin;
        li->begin = node;
        li->length++;
    }
    return li;
}

DList addBack(DList li, int x){
    DListNode *newElem = malloc(sizeof(*newElem));
    DListNode * node = li->begin;
    if(newElem == NULL){
        fprintf(stderr, "Erreur lors de l'allocation de la memoire");
        exit(EXIT_FAILURE);
    }

    //on initialise les pointeurs back et next à null
    newElem->value = x;
    newElem->back = NULL;
    newElem->next = NULL;

    if(isEmpty(li)){
        li = malloc(sizeof(DList));
        li->begin = newElem;
        li->end = newElem;
        li->length = 1;
    }else{
        while(node->next != NULL){  //a la fin de la boucle on aura node = li->end
            node = node->next;
        }
        newElem->back = node;
        node->next = newElem;
        li->end = newElem;  //mis à jour du dernier Noeud
        li->length++;
    }
    return li;
}

DList addAt(DList li, int x, int position){
    int cpt = 1;
    DListNode *newElem = malloc(sizeof(*newElem));
    Node current = li->begin;
    Node before;
    Node lastNode;
    if(newElem == NULL){
        fprintf(stderr, "Erreur lors de l'allocation de la memoire");
        exit(EXIT_FAILURE);
    }

    //on initialise les pointeurs back et next à null
    newElem->value = x;
    newElem->back = NULL;
    newElem->next = NULL;

    if(isEmpty(li)){
        li = malloc(sizeof(DList));
        li->begin = newElem;
        li->end = newElem;
        li->length = 1;

    }else{
        if(position <= 1){
            addFront(li, x);
        }else if(position > length(li)){
            addBack(li, x);
        }else{// si on donne une position correct
            while(cpt<position && current != NULL){
                ++cpt;
                before = current;
                current = current->next;
            }
            newElem->next = current;
            before->next = newElem;
            current->back = newElem;
            li->length++;

            //mis à jour du dernier Noeud
            lastNode = li->begin;
            while(lastNode->next != NULL){
                lastNode = lastNode->next;
            }
            li->end = lastNode;
        }
    }
    return li;
}

DList removeFront(DList li){
    Node firstNode = li->begin;
    if(isEmpty(li) || li->length == 1){
        return newList();
    }else{
        li->begin = firstNode->next;
        firstNode->next->back = NULL;
        free(firstNode);
        firstNode = NULL;
        li->length--;
        return li;
    }
}

DList removeBack(DList li){
    Node lastNode = li->end;
    if(isEmpty(li) || li->length == 1){
        return newList();
    }else{
        li->end = li->end->back;
        li->end->next = NULL;
        free(lastNode);
        li->length--;
        return li;
    }
}

DList removeAt(DList li, int position){
    int i;
    Node positionalNode = li->begin;
    if(position >= li->length){
        li = removeBack(li);
        return li;
    }else if(position <= 1 || li->length == 1){
        li = removeFront(li);
        return li;
    }

    for(i = 0; i<(position - 1); i++){
        positionalNode = positionalNode->next;
    }
    positionalNode->back->next = positionalNode->next;
    positionalNode->next->back = positionalNode->back;
    free(positionalNode);
    li->length--;
    return li;
}

DList clear(DList li){
    li->end = NULL;
    Node current;
    while(li->begin != NULL){
        current = li->begin;
        li->begin = li->begin->next;
        free(current);
        li->length--;
    }
    return li;
}
