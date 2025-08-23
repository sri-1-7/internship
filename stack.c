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
node *head =NULL;   //head node of list

//function declaration
int push();      //to perform push operation
int pop();       //to perform pop operation
int isempty();   //to check stack state
int display();   //to display

//function definition

int push()
{
    node *newnode;  //to create a node

    //reading inputs and creating nodes
    printf("Enter the value to push:");
    newnode=(node *)malloc(sizeof(node));
    scanf("%d",&newnode->data);
    if(head!=NULL)
    {
       newnode->address=head;
       (head)=newnode; 
       
    }
    else
    {
        newnode->address=NULL;
        head=newnode;
    }
    return 1;
} 

int pop()
{
    node *temp; //to delete a node

    //deleting operation
    if(head==NULL)
    {
        printf("stack is empty\n");
        return 0;
    }
    else
    {
       temp=head;
       printf("%d is poped\n",temp->data);
       head=head->address;
       free(temp); 
       return 1;
    }
}


int isempty()
{
    if(head==NULL)
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

int display()
{
    node *traverse;   //to traverse

    if(head==NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }

    traverse=head;
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
                push();
                break;
            }
            case 2: //pop operation
            {
                pop();
                break;
            }
            case 3: //check stack state
            {
                isempty();
                break;
            }
            case 4:
            {
                display();
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