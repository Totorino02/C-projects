#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int cpt1 = 0, cpt2 = 0;
char infix[50], postfix[50], stack[50];
//stack[0] = '(';
void infToPost(char infix[]){
    int i;
    void push(char c);
    void pushToPost(char c);
    char pop();
    setlocale(LC_CTYPE, "");
    //infix = strcat(infix, ')');
    for(i = 0; i<strlen(infix); i++){
        // to add operands
        if(isalpha(infix[i]) || isdigit(infix[i]))
        {
            pushToPost(infix[i]);
            printf("1 %c\n",infix[i]);
        }
        else{
            if(infix[i] == '(')
            {
                push(infix[i]);
                printf("2\n");
            }else{
                if(infix[i] == ')')
                {
                    while (stack[cpt1] =! '(')
                    {
                       pushToPost(pop());
                    }
                    cpt2--;
                    printf("3\n");

                }else{
                    if(infix[i] == '+' || infix[i] == '-')
                    {
                        while (stack[cpt1] =! '(')
                        {
                            pushToPost(pop());
                        }
                        push(infix[i]);
                        printf("4\n");
                    }else{
                        if(infix[i] == '%')
                        {
                            while (stack[cpt1] =! '(' )
                            {
                                pushToPost(pop());
                            }
                            push(infix[i]);
                            printf("5\n");
                        }else{
                            while (stack[cpt1] == '/' || stack[cpt1] == '*')
                            {
                                pushToPost(pop());
                            }
                            push(infix[i]);
                            printf("6\n");
                        }
                    }
                }
            }
        }
    }

    printf("%s\n%s\n%s",infix,stack,postfix);
}

void push(char c){
    stack[cpt1] = c;
    cpt1++;
}

void pushToPost(char c){
    postfix[cpt2] = c;
    cpt2++;
}


char pop(){
    return stack[cpt2--];
}
