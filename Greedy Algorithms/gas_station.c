/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

Example 1:

Input: 

5

1 2 3 4 5

3 4 5 1 2



Output: 

3

Explanation:

Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4

Travel to station 4. Your tank = 4 - 1 + 5 = 8

Travel to station 0. Your tank = 8 - 2 + 1 = 7

Travel to station 1. Your tank = 7 - 3 + 2 = 6

Travel to station 2. Your tank = 6 - 4 + 3 = 5

Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.

Therefore, return 3 as the starting index.

Example 2:

Input: 

3

2 3 4

3 4 3

Output: 

-1

Explanation:

You can't start at station 0 or 1, as there is not enough gas to travel to the next station.

Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4

Travel to station 0. Your tank = 4 - 3 + 2 = 3

Travel to station 1. Your tank = 3 - 3 + 3 = 3

You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.

Therefore, you can't travel around the circuit once no matter where you start.

Constraints:

gas.length == n

cost.length == n

1 <= n <= 10^4

0 <= gas[i], cost[i] <= 10^4
*/

/* Logic -Algorithm
i) to check whether the sum has solution or not
------------------------------------------------
- find the difference between gas and cost array values
- add all the new values
- if the total of all the values >=0, the sum has solution

ii) to find the index value
------------------------------------------------
- start with the index 0
- find the difference between gas[index] and cost[index] and store it to any variable eg. consume
- add the value in the variable consume to the tank variable
- if the tank value is less than 0, increment the index value by 1 and make tank value as 0
- add consume to the total variable (outside the if statement)
- finally return -1 if total < 0 else return index value.
*/

#include <stdio.h>

int main()
{
    int n,i,tank,consume,total=0,index=0;
    scanf("%d",&n);
    int gas[n],cost[n];
    for(i=0;i<n;i++)
        scanf("%d",&gas[i]);
    for(i=0;i<n;i++)
        scanf("%d",&cost[i]);

    // logic
    for(i=0;i<n;i++)
    {
        consume = gas[i] - cost[i];
        tank = tank+consume;
        if(tank<0)
        {
            index++;
            tank=0;
        }
        total = total+consume;
    }

    if(total<0)
        printf("-1");
    else
        printf("%d",index);
    
    return 0;
    

}