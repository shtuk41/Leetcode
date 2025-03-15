#include <numeric>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
private:

    struct hash_pair {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;  // Combine the two hash values
        }
    };

public:
    int maxPoints(vector<vector<int>>& points) {

        int maxPointsOnLine = 1;

        for (int ii = 0; ii < points.size(); ii++)
        {
            unordered_map<pair<int, int>, int, hash_pair> slopes;
            int dup = 0;
            int vert = 0;
            int localMax = 1;

            for (int jj = ii + 1; jj < points.size(); jj++)
            {
                int dy = points[jj][1] - points[ii][1];
                int dx = points[jj][0] - points[ii][0];

                if (dx == 0 && dy == 0)
                {
                    dup++;
                }
                else if (dx == 0)
                {
                    vert++;
                }
                else
                {
                    int dxg = dx;
                    int dyg = dy;

                    //gcd
                    while (dyg != 0)
                    {
                        int rem = dxg % dyg;
                        dxg = dyg;
                        dyg = rem;
                    }


                    int gcd = dxg;
                    dx /= gcd;
                    dy /= gcd;
                    pair<int, int> slope = {dy, dx};
                    slopes[slope] += 1;
                    localMax = max(localMax, slopes[slope] + 1);
                }
            }

            maxPointsOnLine = max(maxPointsOnLine, max(localMax + dup, dup + vert + 1));
        }

        return maxPointsOnLine;

    }
};

void test(vector<vector<int>> points)
{
    Solution sol;

    int result = sol.maxPoints(points);
    std::cout << result << std::endl;
}

int main()
{
    test({ {1,1},{2,2},{3,3} });
    test({ {1,1},{3,2},{5,3}, {4,1},{2,3},{1,4} });
}
