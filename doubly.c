//header file
#include "doubly_op.c"

//main function
void main()
{
    //structure variables
    struct node *head=NULL;//to point the first node
    struct node *old;//for operations
    int counter;//counter variable
    int choice;//to store the choice 
    int place;//to get the insertion place
    int count=0;//to store the count of datas in a list

    //printing menu reading the choice
    printf("1-creating a node\n2-add at beggining\n3-add at end\n4-delete\n5-insert at middle\n6-display\n7-reverse\n8-exit\n");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1://creating a node
            {
                if(head==NULL||count==0)
                {
                    head=malloc(sizeof(struct node));
                    printf("Enter the data:");
                    scanf("%d",&head->data);
                    head->prev=NULL;
                    head->next=NULL;
                    count++;
                    printf("if u want add another data[1-yes/0-no]:");
                    scanf("%d",&counter);
                    if(counter==1)
                    {
                    printf("for add at beggining-2\nfor add at end-3\n");
                    }
                    else
                    {
                        printf("2-add at beginning\n3-add at end\n4-delete\n5-insert at middle\n6-display\n7-reverse\n8-exit\n");
                    }
                    break;
                }
                else
                {
                    printf("head is created\n");
                    printf("for add at beggining-2\nfor add at end-3\n");
                }
                break;
            }
            case 2://adding nodes at begining
            {
                if(head==NULL)
                {
                    head=malloc(sizeof(struct node));
                    printf("Enter the data:");
                    scanf("%d",&head->data);
                    head->prev=NULL;
                    head->next=NULL;
                    count++;
                    printf("if u want add another data[1-yes/0-no]:");
                    scanf("%d",&counter);
                    if(counter==0)
                    {
                        printf("3-add at end\n4-delete\n5-insert at middle\n6-display\n7-reverse\n8-exit\n");
                        break;
                    }
                }
                old=head;
                head=creating_at_begining(&old,&count);
                printf("3-add at end\n4-delete\n5-insert at middle\n6-display\n7-reverse\n8-exit\n");
                break;
            }
            case 3://adding nodes at end
            {
                if(head==NULL)
                {
                    head=malloc(sizeof(struct node));
                    printf("Enter the data:");
                    scanf("%d",&head->data);
                    head->prev=NULL;
                    head->next=NULL;
                    count++;
                    printf("if u want add another data[1-yes/0-no]:");
                    scanf("%d",&counter);
                    if(counter==0)
                    {
                        printf("2-add at beggning\n4-delete\n5-insert at middle\n6-display\n7-reverse\n8-exit\n");
                        break;
                    }
                }
                old=head;
                create_node_at_end(&old,&count);
                printf("2-add at begging\n4-delete\n5-insert at middle\n6-display\n7-reverse\n8-exit\n");
                break;
            }
            case 4://deleting  node
            {
                if(count==0)
                {
                    printf("list is empty\n");
                    printf("1-create a node\n");
                    break;
                }
                old=head;
                head=delete_a_node(&old,&count);
                printf("2-add at begning\n3-add at end\n5-insert at middle\n6-display\n7-reverse\n8-exit\n");
                break;
            }
            case 5://insert at position
            {
                old=head;
                head=insert_at_pos(&old,&count);
                printf("2-add at begning\n3-add at end\n4-delete\n6-display\n7-reverse\n8-exit\n");
                break;
            }
            case 6://displaying the nodes
            {
                if(count==0)
                {
                    printf("list id empty\n");
                    printf("create a node-1\n");
                    break;
                }
                print(&head);
                printf("2-add at begining\n3-add at end\n4-delete\n5-insert at middle\n7-reverse\n8-exit\n");
                break;
            }
            case 7://reverse the list
            {
                old=head;
                head=reverse(&old);
                printf("2-add at begining\n3-add at end\n4-delete\n5-insert at middle\n6-print\n8-exit\n");
                break;
            }
            case 8://exit
            {
                exit(1);
            }
            default:
            {
                printf("out of the menu\n");
            }
        }
    }

}