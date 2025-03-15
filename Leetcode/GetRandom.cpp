#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {

    unordered_map<int, size_t> indexTable;
    vector<int> elements;

public:

    RandomizedSet() {
        std::srand(std::time(nullptr));
    }

    bool insert(int val) {
           
        if (indexTable.find(val) == indexTable.end())
        {
            elements.push_back(val);
            indexTable[val] = elements.size() - 1;

            return true;
        }

        return false;
    }

    bool remove(int val) {
       
        auto it = indexTable.find(val);

        if (it != indexTable.end())
        {
            auto last = std::prev(elements.end());
            auto el = elements.begin();
            std::advance(el, it->second);

            auto itlast = indexTable.find(*last);
            itlast->second = it->second;

            swap(*el, *last);

 
            elements.pop_back();
            indexTable.erase(it);

            return true;
        }

        string s = "hello";

        return false;

    }

    int getRandom() {

        int random = std::rand() % elements.size();
        return elements[random];
    }
};

int main()
{
    RandomizedSet rset;

    std::cout << rset.insert(1) << std::endl;
    std::cout << rset.remove(2) << std::endl;
    std::cout << rset.insert(2) << std::endl;
    std::cout << rset.getRandom() << std::endl;
    std::cout << rset.remove(1) << std::endl;
    std::cout << rset.insert(2) << std::endl;
    std::cout << rset.getRandom() << std::endl;
    std::cout << '\n';

    RandomizedSet rset2;

    std::cout << rset2.insert(0) << std::endl;
    std::cout << rset2.insert(1) << std::endl;
    std::cout << rset2.remove(0) << std::endl;
    std::cout << rset2.insert(2) << std::endl;
    std::cout << rset2.remove(1) << std::endl;
    std::cout << rset2.getRandom() << std::endl;

    return 0;
}



