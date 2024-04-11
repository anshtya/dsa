// 2500. Delete Greatest Value in Each Row
#include <bits/stdc++.h>
using namespace std;

// bruteforce
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