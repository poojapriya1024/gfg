
/*Given an integer array a[] of size n, find the length of the longest subsequence such that the absolute difference between adjacent elements is 1.

Example 1:

Input:
n = 7
a[] = {10, 9, 4, 5, 4, 8, 6}
Output: 
3
Explaination: 
The three possible subsequences of length 3 are {10, 9, 8}, {4, 5, 4}, and {4, 5, 6}, where adjacent elements have a absolute difference of 1. No valid subsequence of greater length could be formed. */


class Solution {
  public:
    int longestSubseq(int n, vector<int> &nums) {

        if(n == 1)
            return 1;
        
        vector<int> dp(n,1);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(abs(nums[i] - nums[j]) == 1)
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        int maxLen = -1;
        
        for(int i=0;i<n;i++)
            maxLen = max(maxLen, dp[i]);
            
        return maxLen;
    }
};
