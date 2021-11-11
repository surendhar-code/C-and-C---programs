/*
Best Time to Buy and Sell Stock II-Peak Valley Approach
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Example 1:

Input:

6 

7 1 5 3 6 4

Output: 

7

Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.

Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Total profit is 4 + 3 = 7.

Example 2:

Input: 

5

1 2 3 4 5

Output: 

4

Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.

Total profit is 4.

Example 3:

5

7 6 4 3 1

Output: 

0

Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

Constraints:

1 <= prices.length <= 3 * 10^4

0 <= prices[i] <= 10^4
*/

#include <stdio.h>

int main()
{
    int n,i,valley=0,peak=0,profit=0;
    scanf("%d",&n);
    int share[n];
    for(i=0;i<n;i++)
        scanf("%d",&share[i]);
    
    i=0;
    while(i<n-1)
    {
        while(i<n-1 && share[i]>share[i+1])
            i++;
        valley = share[i];
        while(i<n-1 && share[i]<share[i+1])
            i++;
        peak = share[i];
        profit = profit+(peak-valley);
    }
    printf("Profit : %d",profit);
    return 0;
}