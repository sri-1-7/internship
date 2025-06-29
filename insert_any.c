#include"create_node.c"

//main function
void main()
{
    //structure variables
    struct node *head;
    struct node *old;
    int counter;//counter variable
    int count;//another counter variable
    int place;//to get insertion space
    head=malloc(sizeof(struct node));
    
    //creating a list
    head->data=20;
    head->link=NULL;
    old=head;
    insert(&old,40);
    insert(&old,90);
    count=3;
    printf("Existing list:\n");
    print(&head);
    printf("if u want to enter one more value [1-yes/0-no]:");
    scanf("%d",&counter);
    printf("%d",count);
    if(counter==1)
    {   
        printf("insertion place:");
        scanf("%d",&place);
        if(place<=count||(place-count)==1)
        {
            insert_at_any(&head,&count,place);
        }
        else
        {
            printf("not possible\n");
            exit(1);
        }
    }
    print(&head);
}