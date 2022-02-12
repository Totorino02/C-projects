#ifndef DLISTE_H_INCLUDED
#define DLISTE_H_INCLUDED

/**Type declaration*/
typedef enum{
    false,
    true
}Bool;

typedef struct DListNode{
    int value;
    struct DListNode *back;
    struct DListNode *next;
}DListNode, *Node;

typedef struct DList{
    int length;
    struct DListNode *begin;
    struct DListNode *end;
} *DList;

/**Prototypes declaration*/

DList newList(void);
Bool isEmpty(DList li);
int length(DList li);
int firstNode(DList li);
int lastNode(DList li);
void show(DList li);
DList addFront(DList li, int x);
DList addBack(DList li, int x);
DList addAt(DList li, int x, int position);
DList removeFront(DList li);
DList removeBack(DList li);
DList removeAt(DList li, int position);
DList clear(DList li);

#endif // DLISTE_H_INCLUDED
