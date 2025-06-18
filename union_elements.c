// program to print same elements 

//header file
#include<stdio.h>

//function declaration
void display_array(int *,int );

//function definition
void display_array(int *array,int size)
{
    int counter;//counter variable
    
    //printing the array elements
    for(counter=0;counter<size;counter++)
    {
        printf("%d ",array[counter]);
    }
    printf("\n");
    

}
//main function
void main()
{
    int array1[]={1,3,5,7,9};//first array constant
    int array2[]={3,5,6,5,5};//second array constant
    int size1=sizeof(array1)/sizeof(array1[0]);//to store size of 1st array
    int size2=sizeof(array2)/sizeof(array2[0]);//to store size of 1st array
    int counter1;//counter variable
    int counter2;//another counter variable
    
    //printing the arrays
    printf("set 1:\n");
    display_array(array1,size1);
    printf("set 2:\n");
    display_array(array2,size2);
    //finding the same elements
    printf("comman elements :\n");
    for(counter1=0;counter1<size1;counter1++)
    {
        for(counter2=0;counter2<size2;counter2++)
        {
            if(array1[counter1]==array2[counter2])
            {
                printf("%d ",array1[counter1]);
                break;
            }
        }
    }
    printf("\n");
}
