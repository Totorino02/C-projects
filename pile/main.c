#include <stdio.h>
#include <stdlib.h>
#include "pile.c"

int main()
{
    Pile *myPile;
    myPile = initStack();
    myPile = push(90, myPile);
    myPile = push(13, myPile);
    myPile = push(72, myPile);
    myPile = push(8, myPile);
    myPile = push(43, myPile);
    myPile = push(69, myPile);
    printf("length: %d\nTop: %d\n", length(myPile), top(myPile));
    show(myPile);
    myPile = pop(myPile);
    show(myPile);
    myPile = pop(myPile);
    show(myPile);
    myPile = pop(myPile);
    show(myPile);

    return 0;
}
