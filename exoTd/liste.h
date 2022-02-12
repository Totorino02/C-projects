#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
typedef struct list {
    int data;
    struct list *suivant;
}list;

typedef enum{
    false,
    true
}Bool;


/** Definition des prototypes de fonctions */

//list construct (int h, list *t);
list * construct();
list * copy_list (list *l);
int length(list *l);
Bool isEmpty(list *l);

#endif // LISTE_H_INCLUDED
