#include<stdio.h>
#include<string.h>
int max(int a, int b);
int lcs( char *c1, char *c2, int n, int m );
int max(int a, int b)
{
    return (a > b)? a : b;
}
void main()
{
char c1[] = "abcde";
char c2[] = "cbacede";
int n = strlen(c1);
int m = strlen(c2);
printf("Length of LCS is %d", lcs( c1, c2, n, m ) );
}
int lcs( char *c1, char *c2, int n, int m )
{
int dp[n+1][m+1];
int i,j;
for (i=0; i<=n; i++)
{
    for (j=0; j<=m; j++)
    {
    if (i == 0 || j == 0)
        dp[i][j] = 0;
 
    else if (c1[i-1] == c2[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
 
    else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}
return dp[n][m];
}
