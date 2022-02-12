#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[50],lettre;
    int cpt = 0, len, i;
    printf("Entrez la lettre: ");
    gets(str);
    printf("la lettre: ");
    scanf("%c", &lettre);

    len = strlen(str);

    for(i = 0; i< len-1; i++){
        if(str[i] == lettre){
            ++cpt;
        }
    }

    printf("lettre %d", cpt);
    return 0;
}
