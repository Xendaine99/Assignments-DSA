#include<stdio.h>
#include<string.h>
int main()
{
    char str[]="ChaitanyaJayant";
    char str2[]="Hello";
    strcpy(str2,str);
    int n=strlen(str2);
    printf("The length of String is %d",n);
    return 0;
}