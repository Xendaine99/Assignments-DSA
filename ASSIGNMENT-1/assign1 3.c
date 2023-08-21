#include<stdio.h>
int main()
{
    float sal;
    printf("Enter the base salary");
    scanf("%f",&sal);
    if(sal>0&&sal<=14999)
    {
        printf("Tax=%f",(0.15*sal));
    }
    if(sal>15000&&sal<29999)
    {
        printf("Tax=%f",(2250+(sal*0.18)));
    }
    if(sal>30000&&sal<49999)
    {
        printf("Tax=%f",(5400+(sal*0.22)));
    }
    if(sal>50000&&sal<79999)
    {
        printf("Tax=%f",(11000+(sal*0.27)));
    }
    if(sal>80000&&sal<150000)
    {
        printf("Tax=%f",(21600+(sal*0.33)));
    }
    return 0;
}