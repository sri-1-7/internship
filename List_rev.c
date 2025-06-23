#include<stdio.h>
#include<stdlib.h>
void main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head,*old,*fresh,*current,*nextt=NULL,*previous=NULL;
    int size;
    int counter;
    int reverse_index;
    printf("enter the size:\n");
    scanf("%d",&size);
    if(size<=0)
    {
        exit(1);
    }
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
    printf("the reversed list is:\n");
    while(old!=NULL)
    {
        printf("%d ",old->data);
        old=old->next;
    }
    
}
