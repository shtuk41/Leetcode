#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        stack<string> dirs;
        string dirName;

        for (int ii = 0; ii < path.length(); ii++)
        {
            if (path[ii] == '.')
            {
                int jj = ii;
                while (path[jj] == '.' && jj < path.length())
                {
                    jj++;
                }

                int numberOfDots = jj - ii;

                if (numberOfDots > 2 || jj < path.length() && path[jj] != '/' || dirName != "")
                {
                    for (int n = 0; n < numberOfDots; n++)
                        dirName += '.';

                    ii += numberOfDots - 1;
                }
                else if (numberOfDots == 2)
                {
                    if (dirs.size() > 1)
                    {
                        dirs.pop();

                        if (dirs.size() > 1)
                            dirs.pop();
                    }

                    ii += 1;
                }
            }
            else if (path[ii] == '/')
            {
                if (dirName != "")
                {
                    if (!dirs.empty() &&  dirs.top() != "/")
                        dirs.push("/");
                    dirs.push(dirName);
                    dirName = "";
                }

                while (path[ii] == '/' && ii < path.length())
                {
                    ii++;
                }

                ii--;

                if (dirs.size() == 0)
                    dirs.push("/");
        
            }
            
            else
            {
                dirName += path[ii];
            }
        }

        if (dirName != "")
        {
            if (!dirs.empty() && dirs.top() != "/")
                dirs.push("/");
            dirs.push(dirName);
        }

        if (dirs.size() > 1 && dirs.top() == "/")
        {
            dirs.pop();
        }

        string result;

        while (!dirs.empty())
        {
            result.insert(0, dirs.top());
            dirs.pop();
        }

        return result;
    }
};

void test(string name, string path)
{
    Solution sol;
    string simple = sol.simplifyPath(path);
    std::cout << name << " : " << simple << std::endl;
}

int main()
{
    test("test1", "/home/");
    test("test2", "/home//foo/");
    test("test3", "/home/user/Documents/../Pictures");
    test("test4", "/../");
    test("test5", "/.../a/../b/c/../d/./");
    test("test6", "/a/./b/../../c/");
    test("test7", "/..hidden");
    test("test8", "/hello../world");
    test("test9", "///eHx/..");
}

