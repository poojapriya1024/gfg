/* Given two strings x and y, and two values costX and costY, the task is to find the minimum cost required to make the given two strings identical. You can delete characters from both the strings. 
The cost of deleting a character from string X is costX and from Y is costY. The cost of removing all characters from a string is the same.

Example 1:

Input: x = "abcd", y = "acdb", costX = 10 
       costY = 20.
Output: 30
Explanation: For Making both strings 
identical we have to delete character 
'b' from both the string, hence cost 
will be = 10 + 20 = 30. */

class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        
        int xlen = x.length(), ylen = y.length();
        
        if(xlen == 1 && ylen == 1)
            return (x == y) ? 0 : min(costX, costY);
        
        vector<vector<int>> dp(xlen+1, vector<int>(ylen+1,0)); //holds the cost 
        
        //calculating the cost for making all substrings of x empty
        for(int a=1;a<=xlen;a++) 
            dp[a][0] = a * costX;
            
        //calculating the cost for making all substrings of y empty
        for(int b=1;b<=ylen;b++) 
            dp[0][b] = b * costY;
        
        
        for(int i=1;i<=xlen;i++)
        {
            for(int j=1;j<=ylen;j++)
            {
                if(x[i-1] == y[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                {
                    int drop_i = dp[i-1][j] + costX;
                    int drop_j = dp[i][j-1] + costY;
                    dp[i][j] = min(drop_i, drop_j);
                }
            }
        }
        
        return dp[xlen][ylen];
        
    }
};
