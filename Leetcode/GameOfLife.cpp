#include <iostream>
#include <vector>

using namespace std;

class Solution {

    enum states
    {
        DEAD = 0,
        LIVE = 1,
        DEAD_L = 2,
        LIVE_D = 3
    };

public:
    void gameOfLife(vector<vector<int>>& board) {

        int width = board[0].size();
        int height = board.size();

        for (int jj = 0; jj < height; jj++)
        {
            for (int ii = 0; ii < width; ii++)
            {
                int numNeightbors = 0;

                if (jj >= 1 && ii > 0)
                {
                    int val = board[jj - 1][ii - 1];
                    if (val == LIVE || val == LIVE_D)
                    {
                        numNeightbors++;
                    }
                }

                if (jj >= 1)
                {
                    int val = board[jj - 1][ii];
                    if (val == LIVE || val == LIVE_D)
                    {
                        numNeightbors++;
                    }

                }

                if (jj >= 1 && ii < width - 1)
                {
                    int val = board[jj - 1][ii + 1];
                    if (val == LIVE || val == LIVE_D)
                    {
                        numNeightbors++;
                    }

                }

                if (ii >= 1)
                {
                    int val = board[jj][ii - 1];
                    if (val == LIVE || val == LIVE_D)
                    {
                        numNeightbors++;
                    }
                }

                if (ii < width - 1)
                {
                    int val = board[jj][ii + 1];
                    if (val == LIVE || val == LIVE_D)
                    {
                        numNeightbors++;
                    }
                }

                if (jj < height - 1 && ii >= 1)
                {
                    int val = board[jj + 1][ii - 1];
                    if (val == LIVE || val == LIVE_D)
                    {
                        numNeightbors++;
                    }
                }

                if (jj < height - 1)
                {
                    int val = board[jj + 1][ii];
                    if (val == LIVE || val == LIVE_D)
                    {
                        numNeightbors++;
                    }
                }

                if (jj < height - 1 && ii < width - 1)
                {
                    int val = board[jj + 1][ii + 1];
                    if (val == LIVE || val == LIVE_D)
                    {
                        numNeightbors++;
                    }
                }

                if (board[jj][ii] == LIVE && numNeightbors < 2)
                    board[jj][ii] = LIVE_D;
                else if (board[jj][ii] == LIVE && (numNeightbors == 2 || numNeightbors == 3))
                    board[jj][ii] = LIVE;
                else if (board[jj][ii] == LIVE && numNeightbors > 3)
                    board[jj][ii] = LIVE_D;
                else if (board[jj][ii] == DEAD && numNeightbors == 3)
                    board[jj][ii] = DEAD_L;
            }
        }

        for (int jj = 0; jj < height; jj++)
        {
            for (int ii = 0; ii < width; ii++)
            {
                if (board[jj][ii] == LIVE || board[jj][ii] == DEAD_L)
                {
                    board[jj][ii] = LIVE;
                }
                else
                {
                    board[jj][ii] = DEAD;
                }
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

    vector<vector<int>> mat1 = { {0, 1, 0},{0, 0, 1},{1, 1, 1},{0, 0, 0} };

    sol.gameOfLife(mat1);

    print(mat1);

    vector<vector<int>> mat2 = { {1, 1},{1, 0} };

    sol.gameOfLife(mat2);

    print(mat2);

    return 0;
}