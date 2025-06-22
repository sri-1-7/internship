//header file
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
//main function

//function definition
int compare(const void *num1,const void *num2)
{
    return(*(int*)num1-*(int *)num2);
}
void main()
{
    int array[MAX];//array constant
    //counter variables
    int counter1;
    int counter2; 
    int counter3;
    int size;//to store size
    int sum;//to check target
    int target;//to store target value

    //reading the size and elements
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the elements:\n");
    for(counter1=0;counter1<size;counter1++)
    {
        scanf("%d",&array[counter1]);
    }
    printf("Enter the target:");
    scanf("%d",&target);

    qsort(array,size,sizeof(int),compare);
    for(counter1=0;counter1<size-2;counter1++)
    {
        counter2=size-1;
        counter3=counter1+1;
        while(counter2>counter3)
        {
           sum=array[counter1]+array[counter2]+array[counter3];
          if(sum==target)
          {
            printf("sum of indices  %d %d %dvalue gives target values\n",counter1,
            counter2,counter3);
            counter2--;
            counter3++;
          }
          else if(sum<target)
          {
            counter3++;
          }
          else if(sum>target)
          {
            counter2--;
          }
        }
    }
}