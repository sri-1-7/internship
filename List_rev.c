//header file
#include"create_node.h"

//main function
void main()
{
    struct node *head,*old,*fresh,*previous=NULL,*next=NULL,*current,*trverse;
    int counter;
    head=malloc(sizeof(struct node));
    printf("Enter a value:");
    scanf("%d",&head->data);
    head->link=NULL;
    old=head;
    printf("if u want to enter one more value [1-yes/0-no]:");
    scanf("%d",&counter);
    if(counter=1)
    {
    create_node(&old);
    }
    printf("\nEntered list:\n");
    print(&head);
    current=head;
    while(current!=NULL)
    {
        next=current->link;
        current->link=previous;
        previous=current;
        current=next;
    }
    head=previous;
    printf("\nThe reversed list is:\n");
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->link;
    }

}