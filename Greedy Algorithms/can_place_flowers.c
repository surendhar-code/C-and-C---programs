/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

Example 1:

Input: 

5

1 0 0 0 1

1

Output: 

true

Example 2:

Input: 

5

1 0 0 0 1

2

Output: 

false

Constraints:

1 <= flowerbed.length <= 2 * 10^4

flowerbed[i] is 0 or 1.

There are no two adjacent flowers in flowerbed.

0 <= n <= flowerbed.length
*/

#include <stdio.h>

int main()
{
    int n,i,flowers,ptr=1,count=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&flowers);

    //can place flowers logic
    while(ptr<n-1)
    {
        if(arr[ptr-1]!=1 && arr[ptr+1]!=1)
        {
            count++;
            arr[ptr]=1;
        }
        ptr++;
    }

    if(count==flowers)
        printf("True");
    else
        printf("False");
    
    return 0;

}