/* Given a number n, Your task is to swap the two nibbles and find the resulting number. 
Example 1:

Input: n = 100
Output: 70
Explanation: 100 in binary is 01100100, two nibbles are (0110) and (0100). If we swap the two nibbles, we get 01000110 which is 70 in decimal. */


class Solution {
  public:
    int swapNibbles(int n) {
        
        int left_nibble = (n & 0xF0);
        int right_nibble = (n & 0x0F);
        
        // shift by 4 bits and interchange nibbles
        return (right_nibble<< 4) | (left_nibble >> 4);
    }
};
