#include <stdio.h>
typedef struct POINT1
{
    int x, y;
} POINT1;
typedef union POINT2
{
    int x;
    int y;
} POINT2;

int main()
{
    POINT1 P1 = {2,3};
    POINT2 P2;
    printf("\n The coordinates of P1 are %d and %d", P1.x, P1.y);
    P2. x = 4;
    printf("\n The x coordinate of P2 is %d", P2.y);
    P2.y = 5;
    printf("\n The y coordinate of P2 is %d", P2.x);
    return 0;
}
