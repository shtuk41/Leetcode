#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

    string format(const std::vector<string>& rowText, int maxWidth, bool lastLine)
    {
        std::string formatted(maxWidth, ' ');

        if (lastLine || rowText.size() == 1)
        {
            int offset = 0;
            for (auto w : rowText)
            {
                formatted.replace(offset, w.length(), w);
                offset += w.length() + 1;
            }

            return formatted;
        }
        else
        {
            int totalWordsLength = 0;

            for (auto rt : rowText)
            {
                totalWordsLength += rt.length();
            }

            int totalSpaces = maxWidth - totalWordsLength;
            int numberOfSpaces = rowText.size() - 1;
            vector<int> buckets(numberOfSpaces);

            for (int ii = 0; ii < totalSpaces; ii++)
            {
                buckets[ii % numberOfSpaces]++;
            }

            int offset = 0;
            int count = 0;
            for (auto w : rowText)
            {
                formatted.replace(offset, w.length(), w);
                offset += w.length();

                if (count < numberOfSpaces)
                    offset += buckets[count++];
            }
        }
        return formatted;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        int length = 0;

        vector<string> finalText;
        vector<string> rowText;
        

        for (int ii = 0; ii < words.size(); ii++)
        {
            length += words[ii].length();

            if (length <= maxWidth)
            {
                rowText.push_back(words[ii]);
                length++; //space
            }
            else
            {
                ii--;
                length = 0;

                finalText.push_back(format(rowText, maxWidth, ii + 1 == words.size()));

                rowText.clear();
            }
        }

        if (length > 0)
        {
            finalText.push_back(format(rowText, maxWidth, true));
        }

        return finalText;
    }
};

void print(const vector<string>&  lines)
{
    for (auto ii = lines.begin(); ii != lines.end(); ++ii)
        std::cout << *ii << '\n';

    std::cout << '\n';
}

int main()
{
    Solution sol;

    int maxWidth = 16;
    vector<string> str = { "This", "is", "an", "example", "of", "text", "justification." };
    vector<string> result = sol.fullJustify(str, maxWidth);
    print(result);

    maxWidth = 16;
    str = { "What","must","be","acknowledgment","shall","be" };
    result = sol.fullJustify(str, maxWidth);
    print(result);

    maxWidth = 20;
    str = { "Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do" };
    result = sol.fullJustify(str, maxWidth);
    print(result);


}