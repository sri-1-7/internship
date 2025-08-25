/*queue implementation*/

//header file 
#include<stdio.h>
#include<stdlib.h>

//node declaration 
//data structure:Doubly linked list
struct node
{
    //data part
    int data; 
    //address part          
    struct node * prev;
    struct node * next;
};
typedef struct node node;
node *head=NULL;//head of the list
node *tail=NULL;//tail of the list

//function declaration
int enqueue();//to perform enqueue operation
int dequeue();//to perform dequeue operation
int display();//to display the queue elements
int isempty();//to check queue state

//function definition
int enqueue()
{
    node *newnode;
    if(head==NULL)
    {
        newnode=malloc(sizeof(struct node ));
        printf("Enter the value:");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
        tail=newnode;
    }
    else
    {
        newnode=malloc(sizeof(struct node ));
        printf("Enter the value:");
        scanf("%d",&newnode->data);
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=NULL;
        tail=newnode;
    }
    return 0;
}
int isempty()
{
    if(head==NULL)
    {
        printf("queue is empty\n");
        return 1;
    }
    else
    {
        printf("queue have elements\n");
        return 0;
    }
}
int dequeue()
{
    node *temp;
    if(isempty())
    {
    printf("%d is removed from queue\n",head->data);
    temp=head;
    head=head->next;
    free(temp);
    }
    return 1;
}

int display()
{
    node *traverse;
    traverse=head;
    if(!isempty())
    {
        while(traverse!=NULL)
        {
            printf("%d ",traverse->data);
            traverse=traverse->next;
        }
        printf("\n");
    }
    return 0;
}
//main function
int main()
{
    int choice;//to store choice

    //printing menu and perform menu operation
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.is empty\n4.display\n5.exit\n");
        
        //reading choice
        printf("Enter the choice:");
        scanf("%d",&choice);

        //switch statement with choice
        switch(choice)
        {
            case 1:
            {
                enqueue();//enqueue operation
                break;
            }
            case 2:
            {
                dequeue();//dequeue operation
                break;
            }
            case 3:
            {
                isempty();//check queue state
                break;
            }
            case 4:
            {
                display();//to display queue elements
                break;
            }
            case 5:
            {
                exit(0);
            } 
            default:
            {
                printf("Out of choice\n");
            }
        }
    }
    return 0;
}