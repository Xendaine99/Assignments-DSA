#include<stdio.h>
#include<string.h>
int main()
{
    char str[]="Chaitanya";
    char str2[]="Jayant";
    strcat(str,str2);
    int n=strlen(str);
    printf("The length of String is %d",n);
    return 0;
}