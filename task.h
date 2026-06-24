#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

using namespace std;

class Task
{
public:
    string id;

    int burstTime;

    int remainingTime;

    vector<string> memoryBlocks;

    int currentMemoryIndex;

    Task(
        string taskId,
        int burst,
        vector<string> memBlocks
    )
    {
        id = taskId;

        burstTime = burst;

        remainingTime = burst;

        memoryBlocks = memBlocks;

        currentMemoryIndex = 0;
    }
    string getCurrentMemoryBlock()
{
    return memoryBlocks[currentMemoryIndex];
}
void moveToNextMemoryBlock()
{
    currentMemoryIndex =
    (currentMemoryIndex + 1)
    % memoryBlocks.size();
}
};

#endif