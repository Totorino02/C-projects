#include <stdio.h>
#include <stdlib.h>
#include "dliste.c"

int main()
{
    printf("\t\t**** Test cases ****\n\n");
    DList myList = newList();
    myList = addFront(myList,12);
    myList = addFront(myList,18);
    myList = addBack(myList,54);
    myList = addAt(myList, 14, 2);
    myList = addAt(myList, 20, 2);
    show(myList);
    printf("\nFirstNode: %d \nLastNode: %d \n\n", firstNode(myList), lastNode(myList));
    myList = removeFront(myList);
    show(myList);
    printf("\n");
    myList = removeAt(myList,3);
    show(myList);
    printf("\n");
    myList = clear(myList);
    show(myList);
    printf("\n");
    printf("Length: %d AND %d", length(myList), myList->length);
    printf("\n");
    return 0;
}
