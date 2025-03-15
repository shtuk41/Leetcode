#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {

        if (citations.size() == 1)
        {
            if (citations[0] == 0)
                return 0;
            else;
                return 1;
        }

        std::sort(citations.begin(), citations.end());

        int h = 0;
        int maxNumElements = 0;

        for (int ii = 0; ii < citations.size(); ii++)
        {
            if (citations[ii] == 0)
                continue;

            int numElements = citations.size() - ii;

            if (citations[ii] > h)
            {
                int temp = citations[ii] < numElements ? citations[ii] : numElements;

                if (temp > h)
                    h = temp;

            }
        }

        return h;
    }
};

int main()
{
    //std::vector<int> input = { 3,0,6,1,5 };
    //std::vector<int> input = { 1,3,1 };
    std::vector<int> input = { 11, 15 };

    Solution sol;
    int hIndex = sol.hIndex(input);

    std::cout << hIndex << std::endl;

    return 0;
}



