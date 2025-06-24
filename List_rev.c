//header file
#include<stdio.h>
#include<stdlib.h>

//main function
void main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head,*old,*fresh,*current,*nextt=NULL,*previous=NULL;//structure and structure variable for creating linked list
    int size;//to store size of linked list
    int counter;//counter variable

    //reading the size
    printf("enter the size:");
    scanf("%d",&size);
    if(size<=0)
    {
        exit(1);
    }

    //reading the elements
    printf("enter the elements:\n");
    head=malloc(sizeof(struct node));
    scanf("%d",&head->data);
    head->next=NULL;
    old=head;
    for(counter=0;counter<size-1;counter++)
    {
     fresh=malloc(sizeof(struct node));
     scanf("%d",&fresh->data);
     fresh->next=NULL;
     old->next=fresh;
     old=old->next;
    }

    //reversing the list
    current=head;
    while(current!=NULL)
    {
        nextt=current->next;
        current->next=previous;
        previous=current;
        current=nextt;
    }
    head=previous;
    old=head;

    //printing the reverse list
    printf("the reversed list is:\n");
    while(old!=NULL)
    {
        printf("%d ",old->data);
        old=old->next;
    }
    
}
