//rotate the array in 90'

//header file
#include<stdio.h>
//main function
void main()
{
    int array[3][3];//array constant
    int counter1;//counter variable
    int counter2;//another counter variable
    printf("*Enter 3x3 matrix*\n\n");
    
    //reading the 3x3 matrix
    for(counter1=0;counter1<3;counter1++)
    {
        for(counter2=0;counter2<3;counter2++)
    {
            printf("Enter [%d %d]:",counter1,counter2);
            scanf("%d",&array[counter1][counter2]);
    }  
    }
    printf("\n");
    
    //printing the 3x3 matrix
    printf("The entered array\n");
    for(counter1=0;counter1<3;counter1++)
    {
        for(counter2=0;counter2<3;counter2++)
    {
            printf("%d ",array[counter1][counter2]);
    }  
    printf("\n");
    }
    printf("\n");
    
    //printing the rotated 3x3 matrix
    printf("The rotated array:\n");
    for(counter1=0;counter1<3;counter1++)
    {
        for(counter2=2;counter2>=0;counter2--)
    {
            printf("%d ",array[counter2][counter1]);
    }  
    printf("\n");
    }
    printf("\n");
    
}