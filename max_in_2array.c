//header file
#include<stdio.h>
#include<stdlib.h>

//function declaration
int *input(int *array,int length);//to get input of the array

//function definition
int *input(int *array,int length)
{
    int counter;
    array=(int *)malloc(length*sizeof(int));
    for(counter=0;counter<length;counter++)
    {
        scanf("%d",&array[counter]);
    }
    return array;
}
//main function
int main()
{
    //array constants
    int *array1;
    int *array2;
    //to store the lenght of the array
    int length_1;
    int length_2;
    //counter variables
    int counter1;
    int counter2;
    //to store the maximum
    int max=0;
    printf("Enter the no of elements for array 1:");
    scanf("%d",&length_1);
    array1=input(array1,length_1);
    printf("Enter the no of elements for array 2:");
    scanf("%d",&length_2);
    array2=input(array2,length_2);

    //finding and printing the comman largest number
    for(counter1=0;counter1<length_1;counter1++)
    {
        for(counter2=0;counter2<length_2;counter2++)
        {
            if(array1[counter1]==array2[counter2])
            {
                if(array1[counter1]>max)
                {
                    max=array1[counter1];
                }
            }
        }
    }
    printf("The largest comman element in the both array is :%d\n",max);
    getch();
}