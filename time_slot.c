//header file
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX_SLOT 10

//function declaration
int input(float person[MAX_SLOT][2],int slot);//for getting input
int slot_corection(float person[MAX_SLOT][2],int *slot1);//for crrecting the slots
int standard_convertion(float person[MAX_SLOT][2],char standard[4],int slot);//to convert UTS

//function definition
int input(float person[MAX_SLOT][2],int slot)
{
    int counter;
    printf("Enter the time[0-24]\n");
    for(counter=0;counter<slot;counter++)
    {
        scanf("%f%*c%f",&person[counter][0],&person[counter][1]);
    }
}
int slot_corection(float person[MAX_SLOT][2],int *slot1)
{
    int counter1;
    int counter2;
    for(counter1=1;counter1<*slot1;counter1++)
    {
         if(person[counter1-1][1]==person[counter1][0])
        {
            person[counter1-1][1]=person[counter1][1];
            (*slot1)--;
            for(counter2=counter1;counter2<*slot1;counter2++)
            {
                person[counter2][1]=person[counter2+1][1];
                person[counter2][0]=person[counter2+1][0];
            }             
            counter1--;
        }
    }
    /*for(counter1=0;counter1<*slot1;counter1++)
    {
        printf("%0.2f-%0.2f\n",person[counter1][0],person[counter1][1]);
    }*/
}

int standard_convertion(float person[MAX_SLOT][2],char standard[4],int slot)
{
    int counter;
    printf("Time standard:");
    scanf("%s",standard);
    if(strcmp("IST",standard)==0)
    {
        for(counter=0;counter<slot;counter++)
        {
            person[counter][0]=person[counter][0]-5.30;
            if(person[counter][0]<0)
            {
                person[counter][0]=-(24.60+person[counter][0]);
                person[counter][0]=person[counter][0]+1;
            }
            else
            { 
                person[counter][0]=person[counter][0]-0.40;
            }
            person[counter][1]=person[counter][1]-5.30;
            if(person[counter][1]<1)
            {
                person[counter][1]=-(24.60+person[counter][1]);
                person[counter][1]=person[counter][1]+1;
            }
            else
            { 
                person[counter][1]=person[counter][1]-0.40;
            }
        } 
        printf("\n");
        printf("- before value indicates previous day\n");
    }
    else if(strcmp("EST",standard)==0)
    {
        for(counter=0;counter<slot;counter++)
        {
            person[counter][0]=person[counter][0]+5;
            person[counter][1]=person[counter][1]+5;
        if(person[counter][0]>24)
        {
            person[counter][0]=-(person[counter][0]-24);
        }
        if(person[counter][1]>24)
        {
            person[counter][1]=-(person[counter][1]-24);
        }
        }
        printf("\n");
        printf("- before value indicates next day\n");
    }
    else if(strcmp("JST",standard)==0)
    {
        for(counter=0;counter<slot;counter++)
        {
            person[counter][0]=person[counter][0]-9;
            if(person[counter][0]<0)
            {
                person[counter][0]=-(24.60+person[counter][0]);
            }
            person[counter][1]=person[counter][1]-9;
            if(person[counter][1]<0)
            {
                person[counter][1]=-(24.60+person[counter][1]);
            }
        } 
        printf("\n");
        printf("-ve alue indicate previous day");
    }
    else if(strcmp("PST",standard)==0)
    {
        for(counter=0;counter<slot;counter++)
        {
            person[counter][0]=person[counter][0]+8;
            person[counter][1]=person[counter][1]+8;
        if(person[counter][0]>24)
        {
            person[counter][0]=-(person[counter][0]-24);
        }
        if(person[counter][1]>24)
        {
            person[counter][1]=-(person[counter][1]-24);
        }
        }
        printf("-ve values indicates next day\n");
    }
    printf("\n");
    printf("Time slot in UTC:\n");
    for(counter=0;counter<slot;counter++)
    {
        printf("%0.2f - %0.2f\n",person[counter][0],person[counter][1]);
    }
}
//main function
void main()
{
    //array constant
    float person1[MAX_SLOT][2];
    float person2[MAX_SLOT][2];
    //to store the slot count
    int slot1;
    int slot2;
    //to store time standard
    char time_standard1[4];
    char time_standard2[4];
    float duration;//to store duration

    //reading the datas and printing the intersection
    printf("For person1\n");
    printf("Enter the no of slot:");
    scanf("%d",&slot1);
    if(slot1==0)
    {
        printf("No slots available\n");
        exit(1);
    }
    input(person1,slot1);
    slot_corection(person1,&slot1);
    printf("Time standard:");
    scanf("%s",time_standard1);
    printf("\nFor person2\n");
    printf("Enter the no of slot:");
    scanf("%d",&slot2);
    if(slot2==0)
    {
        printf("No slots available\n");
        exit(1);
    }
    input(person2,slot2);
    printf("Time standard:");
    scanf("%s",time_standard2);
    if(strcmp(time_standard2,time_standard2)!=0)
    {
    standard_convertion(person1,time_standard1,slot1);
    standard_convertion(person2,time_standard2,slot2);
    }
    printf("Enter the duration of the meet:");
    scanf("%f",&duration);
    duration=duration/10;
    /*for(int counter1=0;counter1<slot1;counter1++)
    {
        printf("%0.2f-%0.2f\n",person1[counter1][0],person1[counter1][1]);
    }*/
   for (int counter1 = 0; counter1 < slot1; counter1++)
{
    for (int counter2 = 0; counter2 < slot2; counter2++)
    {
        float temp = person1[counter1][0];
        while ((int)(temp * 100) < (int)(person1[counter1][1] * 100))
        {
            if ((int)(temp * 100) == (int)(person2[counter2][0] * 100))
            {
                if (person1[counter1][1] - temp >= duration &&
                    person2[counter2][1] - person2[counter2][0] >= duration)
                {

                    printf("Slots available starting time  %.2f till duration period\n", temp);
                }
                break; 
            }
            temp += 0.01;  
        }
    }
}

}