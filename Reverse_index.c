//header file
#include<stdio.h>
#include<stdlib.h>

//main function
void main()
{
    struct node
    {
        int data;
        struct node *previous;
        struct node *next;
    };
    struct node *head,*old,*fresh,*finder;//struct and struct variable
    int size;//to store size
    int counter;//counter variable
    int reverse_index;//to store the reverse index value
    
    //reading the size
    printf("enter the size:");
    scanf("%d",&size);
    if(size<=0)
    {
        exit(1);
    }

    //reading the list elements 
    printf("enter the elements:\n");
    head=malloc(sizeof(struct node));
    scanf("%d",&head->data);
    head->previous=NULL;
    head->next=NULL;
    old=head;
    for(counter=0;counter<size-1;counter++)
    {
        fresh=malloc(sizeof(struct node));
        scanf("%d",&fresh->data);
        fresh->previous=old;
        fresh->next=NULL;
        old->next=fresh;
        old=old->next;
    }
    finder=fresh;
    
    //reading the reverse index value
    printf("enter the index:");
    scanf("%d",& reverse_index);
    if(reverse_index<=0||reverse_index>size)
    {
        printf("-1\n");
        printf("*-1 indicates no index found*\n");
        exit(2);
    }

    //finding and printing the reverse index value;
    counter=1;
    while(counter!=reverse_index)
    {
       finder=finder->previous;
       counter++;
    }
    printf("value:%d\n",finder->data);
}
