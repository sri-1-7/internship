//header file
#include"create_node.h"

//main function
void main()
{
    struct node *head,*old;//structure and structure variables for creating linked list
    int limit=1;//to get the size
    int mid;//to find mid and store mid
    int traverse;//to find mid
    int counter;//counter variable
    
    //reading the input
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&head->data);
    head->link=NULL;
    old=head;
    printf("if u want to enter one more value [1-yes/0-no]:");
    scanf("%d",&counter);
    if(counter=1)
    {
    limit=create_node(&old);
    }

    //finding and printing mid
    traverse=0;
    mid=limit/2;
    old=head;
    while(traverse<mid)
    {
        old=old->link;
        traverse++;
    }
    mid=old->data;
    printf("%d is the mid element\n",mid);
}