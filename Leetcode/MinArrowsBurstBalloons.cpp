#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if (points.size() == 1)
            return 1;

        unordered_set<int> exclude;
 
        sort(points.begin(), points.end());

        int numberArrows = 0;

        for (int ii = 0; ii < points.size(); ii++)
        {
            if (exclude.find(ii) != exclude.end())
                continue;

            int pointsII[2] = { points[ii][0], points[ii][1]};
            exclude.insert(ii);
            int common[2];
            bool commonFound = false;

            for (int jj = ii + 1; jj < points.size(); jj++)
            {
                if (exclude.find(jj) != exclude.end())
                    continue;

                int pointsJJ[2] = { points[jj][0], points[jj][1] };

                if (commonFound && (common[0] >= points[jj][0] && common[0] <= points[jj][1] ||
                    points[jj][0] >= common[0] && points[jj][0] <= common[1]))
                {
                    common[0] = pointsJJ[0] > common[0] ? pointsJJ[0] : common[0];
                    common[1] = pointsJJ[1] < common[1] ? pointsJJ[1] : common[1];


                    exclude.insert(jj);
                }
                else if (!commonFound && (pointsII[0] >= pointsJJ[0] && pointsII[0] <= pointsJJ[1] ||
                    pointsJJ[0] >= pointsII[0] && pointsJJ[0] <= pointsII[1]))
                {
                    exclude.insert(jj);

                    common[0] = pointsII[0] > pointsJJ[0] ? pointsII[0] : pointsJJ[0];
                    common[1] = pointsII[1] < pointsJJ[1] ? pointsII[1] : pointsJJ[1];

                    commonFound = true;
                }
            }

            numberArrows++;
        }

        return numberArrows;
    }
};

void test(string test, vector<vector<int>>& points)
{
    Solution sol;

    int result = sol.findMinArrowShots(points);

    std::cout << test << " : " << result << std::endl;
}

int main()
{
    vector<vector<int>> points1 = { {10, 16}, {2, 8}, {1, 6}, {7, 12} };
    test("test1", points1);

    vector<vector<int>> points2 = { {1, 2}, {3, 4}, {5, 6}, {7, 8}};
    test("test2", points2);

    vector<vector<int>> points3 = { {1, 2},{2, 3}, {3, 4}, {4, 5} };
    test("test3", points3);

    vector<vector<int>> points4 = { {9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7} };
    test("test4", points4);

    return 0;
}

