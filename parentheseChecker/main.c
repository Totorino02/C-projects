#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cpt = -1;
int verifier = 0;
char tab[50];
int main()
{
    int i;
    char pop();
    void push(char c);

    printf("\t\t\t***** Expression verification *****\n\n");
    printf("Entrer the expression: ");
    gets(tab);

    for(i=0; i<strlen(tab); i++){
        if(tab[i] == '{' || tab[i] == '(' || tab[i] == '['){
            push(tab[i]);
        }else if(tab[i] == '}' || tab[i] == ')' || tab[i] == ']'){
            if(pop() == '{' && tab[i] == '}'){
                --verifier;
            }
            if(pop() == '(' && tab[i] == ')'){
                --verifier;
            }
            if(pop() == '[' && tab[i] == ']'){
                --verifier;
            }
            --cpt;
        }
    }

    if(verifier == 0){
        printf("\nValid Expression");
    }else{
        printf("\nInvalid Expression");
    }
    return 0;
}

void push(char c){
    tab[cpt++] = c;
    verifier++;
}

char pop(){
    return tab[cpt-1];
}

