#include <stdlib.h>
#include <stdio.h>
#include "liste.c"

int main()
{
    List myliste = newList();
    myliste = addToTop(myliste, 25);
    myliste = addToTop(myliste, 40);
    myliste = addToBack(myliste, 36);
    myliste = addToTop(myliste, 91);
    myliste = addToBack(myliste, 72);
    myliste = addToTop(myliste, 9);
    myliste = addAt(myliste, 20, 3);
    myliste = removeTop(myliste);
    removeAt(myliste, 3);
    showList(myliste);
    myliste = sort(myliste);
    showList(myliste);
    //isEmpty(myliste) ? printf("True\n") : printf("False\n") ;
    //printf("%d\n", listLength(myliste));
    //search(myliste, 85);
    return 0;
}
