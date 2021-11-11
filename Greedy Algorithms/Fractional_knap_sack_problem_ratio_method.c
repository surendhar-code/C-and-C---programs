
/* Fractional Knapsack problem using Greedy Method */

#include <stdio.h>

int main()
{
    int n,i,cap,j,max=0,temp; 
    scanf("%d",&n);
    float weights[n],profit[n],ratio[n];

    //getting input  from the user
    for(i=0;i<n;i++)
    {
        scanf("%f",&weights[i]); //input for weights
        scanf("%f",&profit[i]); //input for profits
        ratio[i] = profit[i]/weights[i]; // calucating profit/weight ratio
    }

    scanf("%d",&cap); // input for capacity

    //sort by ratio values in descending order
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(ratio[j]<ratio[j+1])
            {
                temp = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = temp;

                temp = weights[j];
                weights[j] = weights[j+1];
                weights[j+1] = temp;

                temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;
            }
        }
    }

    //finding maximum profit

    for(i=0;i<n;i++)
    {
        if(cap>0 && weights[i]<cap)
        {
            cap=cap-weights[i];
            max+=profit[i];

        }
        else if (cap>0 && weights[i]>cap)
        {
            max=max+(profit[i]*(cap/weights[i]));
            cap=0;
            break;
        }
        
    }

    printf("The maximum profit is : %d",max);
    return 0;


}