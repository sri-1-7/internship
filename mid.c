//header file
#include<stdio.h>
#include<stdlib.h>

//main function
void main()
{
    struct node
    {
        int data;
        struct node *link
    };struct node *head,*fresh,*old;//structure and structure variables for creating linked list
    int limit;//to get the size
    int mid;//to find mid and store mid
    int traverse;//to find mid
    int counter;//counter variable
    
    //reading the input
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the no of datas:");
    scanf("%d",&limit);
    if(limit<=0)
    {
        printf("Enter the limit <0\n");
        exit(1);
    }
    printf("Enter the datas:\n");
    scanf("%d",&head->data);
    head->link=NULL;
    old=head;
    for(counter=0;counter<limit-1;counter++)
    {
        fresh=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&fresh->data);
        fresh->link=NULL;
        old->link=fresh;
        old=old->link;
    }

    //finding and printing mid
    traverse=0;
    old=head;
    mid=limit/2;
    while(traverse<mid)
    {
        old=old->link;
        traverse++;
    }
    mid=old->data;
    printf("%d is the mid element\n",mid);
}