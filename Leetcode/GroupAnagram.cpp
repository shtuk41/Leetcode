#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1 {

    map<string, int> groups;
    

    bool isAnagram(string s, string t) {

        int map[256] = { 0 };

        if (s.length() != t.length())
            return false;

        if (s == "" && t == "")
            return true;

        for (auto ch : s)
        {
            map[ch] += 1;
        }

        for (auto ch : t)
        {
            if (map[ch] <= 0)
                return false;
            else
                map[ch]--;
        }

        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int group = 0;
        vector<vector<string>> result;
        vector<bool> assigned;
        assigned.resize(strs.size());

        for (int ii = 0; ii < strs.size(); ii++)
        {
            if (!assigned[ii])
            {
                auto it = groups.find(strs[ii]);

                if (it == groups.end())
                {
                    group++;
                    result.push_back(vector<string>());
                    result[group - 1].push_back(strs[ii]);
                    groups.insert(std::make_pair(strs[ii], group));
                    assigned[ii] = true;

                    for (int jj = ii + 1; jj < strs.size(); jj++)
                    {
                        if (!assigned[jj] && isAnagram(strs[ii], strs[jj]))
                        {
                            groups.insert(std::make_pair(strs[jj], group));
                            result[group - 1].push_back(strs[jj]);
                            assigned[jj] = true;
                        }

                    }
                }
                else
                {
                    result[it->second - 1].push_back(strs[ii]);
                }
            }
        }
 
        return result;
    }
};

class Solution2 {

    bool isAnagram(string s, string t) {

        int map[256] = { 0 };

        if (s.length() != t.length())
            return false;

        if (s == "" && t == "")
            return true;

        for (auto ch : s)
        {
            map[ch] += 1;
        }

        for (auto ch : t)
        {
            if (map[ch] <= 0)
                return false;
            else
                map[ch]--;
        }

        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int group = 0;
        vector<vector<string>> result;
        vector<bool> assigned;
        assigned.resize(strs.size());

        for (int ii = 0; ii < strs.size(); ii++)
        {
            if (!assigned[ii])
            {
                group++;
                result.push_back(vector<string>());
                result[group - 1].push_back(strs[ii]);
                assigned[ii] = true;

                for (int jj = ii + 1; jj < strs.size(); jj++)
                {
                    if (!assigned[jj] && isAnagram(strs[ii], strs[jj]))
                    {
                        result[group - 1].push_back(strs[jj]);
                        assigned[jj] = true;
                    }
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;
        unordered_map<string, vector<string>> dictionary;

        for (int ii = 0; ii < strs.size(); ii++)
        {
            string s = strs[ii];
            std::sort(s.begin(), s.end());
            dictionary[s].push_back(strs[ii]);
        }

        for (auto ii : dictionary)
        {
            result.push_back(ii.second);
        }

        return result;
    }
};

void test(vector<string>& strs)
{
    Solution sol;

    vector<vector<string>> result = sol.groupAnagrams(strs);

    for (auto ii : result)
    {
        for (auto jj : ii)
        {
            if (jj == "")
                std::cout << "\"\"" << ' ';
            else
                std::cout << jj << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "\n\n";

}

int main()
{
    {
        vector<string> test1 = { "eat", "tea", "tan", "ate", "nat", "bat" };
        test(test1);

        vector<string> test2 = { "" };
        test(test2);

        vector<string> test3 = { "a" };
        test(test3);

        vector<string> test4 = { "", ""};
        test(test4);
    }
}