#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "task.h"

using namespace std;

class Parser
{
public:

    static vector<Task> readTasks(string filename)
    {
        vector<Task> tasks;

        ifstream file(filename);

        string line;

        while(getline(file, line))
        {
            stringstream ss(line);

            string temp;

            string taskId;

            int burst;

            vector<string> memBlocks;

            ss >> temp;      // TASK

            ss >> taskId;    // T1

            ss >> temp;      // BURST

            ss >> burst;     // 5

            ss >> temp;      // MEM

            string block;

            while(ss >> block)
            {
                memBlocks.push_back(block);
            }

            tasks.push_back(
                Task(taskId,
                     burst,
                     memBlocks)
            );
        }

        return tasks;
    }
};

#endif