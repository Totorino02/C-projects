#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

List newList(){
    return NULL;
}

// the length of the list
int listLength(List li){
    int cpt = 0;
    while(li != NULL){
        ++cpt;
        li = li->suivant;
    }
    return cpt;
}

/// verify if the List is empty
Bool isEmpty(List li){
    if(listLength(li) == 0)
        return true;
    return false;
}

/// show all the li data
void showList(List li){
    while(li != NULL){
        printf("%d -->  ", li->data);
        li = li->suivant;
    }
    printf("NULL \n");
}

/// add data to the top
List addToTop(List li, int x){
    ListElement *newElem = malloc(sizeof(*newElem));
    newElem->data = x;
    newElem->suivant = li;
    return newElem;
}

/// add data to the end
List addToBack(List li, int x){
    ListElement *newElem = malloc(sizeof(*newElem));
    newElem->data = x;
    newElem->suivant = NULL;

    List current = li;
    while(current->suivant != NULL){
        current = current->suivant;
    }
    current->suivant = newElem;
    return li;
}

/// add data to a specific position
List addAt(List li, int x, int position){
    int cpt = 0;
    ListElement *newElem = malloc(sizeof(*newElem));
    newElem->data = x;

    List current = li;
    List before;

    if(position >= listLength(li)){
        position = listLength(li);
    }else if(position <= 0){
        newElem->suivant = li;
        return newElem;
    }

    while(cpt != position){
        ++cpt;
        before = current;
        current = current->suivant;
    }
    newElem->suivant = current;
    before->suivant = newElem;
    return li;
}

/// remove data from the top
List removeTop(List li){
    ListElement *sndElem = malloc(sizeof(*sndElem));
    sndElem = li->suivant;
    free(li);
    li = NULL;
    return sndElem;
}

/// remove data from the end
List removeBack(List li){
    ListElement *current = malloc(sizeof(*current));
    ListElement *before = malloc(sizeof(*before));

    if(isEmpty(li))
        return;

    current = li;
    while(current != NULL){
        before = current;
        current = current->suivant;
    }
    before->suivant = NULL;
    free(current);
    return li;
}

/// remove data at specific position
void removeAt(List li, int position){
    int cpt = 0;
    ListElement *current = malloc(sizeof(*current));
    ListElement *before = malloc(sizeof(*before));

    if(isEmpty(li))
        return;

    current = li;
    while(cpt != position){
        ++cpt;
        before = current;
        current = current->suivant;
    }
    before->suivant = current->suivant;
    free(current);
}

/// reset all the list
void removeAll(List li){
    if(isEmpty(li))
        return;
    while(li != NULL){
        li = removeTop(li);
    }
}

/// search value in the list
void search(List li, int x){
    int length = listLength(li);
    int cpt = 0;
    while(li != NULL){
        if(li->data == x){
            printf("La valeur %d se trouve à la position %d \n", x, (cpt+1));
            return NULL ;
        }
        li = li->suivant;
        ++cpt;
    }
    printf("non trouvé\n");
}

/// get the value at the specific position
/*int get(List li, int position){
    int i;
    if(isEmpty(li)){
        return -1;
    }
    if(length(li) < position){
        return -1;
    }

    for (int i = 0; i < position; ++i)
    {
        li = li->suivant;
    }

    return li->data;
}*/

/// verify if l1 isEqual to l2
Bool egals(List l1, List l2){
    Bool isMatched = true;

    while(l1 != NULL && l2 != NULL){
        if(l1->data != l2->data){
            isMatched = false;
            break;
        }
        l1 = l1->suivant;
        l2 = l2->suivant;
    }
    return isMatched;
}

//sort the list
List sort(List li){
    ListElement *l1, *l2;
    int temp;
    l1 = li;
    while(l1->suivant != NULL){
        l2 =l1->suivant;
        while(l2 != NULL){
            if(l1->data > l2->data){
                temp = l1->data;
                l1->data = l2->data;
                l2->data = temp;
            }
            l2 = l2->suivant;
        }
        l1 = l1->suivant;
    }
    return li;
}
