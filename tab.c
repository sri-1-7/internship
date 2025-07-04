//header file
#include "tab_fun.c"

//main function
void main()
{
    struct node *obj;//to store function returns
    char tab[20];//to store tab names temporarily
    int steps;//to store the steps count
    int choice;//to store menu choice

    //getting and creating homepage
    printf("search :");
    gets(tab);
    obj=homepage_create(tab);

    //printing the menu
    printf("1-visit\n2-back\n3-forward\n4-exit\n");

    //reading the choice and perform those instruction
    while(1)
    {
        //reading the choice
        printf("\nEnter ur choice:");
        scanf("%d",&choice);
        getchar();

        //doing operation based on choice
        switch(choice)
        {
            case 1://visiting another page
            {
                //reding the page name
                printf("Enter the search tab:");
                gets(tab);

                obj=visit(&obj,tab);//function call
                printf("1-visit\n2-back\n3-forward\n4-exit\n");
                break;
            }
            case 2://back to the page by nth steps
            {
                //reading the steps
                printf("enter the steps:");
                scanf("%d",&steps);

                if(steps<=0)
                {
                    printf("nothing happens");
                    printf("1-visit\n2-back\n3-forward\n4-exit\n");
                    break;
                }
                obj=back(&obj,steps);//function call
                printf("1-visit\n2-back\n3-forward\n4-exit\n");
                break;
            }
            case 3://forwarding to the page by nth steps
            {
                //reading the steps
                printf("Enter the steps:");
                scanf("%d",&steps);

                if(steps<=0)
                {
                    printf("nothing happens\n");
                    printf("1-visit\n2-back\n3-forward\n4-exit\n");
                    break;
                }
                printf("1-visit\n2-back\n3-forward\n4-exit\n");
                obj=forward(&obj,steps);//function call
                break;
            }
            case 4://exit form the program
            {
                exit(1);
            }
        }
    }
}