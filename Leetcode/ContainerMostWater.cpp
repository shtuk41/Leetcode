#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    int maxArea(vector<int>& height) {

        int volume = 0;

        for (int ii = 0; ii < height.size() - 1; ii++)
        {
            for (int jj = ii + 1; jj < height.size(); jj++)
            {
                int h = height[ii] <  height[jj] ? height[ii] : height[jj];
                int vol = h * (jj - ii);

                if (vol > volume)
                    volume = vol;
            }
        }

        return volume;

    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {

        int volume = 0;
        int p1 = 0;
        int p2 = height.size() - 1;

        while (p1 != p2)
        {
            bool firstLower = height[p1] < height[p2];
            int h = firstLower ? height[p1] : height[p2];
            int vol = h * (p2 - p1);

            if (vol > volume)
                volume = vol;

            if (firstLower)
                p1++;
            else
                p2--;
        }

        return volume;
    }
};

int main()
{
    Solution sol;

    vector<int> height = { 1,8,6,2,5,4,8,3,7 };

    int volume = sol.maxArea(height);
    std::cout << volume << std::endl;

    return 0;
}