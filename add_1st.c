//headeer file
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

//function declaration
struct node* create_node(struct node **add)
{
    struct node *fresh;//structure variable for link nodes
    int counter=1;//counter variable

    //linking nodes
    while(counter)
    {
        printf("Enter:");
        fresh=malloc(sizeof(struct node));
        scanf("%d",&fresh->data);
        fresh->link=*add;
        *add=fresh;
        printf("Want to create an another node [1-yes/0-no]:");
        scanf("%d",&counter);
    }
    return fresh;
}

//main function
void main()
{
    struct node *head,*add;//structure variable;
    int counter=1;//counter variable

    //allocating memory for head
    head=malloc(sizeof(struct node));
    //reading the head data
    printf("Enter the data:");
    scanf("%d",&head->data);
    head->link=NULL;
    
    //creating extra nodes
    printf("Want to create an another node [1-yes/0-no]:");
    scanf("%d",&counter);
    if(counter==1)
    {
      add=head;  
      head=create_node(&add);  
    }

    //printing the datas
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->link;
    }
}