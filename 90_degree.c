//rotate the array in 90'

//header file
#include<stdio.h>
#define MAX 10
//main function
void main()
{
    int array[MAX][MAX];//array constant
    int counter1;//counter variable
    int counter2;//another counter variable
    int rows;
    int coloums;

    //reading the rows and coloms
    printf("Enter the no of row:");
    scanf("%d",&rows);
    printf( "Enter the no of coloum:");
    scanf("%d",&coloums);
    
    //reading the  matrix
    for(counter1=0;counter1<rows;counter1++)
    {
        for(counter2=0;counter2<coloums;counter2++)
    {
            printf("Enter [%d %d]:",counter1,counter2);
            scanf("%d",&array[counter1][counter2]);
    }  
    }
    printf("\n");
    
    //printing the 3x3 matrix
    printf("The entered array\n");
    for(counter1=0;counter1<rows;counter1++)
    {
        for(counter2=0;counter2<coloums;counter2++)
    {
            printf("%d ",array[counter1][counter2]);
    }  
    printf("\n");
    }
    printf("\n");
    
    //printing the rotated matrix
    printf("The rotated array:\n");
    for(counter1=0;counter1<rows;counter1++)
    {
        for(counter2=coloums-1;counter2>=0;counter2--)
    {
            printf("%d ",array[counter2][counter1]);
    }  
    printf("\n");
    }
    printf("\n");
    
}