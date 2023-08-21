#include<stdio.h>
int main()
{
    int l,b;
    float r;
    int ch;
    printf("Enter your choice");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("Enter the length of the sides");
        scanf("%d",&l);
        printf("Area=%d",(l*l));
        break;
    case 2:
        printf("Enter the length and breadth of the sides");
        scanf("%d %d",&l,&b);
        printf("Area=%d",(l*b));
        break;
    case 3:
        printf("Enter the radius");
        scanf("%f",&r);
        printf("Area=%f",(r*r*3.14));
        break;
    
    default:
    printf("INVALID CHOICE");
        break;
    }
    return 0;
}