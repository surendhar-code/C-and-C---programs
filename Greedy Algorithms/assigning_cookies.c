/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Example 1:

Input: 

3

1 2 3

2

1 1

Output: 

1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 

And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.

You need to output 1.

Example 2:

Input: 

2

1 2

3

1 2 3

Output: 

2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 

You have 3 cookies and their sizes are big enough to gratify all of the children, 

You need to output 2.

Constraints:

1 <= g.length <= 3 * 10^4

0 <= s.length <= 3 * 10^4

1 <= g[i], s[j] <= 2^31 - 1
*/

#include <stdio.h>

int main()
{
    int n1,n2,i,j,content=0,temp;
    scanf("%d",&n1); // no.of children
    int g[n1];
    for(i=0;i<n1;i++)
        scanf("%d",&g[i]); // getting input for no.of children
    scanf("%d",&n2); // no. of cookies
    int s[n2];
    for(i=0;i<n2;i++)
        scanf("%d",&s[i]); //getting input for cookie size.

    //sorting both the arrays in ascending order
    for(i=0;i<n1-1;i++)
        for(j=0;j<n1-i-1;j++)
        {
            if(g[j]>g[j+1])
            {
                temp = g[j];
                g[j]=g[j+1];
                g[j+1] = temp;
            }
        }
    
    for(i=0;i<n2-1;i++)
        for(j=0;j<n2-i-1;j++)
        {
            if(s[j]>s[j+1])
            {
                temp = s[j];
                s[j]=s[j+1];
                s[j+1] = temp;
            }
        }
    // finding maximum content value
    i=0;
    j=0;
    while(i<n1 && j<n2)
    {
        if(s[j]>=g[i])
        {
            content+=1;
            i++;
            j++;
        }
        else
            j++;
    }
    printf("The output is : %d",content); //printing the output
    return 0;
    
}