#include <algorithm>
#include <iostream>
#include <initializer_list>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> results;

        if (intervals.size() == 0)
        {
            results.push_back(newInterval);
            return results;
        }
      
        auto it = intervals.begin();

        vector<int> testVector = newInterval;

        bool merged1 = false;
        bool merged2 = false;

        while (it != intervals.end())
        {
            if ((*it)[0] >= testVector[0] && (*it)[0] <= testVector[1] ||
                testVector[0] >= (*it)[0] && testVector[0] <= (*it)[1])
            {
                int min = std::min({ testVector[0], testVector[1], (*it)[0], (*it)[1] });
                int max = std::max({ testVector[0], testVector[1], (*it)[0], (*it)[1] });

                testVector = { min, max };

                merged1 = true;
            }
            else
            {
                if (merged1 || !merged2 && testVector[1] < (*it)[0])
                {
                    results.push_back(testVector);
                    merged1 = false;
                    merged2 = true;
                }

                results.push_back(*it);
            }

            it++;
        }

        if (merged1 || !merged2)
        {
            results.push_back(testVector);
        }
       
        return results;
    }
};

void test(string name, vector<vector<int>>& intervals, vector<int>& newInterval)
{
    Solution sol;

    vector<vector<int>> result = sol.insert(intervals, newInterval);

    std::cout << name << '\n';

    for (auto& ii : result)
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
    vector<vector<int>> intervals1 = { {1, 3}, {6, 9}};
    vector<int>  interval1 = { 2, 5 };
    test("test1", intervals1, interval1);

    vector<vector<int>> intervals2 = { {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16} };
    vector<int> interval2 = { 4, 8 };
    test("test2", intervals2, interval2);

    vector<vector<int>> intervals3 = { {1, 2},{6, 7}, {8, 10} };
    vector<int> interval3 = { 3, 5 };
    test("test3", intervals3, interval3);

    vector<vector<int>> intervals4 = { {1, 5} };
    vector<int> interval4 = { 2, 3 };
    test("test4", intervals4, interval4);

    vector<vector<int>> intervals5 = { {1, 5} };
    vector<int> interval5 = { 7, 8 };
    test("test5", intervals5, interval5);

    vector<vector<int>> intervals6 = { {7, 8} };
    vector<int> interval6 = { 1, 5 };
    test("test6", intervals6, interval6);


    return 0;
}