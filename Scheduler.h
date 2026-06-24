#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <queue>
#include <algorithm>

#include "task.h"
#include "CacheHierarchy.h"

using namespace std;

class Scheduler
{
public:

    queue<Task*> readyQueue;

    int quantum;

    Scheduler(int q)
    {
        quantum = q;
    }

    void addTask(Task* task)
    {
        readyQueue.push(task);
    }

    void run(CacheHierarchy& cache)
    {
        int cycle = 1;

        int completedTasks = 0;

        while(!readyQueue.empty())
        {
            Task* current =
                readyQueue.front();

            readyQueue.pop();

            int timeSlice =
                min(quantum,
                    current->remainingTime);

            for(int i = 0;
                i < timeSlice;
                i++)
            {
                cout << "\n================================="
                     << endl;

                cout << "Cycle "
                     << cycle
                     << endl;

                cout << "Running: "
                     << current->id
                     << endl;

                string block =
                    current->getCurrentMemoryBlock();

                int latency =
                    cache.accessMemory(block);

                current->remainingTime--;

                current->moveToNextMemoryBlock();

                cout << "Remaining Time: "
                     << current->remainingTime
                     << endl;

                cout << "Memory Access Latency: "
                     << latency
                     << " cycles"
                     << endl;

                cache.printCaches();

                cycle++;
            }

            if(current->remainingTime > 0)
            {
                readyQueue.push(current);
            }
            else
            {
                completedTasks++;

                cout << "\nTask "
                     << current->id
                     << " completed!"
                     << endl;
            }
        }

        cout << "\n================================="
             << endl;

        cout << "\n=== Final Results ==="
             << endl;

        cout << "Total Cycles: "
             << cycle - 1
             << endl;

        cout << "Tasks Completed: "
             << completedTasks
             << endl;

        cout << "Scheduler: Round Robin"
             << endl;

        cout << "Quantum: "
             << quantum
             << endl;

        cout << "RAM Accesses: "
             << cache.ramAccesses
             << endl;
    }
};

#endif