/* Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.

Note: Output binary string should not contain leading zeros.

Example 1:

Input: s = "10"
Output: 11
Explanation: "10" is the binary representation of 2 and binary representation of 3 is "11"
*/

class Solution {
  public:
    string binaryNextNumber(string s) {
        
        int slen = s.length(), carry = 1;
        
        for(int i=slen-1;i>=0;i--)
        {
            if(s[i] == '0') //0 + 1 = 1 no carry
            {
                s[i] = '1';
                carry = 0;
                break;
            }
            else //1 + 1 = 0 carry 1
            {
                s[i] = '0';
                carry = 1;
            }
        }
        
        if(carry == 1)
            s = "1" + s;
            
        //remove leading zeros
        int index = 0;
        
        while(s[index] == '0')
            index++;
        
        return s.substr(index, slen-index+1);
            
    }
};
