// 2500. Delete Greatest Value in Each Row
#include <bits/stdc++.h>
using namespace std;

// bruteforce (N^3)
int deleteGreatestValue(vector<vector<int>> &grid)
{
    int rowLength = grid[0].size();
    int maxNum = 0, ans = 0;

    for (int k = 0; k < rowLength; k++)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            // storing max for each row
            int maxIndex = 0, localMax = 0;

            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] > localMax)
                {
                    // track index to mark visited
                    maxIndex = j;

                    localMax = grid[i][j];
                }
            }

            // mark visited as 0
            grid[i][maxIndex] = 0;
            if (localMax > maxNum)
            {
                maxNum = localMax;
            }

        }
        ans += maxNum;
        maxNum = 0;
    }

    return ans;
}

// Optimized (M * NlogN) for M*N, comparing column wise
int deleteMaximumValue(vector<vector<int> >& vect)
{
 
    for (int i = 0; i < vect.size(); i++) {
        sort(vect[i].rbegin(), vect[i].rend());
    }
 
    int ans = 0;
    for (int i = 0; i < vect[0].size(); i++) {
        int val = vect[0][i];
        for (int j = 1; j < vect.size(); j++) {
            val = max(val, vect[j][i]);
 
            ans += val;
        }
    }
    return ans;
}