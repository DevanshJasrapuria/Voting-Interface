#include<stdio.h>

void main()
{
    int inputID;
    int votedList[10];
    int votedListNum=0;
    int choice1,choice2;
    int count1=0,count2=0,count3=0;
    int flag;
    L1:
        flag=0;
        printf("Enter your voter id number: ");
        scanf("%d",&inputID);
        if(inputID>100000&&inputID<=100010)
        {
            for(int i=0;i<=votedListNum;i++)
            {
                if(votedList[i]==inputID)
                {
                    flag=1;
                }
            }
            if(flag==1)
            {
                printf("Already Voted!\n");
                goto L1;
            }
            L2:
                printf("Enter 1 to vote for 1st party\nEnter 2 to vote for 2nd party\nEnter 3 to vote for 3rd party\n");
                scanf("%d",&choice1);
                if(choice1==1)
                {
                    count1++;
                }
                else if(choice1==2)
                {
                    count2++;
                }
                else if(choice1==3)
                {
                    count3++;
                }
                else
                {
                    printf("Invalid Entry! Try again\n");
                    goto L2;
                }
                votedList[votedListNum]=inputID;
                votedListNum++;
        }
        else
        {
            printf("Voter ID does not exist! Try again\n");
            goto L1;
        }

        L3:
            printf("Enter 1 to continue voting:\nEnter 2 to get results:\n");
            scanf("%d",&choice2);
            if(choice2==1)
            {
                goto L1;
            }
            else if(choice2==2)
            {
                printf("1st party votes= %d\n2nd party votes= %d\n3rd party votes= %d\n",count1,count2,count3);
                if (count1>count2&&count1>count3)
                {
                    printf("1st party won!");
                }
                else if (count2>count1&&count2>count3)
                {
                    printf("2nd party won!");
                }
                else if (count1==count2&&count2>count3)
                {
                    printf("Both party 1 and party 2 have equal votes!");
                }
                else if (count1==count3&&count3>count2)
                {
                    printf("Both party 1 and party 3 have equal votes!");
                }
                else if (count2==count3&&count3>count1)
                {
                    printf("Both party 2 and party 3 have equal votes!");
                }
                else if (count1==count2&&count2==count3)
                {
                    printf("All 3 parties received equal votes!");
                }
                else
                    printf("3rd party won!");
            }
            else
            {
                printf("Invalid Entry! Try again\n");
                goto L3;
            }

}
