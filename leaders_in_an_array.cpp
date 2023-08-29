class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        
        vector<int> solution;
        
        if(n == 1)
        {
            solution.push_back(arr[0]);
            return solution;
        }
        
        int maxSoFar = arr[n-1]; 
        
        solution.push_back(maxSoFar); // as the rightmost element is always a leader
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i] >= maxSoFar)
            {   
                maxSoFar = arr[i];
                solution.push_back(maxSoFar);
            }
        }
        
        reverse(solution.begin(), solution.end());
        return solution;
    }
};
