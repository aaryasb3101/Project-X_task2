#ifndef CACHEHIERARCHY_H
#define CACHEHIERARCHY_H

#include <iostream>
#include "cachelevel.h"

using namespace std;

class CacheHierarchy
{
public:

    CacheLevel L1;
    CacheLevel L2;
    CacheLevel L3;

    int ramAccesses;

    CacheHierarchy()
        : L1(32),
          L2(128),
          L3(512)
    {
        ramAccesses = 0;
    }

    int accessMemory(string block)
    {
        cout << "Requesting: "
             << block
             << endl;

        // L1 HIT
        if(L1.contains(block))
        {
            cout << "L1 -> HIT (4 cycles)"
                 << endl;

            return 4;
        }

        // L2 HIT
        if(L2.contains(block))
        {
            cout << "L1 -> MISS"
                 << endl;

            cout << "L2 -> HIT (12 cycles)"
                 << endl;

            cout << "Promoting "
                 << block
                 << " -> L1"
                 << endl;

            string evictedL1 =
                L1.insert(block);

            if(evictedL1 != "")
            {
                L2.insert(evictedL1);
            }

            return 12;
        }

        // L3 HIT
        if(L3.contains(block))
        {
            cout << "L1 -> MISS"
                 << endl;

            cout << "L2 -> MISS"
                 << endl;

            cout << "L3 -> HIT (40 cycles)"
                 << endl;

            cout << "Promoting "
                 << block
                 << " -> L2 -> L1"
                 << endl;

            string evictedL1 =
                L1.insert(block);

            if(evictedL1 != "")
            {
                string evictedL2 =
                    L2.insert(evictedL1);

                if(evictedL2 != "")
                {
                    L3.insert(evictedL2);
                }
            }

            return 40;
        }

        // RAM MISS
        cout << "L1 -> MISS"
             << endl;

        cout << "L2 -> MISS"
             << endl;

        cout << "L3 -> MISS"
             << endl;

        cout << "Fetching from RAM (200 cycles)"
             << endl;

        ramAccesses++;

        string evictedL1 =
            L1.insert(block);

        if(evictedL1 != "")
        {
            string evictedL2 =
                L2.insert(evictedL1);

            if(evictedL2 != "")
            {
                L3.insert(evictedL2);
            }
        }

        return 200;
    }

    void printCaches()
    {
        cout << "L1 = ";
        L1.print();
        cout << endl;

        cout << "L2 = ";
        L2.print();
        cout << endl;

        cout << "L3 = ";
        L3.print();
        cout << endl;
    }
};

#endif