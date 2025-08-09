/*main module for program authentication problem*/

//header file
#include "project_def.c"

//main function
int main()
{
    int choice;//to store choice
    char token_name[11];//to token name

    //getting choice untill the user enter an exit option
    while(1)
    {
        //printing details
        printf("\nMENU:\n1.Generate token.\n2.Renew token.\n3.Display active token details\n4.exit.\n");
    
        //reading choice from user
        printf("\nEnter the choice:");
        scanf("%d",&choice);

        //passing choice to switch statement
        switch(choice)
        {
            case 1://generate token
            {
                //getting token name
                printf("Enter the token name (MAXIMUM 10 LETTERS):");
                scanf("%s",token_name);

                generate_token(token_name);//function call
                break;
            }
            case 2://renew token
            {
                //getting token name
                printf("Enter the token name:");
                scanf("%s",token_name);

                renew_token(token_name);//function call
                break;   
            }
            case 3://display active token
            {
                printf("TOKEN DETAILS:\n");
                display_active_token();//function call
                break;
            }
            case 4://exit 
            {
                exit(1);
            }
            default:
            {
                printf("Out of the choice\n");
            }
        }
    }
    return 1;
}