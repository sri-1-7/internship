//rotate the array in 90'

//header file
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

//function declaration
void display(int array[MAX][MAX],int rows,int coloums);

//function definition
void display(int array[MAX][MAX],int rows,int coloums)
{
    int counter1;
    int counter2;
    for(counter1=0;counter1<rows;counter1++)
    {
        for(counter2=0;counter2<coloums;counter2++) 
        {
            printf("%d ",array[counter1][counter2]);
        }
        printf("\n");
    }
    printf("\n");
}
//main function
void main()
{
    int array[MAX][MAX];//array constant
    int counter1=0;//counter variable
    int counter2=0;//another counter variable
    int counter3=0;
    int rows;
    int coloums;
    int flag=1;
    int flag2=1;
    int temp;
    counter2=0;
    printf("\n\"The no of row and coloum must be 1-10\"\n");
    while(flag2)
    {
    //reading the rows and coloums
    printf("Enter the no of row:");
    while(flag)
    {
        scanf("%d",&rows);
        counter2++;
        if(rows>0&&rows<11)
        {
            flag=0;
        }
        else
        {
            if(rows<=0)
            {
                printf("ur number is less then 1\n");
            }
            else
            {
                printf("ur number is greater then 10\n");
            }
            if(counter2==3)
            {
                 printf("try again\n");
                 exit(1);
            }
            printf("Enter the number 1-10:");
       }
    }
    flag=1;
    printf("Enter the no of coloums:");
    while(flag)
    {
        scanf("%d",&coloums);
        counter1++;
        if(coloums>0&&coloums<11)
        {
            flag=0;
        }
        else
        {
            if(coloums<=0)
            {
                printf("ur number is less then 1\n");
            }
            else
            {
                printf("ur number is greater then 10\n");
            }
            
            
            if(counter1==3)
            {
                 printf("try again\n");
                exit(1);
            }
            printf("Enter the number 1-10:");
        }
    }
    flag=1;
    //reading the matrix elements
    for(counter1=0;counter1<rows;counter1++)
    {
        for(counter2=0;counter2<coloums;counter2++) 
        {
            printf("Enter [%d %d]:",counter1,counter2);
            scanf("%d",&array[counter1][counter2]);
        }
    }
    printf("The entered matrix:\n");
    display(array,rows,coloums);

    //rotating the array
    counter3=rows-1;
    for(counter1=0;counter1<rows/2;counter1++)
    {
        for(counter2=0;counter2<coloums;counter2++)
        {
            temp=array[counter1][counter2];
            array[counter1][counter2]=array[counter3][counter2];
            array[counter3][counter2]=temp;
        }
        counter3--;
    }
    if(coloums>=rows)
    {
    for(counter1=0;counter1<rows;counter1++)
    {
        for(counter2=0;counter2<coloums;counter2++)
        {
            if(counter2>counter1)
            {
            temp=array[counter1][counter2];
            array[counter1][counter2]=array[counter2][counter1];
            array[counter2][counter1]=temp;
            }

        }
    }
    }
    else
    {
    for(counter1=0;counter1<coloums;counter1++)
    {
        for(counter2=0;counter2<rows;counter2++)
        {
            if(counter2>counter1)
            {
            temp=array[counter1][counter2];
            array[counter1][counter2]=array[counter2][counter1];
            array[counter2][counter1]=temp;
            }

        }
    }
    }
    temp=rows;
    rows=coloums;
    coloums=temp;
    printf("rotatated matrix:\n");
    display(array,rows,coloums);
    printf("if u want to continue with another array (any integers  1-10 -yes 0-no):");
    scanf("%d",&flag2);
    counter2=0;
    counter1=0;
    
}
}


        