/* Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr. */

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    /* the approach is use to hash map to keep track of the frequency 
	    of each element in the array */
	    
	    unordered_map<int,int> myMap; 
	    
	    for(int i=0;i<n;i++)
	        myMap[arr[i]]++;
	        
	   if(myMap.find(x) != myMap.end())
	        return myMap[x];
	   
	   return 0;
	}
};
