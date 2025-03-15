
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution2 {

private:
    
    int computeScore(const std::string& w)
    {
        int score = 0;
        for (auto ii : w)
        {
            score += static_cast<int>(ii);
        }
        return score;
    }

    unsigned int computePermScore(const std::string& w)
    {
        unsigned int score = 0;
        int base = 128;

        for (auto ii : w)
        {
            score = score * base + static_cast<int>(ii);
        }

        return score;
    }

    bool checkScore(string sCheck, int wordLength, vector<unsigned int> & wordsScore)
    {
        vector<unsigned int> sCheckScore;

        for (int ii = 0; ii < sCheck.length(); ii += wordLength)
        {
            unsigned int score = computePermScore(sCheck.substr(ii, wordLength));
            sCheckScore[score] += 1;
        }


        if (sCheckScore == wordsScore)
            return true;
        else
            return false;
    }

public:

    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result;
        int totalScore = 0;
        int start = 0;
        int end = 0;
        int numberWords = words.size();
        int singleLength = words[0].length();
        int totalLength = numberWords * singleLength;

        if (s.length() < totalLength)
            return result;

        vector <unsigned int> wordsScoreSet;

        for (auto ii : words)
        {
            totalScore += computeScore(ii);
            unsigned int perScore = computePermScore(ii);
            wordsScoreSet.push_back(perScore);
        }

        int stringScore = (int)s[0];

        for (int ii = 1; ii < totalLength; ii++)
        {
            end++;
            stringScore += (int)s[end];
        }

        while (end < s.length())
        {
            if (stringScore == totalScore)
            {
                if (checkScore(s.substr(start, end - start + 1), singleLength, wordsScoreSet))
                {
                    result.push_back(start);
                }
            }

            stringScore -= s[start++];
            stringScore += s[++end];
        }

        return result;
    }
};

class Solution {

private:

    int computeScore(const std::string& w)
    {
        int score = 0;
        for (auto ii : w)
        {
            score += static_cast<int>(ii);
        }
        return score;
    }

    unsigned int computePermScore(const std::string& w)
    {
        unsigned int score = 0;
        int base = 128;

        for (auto ii : w)
        {
            score = score * base + static_cast<int>(ii);
        }

        return score;
    }

    bool checkScore(string sCheck, int wordLength, unordered_map<unsigned int, int>& wordsScore)
    {
        unordered_map<unsigned int, int> sCheckScore;

        for (int ii = 0; ii < sCheck.length(); ii += wordLength)
        {
            unsigned int score = computePermScore(sCheck.substr(ii, wordLength));
            sCheckScore[score] += 1;
        }

        if (sCheckScore == wordsScore)
            return true;
        else
            return false;
    }

public:

    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result;
        int totalScore = 0;
        int start = 0;
        int end = 0;
        int numberWords = words.size();
        int singleLength = words[0].length();
        int totalLength = numberWords * singleLength;

        if (s.length() < totalLength)
            return result;

        unordered_map<unsigned int, int> wordsScoreSet;

        for (auto ii : words)
        {
            totalScore += computeScore(ii);
            unsigned int perScore = computePermScore(ii);
            wordsScoreSet[perScore] += 1;
        }

        int stringScore = (int)s[0];

        for (int ii = 1; ii < totalLength; ii++)
        {
            end++;
            stringScore += (int)s[end];
        }

        while (end < s.length())
        {
            if (stringScore == totalScore)
            {
                if (checkScore(s.substr(start, end - start + 1), singleLength, wordsScoreSet))
                {
                    result.push_back(start);
                }
            }

            stringScore -= s[start++];
            stringScore += s[++end];
        }

        return result;
    }
};

class Solution1 {

private:

    unordered_map<char, int> computeScore(const std::string& w)
    {
        unordered_map<char, int> score;
        for (auto ii : w)
        {
            score[ii] += 1;
        }
        return score;
    }

    bool checkScore(string sCheck, int wordLength, unordered_map<string, int>& wordsScore)
    {
        unordered_map<string, int> sCheckScore;

        for (int ii = 0; ii < sCheck.length(); ii += wordLength)
        {
            sCheckScore[sCheck.substr(ii, wordLength)] += 1;
        }

        if (sCheckScore == wordsScore)
            return true;
        else
            return false;
    }

public:

    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result;
        int start = 0;
        int end = 0;
        int numberWords = words.size();
        int singleLength = words[0].length();
        int totalLength = numberWords * singleLength;

        if (s.length() < totalLength)
            return result;

        unordered_map<string, int> wordsScoreSet;
        string concatenatedWords;

        for (auto ii : words)
        {
            wordsScoreSet[ii] += 1;
            concatenatedWords += ii;
        }

        unordered_map<char, int> totalScore = computeScore(concatenatedWords);
        unordered_map<char, int> stringScore = computeScore(s.substr(0, totalLength));

 
        end = start + totalLength - 1;

        while (end < s.length())
        {
            if (stringScore == totalScore)
            {
                if (checkScore(s.substr(start, end - start + 1), singleLength, wordsScoreSet))
                {
                    result.push_back(start);
                }
            }

            stringScore[s[start++]]-=1;
            stringScore[s[++end]]+=1;

            for (auto it = stringScore.begin(); it != stringScore.end(); )
            {
                if (it->second == 0)
                    it = stringScore.erase(it);
                else
                    ++it;
            }
        }

        return result;
    }
};

void print(string name, vector<int>& result)
{
    std::cout << name << std::endl;

    for (auto ii : result)
    {
        std::cout << ii << std::endl;
    }

    std::cout << "\n";
}

int main()
{
    Solution sol;

    string s1 = "barfoothefoobarman";
    vector<string> words1 = { "foo", "bar" };
    vector<int> result1 = sol.findSubstring(s1, words1);

    print("result1", result1);

    string s2 = "ababaab";
    vector<string> words2 = { "ab", "ba", "ba" };
    vector<int> result2 = sol.findSubstring(s2, words2);

    print("result2", result2);

    string s3 = "bcabbcaabbccacacbabccacaababcbb";
    vector<string> words3 = { "c","b","a","c","a","a","a","b","c" };
    vector<int> result3 = sol.findSubstring(s3, words3);

    print("result3", result3);

    string s4 = "abababab";
    vector<string> words4 = { "ab","ab","ab" };
    vector<int> result4 = sol.findSubstring(s4, words4);

    print("result4", result4);

    return 0;
}

