#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

typedef struct Pile{
    int data;
    struct Pile *suivant;
}Pile;

typedef enum{
    false,
    true
}Bool;

Pile* initStack();
Pile* push(int x, Pile *pile);
Pile* pop(Pile *pile);
int top(Pile *pile);
int length(Pile *pile);
Bool isEmptyStack(Pile *pile);
void show(Pile *pile);



#endif // PILE_H_INCLUDED
