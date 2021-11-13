/*
You have some apples, where arr[i] is the weight of the i-th apple.  You also have a basket that can carry up to 5000 units of weight.

Return the maximum number of apples you can put in the basket.

Example 1:

Input: 

4

100 200 150 1000

Output: 

4

Explanation: All 4 apples can be carried by the basket since their sum of weights is 1450.

Example 2:

Input: 

6

900 950 800 1000 700 800

Output: 

5

Explanation: The sum of weights of the 6 apples exceeds 5000 so we choose any 5 of them.

Constraints:

1 <= arr.length <= 10^3

1 <= arr[i] <= 10^3
*/

#include<stdio.h>

int main()
{
    int n,i,units=0,max=0;
    scanf("%d",&n);
    int basket[n];
    for(i=0;i<n;i++)
        scanf("%d",&basket[i]);
    
    //sort the basket array in ascending order
    for(i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
        {
            if(basket[j]>basket[j+1])
            {
                int temp = basket[j];
                basket[j] = basket[j+1];
                basket[j+1]=temp;
            }
        }
    
    for(i=0; i<n && units+basket[i]<5000; i++)
    {
        units+=basket[i];
        max++;
    }

    printf("The output is : %d",max);
    return 0;
}