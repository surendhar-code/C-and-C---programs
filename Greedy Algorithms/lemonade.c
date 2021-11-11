/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you don't have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with correct change, or false otherwise.
*/

#include <stdio.h>

int main()
{
    int n,i,change5=0,change10=0;
    scanf("%d",&n);
    int bills[n];
    for(i=0;i<n;i++)
        scanf("%d",&bills[i]);

    for(i=0;i<n;i++)
    {
        if(bills[i]==5)
            change5++;
        else if(bills[i]==10)
        {
            if(change5==0)
            {
                printf("False");
                return 0;
            }
            else
            {
                change10++;
                change5--;
            }
                
        }
        else if(bills[i]==20)
        {
            if(change5>0 && change10>0)
            {
                change5--;
                change10--;
            }
            else if(change5>=3)
                change5-=3;
            else
            {
                printf("False");
                return 0;
            }

        }
    }

    printf("True");
    return 0;
    
}