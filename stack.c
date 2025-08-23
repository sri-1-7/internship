/*stack implementation using linked list*/

//header file
#include<stdio.h>
#include<stdlib.h>

//node declaration
struct node
{
    int data;               //data part 
    struct node *address;   //address part
};
typedef struct node node;

//function declaration
int push(node **head);      //to perform push operation
int pop(node **head);       //to perform pop operation
int isempty(node **head);   //to check stack state
int display(node **head);   //to display

//function definition

//input parameter: node **head
int push(node **head)
{
    node *newnode;  //to create a node

    //reading inputs and creating nodes
    printf("Enter the value to push:");
    newnode=(node *)malloc(sizeof(node));
    scanf("%d",&newnode->data);
    if(*head!=NULL)
    {
       newnode->address=*head;
       (*head)=newnode; 
       
    }
    else
    {
        newnode->address=NULL;
        *head=newnode;
    }
    return 1;
} 

//input parameter:node **head
int pop(node **head)
{
    node *temp; //to delete a node

    //deleting operation
    if(*(head)==NULL)
    {
        printf("stack is empty\n");
        return 0;
    }
    else
    {
       temp=*head;
       printf("%d is poped\n",temp->data);
       *head=(*head)->address;
       free(temp); 
       return 1;
    }
}

//input parameter:node **head
int isempty(node **head)
{
    if(*head==NULL)
    {
        printf("Stack is empty\n");
        return 1;
    }
    else
    {
        printf("Stack is not empty\n");
        return 0;
    }
}

//input parameter: node ** head
int display(node **head)
{
    node *traverse;   //to traverse

    if(*head==NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }

    traverse=*head;
    //traversing and printing datas
    while(traverse!=NULL)
    {
        printf("%d ",traverse->data);
        traverse=traverse->address;
    }
    printf("\n");
    return 1;
}
//main function
int main()
{
    int choice;         //to store choice
    node *head =NULL;   //head node of list

    while(1)
    {
        //printing menu and reading choice 
        printf("\nMENU:\n1.Push.\n2.Pop.\n3.isempty\n4.Display.\n5.exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        //switch statement for menu content
        switch(choice)
        {
            case 1: //push operation
            {
                push(&head);
                break;
            }
            case 2: //pop operation
            {
                pop(&head);
                break;
            }
            case 3: //check stack state
            {
                isempty(&head);
                break;
            }
            case 4:
            {
                display(&head);
                break;
            }
            case 5:
            {
                exit(1);
            }
            default:
            {
                printf("Out of choice\n");
            }
        }
    }
    return 1;
}