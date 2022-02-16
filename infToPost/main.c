#include <stdio.h>
#include <stdlib.h>
#include "infToPost.c"

int main()
{
    printf("\n\n***** Infix to PostFix *****\n\n");
    infToPost("A–(B/C+(D\%E*F)/G)*H");
    
    return 0;
}

