/*
There is a broken calculator that has the integer startValue on its display initially. In on operation you can:

- multiply the number on the display by 2, or

- subtract 1 from the number on the display.

Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.

Example 1:

Input: 

2

3

Output: 

2

Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.

Example 2:

Input: 

5

8

Output: 

2

Explanation: Use decrement and then double {5 -> 4 -> 8}.

Example 3:

Input: 

3

10

Output: 

3

Explanation: Use double, decrement and double {3 -> 6 -> 5 -> 10}.

Example 4:

Input: 

1024

1

Output: 

1023

Explanation: Use decrement operations 1023 times.

Constraints:

1 <= x, y <= 10^9

Algorithm or Hint:
------------------
While Y is larger than X, add 1 if it is odd, else divide by 2. After, we need to do X - Y additions to reach X.
*/


#include <stdio.h>

int main()
{
    int x,y,ans=0;
    scanf("%d",&x);
    scanf("%d",&y);

    while(y>x)
    {
        ans++;
        if(y%2==1)
            y++;
        else
            y=y/2;
    }

    printf("The output is : %d",(ans+(x-y)));
    return 0;
}