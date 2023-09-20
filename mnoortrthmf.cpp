#include<bits/stdc++.h>
using namespace std;

int minimumSteps(vector<string> logs) {

    int n = logs.size();
    if(n == 0)
        return n;
    stack<string> stck;

    for(int i=0;i<n;i++)
    {
        
        if(logs[i] == "../") {
            //move to the parent folder

            if(stck.empty())
                continue;
            
            //else, exit the current folder
            stck.pop();
        }

        else if(logs[i] == "./")
            continue;

        else {
            stck.push(logs[i]);
        }
    }

    int solution = 0;
    while(!stck.empty())
    {
        solution++;
        stck.pop();
    }

    return solution;
}

int main()
{
    vector<string> logs = {"F1/", "F2/","./","./","../", "F3/", "F4/","../","./", "./", "F5/","../","F6/"};
    int solution = minimumSteps(logs);
    cout<<solution;
    return 0;
}
