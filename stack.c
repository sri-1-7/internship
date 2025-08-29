/*stack implementation using linked list*/

//header file
#include"create_node.c"

//main function
int main()
{
    struct node *head=NULL; //head of the list
    int choice;             //to store choice
    int count=0;            //to store count of the nodes
    int counter;            //counter variable
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
                if(head==NULL)
                {
                    printf("enter the data:");
                    head=malloc(sizeof(struct node));
                    scanf("%d",&head->data);
                    head->link=NULL;  
                    count++;
                }
                printf("if u want to enter one more value [1-yes/0-no]:");
                scanf("%d",&counter);
                if(counter==1)
                {
                create_node_at_first(&head,&count);
                break;
                }
            }
            case 2: //pop operation
            {
                delete_node_formal(&head,&count);
                break;
            }
            case 3: //check stack state
            {
                if(count!=0)
                {
                    printf("Stack have elements\n");
                }
                else
                {
                    printf("Stack is empty\n");
                }
                break;
            }
            case 4: //to display
            {
                printf("data count:%d\n",count);
                print(&head);
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