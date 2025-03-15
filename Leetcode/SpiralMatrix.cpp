#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int ii = 0;
        int length = matrix.size() * matrix[0].size();

        int col = 0;
        int row = 0;

        vector<int> result;
        result.resize(length);

        int rStart = 0;
        int rEnd = matrix[0].size() - 1;
        int cStart = 0;
        int cEnd = matrix.size() - 1;


        while (true)
        {
            for (int r = rStart; r <= rEnd; r++)
            {
                result[ii++] = matrix[cStart][r];
                if (ii == length) 
                    goto END;
            }

            cStart += 1;

            for (int c = cStart; c <= cEnd; c++)
            {
                result[ii++] = matrix[c][rEnd];
                if (ii == length) 
                    goto END;
            }

            rEnd--;

            for (int r = rEnd; r >= rStart; r--)
            {
                result[ii++] = matrix[cEnd][r];
                if (ii == length) 
                    goto END;
            }

            cEnd--;

            for (int c = cEnd; c >= cStart; c--)
            {
                result[ii++] = matrix[c][rStart];
                if (ii == length) 
                    goto END;
            }

            rStart++;
        }

        END:

        return result;

    }
};

void print(const vector<int>& board)
{
    for (auto ii : board)
    {
        std::cout << ii << ',';
    }

    std::cout << "\n\n";
}

int main()
{
    Solution sol;

    vector<vector<int>> board1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> result1 = sol.spiralOrder(board1);

    print(result1);

    vector<vector<int>> board2 = { {1,2,3,4}, {5,6,7,8},{9,10,11,12} };

    vector<int> result2 = sol.spiralOrder(board2);

    print(result2);

    return 0;
}
