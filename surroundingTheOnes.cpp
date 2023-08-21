class Solution {
public:

vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0},{-1,1},{1,1},{-1,-1},{1,-1}};

bool isValid(int ni, int nj, int row, int col)
{
    return (ni >= 0 && ni < row) && (nj >= 0 && nj < col);
}

int Count(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0; // to keep track of the cells surrounded by an even number of zeros

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 1)
            {
                int noOfZeros = 0;

                // Checking all the cells in the neighborhood
                for(int d=0;d<dir.size();d++)
                {
                    int ni = i + dir[d].first;
                    int nj = j + dir[d].second;
                    
                    if(isValid(ni,nj,row,col) && matrix[ni][nj] == 0)
                        noOfZeros++;
                }

                // Increment the count only if the number of zeros in the neighborhood, including the 1 itself, is even
                if (noOfZeros > 0 && noOfZeros % 2 == 0)
                    count++;
            }
        }
    }

    return count;
}
};
