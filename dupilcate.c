//header file
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
//function declaration
int compare(const void *num1,const void *num2);
//function definition
int compare(const void *num1,const void *num2)
{
    return(*(int*)num1-*(int*)num2);
}
//main function
void main()
{
    int array[MAX];//array constant
    int length;//to store length of array
    //counter variables
    int counter1;
    int counter2;

    //reading the elements and length
    printf("Enter the no of elements:");
    scanf("%d",&length);
    printf("Enter the elements:\n");
    for(counter1=0;counter1<length;counter1++)
    {
        scanf("%d",&array[counter1]);
    }

    //sorting and removing duplicates
    qsort(array,length,sizeof(int),compare);
    counter2=0;
    for(counter1=1;counter1<length;counter1++)
    {
        if(array[counter1]!=array[counter2])
        {
            counter2++;
            array[counter2]=array[counter1];
        }
    }
    //printing the elements
    printf("%d ",counter2);
    printf("The sorted array withou duplicate:\n");
    for(counter1=0;counter1<=counter2;counter1++)
    {
        printf("%d ",array[counter1]);
    }
}
