/*
Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Example 1:

Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: N=4 and all elements from 0
to (N-1 = 3) are present in the given
array. Therefore output is -1.
Example 2:

Input:
N = 5
a[] = {2,3,1,2,3}
Output: 2 3 
Explanation: 2 and 3 occur more than once
in the given array.
Your Task:
Complete the function duplicates() which takes array a[] and n as input as parameters and returns a list of elements that occur more than once in the given array in sorted manner. If no such element is found, return list containing [-1]. 

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
Note : The extra space is only for the array to be returned.
Try and perform all operation withing the provided array. 

Constraints:
1 <= N <= 105
0 <= A[i] <= N-1, for each valid i
*/

#include <stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n],bucket[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        bucket[i] = 0;
    }
        
    for(i=0;i<n;i++)
        bucket[arr[i]-1]++;

    
    for(i=0;i<n;i++)
    {
        if(i==n-1 && bucket[i]<=1)
        {
            printf("-1");
            break;
        }
        else if(bucket[i]>1)
            printf("%d\t",i+1);
    
    }
    
    return 0;
}