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
    int array[MAX];
    int length;
    printf("Enter the no of elements:");
    scanf("%d",&length);
    int counter1;
    int counter2;
    int counter3;
    printf("Enter the elements:\n");
    for(counter1=0;counter1<length;counter1++)
    {
        scanf("%d",&array[counter1]);
    }
    qsort(array,length,sizeof(int),compare);
    for(counter1=0;counter1<length;counter1++)
    {
       for(counter2=counter1+1;counter2<length;counter2++)
       {
         if(array[counter1]==array[counter2])
         {
            for(counter3=counter2;counter3<length-1;counter3++)
            {
                array[counter3]=array[counter3+1];
            }
            length--;
        } 
       }
    }
    for(counter1=0;counter1<length;counter1++)
    {
        printf("%d ",array[counter1]);
    }
}
