//to find comman time slots for a duration

//header file
#include<stdio.h>

//main function
void main()
{
        int slot1[][2]={{10,50},{60,120},{140,210}};//array constant for time slot 1
        int slot2[][2]={{10,15},{60,70}};//array constant for time slot 1
        int slot_count1=sizeof(slot1)/sizeof(slot1[0]);//to store the count of slot1
        int slot_count2=sizeof(slot2)/sizeof(slot2[0]);//to store the count of slot2
        int duration;//to store the time duration
        int counter1;//counter variable
        int counter2;//another counter variable
        int temp1;//to store temporary value
        int temp2;//to store another temporary value
        int flag=0;//flag variable
        //reading the duration
        printf("Enter the duration:");
        scanf("%d",&duration);
        
        for(counter1=0;counter1<slot_count1;counter1++)
        {
            temp1=slot1[counter1][1]-slot1[counter1][0];
            for(counter2=0;counter2<slot_count2;counter2++)
            {
                if(slot1[counter1][0]==slot2[counter2][0])
                {
                    temp2=slot2[counter2][1]-slot2[counter2][0];
                    if(duration<=temp1&&duration<=temp2)
                    {
                        printf("%d to %d\n",slot1[counter1][0],(slot1[counter1][0])+duration);
                        flag=1;
                    }
                }
            }
        }
        if(!flag)
        printf("no time slot is available");
}
