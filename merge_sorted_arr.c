//header file
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

//function declaration
void input(int array[MAX],int length);
int compare(const void *a ,const void *b);
//function definition
void input(int array[MAX],int length)
{
    int counter;
    printf("Enter the elements:\n");
    for(counter=0;counter<length;counter++)
    {
        scanf("%d",&array[counter]);
    }
}
int compare(const void *a ,const void *b)
{
    return(*(int*)a-*(int*)b);
}
//main function
void main()
{
    int array1[MAX];
    int array2[MAX];
    int length1;
    int length2;
    int counter1;
    int counter2;
    printf("Enter the length for array1:");
    scanf("%d",&length1);
    input(array1,length1);
    qsort(array1,length1,sizeof(int),compare);
    printf("Enter the length for array2:");
    scanf("%d",&length2);
    input(array2,length2);
    qsort(array2,length2,sizeof(int),compare);
    counter1=length1;
    for(counter2=0;counter2<length2;counter2++)
    {
        array1[counter1]=array2[counter2];
        counter1++;
    }
    qsort(array1,counter1,sizeof(int),compare);
    for(counter2=0;counter2<counter1;counter2++)
    {
        printf("%d ",array1[counter2]);
    }
}