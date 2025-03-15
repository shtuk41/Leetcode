#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

class LRUCache {

    unsigned int maxNodeCapacity;
    unordered_map<int, list<pair<int, int>>::iterator> table;
    list<pair<int, int>> values;

    void UpdateGet(list<pair<int, int>>::iterator &it_val)
    {
        values.splice(values.end(), values, it_val);
        it_val = prev(values.end());
    }

    void UpdatePut(int key, int value, list<pair<int, int>>::iterator& it_val)
    {
        auto it_table = table.find(key);

        if (it_table != table.end() && it_table->second != values.end())
        {
            it_table->second->second = value;
            values.splice(values.end(), values, it_table->second);
            it_val = prev(values.end());
        }
        else
        {
            values.push_back({ key, value });
            it_val = prev(values.end());

            if (values.size() > maxNodeCapacity)
            {
                auto f  = values.front();
                values.pop_front();
                table[f.first] = values.end();
            }
        }
    }

public:
    LRUCache(int capacity) : maxNodeCapacity(capacity) {}

    int get(int key) {

        auto it = table.find(key);

        if (it == table.end() || it->second == values.end())
        {
            return -1;
        }
        else
        {
            UpdateGet(it->second);
            return it->second->second;
        }
    }

    void put(int key, int value) {

        list<pair<int, int>>::iterator it_put;
        UpdatePut(key, value, it_put);
        table[key] = it_put;
    }
};

void test(vector<vector<int>> commands)
{
    LRUCache* lrucache = new LRUCache(commands[0][0]);
    
    for (vector<vector<int>>::iterator it = commands.begin() + 1; it != commands.end(); ++it)
    {
        if (it->size() == 1)
        {
            std::cout << "get: " << (*it)[0] << " " << lrucache->get((*it)[0]) << '\n';
        }
        else
        {
            lrucache->put((*it)[0], (*it)[1]);
        }
    }

    std::cout << '\n';
}

int main()
{
    test({ {2}, {1,1}, {2,2}, {1}, {3,3}, {2}, {4,4}, {1}, {3}, {4} });
    test({ {2},{1, 0},{2, 2},{1},{3, 3},{2},{4, 4},{1},{3},{4} });
    test({ {1},{2,1},{2},{3,2},{2},{3}});
    test({ {2},{2},{2, 6},{1},{1, 5},{1, 2},{1},{2} });
    test({ {2},{2, 1},{2, 2},{2},{1, 1},{4, 1},{2} });
    test({{10}, {10, 13}, {3, 17}, {6, 11}, {10, 5}, {9, 10}, {13}, {2, 19}, {2}, {3}, {5, 25}, {8}, {9, 22}, {5, 5}, {1, 30}, {11}, {9, 12}, {7}, {5}, {8}, {9}, {4, 30}, {9, 3}, {9}, {10}, {10}, {6, 14}, {3, 1}, {3}, {10, 11}, {8}, {2, 14}, {1}, {5}, {4}, {11, 4}, {12, 24}, {5, 18}, {13}, {7, 23}, {8}, {12}, {3, 27}, {2, 12}, {5}, {2, 9}, {13, 4}, {8, 18}, {1, 7}, {6}, {9, 29}, {8, 21}, {5}, {6, 30}, {1, 12}, {10}, {4, 15}, {7, 22}, {11, 26}, {8, 17}, {9, 29}, {5}, {3, 4}, {11, 30}, {12}, {4, 29}, {3}, {9}, {6}, {3, 4}, {1}, {10}, {3, 29}, {10, 28}, {1, 20}, {11, 13}, {3}, {3, 12}, {3, 8}, {10, 9}, {3, 26}, {8}, {7}, {5}, {13, 17}, {2, 27}, {11, 15}, {12}, {9, 19}, {2, 15}, {3, 16}, {1}, {12, 17}, {9, 1}, {6, 19}, {4}, {5}, {5}, {8, 1}, {11, 7}, {5, 2}, {9, 28}, {1}, {2, 2}, {7, 4}, {4, 22}, {7, 24}, {9, 26}, {13, 28}, {11, 26}} );

    return 0;
}


