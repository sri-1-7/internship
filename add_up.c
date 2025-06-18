//add upto target

//header file
#include<stdio.h>

//main function
void main()
{
    int array[]={2,3,5,6,7};//array constant
    int target;//to store target
    int size=sizeof(array)/sizeof(array[0]);//size of array
    int counter1;//counter variable
    int counter2;//another counter variable
    int flag=0;//flag variable
    
    //reading the target
    printf("Enter the tatget:");
    scanf("%d",&target);
    
    //finding the values and printing
    for(counter1=0;counter1<size;counter1++)
    {
        for(counter2=counter1+1;counter2<size;counter2++)
        {
            if(array[counter1]+array[counter2]==target)
            {
               flag=1;
                printf("%d+%d=%d\n",array[counter1],array[counter2],target);
            }
        }
    }
    if(!flag)
    {
        printf("no values match");
    }
}
