#include <algorithm>
#include <iostream>
#include <initializer_list>
#include <vector>
#include <string>

using namespace std;

class Solution2 {

    bool overlap(vector<int>& int1, vector<int>& int2)
    {
        if (int1[0] >= int2[0] && int1[0] <= int2[1] ||
            int2[0] >= int1[0] && int2[0] <= int1[1] )
            return true;
        else
            return false;
    }

    vector<int> commonRange(initializer_list<int> &list)
    {
        int min = *std::min_element(list.begin(), list.end());
        int max = *std::max_element(list.begin(), list.end());

        return vector<int>({ min, max });
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        if (intervals.size() == 1)
        {
            result.push_back(intervals[0]);
            return result;
        }

        result.push_back(*intervals.begin());
        int count = 0;
        
        while (count < result.size())
        {
            auto it = intervals.begin();
            bool merge = false;

            while (it != intervals.end())
            {
                if (overlap(result[count], *it))
                {
                    initializer_list<int> list = { (*it)[0], (*it)[1], result[count][0], result[count][1] };
                    result[count] = commonRange(list);
                    it = intervals.erase(it);
                    merge = true;
                }
                else
                {
                    it++;
                }
            }

            if (!merge)
            {
                if (intervals.size() > 0)
                    result.push_back(*intervals.begin());
                
                count++;
            }


        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> result;

        if (intervals.size() == 1)
        {
            result.push_back(intervals[0]);
            return result;
        }

        sort(intervals.begin(), intervals.end());

        result.push_back(intervals[0]);
        int counter = 1;

        int resultCount = 0;

        while (resultCount < result.size())
        {
            bool merged = false;

            while (counter < intervals.size())
            {
                int r[2] = { result[resultCount][0], result[resultCount][1] };
                int i[2] = { intervals[counter][0], intervals[counter][1] };

                if (r[0] >= i[0] && r[0] <= i[1] ||
                    i[0] >= r[0] && i[0] <= r[1])
                {
                    int min = std::min({ i[0], i[1], r[0], r[1] });
                    int max = std::max({ i[0], i[1], r[0], r[1] });

                    result[resultCount] = {min, max};
                }
                else
                {
                    result.push_back(intervals[counter]);
                    break;
                }

                counter++;
            }

            resultCount++;
        }
        
        return result;
    }
};

void test(string name, vector<vector<int>>& intervals)
{
    Solution sol;

    vector<vector<int>> result = sol.merge(intervals);

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
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    test("test1", intervals1);

    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    test("test2", intervals2);

    vector<vector<int>> intervals3 = { {2,3}, {4, 5}, {6,7}, {8,9}, {1, 10} };
    test("test3", intervals3);

    vector<vector<int>> intervals4 = { {2,3}, {5, 5}, {2, 2}, {3, 4}, {3, 4} };
    test("test4", intervals4);

    vector<vector<int>> intervals5 = { {0,2}, {2,3}, {4,4}, {0,1}, {5,7}, {4,5}, {0,0} };
    test("test5", intervals5);

    return 0;
}