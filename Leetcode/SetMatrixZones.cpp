#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rCount = 0;
        int cCount = 0;
        bool setFirst0 = false;

        for (auto row : matrix)
        {
            bool found = false;
            for (auto col : row)
            {
                if (matrix[rCount][cCount] == 0)
                {
                    matrix[0][cCount] = rCount == 0 && matrix[0][cCount] != 0 ? -1 : 0;
                    found = true;

                    if (rCount == 0)
                        setFirst0 = true;
                }

                cCount++;
            }

            if (found && rCount > 0)
            {
                cCount = 0;
                for (auto &col : row)
                {
                    matrix[rCount][cCount] = 0;
                    cCount++;
                }
            }

            cCount = 0;
            rCount++;
        }

        cCount = 0;

        for (auto col : matrix[0])
        {
            if (col == 0)
            {
                for (int jj = 0; jj < matrix.size(); jj++)
                {
                    matrix[jj][cCount] = 0;
                }
            }

            cCount++;
        }

        if (setFirst0)
        {
            for (int ii = 0; ii < matrix[0].size(); ii++)
            {
                matrix[0][ii] = 0;
            }
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

    vector<vector<int>> mat1 = { {1, 1, 1},{1, 0, 1},{1, 1, 1 } };

    sol.setZeroes(mat1);

    print(mat1);

    vector<vector<int>> mat2 = { {0, 1, 2, 0},{3, 4, 5, 2},{1, 3, 1, 5} };

    sol.setZeroes(mat2);

    print(mat2);

    return 0;
}