#include <queue>
#include <algorithm>
#include <vector>
#include "../entities/Process.h"

using namespace std;

void roundRobinScheduler(vector<Process> &processes, int timeQuantum)
{
    queue<Process> readyQueue;
    int currentTime = 0;
    int remainingProcesses = processes.size();

    // this sort function is sorting the processes vector according to their arrival time so that its
    // easier to impliment the round robin scheduling
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
         { return a.arrivalTime < b.arrivalTime; });

    int processesIndex = 0;
    int processesIndexForTurnAroundTime = 0;
    while (remainingProcesses > 0)
    {
        // Check for new arrivals and add them to the ready queue
        while (!processes.empty() && processes[processesIndex].arrivalTime <= currentTime)
        {
            readyQueue.push(processes[processesIndex]);
            processes[processesIndex].waitingTime = currentTime - processes[processesIndex].arrivalTime;
            processesIndex++;
        }

        if (!readyQueue.empty())
        {
            Process currentProcess = readyQueue.front();
            readyQueue.pop();

            int executionTime = min(timeQuantum, currentProcess.burstTime);
            currentProcess.burstTime -= executionTime;
            currentTime += executionTime;

            if (currentProcess.burstTime > 0)
            {
                readyQueue.push(currentProcess);
            }
            else
            {
                processes[processesIndexForTurnAroundTime].turnAroundTime = currentTime - processes[processesIndexForTurnAroundTime].arrivalTime;
                processesIndexForTurnAroundTime++;
                cout << "Task ID " << currentProcess.id << " has completed.\n";
                remainingProcesses--;
            }
        }
        else
        {
            currentTime++;
        }
    }
    cout << "Process ID\tWaiting Time\tTurn Around Time" << endl;
    for (const Process &process : processes)
    {
        cout << process.id << "\t\t" << process.waitingTime << "\t\t" << process.turnAroundTime << endl;
    }
}