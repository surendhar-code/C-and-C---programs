/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 

2

Output: 

2

Explanation: 

There are two ways to climb to the top.

1. 1 step + 1 step

2. 2 steps

Example 2:

Input: 

3

Output: 

3

Explanation: 

There are three ways to climb to the top.

1. 1 step + 1 step + 1 step

2. 1 step + 2 steps

3. 2 steps + 1 step

Constraints:

1 <= n <= 45
*/


#include <stdio.h>
int staircase[45];

int staircase_memo(int n)
{
    if(staircase[n]!= -1)
        return staircase[n];
    staircase[n] = staircase_memo(n-1) + staircase_memo(n-2);
    return staircase[n];
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        staircase[i] = -1;
    
    staircase[1] = 1;
    staircase[2] = 2;
    printf("%d",staircase_memo(n));
    return 0;
}