/* Given three numbers n, x, and y, Geek and his friend are playing a coin game. In the beginning, there are n coins. In each move, a player can pick x, y, or 1 coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to determine whether Geek will win the game or not if both players play optimally.

Example 1:

Input: 
n = 5
x = 3
y = 4
Output: 
1
*/


class Solution {
  public:
    int findWinner(int n, int x, int y) {
        
        if(n == 1)
            return 1;
        
        vector<int> isWinner(n+1); //determines if geek wins the game
        isWinner[0] = 0; //geek looses if there is no coin to pick
        isWinner[1] = 1; //geek will win if there is only one coin to pick
        
        for(int i=2;i<=n;i++)
        {
            //geek can't choose a coin if it was geeks' turn before
            if( (i-1) >= 0 && isWinner[i-1] == 0)
                isWinner[i] = 1;
            
            else if( (i-x) >= 0 && isWinner[i-x] == 0)
                isWinner[i] = 1;
                
            else if( (i-y) >= 0 && isWinner[i-y] == 0)
                isWinner[i] = 1;
            
            else
                isWinner[0];
        }
        
        return isWinner[n];
    }
};
