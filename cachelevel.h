#ifndef CACHELEVEL_H
#define CACHELEVEL_H

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class CacheLevel
{
public:

    int capacity;

    queue<string> blocks;

    unordered_set<string> lookup;

    CacheLevel(int cap)
    {
        capacity = cap;
    }

    bool contains(string block)
    {
        return lookup.count(block);
    }

    string insert(string block)
    {
        if(contains(block))
            return "";

        string evicted = "";

        if(blocks.size() >= capacity)
        {
            evicted = blocks.front();

            cout << evicted
                 << " evicted from cache"
                 << endl;

            blocks.pop();

            lookup.erase(evicted);
        }

        blocks.push(block);

        lookup.insert(block);

        return evicted;
    }

    void print()
    {
        queue<string> temp = blocks;

        cout << "[";

        while(!temp.empty())
        {
            cout << temp.front();

            temp.pop();

            if(!temp.empty())
            {
                cout << ", ";
            }
        }

        cout << "]";
    }
};

#endif