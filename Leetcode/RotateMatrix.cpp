#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int size = matrix.size();
        int level = 0;
        int levelsize = size - 1;

        while (levelsize > 0)
        {
            int start = level;
            int end = size - level;

            vector<int> temp(matrix[level].begin() + start, matrix[level].begin() + end);

            for (int ii = levelsize; ii >= 0; ii--)
            {
                matrix[level][ii + level] = matrix[levelsize - ii + level][level];
            }

            for (int ii = 0; ii < levelsize + 1; ii++)
            {
                matrix[ii + level][level] = matrix[levelsize + level][ii + level];
            }

            for (int ii = 0; ii < levelsize + 1; ii++)
            {
                matrix[levelsize + level][ii + level] = matrix[levelsize - ii + level][levelsize + level];
            }

            for (int ii = levelsize; ii >= 0; ii--)
            {
                //matrix[ii][levelsize - 1] = matrix[levelsize - 3][ii];
                matrix[ii + level][levelsize + level] = temp[ii];
            }

            levelsize -= 2;
            level++;
        }
    }
};

void print(vector<vector<int>> mat)
{
    for (auto ii : mat)
    {
        for (auto jj : ii)
        {
            std::cout << jj << ',';
        }

        std::cout << '\n';
    }

    std::cout << '\n';
}

int main()
{
    Solution sol;

    vector<vector<int>> mat1 = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };

    sol.rotate(mat1);

    print(mat1);

    vector<vector<int>> mat2 = { {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16} };

    sol.rotate(mat2);

    print(mat2);

    return 0;
}