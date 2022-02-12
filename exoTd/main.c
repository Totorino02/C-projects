#include <stdio.h>
#include <stdlib.h>
#include "liste.c"

int main()
{
    list *myList;
    myList = construct();
    printf("%d", length(myList));
    return 0;
}
