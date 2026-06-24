#include <iostream>

#include "Parser.h"
#include "Scheduler.h"
#include "CacheHierarchy.h"

using namespace std;

int main()
{
    vector<Task> tasks =
        Parser::readTasks("input.txt");

    Scheduler scheduler(2);

    for(Task& task : tasks)
    {
        scheduler.addTask(&task);
    }

    CacheHierarchy cache;

    scheduler.run(cache);

    return 0;
}