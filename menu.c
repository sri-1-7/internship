//header file
#include "create_node.c"

//main function
void main()
{
    struct node *head;
    struct node *old;
    int choice;
    int counter;
    int counter1=0;
    int count=0;
    int place;
    int data;
    head=malloc(sizeof(struct node));
    printf("MENU:\n1.create a linked list\n2.add node at end\n3.add node at the first\n4.add node at middle\n5.delete node for a given value\n6.display\n7.reverse\n8.exit\n");
    while(1)
    {
        printf("\nEnter ur choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                if(counter1>0)
                {
                    printf("head a list is created\n");
                    printf("\nfor add data at end -2\nfor add data at begining -3\n");
                    break;
                }
                else
                {
                    printf("enter the data:");
                    scanf("%d",&head->data);
                    head->link=NULL;
                    printf("if u want to enter one more value [1-yes/0-no]:");
                    scanf("%d",&counter);
                    counter1++;
                    count++;
                }
                if(counter=1)
                {
                   printf("\nfor add data at end -2\nfor add data at begining -3\n"); 
                }
                break;
            }
            case 2:
            {
                old=head;
                create_node_at_end(&old,&count);
                printf("\nfor display-6\nfor add at begining-3\nfor add at middle-4\nfor delete a node-5\nfor reverse-7\nexit-8\n");
                break;
            }
            case 3:
            {
                old=head;
                head=create_node_at_first(&old,&count);
                printf("\nfor display-6\nfor add at end-2\nfor add at middle-4\nfor delete a node-5\nfor reverse-7\nexit-8\n");
                break;
            }
            case 4:
            {
                old=head;
                printf("insertion place:");
                scanf("%d",&place);
                if(place==0||place<0)
                {
                    printf("not possible\n");
                    break;
                }
                if(place<=count||(place-count)==1)
                {
                  insert_at_any(&head,&count,place);
                }
                else
                {
                    printf("not possible\n");
                    printf("\nfor display-6\nfor add at end-2\nfor add at begining-3\nfor delete a node-5\nfor reverse-7\nexit-8\n");
                    break;
                }   
                printf("\nfor display-6\nfor add at end-2\nfor add at begining-3\nfor delete a node-5\nfor reverse-7\nexit-8\n");
                break;
            }
            case 5:
            {
                if(count>0)
                {
                    old=head;
                    printf("Enter the data to delete:");
                    scanf("%d",&data);
                    head=delete_node(&old,&count,data);  
                    printf("\nfor add at end-2\nfor add at begining-3\nfor add at middle-4\nfor delete a node-5\nfor reverse-7\nexit-8\n");
                    break;
                }
                else
                {
                    printf("list is empty\n");
                    printf("for create node -1\n");
                }
                printf("\nfor display-6\nfor add at end-2\nfor add at begining-3\nfor add at middle-5\nfor reverse-7\nexit-8\n");
                break;
      
            }
            case 6:
            {
                if(count>0)
                {
                    print(&head);
                    printf("\nfor add at end-2\nfor add at begining-3\nfor add at middle-4\nfor delete a node-5\nfor reverse-7\nexit-8\n");
                    break;
                }
                printf("list is empty\n");
                break;
            }
            case 7:
            {
                head=reverse(&head);
                printf("\nfor display-6\nfor add at end-2\nfor add at begining-3\nfor add at middle-4\nfor delete a node-5\nfor reverse-7\nexit-8\n");
                break;
            }
            case 8:
            {
                exit(1);
            }
            default:
            {
                printf("out of the menu\n");
                printf("MENU:\n1.create a linked list\n2.add node at end\n3.add node at the first\n4.add node at middle\n5.delete node for a given value\n6.display\n7.reverse\n8.exit\n");
            }
        }
    }
}