// to reverse a array according to integer k

//header file
#include<stdio.h>
#include<stdlib.h>

//main function
int main()
{
    int array[]={1,2,3,4,5,6,7,8};//array constant
    int size=sizeof(array)/sizeof(array[0]);//size of array
    int temp;//to store a value temporarily
    int count;//for count purpose
    //counter variables
    int counter1;
    int counter2;
    int k;//interger k mentioned in problem
    
    //reading k value
    printf("Enter the k value:");
    scanf("%d",&k);
    
    //finding and printing the solutions
    if(k>size-1)
    {
        printf("u r bryond the limit");
        exit(1);
    }
    else if(k<0)
    {
        printf("only +ve integers are accepted");
        exit(2);
    }
    else if(k>1)
    {
        for(counter1=0;counter1<size;counter1=counter1+k)
        {
            count=counter1+k-1;
            if(count>=size)
            {
                count=size-1;
                if(counter1+(k/2)==count&&count!=k||counter1+(k/2)>size)
                {
                    temp=array[count-1];
                    array[count-1]=array[count];
                    array[count]=temp;
                    break;
                }
            }
            for(counter2=counter1;counter2<(counter1+(k/2))&&counter2<size;counter2++)
            {
                temp=array[counter2];
                array[counter2]=array[count];
                array[count]=temp;
                count--;
            }
        }
    }
    for(counter1=0;counter1<size;counter1++)
    {
        printf("%d ",array[counter1]);
    }
}
