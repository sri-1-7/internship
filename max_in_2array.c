//header file
#include<stdio.h>
#include<stdlib.h>

//function declaration
int *input(int *array,int length);//to get input of the array
int maxi(int array1[],int array2[],int length1,int length2);
int compare(const void *num1,const void *num2);
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
int compare(const void *num1,const void *num2)
{
    return(*(int*)num1-*(int *)num2);
}
int maxi(int array1[],int array2[],int length1,int length2)
{
    int counter1=length1-1;
    int counter2=length2-1;
    while(counter1!=0&&counter2!=0)
    {
        if(array1[counter1]==array2[counter2])
        {
            return array1[counter1];
        }
        else if(array1[counter1]>array2[counter2])
        {
            counter1--;
        }
        else
        {
            counter2--;
        }
    }
    return 0;
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
    qsort(array1,length_1,sizeof(int),compare);
    printf("Enter the no of elements for array 2:");
    scanf("%d",&length_2);
    array2=input(array2,length_2);
    qsort(array2,length_2,sizeof(int),compare);

    //finding and printing the comman largest number
    max=maxi(array1,array2,length_1,length_2);
    printf("The largest comman element in the both array is :%d\n",max);
}