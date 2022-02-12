#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

/**Types declaration**/
typedef enum{
    false,
    true
}Bool;

typedef struct ListElement{
    int data;
    struct ListElement *suivant;
}ListElement, *List;

/**Functions prototype declaration**/
List newList();
void showList(List li);
Bool isEmpty(List li);
int listLength(List li);
List addToTop(List li, int x);
List addToBack(List li, int x);
List addAt(List li, int x, int position);
void removeAt(List li, int position);
void removeAll(List li);
List removeTop(List li);
void search(List li, int x);
int get(int x);
Bool egals(List l1, List l2);
List sort(List li);
#endif // LISTE_H_INCLUDED
